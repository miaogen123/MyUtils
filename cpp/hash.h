//来源
//http://blog.csdn.net/djinglan/article/details/8812934
//
/// @brief BKDR Hash Function
/// @detail 本算法由于在Brian Kernighan与Dennis Ritchie的《The C Programming Language》一书被展示而得名，是一种简单快捷的hash算法，也是Java目前采用的字符串的Hash算法（累乘因子为31）。
#pragma once
#include<cstdio>

template<class T>
size_t BKDRHash(const T *str);

/// @brief SDBM Hash Function
/// @detail 本算法是由于在开源项目SDBM（一种简单的数据库引擎）中被应用而得名，它与BKDRHash思想一致，只是种子不同而已。
template<class T>
size_t SDBMHash(const T *str);

/// @brief RS Hash Function
/// @detail 因Robert Sedgwicks在其《Algorithms in C》一书中展示而得名。
template<class T>
size_t RSHash(const T *str);

/// @brief AP Hash Function
/// @detail 由Arash Partow发明的一种hash算法。
template<class T>
size_t APHash(const T *str);

/// @brief JS Hash Function
/// 由Justin Sobel发明的一种hash算法。
template<class T>
size_t JSHash(const T *str);

/// @brief DEK Function
/// @detail 本算法是由于Donald E. Knuth在《Art Of Computer Programming Volume 3》中展示而得名。
template<class T>
size_t DEKHash(const T* str);

/// @brief FNV Hash Function
/// @detail Unix system系统中使用的一种著名hash算法，后来微软也在其hash_map中实现。
template<class T>
size_t FNVHash(const T* str);

/// @brief DJB Hash Function
/// @detail 由Daniel J. Bernstein教授发明的一种hash算法。
template<class T>
size_t DJBHash(const T *str);

/// @brief DJB Hash Function 2
/// @detail 由Daniel J. Bernstein 发明的另一种hash算法。
template<class T>
size_t DJB2Hash(const T *str);

/// @brief PJW Hash Function
/// @detail 本算法是基于AT&T贝尔实验室的Peter J. Weinberger的论文而发明的一种hash算法。
template<class T>
size_t PJWHash(const T *str);

/// @brief ELF Hash Function
/// @detail 由于在Unix的Extended Library Function被附带而得名的一种hash算法，它其实就是PJW Hash的变形。
template<class T>
size_t ELFHash(const T *str);


//from: https://blog.csdn.net/lwm_1985/article/details/7459020
unsigned long long MurmurHash64B (const void * key, int len, unsigned int seed = 0xEE6B27EB);