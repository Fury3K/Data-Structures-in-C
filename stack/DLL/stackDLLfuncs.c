#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stackDLLheader.h"

void printMenu()
{
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
    strcpy(newNode -> nameD, name);
    strcpy(newNode -> numberD, number);
    newNode -> next = NULL;

}

void pushStack(struct Node** head, struct Node* newNode )
{
     newNode -> next = *head;
     newNode -> prev = NULL;
     if((*head) != NULL)
     {
         (*head) -> prev = newNode;
     }
     *head = newNode;
}


void printList(struct Node* head) {
    struct Node* p;
    int count = 1;
    for (p = head; p; p = p->next) {
        printf("%d.) ", count);
        count++;
        printf("%s\t\t|\t %s", p -> nameD, p -> numberD);
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

void showDataReverse(struct Node **head)
{
    if(*head == NULL)
       printf("\n\nERROR: No records available.\n\n");
    else
     {
        printf("\n\nPhonebook\n\n");
        struct Node *ptr = malloc(sizeof(struct Node));
        ptr = *head;
        while(ptr->next != NULL)
            ptr = ptr->next;
        while(ptr != NULL)
        {
            printf("%s\t%s\n", ptr->nameD, ptr->numberD);
            ptr = ptr->prev;
        }
        printf("\n");
        }
}

