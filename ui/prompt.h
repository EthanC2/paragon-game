#pragma once

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*
 * SUMMARY:
 *  Reads a boolean from the user in the for of a yes/no question
 * */
bool prompt_bool(const char *prompt)
{
    char response[16];
    
    do
    {
	printf("%s (y/n)?: ", prompt);
	scanf("%15[^\n]s", response);

	if (strcasecmp(response, "y") == 0 || strcasecmp(response, "yes") == 0)
	{
	    return true;
	}
	else if (strcasecmp(response, "n") == 0 || strcasecmp(response, "no") == 0)
	{
	    return false;
	}

	printf("\"%s\" is not a yes or no!\n", response);
    }
    while (true);
}

/*
 *  SUMMARY:
 *	Reads an integer between the range [min,max] from the user
 * */
int prompt_int(int min, int max)
{
    int integer;

    do 
    { 
       printf("(int %d-%d)> ", min, max); 
    } while (scanf("%d", &integer) < 0 || integer < min || integer > max);

    return integer;
}
