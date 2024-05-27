#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queueDLLheader.h"

int main(){
    int choice, position, changeChoice, qCount = 0;
    char name[50],number[20], appendChoice;
    struct Node *newNode;
    struct Node *head = NULL;
    while(1)
    {
        
        printMenu();
        printf("\n Your choice: ");
        scanf("%d", &choice);
    
        if(choice == 1)
        {
            printf("Enter your Name:    ");
            scanf(" %[^\n]s", name);
            printf("Enter your Number:  ");
            scanf(" %[^\n]s", number);
            newNode = createNode();
            assignNode(newNode, name, number);
            enQueue(&head, newNode);
            qCount++;
            if(qCount > 3)
            {
                deQueue(&head,newNode);
            }

        }

        else if(choice == 2)
        {
            showDataReverse(&head);
        }

        else if(choice == 3)
        {
            printf("Thank you for using! Goodbye!");
            break;
        }

    }
    return 0;
}