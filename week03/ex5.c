#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX_VALUE 1000


/**
 * Structure of a linked list.
 * The last element (TAIL) must have a value of 'next' = NULL.
 **/
typedef struct dlinked_list {
	int data;
	struct dlinked_list* prev;
	struct dlinked_list* next;
} dlinked_list;


void print_list(dlinked_list* head);
void insert_node(dlinked_list* prevNode, dlinked_list* newNode);
void delete_node(dlinked_list* head, dlinked_list* delNode);
dlinked_list* find_node(dlinked_list* head, int index);


int main(int argc, char** argv) {
	srand(time(0));
	int ind;	// Used for indexing elements (Insertion, deletion)
	dlinked_list* head = (dlinked_list*) malloc(sizeof(dlinked_list));
	head->prev = NULL;
	head->next = NULL;
	
	dlinked_list* prevNode = head;
	for (int i = 0; i < 10; i++) {
		dlinked_list* node = (dlinked_list*) malloc(sizeof(dlinked_list));
		node->data = rand() % MAX_VALUE;
		
		insert_node(prevNode, node);
		prevNode = node;
	}
	printf("Initial data:\n");
	print_list(head);

	// Insertion
	if (argc > 1)
		sscanf(argv[1], "%d", &ind);
	else
		ind = 2;
	dlinked_list* node = (dlinked_list*) malloc(sizeof(dlinked_list));
	node->data = 10;
	prevNode = find_node(head, ind);
	insert_node(prevNode, node);
	printf("\nInsert 10 after element #%d:\n", ind);
	print_list(head);
	
	// Deletion
	if (argc > 2)
		sscanf(argv[2], "%d", &ind);
	else
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
dlinked_list* find_node(dlinked_list* head, int index) {
	dlinked_list* cur = head;
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
void print_list(dlinked_list* head) {
	dlinked_list* cur = head->next;
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
void insert_node(dlinked_list* prevNode, dlinked_list* newNode) {
	if (prevNode == NULL)
		return;

	dlinked_list* temp = prevNode->next;
	prevNode->next = newNode;
	if (newNode != NULL) {
		newNode->prev = prevNode;
		newNode->next = temp;
	}
	if (temp != NULL)
		temp->prev = newNode;
}

/**
 * Delete a node from the linked list.
 *
 * @param head - a head of linked list.
 * @param delNode - a node that will be deleted.
 **/
void delete_node(dlinked_list* head, dlinked_list* delNode) {
	dlinked_list* cur = head;
	while (cur->next != NULL) {
		if (cur->next == delNode) {
			dlinked_list* temp = cur->next->next;
			free(cur->next);
			cur->next = temp;
			if (temp != NULL)
				temp->prev = cur;
			return;
		}
		cur = cur->next;
	}
}
