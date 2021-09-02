#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX_VALUE 1000


/**
 * Structure of a linked list.
 * The last element (TAIL) must have a value of 'next' = NULL.
 **/
typedef struct linked_list {
	int data;
	struct linked_list* next;
} linked_list;


void print_list(linked_list* head);
void insert_node(linked_list* prevNode, linked_list* newNode);
void delete_node(linked_list* head, linked_list* delNode);
linked_list* find_node(linked_list* head, int index);


int main() {
	srand(time(0));
	int ind;	// Used for indexing elements (Insertion, deletion)
	linked_list* head = (linked_list*) malloc(sizeof(linked_list));
	head->next = NULL;
	
	linked_list* prevNode = head;
	for (int i = 0; i < 10; i++) {
		linked_list* node = (linked_list*) malloc(sizeof(linked_list));
		node->data = rand() % MAX_VALUE;
		
		insert_node(prevNode, node);
		prevNode = node;
	}
	printf("Initial data:\n");
	print_list(head);

	// Insertion
	ind = 2;
	linked_list* node = (linked_list*) malloc(sizeof(linked_list));
	node->data = 10;
	prevNode = find_node(head, ind);
	insert_node(prevNode, node);
	printf("\nInsert 10 after element #%d:\n", ind);
	print_list(head);
	
	// Deletion
	ind = 4;
	node = find_node(head, ind);
	delete_node(head, node);
	printf("\nDelete element #%d:\n", ind);
	print_list(head);
}

/**
 * Return a node with special index.
 * If index < 0 or index > size of a list, then returns NULL pointer.
 *
 * @param head - a head of linked list.
 * @param index - index of the element that should be returned.
 * @return a node with special index.
 **/
linked_list* find_node(linked_list* head, int index) {
	linked_list* cur = head;
	for (int i = 0; i < index; i++) {
		if (cur == NULL)
			return NULL;
		cur = cur->next;
	}
	return cur;
}

/**
 * Print out the values of a list.
 **/
void print_list(linked_list* head) {
	linked_list* cur = head->next;
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

/**
 * Insert a new node at the position next to special node.
 *
 * @param prevNode - a node after that new node should be inserted.
 * @param newNode - a node that will be inserted.
 **/
void insert_node(linked_list* prevNode, linked_list* newNode) {
	linked_list* temp = prevNode->next;
	prevNode->next = newNode;
	newNode->next = temp;
}

/**
 * Delete a node from the linked list.
 *
 * @param head - a head of linked list.
 * @param delNode - a node that will be deleted.
 **/
void delete_node(linked_list* head, linked_list* delNode) {
	linked_list* cur = head;
	while (cur->next != NULL) {
		if (cur->next == delNode) {
			linked_list* temp = cur->next->next;
			free(cur->next);
			cur->next = temp;
			return;
		}
		cur = cur->next;
	}
}
