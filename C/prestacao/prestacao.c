#include <stdio.h>
#include <stdlib.h>

int main(){
    float valorCompra, valorPrest;

    printf("Enter the product value: $");
    scanf("%f", &valorCompra);

    valorPrest = valorCompra / 5;

    printf("Installment is: $%.2f", valorPrest);
    return 0;
}