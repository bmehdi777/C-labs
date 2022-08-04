#include <stdio.h>

int main() {
	//int test = 1;
	//int *pointerTest = test;

	char *test[] = { "aa", "bb" };
	char **pointerTest = test;

	printf("Test value : %s\n", test[0]);
	printf("PointerTest value : %p\n", (void*)pointerTest);
	printf("Test value through PointerTest: %s\n", *pointerTest);

	printf("---\n");

	int test2 = 128;
	int *pointerTest2 = &test2;

	printf("Test2 value : %i\n", test2);
	printf("PointerTest2 value : %p\n", (void*)pointerTest2);
	printf("Test2 value through PointerTest2: %i\n", *pointerTest2);

	printf("---\n");

	int test3 = 130;
	int *pointerTest3 = &test3;
	// int *pointerTest4 = &pointerTest3; <-- It's impossible because we actually have a pointer to a pointer anbd not a simple int pointer
	int **pointerTest4 = &pointerTest3;

	printf("Test3 value : %i\n", test3);
	printf("PointerTest3 value : %p\n", (void*)pointerTest3);
	printf("Test3 value trhough PointerTest3 : %i\n", *pointerTest3);
	printf("PointerTest4 value : %p\n", (void*)pointerTest4);
	printf("PointerTest3 value through PointerTest4 : %p\n", (void*)*pointerTest4);
	printf("Test3 value through PointerTest4 through PointerTest3 : %i\n", **pointerTest4);

	printf("---\n");

	int test4 = 1;
	int *pointerTest5 = &test4;
	printf("Test4 value : %d\n", test4);
	printf("PointerTest5 value : %p\n", (void*)pointerTest5);
	printf("Test4 value through PointerTest5 : %i\n", *pointerTest5);
	printf("What if we just try to have access to pointerTest5+1 address ... : %p\n", (void*)pointerTest5+4);
	printf("And what is inside of it ? %d\n", *pointerTest5+4);

	printf("---\n");

	int *pointerTest6 = (int*) 0x1234;
	printf("Content at address 0x1234 : %i\n", *pointerTest6);
	// We get a segmentation fault because we try to access to memory that we aren't allowed to
	return 0;
}