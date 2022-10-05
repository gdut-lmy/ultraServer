//
// Created by lmy on 2022/10/5.
//

#ifndef ULTRASERVER_MACRO_H
#define ULTRASERVER_MACRO_H

#include <string.h>
#include <assert.h>
#include "log.h"
#include "util.h"

#if defined __GNUC__ || defined __llvm__
/// LIKCLY 宏的封装, 告诉编译器优化,条件大概率成立
#define ULTRA_LIKELY(x) __builtin_expect(!!(x), 1)
/// LIKCLY 宏的封装, 告诉编译器优化,条件大概率不成立
#define ULTRA_UNLIKELY(x) __builtin_expect(!!(x), 0)
#else
#define ULTRA_LIKELY(x) (x)
#define ULTRA_UNLIKELY(x) (x)
#endif

/// 断言宏封装
#define ULTRA_ASSERT(x)                                                                \
    if (ULTRA_UNLIKELY(!(x))) {                                                        \
        ULTRA_LOG_ERROR(ULTRA_LOG_ROOT()) << "ASSERTION: " #x                          \
                                          << "\nbacktrace:\n"                          \
                                          << ultra::BacktraceToString(100, 2, "    "); \
        assert(x);                                                                     \
    }

/// 断言宏封装
#define ULTRA_ASSERT2(x, w)                                                            \
    if (ULTRA_UNLIKELY(!(x))) {                                                        \
        ULTRA_LOG_ERROR(ULTRA_LOG_ROOT()) << "ASSERTION: " #x                          \
                                          << "\n"                                      \
                                          << w                                         \
                                          << "\nbacktrace:\n"                          \
                                          << ultra::BacktraceToString(100, 2, "    "); \
        assert(x);                                                                     \
    }

#endif //ULTRASERVER_MACRO_H
