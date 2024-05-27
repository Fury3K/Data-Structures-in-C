#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stackSLLheader.h"


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
            printf("Enter your Name:    ");
            scanf(" %[^\n]s", name);
            printf("Enter your Number:  ");
            scanf(" %[^\n]s", number);
            newNode = createNode();
            assignNode(newNode, name, number);
            pushStack(&head, newNode);
        }

        else if(choice == 2)
        {
            printList(head);
        }

        else if(choice == 3)
        {
            printf("Which position would you like to delete?:   ");
            scanf("%d", &position);
            popStack(&head, position);
        }

        else if(choice == 4)
        {
            printf("Thank you for using! Goodbye!");
            break;
        }

    }
    return 0;
}
