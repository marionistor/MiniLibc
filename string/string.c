// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */

	char *s = destination;

	while (*source != '\0') {
		*s = *source;
		source++;
		s++;
	}

	*s = '\0';

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */

	char *s = destination;

	while (len && *source != '\0') {
		*s = *source;
		source++;
		s++;
		len--;
	}

	while (len) {
		*s = '\0';
		s++;
		len--;
	}
		return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */

	char *s = destination + strlen(destination);

	while (*source != '\0') {
		*s = *source;
		source++;
		s++;
	}

	*s = '\0';

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */

	char *s = destination + strlen(destination);

	while (len && *source != '\0') {
		*s = *source;
		source++;
		s++;
		len--;
	}

	*s = 0;

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */

	while (*str1 != '\0' && *str2 != '\0') {
		if (*str1 > *str2) {
			return 1;
		}
		if (*str1 < *str2) {
			return -1;
		}
		str1++;
		str2++;
	}

	if (*str1 != '\0') {
		return 1;
	}

	if (*str2 != '\0') {
		return -1;
	}

	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */

	while (*str1 != '\0' && *str2 != '\0' && len) {
		if (*str1 != *str2) {
			return *str1 - *str2;
		}
		str1++;
		str2++;
		len--;
	}

	if (len != 0) {
		return *str1 - *str2;
	}

	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */

	while (*str != '\0') {
		if (*str == c) {
			return (char *)str;
		}
		str++;
	}

	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */

	char *addr = NULL;

	while (*str != '\0') {
		if (*str == c) {
			addr = (char *)str;
		}
		str++;
	}

	return addr;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */

	while (*haystack != '\0') {
		if (strncmp(haystack, needle, strlen(needle)) == 0) {
			return (char *)haystack;
		}
		haystack++;
	}

	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */

	char *addr = NULL;

	while (*haystack != '\0') {
		if (strncmp(haystack, needle, strlen(needle)) == 0) {
			addr = (char *)haystack;
		}
		haystack++;
	}

	return addr;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */

	const char *src = (const char *)source;
	char *dest = (char *)destination;

	strncpy(dest, src, num);

	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */

	const char *src = (const char *)source;
	char *dest = (char *)destination;

	if (dest < src) {
		memcpy(dest, src, num);
	} else {
		while (num) {
			*(dest + num - 1) = *(src + num - 1);
			num--;
		}
	}

	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */

	const char *p1 = (const char *)ptr1;
	const char *p2 = (const char *)ptr2;

	int ret_val = strncmp(p1, p2, num);

	return ret_val;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */

	char *src = (char *)source;

	while (num) {
		*src = value;
		src++;
		num--;
	}

	return source;
}
