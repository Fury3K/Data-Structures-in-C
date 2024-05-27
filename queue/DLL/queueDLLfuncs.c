#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queueDLLheader.h"

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
    newNode -> link = NULL;

}

void printMenu(){
    printf("[1] Append");
    printf("\n[2] Browse"); 
    printf("\n[3] Exit");
    printf("\nChoice: ");
};

void insertMenu(){
    printf("Where do you want to insert the data?");
    printf("\n[1] front ");
    printf("\n[2] between ");
    printf("\n[3] end ");
    printf("\n[4] back ");
    printf("\nChoice: ");
};

void chooseChange(){
    printf("\n[1] name");
    printf("\n[2] number");
    printf("\nChoice: ");
};

void printList(struct Node* head)
{ 
    struct Node* p;
    int count = 1;
    for (p = head; p; p = p->link) {
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
};

void deQueue(struct Node **head, struct Node* newNode)
{
    struct Node *ptr;
    ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr = *head;
    *head = ptr -> link;
    free(ptr);
    ptr = *head;
}

void enQueue(struct Node** head, struct Node* newNode )
{
    struct Node *ptr;
    ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr = *head;
    if(*head == NULL)
    {
        newNode->link = *head;
        newNode -> prev = NULL;
        if((*head) != NULL)
        {
            (*head) -> prev = newNode;
        }
        *head = newNode;
    }
    else
    {
        newNode -> link = NULL;
        while(ptr -> link != NULL)
            ptr = ptr->link;
        ptr -> link = newNode;
        newNode ->prev = ptr;
    }
}

void showDataReverse(struct Node **head)
{
    if(*head == NULL)
       printf("\n\nERROR: No records available.\n\n");
    else
     {
        printf("\n\nPhonebook\n\n");
        struct Node *ptr = malloc(sizeof(struct Node));
        ptr = *head;
        while(ptr->link != NULL)
            ptr = ptr->link;
        while(ptr != NULL)
        {
            printf("%s\t%s\n", ptr->nameData, ptr->numberData);
            ptr = ptr->prev;
        }
        printf("\n");
        }
}
