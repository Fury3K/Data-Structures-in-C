#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
    char nameData[50], numberData[20];
    struct Node* link;
    struct Node* prev;
};
struct Node* createNode();
void assignNode(struct Node* newNode, char name[], char number[]);
void printList(struct Node* newNode);
void enQueue(struct Node** head, struct Node* newNode );
void deQueue(struct Node **head, struct Node* newNode);
void printMenu();
void insertMenu();
void chooseChange();
void showDataReverse(struct Node **head);