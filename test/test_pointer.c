#include <stdio.h>
#include <string.h>

struct Person {
	char name[64];
	int age;
};

int main(int argc, char **argv) {
	struct Person people[100];
	strcpy(people[0].name, "test");
	people[0].age = 12;

	return 0;
}
