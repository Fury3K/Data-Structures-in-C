#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node;
void printMenu();
struct Node* createNode();
void assignNode(struct Node* newNode, char name[], char number[]);
void insertHead(struct Node** head, struct Node* newNode );
void insertPosition(struct Node** head, struct Node* prevNode, int position);
void insertTail(struct Node** head, struct Node* newNode);
void printList(struct Node* head);
void changeSelect();
void changeName(struct Node **head, int position, char name[]);
void changeNumber(struct Node **head, int position, char number[]);
void deleteNode(struct Node **head, int position);
