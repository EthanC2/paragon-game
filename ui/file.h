#pragma once

#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include "error.h"

static int page_size;
static FILE *file;
static char *buffer;
static ssize_t nread;

__attribute__ ((constructor)) void file_init()
{
    page_size = getpagesize();
    buffer = (char*) malloc(page_size * sizeof(char));
    file = NULL;
    nread = 0;
}

__attribute__ ((destructor)) void file_exit()
{
    free(buffer);
}

void file_print(const char *filename)
{
    file = fopen(filename, "r");
    if (file == NULL)
    {
	error(filename, ENOFILE, true);
	return;
    }

    while (!feof(file))
    {
	nread = fread(buffer, sizeof(char), page_size, file);
	if (nread > 0)
	{
	    fputs(buffer, stdout);
	}
    }

    fclose(file);
}
