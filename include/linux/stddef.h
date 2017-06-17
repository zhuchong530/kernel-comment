#ifndef _LINUX_STDDEF_H
#define _LINUX_STDDEF_H

#include <uapi/linux/stddef.h>

#undef NULL
#define NULL ((void *)0)

enum {
	false	= 0,
	true	= 1
};

#undef offsetof
#ifdef __compiler_offsetof
#define offsetof(TYPE, MEMBER)	__compiler_offsetof(TYPE, MEMBER)
#else
/*
  (TYPE *)0将整型常量0强制转换为TYPE型的指针，且这个指针指向的地址为0，
  也就是将地址0开始的一块存储空间映射为TYPE型的对象，接下来再对结构体中MEMBER成员进行取址，
  而整个TYPE结构体的首地址是0，这里获得的地址就是MEMBER成员在TYPE中的相对偏移量。再将这个偏移量强制转换成size_t型数据（无符号整型）。
*/
#define offsetof(TYPE, MEMBER)	((size_t)&((TYPE *)0)->MEMBER)
#endif

/**
 * offsetofend(TYPE, MEMBER)
 *
 * @TYPE: The type of the structure
 * @MEMBER: The member within the structure to get the end offset of
 */
#define offsetofend(TYPE, MEMBER) \
	(offsetof(TYPE, MEMBER)	+ sizeof(((TYPE *)0)->MEMBER))

#endif
