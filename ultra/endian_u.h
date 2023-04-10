//
// Created by lmy on 2022/11/3.
//

#ifndef __ULTRASERVER_ENDIAN_H__
#define __ULTRASERVER_ENDIAN_H__

#define ULTRA_LITTLE_ENDIAN 1
#define ULTRA_BIG_ENDIAN 2

#include <byteswap.h>


#include <cstdint>

namespace ultra {

/**
 * @brief 8字节类型的字节序转化
 */
    template <class T>
    typename std::enable_if<sizeof(T) == sizeof(uint64_t), T>::type
    byteswap(T value) {
        return (T)bswap_64((uint64_t)value);
    }

/**
 * @brief 4字节类型的字节序转化
 */
    template <class T>
    typename std::enable_if<sizeof(T) == sizeof(uint32_t), T>::type
    byteswap(T value) {
        return (T)bswap_32((uint32_t)value);
    }

/**
 * @brief 2字节类型的字节序转化
 */
    template <class T>
    typename std::enable_if<sizeof(T) == sizeof(uint16_t), T>::type
    byteswap(T value) {
        return (T)bswap_16((uint16_t)value);
    }

#if BYTE_ORDER == BIG_ENDIAN
#define ULTRA_BYTE_ORDER ULTRA_BIG_ENDIAN
#else
#define ULTRA_BYTE_ORDER ULTRA_LITTLE_ENDIAN
#endif

#if ULTRA_BYTE_ORDER == ULTRA_BIG_ENDIAN

    /**
 * @brief 只在小端机器上执行byteswap, 在大端机器上什么都不做
 */
template <class T>
T byteswapOnLittleEndian(T t) {
    return t;
}

/**
 * @brief 只在大端机器上执行byteswap, 在小端机器上什么都不做
 */
template <class T>
T byteswapOnBigEndian(T t) {
    return byteswap(t);
}
#else

/**
 * @brief 只在小端机器上执行byteswap, 在大端机器上什么都不做
 */
    template <class T>
    T byteswapOnLittleEndian(T t) {
        return byteswap(t);
    }

/**
 * @brief 只在大端机器上执行byteswap, 在小端机器上什么都不做
 */
    template <class T>
    T byteswapOnBigEndian(T t) {
        return t;
    }
#endif

}

#endif //ULTRASERVER_ENDIAN_H
