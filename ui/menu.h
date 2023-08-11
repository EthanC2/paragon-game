#pragma once

#include <stdio.h>
#include <stddef.h>
#include "prompt.h"
#include "error.h"

int menu_choice(const char *menu_file)
{
    //1. Open menu file
    //2. Find and get pointer '\n\n' delimiter between header and choices
    //3. Transform second '\n' into '\0'
    //4. Print menu header
    //5. Print enumerator menu choices
    //6. Return choice
    FILE *menu = fopen(menu_file, "r");
    if (menu == NULL)
    {
	//TODO
	fatal_error(MISSING_FILE);
	return;
    }

    return prompt_int(NULL, 1, nopt);
}


int menu_choice(char *header, char **options, int nopt)
{
    if (header != NULL) 
    {
	puts(header);
    }

    for(int i=0; i < nopt; ++i)
    {
	printf("%d. %s\n", i+1, options[i]);
    }

    return prompt_int(NULL, 1, nopt) - 1;
}
