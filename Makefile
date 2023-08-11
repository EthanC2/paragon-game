paragon: paragon.o
	gcc -o paragon paragon.o -Wall -Wextra

paragon.o: paragon.c
	gcc -c paragon.c -Wall -Wextra

check:
	gcc paragon.c -fsyntax-only -Wall -Wextra

clean:
	rm paragon paragon.o
