#include <stdio.h>
#include <stdlib.h>
#include "ui/menu.h"
#include "ui/file.h"
#include "game/game.h"

int main()
{
    while (true)
    {
	int choice = menu_choice("text/meta/titlescreen.menu", 4);
    
	switch (choice)
	{
	    case 0:
		file_print("text/meta/about.txt");
		break;
	    case 1:
		game_main();
		break;
	    case 2:
		file_print("text/meta/credits.txt");
		break;

	    case 3:
		exit(EXIT_SUCCESS);
	}
    }
    
    __builtin_unreachable();
}
