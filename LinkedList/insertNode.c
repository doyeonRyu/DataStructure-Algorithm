/*
File: Linked list with dummy head.c

Author: Doyeon Ryu
Date: 2024.01.19
Course: data structure-linked list

Summary of file:
    Create a new variable by using dinamic memory allocation and insert it into the linked list,
    Delete value from the linked list
    Scan and print the linked list
    Free Linked List

*/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef  struct NODE {
    int key;
    struct NODE* next;
} NODE;

NODE* CreateNode();
int InsertKey(struct NODE*, int);
int DeleteKey(struct NODE*, int);
void ScanList(struct NODE*);
void FreeList(struct NODE*);

int main()
{
    printf("Create a dummy head node.\n");
    NODE* head = CreateNode(); // Dummy head node
    head->next = NULL;
    srand(time(NULL));

    int* nums;
    nums = (int*) malloc (10*sizeof(int)); // Create 10 nums by using dynamic memory allocation

    //Defensive coding
    if(nums == NULL) {
        printf("malloc failed.\n");
        return 1;
    }

    //Between 0 and 100, it creates a new integer value at random and stores it in 10 nodes.
    for (int i = 0; i < 10; i++) {
        nums[i] = rand() % 101;
    } 

    //Insert the key
    for (int i = 0; i < 10; i++) {
        InsertKey(head, nums[i]);
    }
    ScanList(head);

    //Delete the key
    for(int i = 0; i < 10; i++) {
        DeleteKey(head, nums[i]);
    }
    ScanList(head);

    printf("\nFinal Result\n");
    ScanList(head);
    FreeList(head); // Free the linked list
    free(nums); // Free 10 nums

    return 0;
}

/*
struct NODE* CreateNode()

Summary of the function:
    The function contains code that creates a new node by dynamically allocating memory.

Parameters: nothing

Return value:
    if new node was created successfully, return struct NODE* new_node
    otherwise return NULL

Description:
    Creates a new node in the form of struct NODE using dynamic memory allocation.
    If new node was created successfully, return struct NODE* new_node.
    Else, return NULL.
*/
NODE* CreateNode()
{
    NODE* new_node;
    printf("Return a new node address.\n");
    new_node = (NODE *) malloc (sizeof(NODE*));

    //Defensive coding
    if (new_node == NULL) {
        printf("Memory is full.\n");
        return NULL;
    }
    else {
        return new_node;
    }
}

/*
int InsertKey(struct NODE* head, int value)

Summary of the function: 
    This function contains code that inserts the key

Parameters: struct NODE
    struct NODE* head: pointer to the NODE structure, head of the linked list
    int value: integer value, new key to insert

Return value:
    If insert was successful, return 0.
    Else (key already exists), returns -1.

Description: 
    It searches the linked list until it finds the position where the key will fit.
    After finding the position, it creates a new node and inserts it into the linked list.
    Finally, the key of the new node becomes a value, the previous node should point to the new node, and the current node should point to the next node.
*/
int InsertKey(NODE* head, int value) 
{
    printf("\nInsert value: %d\n", value);
    NODE* ptr = head->next, *pre_ptr = head, *new_node = NULL;

    while(ptr) {
        if(ptr->key > value) {
            break;
        }
        else if(ptr->key == value) {
            printf("The input key is already exists,\n");
            return -1;
        }

        printf("Key value of the current node: %d\n", ptr->key);

        pre_ptr = ptr;
        ptr = ptr->next;
    }
    printf("Create a new node\n");
    new_node = CreateNode();

    if (new_node == NULL) {
        printf("Fail to create a new node\n");
        return -1;
    }
    else {
        new_node->key = value;
        pre_ptr->next = new_node;
        new_node->next = ptr;
        return 0;
    }
}

/*
int DeleteKey(struct NODE* head, int value)

Summary of the function: 
    This function contains code that deletes the key

Parameters: struct NODE
    struct NODE* head: pointer to the NODE structure, head of the linked list
    int value: integer value, new key to delete

Return value:
    If deletion was successful, return 0.
    Else (key already exists), returns -1.

Description: 
    It searches the linked list until it finds the position where the key is equal to the node value.
    After finding the position, it excludes and releases that node.
    Finally, the previous node should point to the next node of the current node, and delkey becomes the key of the current node.
*/
int DeleteKey(NODE* head, int value) {
    
    int delkey = -1;
    printf("\nDelete value: %d\n", value);
    NODE *ptr = head->next, *pre_ptr = head, *new_node = NULL;

    while (ptr) {
        if (ptr->key > value) {
            printf("The input key does not exist.\n");
            return -1;
        }
        else if (ptr->key == value) {
            break;
        }

        printf("Key value of the current node: %d\n", ptr->key);

        pre_ptr = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("The input key does not exist.\n");
        return -1;
    }

    pre_ptr->next = ptr->next;
    delkey = ptr->key;
    free(ptr);
    
    printf("Free a node for the key value: %d\n", delkey);

    return 0;
}

/*
void ScanList(struct NODE* head)

Summary of the function: 
    This function contains code to scan and print the linked list.

Parameters: struct NODE
    struct NODE* head: pointer to the NODE structure, head of the linked list.

Return value:
    Nothing - only the linked list is printed.

Description: 
    This will scan the whole linked list and print it.
*/
void ScanList(NODE *head)
{
    printf("\n-----Start ScanList-----\n");
    NODE *ptr = head->next;

    int i=0;
    while (ptr !=NULL) {
        printf("The %d-th node's key value: %d\n", i, ptr->key);
        ptr = ptr->next;
        i++;
    }
    printf("-----End ScanList-----\n\n");
}

/*
void ScanList(struct NODE* head)

Summary of the function: 
    This function contains code to scan and print the linked list.

Parameters:
    struct NODE* head: pointer to the NODE structure, head of the linked list.

Return value:
    Nothing - only the linked list is printed.

Description: 
    It creates tmp which is in the pointer of struct NODE.
    It puts each node into tmp and frees tmp while it scans the linked list.

*/
void FreeList(NODE* head)
{
	NODE* ptr = head, * tmp = NULL;
	int i = 0;
	while (ptr != NULL)
	{
		if (i == 0)
		{
			printf("Free the head node.\n");
		}
		else
		{
			printf("Free the %d-th node.\n", i - 1);
		}
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
		i++;
	}
}
