#include <stdio.h>
#include <stdlib.h>

int main(){

    int a, b, c;
    printf("Enter three values: ");
    scanf("%d %d %d", &a, &b, &c);
    
    if (a < b && a < c){
        printf("The lower number is %d", a);
    } else if (b < a && b < c){
        printf("The lower number is %d", b);
    } else if (c < a && c < b){
        printf("The lower number is %d", c);
    } else if (a == b || a == c || b == c) {
        printf("Pelo menos dois valores são iguais.");
    } else {
        printf("Todos sao valores iguais.");
    }
}