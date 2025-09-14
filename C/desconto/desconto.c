#include <stdio.h>
#include <stdlib.h>

int main(){
    float valorVenda, desconto, newValue;
    
    printf("Qual foi o valor de venda: $");
    scanf("%f", &valorVenda);

    printf("Qual a porcentagem do desconto: ");
    scanf("%f", &desconto);

    desconto = desconto / 100;

    newValue = valorVenda - (valorVenda * desconto);

    printf("O valor com o desconto é de: $%.2f", newValue);

    return 0;
}