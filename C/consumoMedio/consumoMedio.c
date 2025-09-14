#include <stdio.h>
#include <stdlib.h>

int main(){
    float consumoMedio, distanciaTotal, totalCombus;

    printf("Qual foi a sua distância percorrida? ");
    scanf("%f", &distanciaTotal);

    printf("Qual foi o total de combustível gasto? ");
    scanf("%f", &totalCombus);

    consumoMedio = distanciaTotal / totalCombus;

    printf("O consumo médio do seu automóvel foi de: %.2f km/l", consumoMedio);
    
    return 0;
}