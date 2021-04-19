/* Trabalho 4 - Questão 3 - 2,0 pontos
Ana Paula Trindade Corrêa - RA 1430481923064
Daniel Rosário Bachiega - RA 1430481923054
Wilamos César Leite Leal - RA 1430481923026

Conceito de Recursividade: Em termos gerais, este conceito pode ser considerado
como um processo de repetição de uma rotina. Portanto, de maneira simples, pode
ser definida como uma rotina (procedimento ou função) que chama a si mesma, de
forma direta ou indireta, onde se deve tomar cuidado com o Loop.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int soma (int valorInicial, int valorFinal);
int Soma(int min, int max);

int main() {

    setlocale(LC_ALL,"");

    printf ("Soma de numeros sequenciais existentes em um intervalo.\n");

    int valorInicial, valorFinal, total;
    printf ("\n 1) Digite o menor valor do intervalo: ");
    scanf ("%d", &valorInicial);

    while (valorFinal <= valorInicial) {
        printf ("\n 2) Digite o maior valor do intervalo: ");
        scanf ("%d", &valorFinal);
    }

    total = soma(valorInicial, valorFinal);
    printf ("\nR.: A soma dos valores entre %d e %d = %d .\n\n", valorInicial, valorFinal, total);

    total = 0;
    if (total < Soma(valorInicial, valorFinal)) {
        total = Soma(valorInicial, valorFinal);
    }
    total = soma(valorInicial, valorFinal);
    printf ("\nA soma dos valores %d e %d = %d\n", valorInicial, valorFinal, total);

    system ("pause");
    return 0;
}

int soma(int valorInicial, int valorFinal) {
    int acumulador=0, contador, i;
    contador = valorFinal - valorInicial + 1;
    for (i=0; i<contador; i++) {
        acumulador = acumulador + valorInicial;
        valorInicial = valorInicial + 1;
    }
    return acumulador;
}

int Soma(int valorInicial, int valorFinal){
    int acumulador=0;
    acumulador = acumulador + valorInicial;
    return acumulador;
}
