#include <stdio.h>

int main(int argc, char *argv[]) {

	if (argc == 1) {
		printf("You only have one argument. You suck.\n");
	} else if (argc > 1 || argc < 4) {
		printf("Here's youur arguments :\n");

		for (int i=1; i<argc; i++) {
			printf("%s\n", argv[i]);
		}
		printf("\n");
	} 

	return 0;
}
