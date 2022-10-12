//
// Created by lmy on 2022/10/10.
//

#ifndef ULTRASERVER_THREAD_H
#define ULTRASERVER_THREAD_H

#include "mutex.h"

namespace ultra {

    /**
     * @brief 线程类
     */
    class Thread : Noncopyable {
    public:
        /// 线程智能指针类型
        typedef std::shared_ptr<Thread> ptr;

        /**
         * @brief 构造函数
         * @param[in] cb 线程执行函数
         * @param[in] name 线程名称
         */
        Thread(std::function<void()> cb, const std::string &name);

        /**
         * @brief 析构函数
         */
        ~Thread();

        /**
         * @brief 线程ID
         */
        pid_t getId() const { return m_id; }

        /**
         * @brief 线程名称
         */
        const std::string &getName() const { return m_name; }

        /**
         * @brief 等待线程执行完成
         */
        void join();

        /**
         * @brief 获取当前的线程指针
         */
        static Thread *GetThis();

        /**
         * @brief 获取当前的线程名称
         */
        static const std::string &GetName();

        /**
         * @brief 设置当前线程名称
         * @param[in] name 线程名称
         */
        static void SetName(const std::string &name);

    private:
        /**
         * @brief 线程执行函数
         */
        static void *run(void *arg);

    private:
        /// 线程id
        pid_t m_id = -1;
        /// 线程结构
        pthread_t m_thread = 0;
        /// 线程执行函数
        std::function<void()> m_cb;
        /// 线程名称
        std::string m_name;
        /// 信号量
        Semaphore m_semaphore;
    };

}
#endif //ULTRASERVER_THREAD_H
