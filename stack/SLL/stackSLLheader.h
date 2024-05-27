#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node;
void printMenu();
struct Node* createNode();
void assignNode(struct Node* newNode, char name[], char number[]);
void pushStack(struct Node** head, struct Node* newNode);
void printList(struct Node* head);
void popStack(struct Node **head, int position);
