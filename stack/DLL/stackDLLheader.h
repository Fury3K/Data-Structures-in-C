#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char nameD[50], numberD[20];
    struct Node* next;
    struct Node* prev;
};
void printMenu();
struct Node* createNode();
void assignNode(struct Node* newNode, char name[], char number[]);
void pushStack(struct Node** head, struct Node* newNode);
void printList(struct Node* head);
void popStack(struct Node **head, int position);
void showDataReverse(struct Node **head);
