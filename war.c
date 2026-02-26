#include <stdio.h>
#include <string.h>
struct Territorio{
    char nome[50];
    char corExercito[20];
    int numTropas;
};
int main(){
    struct Territorio t1, t2, t3, t4, t5;
    printf("Digite o nome do territorio 1: ");
    scanf("%s", t1.nome);
    printf("Digite a cor do exército 1: ");
    scanf("%s", t1.corExercito);
    printf("Digite o número de tropas do território 1:");
    scanf("%d", &t1.numTropas);
    printf("Digite o nome do territorio 2:");
    scanf("%s", t2.nome);
    printf("Digite a cor do exército 2:");
    scanf("%s", t2.corExercito);
    printf("Digite o número de tropas do território 2:");
    scanf("%d", &t2.numTropas);
    printf("Digite o nome do territorio 3:");
    scanf("%s", t3.nome);
    printf("Digite a cor do exército 3:");
    scanf("%s", t3.corExercito);
    printf("Digite o número de tropas do território 3:");
    scanf("%d", &t3.numTropas);
    printf("Digite o nome do territorio 4:");
    scanf("%s", t4.nome);
    printf("Digite a cor do exército 4:");
    scanf("%s", t4.corExercito);
    printf("Digite o número de tropas do território 4:");
    scanf("%d", &t4.numTropas);
    printf("Digite o nome do territorio 5:");
    scanf("%s", t5.nome);
    printf("Digite a cor do exército 5:");
    scanf("%s", t5.corExercito);
    printf("Digite o número de tropas do território 5:");
    scanf("%d", &t5.numTropas);
    printf("\nTerritório 1: %s\nCor do Exército: %s\nNúmero de Tropas: %d\n", t1.nome, t1.corExercito, t1.numTropas);
    printf("\nTerritório 2: %s\nCor do Exército: %s\nNúmero de Tropas: %d\n", t2.nome, t2.corExercito, t2.numTropas);
    printf("\nTerritório 3: %s\nCor do Exército: %s\nNúmero de Tropas: %d\n", t3.nome, t3.corExercito, t3.numTropas);
    printf("\nTerritório 4: %s\nCor do Exército: %s\nNúmero de Tropas: %d\n", t4.nome, t4.corExercito, t4.numTropas);
    printf("\nTerritório 5: %s\nCor do Exército: %s\nNúmero de Tropas: %d\n", t5.nome, t5.corExercito, t5.numTropas);
    return 0;
}
