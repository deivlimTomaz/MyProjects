#include <stdio.h>
#include <stdlib.h>

int main(){
    float celsius, fahrenheit;
    int choice;

    printf("Você deseja converter: \n");
    printf("1. Celsius -> Fahrenheit\n");
    printf("2. Fahrenheit -> Celsius\n");

    scanf("%d", &choice);

    switch(choice){
        case 1:
            printf("Digite o valor de ° em Celsius: ");
            scanf("%f", &celsius);
            fahrenheit = (celsius * 9.0 /5.0) + 32;
            printf("A conversão de %.1f° Celsius é de %.1f° Fahrenheit", celsius, fahrenheit);
            break;

        case 2:
            printf("Digite o valor de ° em Fahrenheit: ");
            scanf("%f", &fahrenheit);
            celsius = (5.0 / 9.0) * (fahrenheit - 32);
            printf("A conversão de %.1f° Fahrenheit é de %.1f° Celsius", fahrenheit, celsius);
            break;

        default:
            break;
    }
}