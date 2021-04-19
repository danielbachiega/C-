#include <stdio.h>
#include <ctype.h>
#define t 7

int main(){
   
    int i, j, k, contador;
    char c, origem, destino;
    int mat[t][t] = {{0, 2, 11, 6, 15, 11, 1},
                    {2, 0, 7, 12, 4, 2, 15},
                    {11, 7, 0, 11, 8, 3, 13},
                    {6, 12, 11, 0, 10, 2, 1},
                    {15, 4, 8 ,10, 0, 5, 13},
                    {11, 2, 3, 2, 5, 0, 14},
                    {1, 15, 13, 1, 13, 14, 0}};

    printf("*   A   B   C   D   E   F   G\n");
    for(i=0, c='A'; i<t; i++, c++){
        printf("%c   ", c);
        for(j=0; j<t; j++){
            if(mat[i][j] < 10)
                printf("%d   ", mat[i][j]);
            else
                printf("%d  ", mat[i][j]);
        }
        printf("\n");
    }

    printf("\nEscolha a origem: ");
    scanf("%c", &origem);
    origem = toupper(origem);
    printf("Escolha o destino: ");
    fflush(stdin);
    scanf("%c", &destino);
    destino = toupper(destino);

    contador = 0;
    k = 0;
    while(k <= destino-65){
        contador = contador + mat[origem-65][k];
        k++;
    }
    if(origem-65 == destino-65)
        printf("Sem deslocamento");
    else
        printf("Tempo de deslocamento: %d horas.", contador);
    return 0;
}

