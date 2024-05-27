#include<stdio.h>

int main(){

    char c1;
    char c2;

    printf("Enter first letter: ");
    scanf("%c", &c1);

    printf("Enter second letter: ");
    scanf("%c", &c2);
    

    printf("%c", tolower(c1));
    printf("%c", tolower(c2));

}
