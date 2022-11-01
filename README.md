# ultraServer

ultra高性能服务器框架

##当前进度
| 日期         |        进度        |
|------------|:----------------:|
| 2022-9-28  |   创建项目结构，项目初始化   |
| 2022-9-29  |      完成日志模块      |
| 2022-10-5  | 完善util模块与macro模块 |
| 2022-10-8  |     完成环境配置模块     |
| 2022-10-9  |   融合日志模块与配置模块    |
| 2022-10-12 |      完成线程模块      |
| 2022-10-17 |      完成协程模块      |
| 2022-10-19 |     完成协程调度模块     |
| 2022-10-25 |     完成IO调度模块     |
| 2022-10-31 |     完成定时器模块      |
| todo       |      hook模块      |





## 模块概述

### 日志模块

支持流式日志风格写日志和格式化风格写日志，支持日志格式自定义，日志级别，多日志分离等功能。

流式日志使用示例：

```cpp
ULTRA_LOG_INFO(g_logger) << "message";
```

c风格格式化日志使用示例：
```cpp
ULTAR_LOG_FMT_INTO(g_logger,"%s","this is a log");
```
### 配置模块
用于定义、声明配置项，并且从配置文件中加载用户配置。

#### 配置模块设计
简单来说，约定优于配置的背景条件是，一般来说，程序所依赖的配置项都有一个公认的默认值，也就是所谓的约定。这点有可许多可以参考的例子，比如对于一个http网络服务器，服务端口通常都是80端口，对于配置文件夹路径，一般都是conf文件夹，对于数据库目录，一般都是db或data文件夹。对于这些具有公认约定的配置，就不需要麻烦程序员在程序跑起来后再一项一项地指定了，而是可以初始时就将配置项设置成对应的值。这样，程序员就可以只修改那些约定之外的配置项，然后以最小的代价让程序跑起来。

约定优于配置的方式可以减少程序员做决定的数量，获得简单的好处，同时兼顾灵活性。

在代码上，约定优于配置的思路体现为所有的配置项在定义时都带一个的默认值，以下是一个ultra配置项的示例，这是一个int类型的配置项，名称为tcp.connect.timeout，初始值为5000。

```cpp
static ultra::ConfigVar<int>::ptr g_tcp_connect_timeout = ultra::Config::Lookup("tcp.connect.timeout", 5000, "tcp connect timeout");
```

ultra的配置项定义之后即可使用，比如上面的配置项可以直接使用g_tcp_connect_timeout->getValue()获取参数的值，这里获取的为默认值5000。

ultra使用YAML做为配置文件，配置名称大小写不敏感，并且支持级别格式的数据类型，比如上面的配置项对应的YAML配置文件内容如下：

```yaml
tcp:
    connect:
        timeout: 10000
```

这里指定了配置名称为 tcp.connect.timeout的配置项的值为10000。由于配置文件指定的值与默认值不一样，当配置文件加载后，对应的配置项值会被自动更新为10000，如果配置项还注册了配置变更回调函数的话，会一并调用配置变更回调函数以通知配置使用方。

ultra支持STL容器（vector, list, set, map等等），支持自定义类型（需要实现序列化和反序列化方法)。

#### 配置模块实现

使用YAML解析库，核心技术使用仿函数的偏特化实现。

### 协程模块
1. **协程与函数**：协程其实就是函数，它不能像线程一样并发，工作在用户态。协程与函数的不同点就是函数一旦被调用，只能从头开始执行，直到函数结束，而协程
可以执行到一半就退出（也就是协程的原语yield）,但这个时候协程并没有真正得结束，只是让出CPU执行权，在后面合适的时机再
重新恢复运行（也就是协程的resume方法），在这段时间内，其他的协程可以获得CPU执行权，所以协程也称为轻量级线程（减少了很多上下文切换）。
2. **协程可实现的基础**：协程能够之所以执行过程中能够yield，是因为能够保存yield之前的状态，以便后面再恢复执行，这个状态也就是协程上下文。协程上下文包含了函数在当前执行状态下得全部CPU寄存器的值，这些寄存器值记录了函数栈帧、代码的执行位置等信息，如果将这些寄存器的值重新设置给CPU，就相当于恢复了函数的运行。在linux下用ucontect_t结构体表示，通过getcontext()来获取。
3. **协程与线程**：协程虽然称为轻量级线程，但是单线程内协程是不能并发的，其本质还是函数，只不过可以花里胡哨的运行，协程只能一个协程yield后另外一个协程resume，而线程是真正可以实现并发执行的。
4. **注意**：因为单线程下协程不是并发执行的，所以不能在协程里使用线程级别的锁来做协程同步。


####协程模块设计
采用非对称协程模型设计，也就是子协程只能和线程主协程切换，而不能和另外一个子协程切换，并且在程序结束时，一定要再切回主协程，以保证程序正确结束。

对称协程中，子协程可以直接和子协程切换，也就是说每个协程不仅要运行自己的入口函数代码，还要负责选择出下一个合适的协程进行切换，每个协程都要充当调度器的角色，这样设计程序的控制流会变得很复杂和难以管理。而在非对称协程中，可以借助专门的调度器来负责调度协程，每个协程只需要运行自己的入口函数，然后结束时将运行权交给调度器，由调度器选出下一个要执行的协程即可。

借助线程局部变量thread_local来实现协程模块：
* thread_local: 线程局部变量与全局变量类似，不同之处在于声明的线程局部变量在每个线程都独有一份，而全局变量是全部线程共享一份。

使用线程局部变量来保存协程上下文对象，是为了在不同线程的协程相互不影响，每个线程都要独自处理当前线程的协程切换问题。使用两个线程局部变量来存储上下文信息分别是t_fiber,和t_thread_fiber，也就是说一个线程在任何时候最多只知道这两个协程的上下文信息。两个协程通过swapcontext函数来实现切换，也就是说，这两个线程局部变量必须有一个是来保存线程主协程的上下文的，如果两个线程局部变量都是保存子协程的上下文，那么无论怎么调用swapcontext，都无法切换到线程主协程，程序就跑飞了。
### 协程调度模块
实现N-M的协程调度器，N个线程运行M个协程，协程可以在线程之间进行切换，也可以绑定到指定的线程运行。协程调度实现了子协程与子协程之间的切换。

#### 协程调度概述

当有很多协程时，怎么用线程把这些协程都消化掉，这就是协程调度。之前的协程模块，需要用户手动执行resume方法进行调度，等协程运行结束返回，再运行下一个协程。用户在充当调度器，使用不够方便。引入协程调度后，创建一个协程调度器，然后将协程或者函数加入调度器，由调度器来完成调度工作，其实就是协程池。

#### 协程调度设计

使用多线程消化添加到任务队列的协程和线程。

1. 协程调度的初始化。协程调度器在初始化时支持传入线程数和一个布偶型的use_caller参数，此参数表示是否使用caller线程。在使用caller线程的情况下，线程数自动减一，并且调度器内部会初始化一个属于caller线程的调度协程并保存起来。
2. 添加任务。通过schedule方法向调度器中添加任务，但此时调度器不会立马工作，而是将他们保存到任务队列中。
3. 启动调度。对应start方法，此方法会创建线程池，线程数由初始化参数决定，调度线程一旦创建完成后，就会从任务队列中取任务执行。
4. 调度协程。对应run方法。调度协程负责从调度器的任务队列中取任务执行。取出的任务即子协程，调度协程与子协程之间切换即为前面说的非对称模型，每个子协程执行完都必须切换到调度协程，当任务队列为空的时候，切换到idle(空闲)协程，这个idle什么也不做，等有新任务添加后，idle会退出并回到调度协程，继续调度任务。

    在非对称协程中，子协程只能与主协程切换。调度协程不能直接和子线程切换，主要原因就是每个线程用两个线程局部变量只保存了正在运行的协程的上下文，以及线程主协程的上下文，如果是保存两个子协程的上下文，就无法切换回主协程，导致程序跑飞。改用三个线程局部变量即可实现调度协程与子协程切换，三个线程局部变量分别保存正在运行子协程的上下文，线程主协程上下文，调度协程上下文。
    1. 给协程类增加一个bool类型的成员m_runInScheduler，用于记录该协程是否通过调度器来运行。

    2. 创建协程时，根据协程的身份指定对应的协程类型，具体来说，只有想让调度器调度的协程的m_runInScheduler值为true，线程主协程和线程调度协程的m_runInScheduler都为false。

    3. resume一个协程时，如果如果这个协程的m_runInScheduler值为true，表示这个协程参与调度器调度，那它应该和三个线程局部变量中的调度协程上下文进行切换，同理，在协程yield时，也应该恢复调度协程的上下文，表示从子协程切换回调度协程；

    4. 如果协程的m_runInScheduler值为false，表示这个协程不参与调度器调度，那么在resume协程时，直接和线程主协程切换就可以了，yield也一样，应该恢复线程主协程的上下文。m_runInScheduler值为false的协程上下文切换完全和调度协程无关，可以脱离调度器使用。

    经过上面的改造了，就可以解决单线程环境下caller线程主协程-调度协程-任务协程之间的上下文切换问题了，假设caller线程主协程的上下文为main_ctx，调度协程的上下文为scheduler_ctx，任务协程上下文为child_ctx，那么单线程下的协程切换将像下面这样：
    ![img.png](assert/img.png)

### IO协程调度——epoll

是协程调度模块的子类。封装了epoll，支持为socket fd注册读写事件回调函数。IO调度模块重写idle方法解决协程调度模块idle协程忙等待cpu占用率高的问题。IO协程调度器使用一对管道pipe来tickle调度协程，当调度器空闲时，idle协程通过epoll_wait阻塞在读管道的fd上，等到管道的读事件发生，也就意味着有新任务需要调度(tickle方法写管道)，idle协程检测到管道可读后退出，调度器执行执行调度。

#### IO协程调度概述



#### IO调度协程设计

### 定时器模块

### HOOK模块——同步方式实现异步


