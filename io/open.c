// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	/* TODO: Implement open system call. */

	int ret;

	if (flags & O_CREAT) {
		va_list v;
		va_start(v, flags);
		int mode = va_arg(v, int);
		ret = syscall(__NR_open, filename, flags, mode);
		va_end(v);
	} else {
		ret = syscall(__NR_open, filename, flags);
	}

	if (ret < 0) {
		errno = -ret;
		return -1;
	}

	return ret;
}
