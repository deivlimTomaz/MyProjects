// FAZER UMA APRIMORAÇÃO BASEADO EM MULTAS GRAVÍSSIMAS E GRAVES DE ACORDO COM A VELOCIDADE
// ESTABELECER UM CÓDIGO PARA PEGAR X MULTA E CALCULAR VALOR DA MULTA

#include <stdio.h>
#include <stdlib.h>

int main(){
    int velCarro;

    printf("Velocidade: ");
    scanf("%d", &velCarro);

    if (velCarro < 80){
        printf("Você está dentro do limite permitido. Portanto, não foi multado.");
    } 
    else {
        printf("Você está fora do limite permitido. Portanto, foi multado ");
    }
}