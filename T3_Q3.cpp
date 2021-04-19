/*Programa que lê uma quantidade, informada pelo usuario, de strings de até 20 caracteres e apo´s leitura ordena as strings em ordem alfabética.*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main() {

    setlocale (LC_ALL, "");
 	int i,j, qnt;
 	
 	printf("\nDigite a quantidade de nomes:  ");
 	scanf("%d", & qnt);
 	if(qnt<1){
 		printf("\nDigite um valor valido:  ");
 		scanf("%d", & qnt);
	 }
 	qnt=qnt+2;
 	
 	char nomes[qnt][20],aux[20];
 	
 	
 	for(i=0;i<qnt-2;i++){
 		printf("\nDigite o %dº nome:  ",i+1);
 		scanf("%s", & nomes[i]);
	 }
	 j=0;
	 while(j<qnt*qnt){
	 
	 	for(i=0;i<qnt;i++){
				if(strcmp(nomes[i], nomes[i+1])>0){
				 	strcpy(aux,nomes[i]);
				 	strcpy(nomes[i],nomes[i+1]);
				 	strcpy(nomes[i+1],aux);
				 }
			}
			
			i=0;
			j=j+1;
	}
	
	printf("\nNomes em ordem Alfabetica:");
 	for (i = 2; i < qnt; i++){
	 
   		printf("\n%dº:%s", i-1,nomes[i]);
	}

    return 0;
}
