#include <stdio.h>

int main(){
    int x;

    printf("Enter a value for x: ");
    scanf("%d", &x);

    if (x < 0){
        x = x * (-1);
        printf("%d", x);
    } else {
        printf("%d", x);
    }
}