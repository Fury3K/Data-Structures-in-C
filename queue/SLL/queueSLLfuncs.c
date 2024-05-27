#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queueSLLheader.h"

struct Node{
    char nameData[50], numberData[20];

    struct Node* next;
    struct Node* prev;

};

void printMenu()
{
    printf("\nQUEUE PHONEBOOK\n");
    printf("1. Append \n");
    printf("2. Delete \n");
    printf("3. Browse \n");
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

void enQueue(struct Node** head, struct Node* newNode )
{
    struct Node *ptr;
    ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr = *head;
    if(*head == NULL)
    {
        newNode -> next = *head;
        *head = newNode;
    }
    else
    {
        newNode -> next = NULL;
        while(ptr->next != NULL)
            ptr = ptr -> next;
        ptr -> next = newNode;
    }
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

void deQueue(struct Node **head, struct Node* newNode)
{
    struct Node *ptr;
    ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr = *head;
    if(*head == NULL)
    {
        printf("The list is empty!\n");
    }
    *head = ptr -> next;
    free(ptr);
    ptr = *head;

}