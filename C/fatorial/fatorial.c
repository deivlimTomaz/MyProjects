#include <stdio.h>
#include <stdlib.h>

int main(){
    int num, fatorial;
    fatorial = 1;

    printf("Digite um número para calcular o fatorial:\n");
    printf("-> ");
    scanf("%d", &num);

    if (num >= 0) {
        for (int i = 1; i <= num; i++){
            fatorial = fatorial * i;
        }

        printf("%d! é igual a %d\n", num, fatorial);
    } else {
        printf("Não existe fatorial para número negativo.");
    }
}