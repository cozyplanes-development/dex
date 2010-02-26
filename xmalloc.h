#ifndef XMALLOC_H
#define XMALLOC_H

#include "common.h"

#if defined(__GNUC__) && (__GNUC__ >= 3)
#define __MALLOC	__attribute__((__malloc__))
#else
#define __MALLOC
#endif

#define xnew(type, n)		(type *)xmalloc(sizeof(type) * (n))
#define xnew0(type, n)		(type *)xcalloc(sizeof(type) * (n))
#define xrenew(mem, n)		do { \
					mem = xrealloc(mem, sizeof(*mem) * (n)); \
				} while (0)

void * __MALLOC xmalloc(size_t size);
void * __MALLOC xcalloc(size_t size);
void * __MALLOC xrealloc(void *ptr, size_t size);
char * __MALLOC xstrdup(const char *str);
void * __MALLOC xmemdup(const void *ptr, size_t size);
char * __MALLOC xstrndup(const char *str, size_t n);

#endif
