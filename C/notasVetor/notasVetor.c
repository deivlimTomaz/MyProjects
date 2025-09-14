#include <stdio.h>
#include <stdlib.h>

int main(){
    char inst[30];
    int alunosM;
    float notas[10], soma, media;

    soma = 0;
    alunosM = 0;

    printf("Qual é a sua instituição de ensino:\n");
    scanf("%s", &inst);

    printf("BEM-VINDO AO SISTEMA DE NOTAS DA %s\n", inst);

    for (int i = 0; i <= 9; i++){

        printf("Digite a nota do %d° aluno: ", i + 1);
        scanf("%f", &notas[i]);
        system("clear");

        soma = soma + notas[i];

        if (notas[i] >= 7.0) {
            alunosM++;
        }
    }

    media = soma / 10;

    printf("\n");
    printf("As notas da turma foram:\n");
    printf("\n");

    for (int i = 0; i <= 9; i++){
        printf("%.2f\n", notas[i]);
    }

    printf("\n");
    printf("A média da turma foi de: %.2f", media);
    printf("\n");
    printf("%d alunos tiveram nota igual ou superior à média 7.0.\n", alunosM);

    return 0;

}