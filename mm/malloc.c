// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */

	if (size == 0) {
		return NULL;
	}

	long *addr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	if (addr == MAP_FAILED) {
		return NULL;
	}

	mem_list_add(addr, size);

	return addr;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */

	if (nmemb == 0 || size == 0) {
		return NULL;
	}

	long *addr = mmap(NULL, nmemb * size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	if (addr == MAP_FAILED) {
		return NULL;
	}

	mem_list_add(addr, nmemb * size);

	memset(addr, 0, nmemb * size);

	return addr;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */

	struct mem_list *lst = mem_list_find(ptr);

	if (lst == NULL) {
		return;
	}

	int ret = munmap(lst->start, lst->len);

	if (ret == 0) {
		mem_list_del(lst->start);
	}
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */

	if (ptr == NULL) {
		return malloc(size);
	}

	if (size == 0) {
		free(ptr);
		return NULL;
	}

	struct mem_list *lst = mem_list_find(ptr);

	if (lst == NULL) {
		return NULL;
	}

	void *addr = mremap(ptr, lst->len, size, MAP_PRIVATE | MAP_ANONYMOUS);

	if (addr == MAP_FAILED) {
		return ptr;
	}

	lst->len = size;
	lst->start = addr;

	return addr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */

	if (nmemb && size > __SIZE_MAX__ / nmemb) {
		errno = ENOMEM;
		return NULL;
	}

	return realloc(ptr, nmemb * size);
}
