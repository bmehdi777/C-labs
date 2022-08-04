#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "dbg.h"

struct FileNode {
	char *name;
	char *path;
	struct FileNode *next;
};

struct FileNode* create_node(char *name, char *path) {
	struct FileNode *node = malloc(sizeof(struct FileNode));
	
	node->name = name;
	node->path = path;
	node->next = NULL;

	return node;
}

/*
 * Add node at the end of linked list
 */
void push_node(struct FileNode *head, struct FileNode *new_node) {
	struct FileNode *temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}

	temp->next = new_node;
}

int remove_node_by_index(struct FileNode *head, int index) {
	struct FileNode *current = head;
	struct FileNode *temp = NULL;

	for (int i = 0; i < index - 1; i++) {
		if (current->next == NULL) {
			return 0;
		}
		current = current->next;
	}

	if (current->next == NULL) {
		return 0;
	}


	temp = current->next;
	current->next = temp->next; // Here is the jump
	free(temp);
	return 1;

}

/*
 * Clear every linked list node
 * Take the address of the head as param
 */
void clear_node(struct FileNode **head) {
	struct FileNode *previous = *head;
	while (*head) {
		*head = (*head)->next;
		free(previous);
		previous = *head;
	}
}

void print_node(struct FileNode *head) {
	struct FileNode *current = head;

	while(current != NULL) {
		printf("Actual node : %p\n", (void*)current);
		printf("File name : %s\n", current->name);
		printf("File path : %s\n", current->path);
		printf("Next node : %p\n", (void*)current->next);
		printf("--- \n");
		current = current->next;
	} 
}

int main(int argc, char *argv[]) {
	struct FileNode *node1 = create_node("Test 1", "/");
	struct FileNode *node2 = create_node("Test2", "/var");
	struct FileNode *node3 = create_node("Test3", "/var/log");
	struct FileNode *node4 = create_node("Test4", "/tmp");
	struct FileNode *node5 = create_node("Test5", "/tmp/test");

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;

	print_node(node1);

	
	printf("\n--- deleting node 2 --- \n\n");
	remove_node_by_index(node1,2);

	print_node(node1);

	clear_node(&node1);

	return 0;
}
