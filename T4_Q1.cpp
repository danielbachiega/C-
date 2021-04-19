/* Trabalho 4 - Questão 1 - 1,0 ponto
Ana Paula Trindade Corrêa - RA 1430481923064
Daniel Rosário Bachiega - RA 1430481923054
Wilamos César Leite Leal - RA 1430481923026 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void retangulo (int a, int c);

int main() {

    setlocale (LC_ALL, "");

	int linha, coluna;

	printf ("Digite a altura do retângulo: ");
	scanf ("%d", &linha);

	printf ("\nDigite o comprimento do retângulo: ");
	scanf ("%d", &coluna);

    printf ("\n");
	retangulo (linha, coluna);
	printf ("\n");

	system ("pause");
    return 0;
}

void retangulo (int a, int c) {
	int d=c;
	while (a>0) {
		a--;
		c=d;
		while (c > 0) {
			printf ("*");
			c--;
		}
		printf ("\n");
	}
}
