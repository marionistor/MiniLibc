// SPDX-License-Identifier: BSD-3-Clause

#include <internal/syscall.h>
#include <errno.h>
#include <time.h>

int nanosleep(const struct timespec *req, struct timespec *rem)
{
    int ret = syscall(__NR_nanosleep, req, rem);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

unsigned int sleep(unsigned int seconds)
{
    struct timespec t = {.tv_sec = seconds, .tv_nsec = 0};

    if (nanosleep(&t, &t)) {
        return t.tv_sec;
    }

    return 0;
}
