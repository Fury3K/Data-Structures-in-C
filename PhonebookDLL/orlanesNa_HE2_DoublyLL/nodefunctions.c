#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodeDLL.h"

struct Node{
    char nameData[50], numberData[20];

    struct Node* next;
    struct Node* prev;

};

void printMenu()
{
    printf("1. Append \n");
    printf("2. Browse \n");
    printf("3. Change \n");
    printf("4. Delete \n");
    printf("5. Exit \n");
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

void insertHead(struct Node** head, struct Node* newNode )
{
     newNode -> next = *head;
     newNode -> prev = NULL;
     if((*head) != NULL)
     {
         (*head) -> prev = newNode;
     }
     *head = newNode;
}

void insertPosition(struct Node** head, struct Node* newNode, int position)
{
    struct Node* ptr;
    struct Node* ptr2;
    int count = 0;
    ptr = *head;
    ptr2 = *head;
    while (ptr2 -> next != NULL)
    {
        count++;
        ptr2 = ptr2 -> next;
    }
    if(position < 1 || position > count + 1)
    {
        printf("\nInvalid Position Number!");
    }
    else
    {
        position--;
        while(position != 1)
        {
            ptr = ptr -> next;
            position--;
        }
    if(ptr -> next == NULL)
    {
        printf("The next node cannot be NULL!");
    }
        newNode -> next = ptr -> next;
        ptr -> next = newNode;
        newNode -> prev = ptr;
    }

}

void insertTail(struct Node** head, struct Node* newNode)
{
    struct Node* ptr;
    ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr = *head;


    while(ptr -> next != NULL)
        ptr = ptr->next;
    
    ptr -> next = newNode;
    newNode ->prev = ptr;
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

void changeSelect()
{
    printf("\n1. Name");
    printf("\n2. Number");
    printf("\n3. Both");
    printf("\nYour choice:    ");
}

void changeName(struct Node **head, int position, char name[])
{
    struct Node *ptr;
    ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr = *head;
    int count = 1;
    while(count != position)
    {
        if(ptr -> next)
            ptr = ptr->next;
        count++;
    }
    strcpy(ptr -> nameData, name);
}

void changeNumber(struct Node **head, int position, char number[])
{
     struct Node *ptr;
    ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr = *head;
    int count = 1;
    while(count != position)
    {
        if(ptr -> next)
            ptr = ptr->next;
        count++;
    }
    strcpy(ptr -> numberData, number);
}

void deleteNode(struct Node **head, int position)
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
    else if(position == 1)
    {
        *head = ptr -> next;
        free(ptr);
        ptr = NULL;
    }
    else
    {
        while(position != 1)
        {
            ptr2 = ptr;
            ptr = ptr -> next;
            position--;
        }
        ptr2 = ptr -> prev;
        ptr2 -> next = ptr -> next;
        if(ptr -> next != NULL)
            ptr -> next -> prev = ptr2;
        free(ptr);
    }  
}

void showDataReverse(struct Node **head){

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
            printf("%s\t%s\n", ptr->nameData, ptr->numberData);
            ptr = ptr->prev;
        }
        printf("\n");
    }
}
