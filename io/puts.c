// SPDX-License-Identifier: BSD-3-Clause

#include <internal/io.h>
#include <string.h>
#include <stdio.h>

int puts(const char *s)
{
    int ret;

    ret = write(1, s, strlen(s));
    if (ret == -1) {
        return EOF;
    }

    ret = write(1, "\n", 1);
    if (ret == -1) {
        return EOF;
    }

    return ret;
}
