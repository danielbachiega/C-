/* Trabalho 4 - Questão 5 - 3,0 pontos
Ana Paula Trindade Corrêa - RA 1430481923064
Daniel Rosário Bachiega - RA 1430481923054
Wilamos César Leite Leal - RA 1430481923026 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void F1(int Mat[3][3], int *s1, int *s2, int *s3);
void F2(int vetA[], int vetB[]);

int main(){
    setlocale(LC_ALL,"");
    int N, Mat[3][3], soma1=0, soma2=0, soma3=0;
    int vet1[10] = {5, 12, 4, 7, 10, 3, 2, 6, 23, 16};
    int vet2[5] = {3, 11, 5, 8, 2};
    printf("(1) Funcao que soma linhas da Matriz.\n");
    printf("(2) Funcao verifica divisores.\n");
    printf("Digite 1 para primeira funcao ou 2 para segunda funcao:\n");
    scanf("%d", &N);
    while(N < 1 || N > 2){
        printf("Invalido!!! Digite 1 ou 2:\n");
        scanf("%d", &N);
    }
    printf("\n");

    if(N == 1){
        F1(Mat, &soma1, &soma2, &soma3);
        printf("\nSoma da primeira linha = %d", soma1);
        printf("\nSoma da segunda linha = %d", soma2);
        printf("\nSoma da terceira linha = %d", soma3);
    }
    else{
        F2(vet1, vet2);
    }
    system ("pause");
    return 0;
}

void F1(int Mat[3][3], int *s1, int *s2, int *s3){
    int i, j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            printf("Mat[%d][%d] = ", i, j);
            scanf("%d", &Mat[i][j]);
            if(i==0)
                *s1 = *s1 + Mat[i][j];
            if(i==1)
                *s2 = *s2 + Mat[i][j];
            if(i==2)
                *s3 = *s3 + Mat[i][j];
        }
    }
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            printf("%d ", Mat[i][j]);
        }
        printf("\n");
    }
}

void F2(int vetA[], int vetB[]){
    int i, j, contador;
    for(i=0; i<10; i++){
        printf("vetA[%d] = ", i);
        scanf("%d", &vetA[i]);
    }
    for(i=0; i<5; i++){
        printf("vetB[%d] = ", i);
        scanf("%d", &vetB[i]);
    }
    printf("\nvetA: ");
    for(i=0; i<10; i++){
        printf("%d|", vetA[i]);
    }
    printf("\nvetB: ");
    for(i=0; i<5; i++){
        printf("%d|", vetB[i]);
    }
    printf("\n");

    i=0;
    while(i < 10){
        contador = 0;
        printf("Numero %d\n", vetA[i]);
        for(j=0; j<5; j++){
            if(vetA[i]%vetB[j] == 0){
                printf("Divisivel por %d na posicao %d\n", vetB[j], j+1);
                contador++;
            }
        }
        if(contador == 0){
            printf("Nao possui divisores no segundo vetor\n");
        }
        i++;
    }
}
