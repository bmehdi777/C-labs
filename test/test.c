#include <stdio.h>
#include <stdlib.h>

void pointer(int *test) {
	printf("%p\n", test);
	printf("%d\n", *test);

	*test = 10;

	printf("%p\n", test);
	printf("%d\n", *test);
}
void no_pointer(int test) {
	// Can convert address value to long int or convert it into pointers to print them with %p
	printf("%ld\n", (long)&test);
	printf("%p\n", (void*) &test);
	printf("%d\n", test);

	test = 10;

	printf("%p\n", (void*) &test);
	printf("%d\n", test);
}

int main(int argc, char *argv[]) {
	int test = 150;
	int *pTest = &test;
	no_pointer(test);
	printf("---\n");
	pointer(pTest);
	return 0;
}
