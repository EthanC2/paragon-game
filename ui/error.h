#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ENOFILE 1

static const char *err_lut[] = {
    [ENOFILE] = "missing file"
};

void error(const char *context, int errcode, bool fatal)
{
    if (context == NULL)
    {
	context = "no context";
    }

    printf("[ERROR] %s: %s\n", err_lut[errcode], context);

    if (fatal)
    {
	exit(+errcode);
    }
}
