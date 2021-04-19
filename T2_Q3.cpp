/*Sistema para armazenar as notas de uma classe um numero de alunos fornecido pelo usuario.
Então usuario ira informar uma identificação numerica do aluno seguido de suas notas:
prova com peso 0.4 
trabalho com peso 0.2
projeto com peso 0.3
participação com peso 0.1 do aluno em questão;
Notas tem o formato de 0 a 100.
Então sistema calcula a media e exibe uma tabela de todos os alunos e suas notas.
Seguido de uma mensagem indicando "Aprovado" se media>6, "Exame" se 6>media>2 e "Reprovado" se media<2.
*/
#include<stdio.h>
#include <conio.h>
int main(){
	int i,l,x;
	printf("Digite a quantidade de alunos: ");
	scanf("%d",&x);
	float matriz[x][6];
	for(i=0; i<x; i++){
        printf("\nDigite o identificação numerica do aluno do aluno: ");
        scanf("%f", &matriz[i][0]); 
    	
		do{
		printf("\nDigite a nota de 0 a 100 da prova (Peso 40%%) do aluno %.0f: ",matriz[i][0] );
        scanf("%f", &matriz[i][1]);
        if(matriz[i][1]>100 || matriz[i][1]<0 ){
        	printf("DIGITE UM VALOR VALIDO");
		}
		}while(matriz[i][1]>100 || matriz[i][1]<0 );
        
    	do{
        printf("\nDigite a nota de 0 a 100 do trabalho (Peso 20%%) do aluno %.0f: ",matriz[i][0] );
        scanf("%f", &matriz[i][2]);
         if(matriz[i][2]>100 || matriz[i][2]<0 ){
        	printf("DIGITE UM VALOR VALIDO");
		}
		}while(matriz[i][2]>100 || matriz[i][2]<0 );
		
		do{
        printf("\nDigite a nota de 0 a 100 do projeto (Peso 30%%) do aluno %.0f: ",matriz[i][0] );
        scanf("%f", &matriz[i][3]);
         if(matriz[i][3]>100 || matriz[i][3]<0 ){
        	printf("DIGITE UM VALOR VALIDO");
		}
		}while(matriz[i][3]>100 || matriz[i][3]<0 );
		
		do{
        printf("\nDigite a nota de 0 a 100 de participacao (Peso 10%%) do aluno %.0f: ",matriz[i][0] );
        scanf("%f", &matriz[i][4]);
         if(matriz[i][4]>100 || matriz[i][4]<0 ){
        	printf("DIGITE UM VALOR VALIDO");
			}
		}while(matriz[i][4]>100 || matriz[i][4]<0 );
		
        matriz[i][5]=(matriz[i][1]*0.4)+(matriz[i][2]*0.2)+(matriz[i][3]*0.3)+(matriz[i][1]*0.1);
        printf("\nPROXIMO ALUNO");
    }
    printf("\nALUNO  |   PROVA   |  TRABALHO  |  PROJETO  |  PARTICIPACAO  |   MEDIA   |  SITUACAO\n ");
    for(i=0; i<x; i++){
		for(l=0; l<6; l++){
			printf("%.0f     |     ",matriz[i][l]);
		}
		if(matriz[i][5]<60){
			if(matriz[i][5]<20){
				printf("REPROVADO\n");
			}
			else{
				printf("EXAME\n");	
			}	
		}
		else{
			printf("APROVADO\n");
		}
	}
	return 0;
}
