/* Trabalho 4 - Questão 2 - 2,0 pontos
Ana Paula Trindade Corrêa - RA 1430481923064
Daniel Rosário Bachiega - RA 1430481923054
Wilamos César Leite Leal - RA 1430481923026 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void F1(void);
int F2(int num);

int main() {

    setlocale (LC_ALL, "");

    int i, opcao;
    printf("(1) Funcao String\n(2) Funcao Vetor de Inteiros\n");
    printf("Digite opcao 1 ou 2:\n");
    scanf("%d", &opcao);
    while(opcao != 1 && opcao != 2){
        printf("Numero Invalido! Digite 0 ou 1:\n");
        scanf("%d", &opcao);
    }
    if(opcao == 1){
        printf("\nFuncao 1\n");
        F1();
    }
    else{
        printf("\nFuncao 2 \n");
        printf("Digite um numero inteiro: ");
        scanf("%d", &i);
        F2(i);
    }
    system ("pause");
    return 0;
}

void F1(void){
    int i;
    char c, frase[101];
    printf("Informe um caractere: ");
    fflush(stdin);
    scanf("%c", &c);
    fflush(stdin);
    printf("Digite uma frase:\n");
    gets(frase);
    i = 0;
    while(frase[i] != '\0'){
        if(c == frase[i])
            frase[i] = '*';
        i++;
    }
    puts(frase);
}

int F2(int num){
    int i, contador=0;
    int P[50];
    for(i=0; i<50; i++){
        printf("P[%d] = ", i);
        scanf("%d", &P[i]);
        if(P[i] == num)
            contador++;
    }
    printf("O numero %d ", num);;
    if(contador >= 2)
        printf("Aparece duas vezes no vetor\n");
    else
        printf("Nao aparece duas vezes no vetor\n");
}
