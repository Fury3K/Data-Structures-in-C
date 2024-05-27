#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stackSLLheader.h"

struct Node{
    char nameData[50], numberData[20];

    struct Node* next;
    struct Node* prev;

};

void printMenu()
{
    printf("STACK PHONEBOOK\n");
    printf("1. Append \n");
    printf("2. Browse \n");
    printf("3. Delete \n");
    printf("4. Exit \n");
}
struct Node* createNode()
{
    struct Node *new;
    new = malloc(sizeof(struct Node));
    return new;
}

void assignNode(struct Node* newNode, char name[], char number[])
{
    strcpy(newNode -> nameData, name);
    strcpy(newNode -> numberData, number);
    newNode -> next = NULL;

}

void pushStack(struct Node** head, struct Node* newNode )
{
    newNode -> next = *head;
    *head = newNode;
}


void printList(struct Node* head) {
    struct Node* p;
    int count = 1;
    for (p = head; p; p = p->next) {
        printf("%d.) ", count);
        count++;
        printf("%s\t\t|\t %s", p -> nameData, p -> numberData);
        printf("\n");
    }
    if(head == NULL)
    {
        printf("\nYour list is currently empty!");
    }
    printf("\n");
}

void popStack(struct Node **head, int position)
{
    struct Node *ptr;
    struct Node *ptr2;
    ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr2 = (struct Node*)malloc(sizeof(struct Node));
    ptr = *head;
    ptr2 = *head;
    if(head == NULL)
    {
        printf("The list is currently empty!");
    }
    while(position != 0)
    {
        *head = ptr -> next;
        free(ptr);
        ptr = *head;
        position--;
    }

}