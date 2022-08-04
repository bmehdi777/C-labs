#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>


struct Person {
	char *name;
	int age;
	int height;
	int weight;
};

void Person_print(struct Person *who) {
	// We use "->" we have to deal with pointer, we access to name (per example) through a pointer *who
	printf("Name : %s\n", who->name);
	printf("\tAge : %d\n", who->age);
	printf("\tHeight : %d\n", who->height);
	printf("\tWeight : %d\n", who->weight);
}

void Person_print2(struct Person who) {
	// We use "->" we have to deal with pointer, we access to name (per example) through a pointer *who
	printf("Name : %s\n", who.name);
	printf("\tAge : %d\n", who.age);
	printf("\tHeight : %d\n", who.height);
	printf("\tWeight : %d\n", who.weight);
}

int main() {
	// Make two people structures
	struct Person joe = { .name = "Joe Alex", .age = 32, .height = 64, .weight = 140 };
	struct Person frank = { .name = "Frank Blank", .age = 20, .height = 72, .weight = 180 };

	// We declare a pointer to each struct
	struct Person *pJoe = &joe;
	struct Person *pFrank = &frank;

	// print them out and where they are in memory
	// This time they are not on the heap but on the stack
	printf("Joe is at memory location %p :\n", &joe);
	printf("Joe is at memory location %p :\n", pJoe);
	Person_print(&joe);
	Person_print2(joe);

	printf("Frank is at memory location %p :\n", &frank);
	printf("Frank is at memory location %p :\n", pFrank);
	Person_print(&frank);
	Person_print2(frank);

	// make everyone age 20 years and print them again
	// Here no need to use "->" because we have our struct already, we don't deal with struct through pointer
	joe.age += 20;
	joe.height -= 2;
	joe.weight += 40;
	Person_print(&joe);

	frank.age += 20;
	frank.weight += 20;
	Person_print(&frank);

	return 0;
}
