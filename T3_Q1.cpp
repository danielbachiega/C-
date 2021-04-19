/* Trabalho 3 - Questão 1 - 3,0 pontos
Ana Paula Trindade Corrêa - RA 1430481923064
Daniel Rosário Bachiega - RA 1430481923054
Wilamos César Leite Leal - RA 1430481923026 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main() {

    setlocale (LC_ALL, "");

	char a[51];
	char b[51];
	char aux[103];

	printf ("Escreva uma palavra qualquer: \n");
	scanf ("%s", &a);
	printf ("\nEscreva outra palavra novamente: \n");
	scanf ("%s", &b);

	int i;
	int j=0;
	int k=0;
	for (i=0; i<=100; i++) {
        if ((i%2) == 0) {
            if ((a[j] != 0)) {
                aux[i]=a[j];
				j++;
            } else {
			aux[i]=b[k];
			k++;
            }
		}
		if ((i%2) != 0) {
			aux[i]=b[k];
			k++;
		}
	};
	printf ("\nA palavra de forma intercalada é: %s\n\n", aux);

	system ("pause");
    return 0;
}
