#include <stdio.h>
#include <stdlib.h>

int main(){
    int a, b, c;

    printf("Enter a value for a: ");
    scanf("%d", &a);

    printf("Enter a value for b: ");
    scanf("%d", &b);

    printf("Enter a value for c: ");
    scanf("%d", &c);

    if ((a < (b + c)) || (b < (a + c)) || (c < (a + b))){
        printf("It is a triangle.");
    } 
    else {
        printf("It is not a triangle.");
    }

    return 0;
}