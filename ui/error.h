#pragma once

#include <stdio.h>
#include <stdlib.h>

void error(const char *context)
{
    printf("uh oh! %s\n", context);
}

void fatal_error(const char *context, int exit_code)
{
    printf("FATAL ERROR: %s (error code: %d)\n", context, exit_code);
    exit(exit_code);
}
