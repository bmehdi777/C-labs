#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "dbg.h"

int print_a_message(const char *message) {
	printf("A STRING : %s\n", message);
	return 0;
}

int uppercase(const char *msg) {
	for (int i = 0; i < strlen(msg);i++) {
		printf("%c", toupper(msg[i]));
	}
	printf("\n");
	return 0;
}

int lowercase(const char *msg) {
	for (int i = 0; msg[i] != '\0'; i++) {
		printf("%c", tolower(msg[i]));
	}
	printf("\n");
	return 0;
}

int fail_on_purpose(const char *msg) {
	return 1;
}
