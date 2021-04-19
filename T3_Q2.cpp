/* Trabalho 3 - Questão 2 - 4,0 pontos
Ana Paula Trindade Corrêa - RA 1430481923064
Daniel Rosário Bachiega - RA 1430481923054
Wilamos César Leite Leal - RA 1430481923026 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main() {

    setlocale (LC_ALL, "");

	char a[101];
	//char aux1[13] = {"ADOPQRadopqr"} ;
	char aux1[13] = {'A','D','O','P','Q','R','a','d','o','p','q','r'};
	char aux2[3] = {'B','b'};
	int total1 = 0;
	int total2 = 0;
	int buraco;
	int i;
	int k;

	printf ("Digite a primeira frase: ");
	gets(a);

	for(i=0; i<=101; i++){
		if(a[i] != 0){
			for(k=0; k<=12; k++){
				if(a[i] == aux1[k]){
					total1++;
				}
			}
		}
	}
	total1 = total1 - 1;

	for(i=0; i<=101; i++){
		if(a[i] != 0){
			for(k=0; k<=12; k++){
				if(a[i] == aux2[k]){
					total2 = total2 + 2;
				}
			}
		}
	}

	printf ("\n%d", total1);
	printf ("\n%d", total2);
	buraco = (total1 + total2);
	printf ("\nTotal de buracos: %d\n\n", buraco);

	system ("pause");
    return 0;
}
