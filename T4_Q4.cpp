/* Trabalho 4 - Questão 4 - 2,0 pontos
Ana Paula Trindade Corrêa - RA 1430481923064
Daniel Rosário Bachiega - RA 1430481923054
Wilamos César Leite Leal - RA 1430481923026 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define t 10

void Criar_vetor(int vet[t]);
void Valor_repetido(int vet1[t], int vet2[t]);

int main(){
    setlocale(LC_ALL,"");
    int i, vetA[t], vetB[t];

    Criar_vetor(vetA);
    printf("\n");
    Criar_vetor(vetB);
    printf("\n");
    Valor_repetido(vetA, vetB);
    system ("pause");
    return 0;
}

void Criar_vetor(int vet[t]){
    int i;
    for(i=0; i<t; i++){
        printf("vet[%d]: ", i);
        scanf("%d", &vet[i]);
    }
    for(i=0; i<t ;i++)
        printf("%d|", vet[i]);
    printf("\n");
    return;
}

void Valor_repetido(int vet1[t], int vet2[t]){
    int i, j, x, aux, cont, vet[2*t];

    for(i=0, j=0; i<2*t; i++){
        if(i < t){
            vet[i] = vet1[i];
        }
        else{
            vet[i] = vet2[j];
            j++;
        }
    }
    for (i=0; i<2*t; i++){
        for (j=0; j<2*t; j++){
            if (vet[i] < vet[j]){
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }

        for(i=0; i<2*t; i++){
        cont = 0;
        x = vet[i];
        for(j=0; j<2*t; j++){
            if(vet[i] == vet[j]){
                cont++;
            }
        }
        if(x != vet[i+1] && cont > 1){
            j=0;
            while(j<cont){
                printf("%d, ", vet[i]);
                j++;
            }
            printf("\n");
        }
    }
    return;
}
