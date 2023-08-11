#include <stdio.h>
#include <stdlib.h>
#include "ui/menu.h"
#include "ui/file.h"
#include "game/game.h"

int main()
{
    while (true)
    {
	int choice = menu_choose("text/meta/titlescreen.menu");
    
	switch (choice)
	{
	    case 0:
		puts("printing about");
		file_print("text/meta/about.txt");
		break;
	    case 1:
		puts("starting game");
		game_main();
		break;
	    case 2:
		puts("exiting");
		exit(EXIT_SUCCESS);
	}
    }
    
    __builtin_unreachable();
}
