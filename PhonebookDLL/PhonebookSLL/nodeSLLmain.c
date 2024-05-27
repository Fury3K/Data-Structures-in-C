#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodeSLLheader.h"


int main(){
    int choice, position, changeChoice;
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
            printf("a. Front \n");
            printf("b. Position \n");
            printf("c. Tail \n");
            scanf(" %c", &appendChoice);
            if(appendChoice == 'a')
            {
                printf("Enter your Name:    ");
                scanf(" %[^\n]s", name);
                printf("Enter your Number:  ");
                scanf(" %[^\n]s", number);
                newNode = createNode();
                assignNode(newNode, name, number);
                insertHead(&head, newNode);
            }

            else if(appendChoice == 'b')
            {
                printf("Enter your Name:    ");
                scanf(" %[^\n]s", name);
                printf("Enter your Number:  ");
                scanf(" %[^\n]s", number);
                printf("Enter the position you want:    ");
                scanf("%d", &position);
                newNode = createNode();
                assignNode(newNode, name, number);
                insertPosition(&head, newNode, position);
            }

            else if(appendChoice == 'c')
            {
                printf("Enter your Name:    ");
                scanf(" %[^\n]s", name);
                printf("Enter your Number:  ");
                scanf(" %[^\n]s", number);
                newNode = createNode();
                assignNode(newNode, name, number);
                insertTail(&head, newNode);

            }
        }

        else if(choice == 2)
        {
            printList(head);
        }

        else if(choice == 3)
        {
            printf("Which position would you like to change?:    ");
            scanf("%d", &position);
            changeSelect();
            scanf("%d", &changeChoice);
            if(changeChoice == 1)
            {
                printf("Enter new name: ");
                scanf(" %[^\n]s", &name);
                changeName(&head, position, name);
            }
            else if(changeChoice == 2)
            {
                printf("Enter new number:   ");
                scanf(" %[^\n]s", &number);
                changeNumber(&head, position, number);
            }
            else if(changeChoice == 3)
            {
                printf("Enter new name: ");
                scanf(" %[^\n]s", &name);
                printf("Enter new number:   ");
                scanf(" %[^\n]s", &number);
                changeName(&head, position, name);
                changeNumber(&head, position, number);
            }
        }

        else if(choice == 4)
        {
            printf("Which position would you like to delete?:   ");
            scanf("%d", &position);
            deleteNode(&head, position);
        }

        else if(choice == 5)
        {
            printf("Thank you for using! Goodbye!");
            break;
        }

    }
    return 0;
}