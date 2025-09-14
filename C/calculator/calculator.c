#include <stdio.h>
#include <stdlib.h>

int main(){
    float x, y;
    char choice;

    printf("Enter a value for x: ");
    scanf("%f", &x);

    printf("Enter a value for y: ");
    scanf("%f", &y);

    printf("Choose an operation ('+', '-', '*', '/'): ");
    scanf(" %c", &choice);

    if (choice == '+'){
        float sum = x + y;
        printf("%.2f", sum);
    } else if(choice == '-'){
        float sub = x - y;
        printf("%.2f", sub);
    } else if (choice == '*'){
        float mult = x * y;
        printf("%.2f", mult);
    } else if (choice == '/'){
        if (y != 0){
            float div = x / y;
            printf("%.2f", div);
        } else{
            printf("Cannot divise by 0");
        }
    } else {
        printf("Enter a valid operation!");
    }
}