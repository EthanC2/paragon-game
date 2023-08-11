#pragma once

#include <stdio.h>
#include <stddef.h>
#include "prompt.h"
#include "file.h"

int menu_choice(const char *filename, int nopt)
{
    putchar('\n');
    file_print(filename);
    putchar('\n');
    return prompt_int(1, nopt) - 1;
}
