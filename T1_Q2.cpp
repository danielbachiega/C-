#include <stdio.h>
#include <locale.h>
int main(){
    setlocale(LC_ALL,"");
    int Numeros[10],SaoAmigos[5],i,contador1,contador2,aux, divisores[10];
    
   aux=0;
   
     printf("Criação do vetor Numeros:\n");
    
	for(i=0; i<10; i++){
        printf("Digite o %dº número: ", i+1);
        scanf("%d", &Numeros[i]);
    }
    i=0;
    for(i=0;i<10;i=i+2){
		contador1=contador2=1;
		divisores[i+1] = divisores[i]=0;
    	 while(contador1 < Numeros[i]){
        	    if(Numeros[i] % contador1 == 0){
            	    divisores[i] = contador1+divisores[i];
            	}
            	contador1++;
        	}while(contador1 < Numeros[i]);
      
    	
    	while(contador2 < Numeros[i+1]){
        	    if(Numeros[i+1] % contador2 == 0){
            	    divisores[i+1] = contador2+divisores[i+1];
            	}
            	contador2++;
        	}
        
 		
	}
	
	for(aux=0,i=0;aux<5;aux++,i=i+2){
		
			if(divisores[i] == Numeros[i+1] && divisores[i+1]==Numeros[i]){
				SaoAmigos[aux]=1;
			}
			else{
				SaoAmigos[aux]=0;
			}	
        
			
		}

	printf("\n");	
	for(i=0; i<10; i++){
        printf("%d|",Numeros[i]);
   }
   printf("\n");
	for(i=0;i<5;i++){
	printf("%d|",SaoAmigos[i]);	
	
	}
	
    return 0;
}
