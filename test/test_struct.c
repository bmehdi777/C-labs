#include <stdio.h>
#include <stdlib.h>

struct Person {
	char *name;
	char *lastname;
	int age;
};

void stack_person() {
	struct Person joe = { .name = "Joe", .lastname = "Test", .age = 40 };

	printf("Stack person's name : %s\n", joe.name);
	printf("Stack person's lastname : %s\n", joe.lastname);
	printf("Stack person's age : %d\n", joe.age);

	// No need to free, joe is stored no the stack (we didn't use malloc) and it'll be freed when the stack will pop the function stack_person()
}

void struct_print(struct Person *test) {
	// We use structure dereference "->" because we have a pointer to 
	// (*pointer).variable is equal to pointer->variable
	printf("Test : %s\n", (*test).name);
	printf("Name : %s\n", test->name);
	printf("Lastname : %s\n", test->lastname);
	printf("Age : %d\n", (*test).age);
}

int main(int argc, char *argv[]) {

	struct Person *test = malloc(sizeof(struct Person));
	test->name = "Lorem";
	test->lastname = "Ipsum";
	test->age = 22;

	struct_print(test);
	printf("---\n");
	printf("Test : %s\n", (*test).name);
	printf("Test2 : %s\n", test->name);
	free(test);


	printf("---\n\n");
	stack_person();
	return 0;
}