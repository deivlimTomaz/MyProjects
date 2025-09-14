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

    // Define if it a triangle or not

    if ((a < (b + c)) && (b < (a + c)) && (c < (b + a))){
        printf("It is a triangle.\n");

        // Detectar se é isósceles, escaleno ou equilátero
        if ((a == b) && (a == c) && (b == c)){
            printf("Equilatero");
        } else if ((a == b) || (a == c) || (b == c)){
            printf("Isosceles");
        } else if ((a != b) || (a != c) || (b != c)){
            printf("Escaleno");
        }
    } 
    else {
        printf("It is not a triangle.");
    }

    return 0;
}