#include <stdio.h>

int main(int argc, char *argv[]) {
	// Create two arrays we care about
	int ages[] = {23, 43, 12, 89, 2};
	char *names[] = {
		"Alan", "Frank",
		"Mary", "John", "Lisa"
	};

	// Safely get the size of ages
	int count = sizeof(ages) / sizeof(int);

	// first way using indexing
	for (int i=0; i < count; i++) {
		printf("%s has %d years alive.\n", names[i], ages[i]);
	}

	printf("...\n");

	// set up the pointers to the start of the arrays
	int *cur_age = ages;
	char **cur_name = names;

	for (int i = 0; i < count; i++) {
		printf("%s is %d years old.\n", cur_name[i], cur_age[i]);
	}
	printf("\n\nIt's a test : \nPointer points to address : %p\nValue at that address: %i\n\n", (void *)cur_age, *cur_age);
	printf("\n%i - ", *(cur_age+1));
	printf("%p", (void*)(cur_age+1));

	printf("...\n");

	// third way, pointers are just arrays
	for (int i=0; i < count; i++) {
		printf("%s is %d years old again.\n", cur_name[i], cur_age[i]);
	}

	printf("...\n");

	// fourth way with pointers in a stupid complex way
	for (cur_name = names, cur_age = ages; (cur_age - ages) < count; cur_name++, cur_age++) {
		printf("%s lived %d years so far.\n", *cur_name, *cur_age);
	}
	return 0;
}
