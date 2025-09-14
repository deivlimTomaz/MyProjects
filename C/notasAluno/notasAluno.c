#include <stdio.h>
#include <stdlib.h>

int main(){
    float nota, soma, media;
    int i;
    char nome[30] = "";
    soma = 0.0;

    printf("Qual é o seu nome? ");
    scanf("%s", &nome);

    for (i = 1; i <=3; i++){
        printf("Digite a sua %dª nota: ", i);
        scanf("%f", &nota);

        soma+=nota;
    }

    media = soma / i;

    printf("Seu nome é %s e sua média final foi de %.2f\n", nome, media);

    if (media > 5.00){
        printf("Parabéns, foi aprovado!");
    } else {
        printf("Infelizmente você foi reprovado.");
    }

    return 0;
}