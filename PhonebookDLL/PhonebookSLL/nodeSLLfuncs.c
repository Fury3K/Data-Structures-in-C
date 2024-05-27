#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodeSLLheader.h"


struct Node{
    char nameData[50], numberData[20];

    struct Node* next;

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
     *head = newNode;
}

void insertPosition(struct Node** head, struct Node* prevNode, int position)
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
        printf("Invalid Position Number!");
    }
    else
    {
        position--;
        while(position != 1)
        {
            ptr = ptr -> next;
            position--;
        }
        prevNode -> next = ptr -> next;
        ptr -> next = prevNode;
    }

}

void insertTail(struct Node** head, struct Node* newNode)
{
    struct Node* ptr;
    ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr = *head;


    while(ptr -> next != NULL)
        ptr = ptr->next;
    
    newNode ->next = ptr -> next;
    ptr -> next = newNode;

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
        ptr2 -> next = ptr -> next;
        free(ptr);
        ptr = NULL;
    }
}