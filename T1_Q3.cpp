/*Sistema para armazenar as nota de um aluno.
Usuario ira informar suas notas:
prova com peso 0.4 
trabalho com peso 0.2
projeto com peso 0.3
participação com peso 0.1 do aluno em questão;
Notas tem o formato de 0 a 100.
Então sistema calcula a media e exibe notas do aluno.
Seguido de uma mensagem indicando "Aprovado" se media>6, "Exame" se 6>media>2 e "Reprovado" se media<2.
*/
#include<stdio.h>
#include <conio.h>
int main(){
	int i;
	float nota[5];
	
	
        
		do{
		printf("\nDigite a nota de 0 a 100 da prova (Peso 40%%) do aluno: ");
        scanf("%f", &nota[0]);
        if(nota[0]>100 || nota[0]<0 ){
        	printf("DIGITE UM VALOR VALIDO");
		}
		}while(nota[0]>100 || nota[0]<0 );
        
    	do{
        printf("\nDigite a nota de 0 a 100 do trabalho (Peso 20%%) do aluno: ");
        scanf("%f", &nota[1]);
         if(nota[1]>100 || nota[1]<0 ){
        	printf("DIGITE UM VALOR VALIDO");
		}
		}while(nota[1]>100 || nota[1]<0 );
		
		do{
        printf("\nDigite a nota de 0 a 100 do projeto (Peso 30%%) do aluno : ");
        scanf("%f", &nota[2]);
         if(nota[2]>100 || nota[2]<0 ){
        	printf("DIGITE UM VALOR VALIDO");
		}
		}while(nota[2]>100 || nota[2]<0 );
		
		do{
        printf("\nDigite a nota de 0 a 100 de participacao (Peso 10%%) do aluno : ");
        scanf("%f", &nota[3]);
         if(nota[3]>100 || nota[3]<0 ){
        	printf("DIGITE UM VALOR VALIDO");
			}
		}while(nota[3]>100 || nota[3]<0 );
		
		nota[4]=(nota[0]*0.4)+(nota[1]*0.2)+(nota[2]*0.3)+(nota[3]*0.1);
    
    
    printf("\nPROVA    |  TRABALHO   |   PROJETO   |PARTICIPACAO |    MEDIA    |  SITUACAO\n ");
    for(i=0; i<5; i++){
		
			printf("%.0f     |     ",nota[i]);
		
		}
		if(nota[4]<60){
			if(nota[4]<20){
				printf("REPROVADO\n");
			}
			else{
				printf("EXAME\n");	
			}	
		}
		else{
			printf("APROVADO\n");
	}
	return 0;
}
