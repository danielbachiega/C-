#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define tamCli 200
#define tamProd 200
#define tamVen 200
#define arquivoClientes "clientes.dat"
#define arquivoProduto "produto.dat"
#define arquivoVenda "venda.dat"
#define arqLista
/*---------------------- Tipos de Cadastro-----------------------------*/

typedef struct //define o tipo data
{
	int dia;
	int mes;
	int ano;

}dt;

typedef struct //define o tipo cliente
{
    int codigo;
	char nome[30];
    char endereco[50];
	char cpf[15];
    int telefone;
}cliente;

typedef struct //define o tipo produto
{
    int codigo;
    int qnt;
    float preco;
	char tipo[10];
	char descricao[30];
}produto;

typedef struct //define o tipo venda
{
    int codigo;
    int cpf_cliente;
    char vendedor[15];
    int cod_produto;
    int quantidade;
	dt data_lanc;
}venda;

/*---------------------- Funçoes do Programa-----------------------------*/
      /*---------------------- Cadastro-----------------------------*/
      
void cadastraCliente(void) //funcão cadastrar cliente
{

	FILE * arq;
	cliente x;
    char aux[15];
    char aux2[15];
    char cpf[15];
    int i=0,j=0;
    int a = 0, num=0;
    do{
		do{
		   printf("\n\n\t     Cadastro de Novo Cliente\n\n");
		   if ((arq = fopen(arquivoClientes, "a+b")) == NULL) {
				fprintf(stderr, "\n\tImpossivel abrir o arquivo %s!\n", arquivoClientes);
		   }
		   fseek(arq, 0, SEEK_SET);
		   a=0;
		   printf("\nCPF: ");
		   fflush(stdin);
		   gets(cpf);
		   while(fread(&x, sizeof(cliente), 1, arq) > 0) {
			if(strncmp(cpf,x.cpf, strlen(cpf)) == 0){
			  a=a+1;
		    }
	       }
		   if(a > 0){
			  printf("\n\n\tJa existe um cliente cadastrado com esse cpf: %s\n\n",cpf);
			  printf("\n\tCPF Invalido !!!\n\n");
		   }
		}while(a > 0);
	        fseek(arq, 0, SEEK_END);
		x.codigo= ftell(arq) / sizeof(cliente) + 1;
		printf("\tCodigo do Cliente: %d\n\n", x.codigo);
		printf("\n\nCPF: %s \n",cpf);
	        strcpy(x.cpf,cpf);

		printf("\nNome: ");
		fflush(stdin);
		gets(x.nome);

		printf("\nEndereco: ");
		fflush(stdin);
		gets(x.endereco);

		printf("\nTelefone: ");
		fflush(stdin);
		gets(aux);
	        x.telefone=atoi(aux);


		fwrite(&x, sizeof(cliente), 1, arq);
	    system("cls");
	    printf("\n\n\tCliente Cadastrado Com Sucesso!\n\n");
	    fclose(arq);

        printf("\n\tDeseja Cadastrar outro Cliente ?\n\n\t1 - Sim\n\n\t2 - Nao\n\n ");
 	    scanf("%d", &num);
		  while(num < 0 || num > 2){
			  	system ("cls");
			  	printf("\n\tOpcao Invalida!!\n\n");
                printf("\n\tDeseja Cadastrar outro Cliente ?\n\n");
                printf("\n\tDigite novamente:\n\n\n\t\t1 - Sim\n\n\t\t2 - Nao\n");
  		        scanf("%d", &num);
				system("cls");
	      }
	}while(num==1);
}


void cadastraProduto(void) //funcão cadastrar Produto
{ 
	FILE * arq;
	produto x;
	int num=0;
	do{

		printf("\n\n\t     Cadastro de novo Produto \n\n");
		if ((arq = fopen(arquivoProduto, "ab")) == NULL) {
			fprintf(stderr, "\n\tImpossivel abrir o arquivo %s!\n", arquivoProduto);
		}
		fseek(arq, 0, SEEK_END);

		x.codigo = ftell(arq) / sizeof(produto) + 1;

	       system("cls");
	       printf("Cadastro de Produtos\n\n");

	       printf("Codigo: %d\n\n", x.codigo);
	       printf("\nDescricao: ");
	       fflush(stdin);
		   gets(x.descricao);
	       printf("\nTipo: ");
	       gets(x.tipo);
	       printf("\nPreco (ex. 12.97): ");
	       scanf("%f",&x.preco);
	 	   printf("\nQuantidade: ");
	       scanf("%d",&x.qnt);

		   fwrite(&x, sizeof(produto), 1, arq);
    	   system("cls");
		   printf("\n\n\tProduto Cadastrado Com Sucesso!\n\n");

		   fclose(arq);

			printf("\n\tDeseja Cadastrar outro Produto ?\n\n\t1- Sim\n\n\t2- Nao\n\n ");
			scanf("%d", &num);
			while(num < 0 || num > 2){
  		  	     system ("cls");
				 printf("\n\tOpcao Invalida!!\n\n\tDigite novamente:\n\n\t\t1-Sim\n\n\t\t2- Nao\n");
		         scanf("%d", &num);
           }
	}while(num==1);
}

int diminuiEstoque(int codigo, int quantidade)

{
	FILE * arq;
	produto c;
	int num=0,num2=0;
	int aux;
	int achei = 0;
	int i=0,j=0;
	arq = fopen(arquivoProduto, "r+b");
    system("pause");
			while(fread(&c, sizeof(produto), 1, arq) > 0) 
			{

				if( codigo == c.codigo){
		 			aux=c.qnt-quantidade;
		 			c.qnt=aux;
		 			printf("%d",aux);
					achei = 1;	 
				}
			}

		    if (!achei){

			  system ("cls");
			 return 1;

			}else{return 0;}


		fseek(arq,0,SEEK_SET);

		
      	
	    system("cls");
	    fclose(arq);
	  

	
    system("cls");
	
}

	



void cadastravenda(void) //Função cadastra venda
{ 
	FILE * arq;
	venda x;
	int num=0;
	do{

		printf("\n\n\t     Cadastro de nova Venda \n\n");
		if ((arq = fopen(arquivoVenda, "ab")) == NULL) {
			fprintf(stderr, "\n\tImpossivel abrir o arquivo %s!\n", arquivoVenda);
		}
		fseek(arq, 0, SEEK_END);

		x.codigo = ftell(arq) / sizeof(venda) + 1;

	       system("cls");
	       printf("Cadastro de Venda\n\n");

	       printf("Codigo: %d\n\n", x.codigo);
	       printf("\nVendedor: ");
	       fflush(stdin);
		   gets(x.vendedor);
		   printf("\nCPF do cliente (ex. 12345678900): ");
	       scanf("%d",&x.cpf_cliente);
	 	   printf("\nCodigo do produto: ");
	       scanf("%d",&x.cod_produto);
	       printf("\nQuantidade: ");
	       scanf("%d",&x.quantidade);
	       int aux;
	       aux=diminuiEstoque(x.cod_produto,x.quantidade);
	       if (aux==1){
	       	system ("cls");
				 printf("\n\tProduto não cadastrado\n");
		   }
	       printf("\nData da venda (ddmmaaaa): ");
		   scanf("%02d %02d %4d", &x.data_lanc.dia, &x.data_lanc.mes, &x.data_lanc.ano);

		   fwrite(&x, sizeof(venda), 1, arq);
    	   system("cls");
		   printf("\n\n\tVenda Cadastrada Com Sucesso!\n\n");

		   fclose(arq);

			printf("\n\tDeseja Cadastrar outra Venda ?\n\n\t1- Sim\n\n\t2- Nao\n\n ");
			scanf("%d", &num);
			while(num < 0 || num > 2){
  		  	     system ("cls");
				 printf("\n\tOpcao Invalida!!\n\n\tDigite novamente:\n\n\t\t1-Sim\n\n\t\t2- Nao\n");
		         scanf("%d", &num);
           }
	}while(num==1);
}


      /*---------------------- Consulta -----------------------------*/
              /*--------------- Cliente ----------------*/
      
void consultaClientes (void) //Função consulta Cliente
{
system("cls");

FILE * arq;
FILE * arq2;
int num=0;

cliente c;

	if ((arq = fopen(arquivoClientes, "rb")) == NULL) {
		fprintf(stderr, "\n\tNao existe nenhum cliente cadastrado!\n\n\n");
		printf("\n\ns");
        system("pause");
		return;
	}

	if((arq2 = fopen(arqLista"TodosClientes.txt", "w")) == NULL) {
		fprintf(stderr, "\n\tErro de abertura do arquivo %s!\n", arqLista"TodosClientes.txt");
        printf("\n\n");
		system("pause");
		return;
	}

	printf("\n\nClientes Cadastrados\n\n");
	printf("==========================================================================\n");
	printf("Cod. Nome\tEndereco\tCpf\t   tel.\n");
	printf("==========================================================================\n\n");
	printf("--------------------------------------------------------------------------\n");
	while (fread(&c, sizeof(cliente), 1, arq) > 0) {

     printf("%04d %-10s %-15s %-10s %-10d \n",c.codigo,c.nome,c.endereco,c.cpf,c.telefone);

	printf("--------------------------------------------------------------------------\n");
	}
	fseek(arq,0,SEEK_SET);

    printf("\n\n\tDeseja gerar um relatorio ?\n\n\tDigite:\n\n\t1- Sim\n\n\t2- Nao\n\n\t");
    scanf("%d", &num);
    while(num<1||num>2){
	  	system ("cls");
	    printf("\n\tOpcao Invalida!!!");
        printf("\n\n\tDeseja gerar um relatorio ?\n\n\tDigite novamente:\n\n\t\t 1- Sim \n\t\t 2- Nao\n ");
        scanf("%d", &num);
    }
    if(num==1){
    	fprintf(arq2,"\n\nClientes Cadastrados\n\n");
	    fprintf(arq2,"==========================================================================\n");
	    fprintf(arq2,"Cod. Nome\tEndereco\tCpf\t   tel.\n");
     	fprintf(arq2,"--------------------------------------------------------------------------\n");
      	while (fread(&c, sizeof(cliente), 1, arq) > 0) {
            fprintf(arq2,"%04d %-10s %-10s %-10s %-12d \n",c.codigo,c.nome,c.endereco,c.cpf,c.telefone);
            fprintf(arq2,"--------------------------------------------------------------------------\n");
        }
	    fprintf(arq2,"==========================================================================\n");
        system ("cls");
		printf("\n\n\tRelatorio gerado com sucesso!\n\n");
   }
   else if(num==2){
		   system ("cls");
		  	return;
   }
    system("pause");
    system("cls");
    fclose(arq);
    fclose(arq2);
}

void consultaClienteNome(void) //Função consulta Cliente por nome
{
system("cls");

FILE * arq;
FILE * arq2;

cliente c;
int num=0,num2=0;
char nome[50];
int achei = 0;

int i=0,j=0;

	do{
		if ((arq = fopen(arquivoClientes, "rb")) == NULL) {
			fprintf(stderr, "\n\tNao existe nenhum cliente cadastrado!\n");
			printf("\n\n");
			system("pause");
            return;
		}
		if((arq2 = fopen(arqLista"PesquisaClienteNome.txt", "w")) == NULL) {
			fprintf(stderr, "\n\tErro de abertura do arquivo %s!\n", arqLista"PesquisaClienteNome.txt");
			printf("\n\n");
            system("pause");
            return;
		}
		printf("\n\n\t     Pesquisa de clientes por nome\n\n");
	    do{
			printf("\tNome do Cliente: ");
			scanf(" %50[^\n]", nome);
		    printf("\n\n");
			rewind(arq);
	        printf("\n\nClientes cadastrados com esse nome:%s\n\n",nome);
	        printf("==========================================================================\n");
	        printf("Cod. Nome\tEndereco\tCpf\t   tel. \n");
	        printf("==========================================================================\n\n");
	        printf("--------------------------------------------------------------------------\n");

			while(fread(&c, sizeof(cliente), 1, arq) > 0)
            {
			  for(i=0;i< (strlen(nome));i++)
              {
			  	nome[i]=toupper(nome[i]);
				for(j=0;j<(strlen(c.nome));j++)
                {
			  		c.nome[j]=toupper(c.nome[j]);
			  	}
			  }
			  if(strncmp(nome,c.nome, strlen(nome)) == 0)
              {
                   printf("%04d %-10s %-15s %-10s %-10d \n",c.codigo,c.nome,c.endereco,c.cpf,c.telefone);
	           printf("--------------------------------------------------------------------------\n");
			achei = 1;
			  }
			}
	        printf("==========================================================================\n\n");
		    if (!achei){
			  printf("\n\n\tNao existe cliente cadastrado com esse nome: %s\n\n",nome);
			  printf("\n\tDigite Novamente !\n\n");
			}

		}while(!achei);

		fseek(arq,0,SEEK_SET);

		printf("\n\n\tDeseja Gerar Um Relatorio ?\n\n\tDigite:\n\n\t1- Sim\n\n\t2- Nao\n\n\t");
		scanf("%d", &num);
		while(num<1||num>2)
		{
           system ("cls");
		   printf("\n\tOpcao Invalida!!!\n\n");
           printf("\tDeseja Gerar Um Relatorio ?\n\n");
           printf("\tDigite novamente:\n\n\t\t 1- Sim \n\t\t 2- Nao\n");
		   scanf("%d", &num);
        }

		if(num==1){
	           fprintf(arq2,"\n\nClientes cadastrados com esse nome\n\n");
	           fprintf(arq2,"==========================================================================\n");
	           fprintf(arq2,"Cod. Nome\tEndereco\tCpf\t   tel. \n");
	           fprintf(arq2,"==========================================================================\n\n");
	           fprintf(arq2,"--------------------------------------------------------------------------\n");

			   while(fread(&c, sizeof(cliente), 1, arq) > 0)
               {
			     for(i=0;i< (strlen(nome));i++)
                 {
			  	  nome[i]=toupper(nome[i]);
				  for(j=0;j<(strlen(c.nome));j++)
                  {
			  		c.nome[j]=toupper(c.nome[j]);
			  	  }
		         }
			  	 if(strncmp(nome,c.nome, strlen(nome)) == 0)
                 {
				     fprintf(arq2,"%04d %-10s %-10s %-10s %-12d \n",c.codigo,c.nome,c.endereco,c.cpf,c.telefone);
                	 fprintf(arq2,"--------------------------------------------------------------------------\n");
				     achei = 1;
				 }
			   }
	           fprintf(arq2,"==========================================================================\n\n");

			   system ("cls");
			   printf("\n\n\tRelatorio gerado com sucesso!!\n\n");
   			   system("pause");
			}

	    system("cls");
	    fclose(arq);
	    fclose(arq2);

		printf("\n\tDeseja Realizar Outra Pesquisa ?\n\n\t1- Sim\n\n\t2- Nao\n\n ");
		scanf("%d", &num2);
		while(num2 < 0 || num2 > 2)
		{
			system ("cls");
		    printf("\n\tOpcao Invalida!!!\n\n");
            printf("\tDeseja Realizar Outra Pesquisa ?\n\n");
            printf("\tDigite novamente:\n\n\t\t 1-Sim \n\t\t 2- Nao).\n");
      		scanf("%d", &num2);
		}
	system("cls");
	}while(num2==1);
}

void consultaClienteCPF(void) //Função consulta Cliente por CPF
{
system("cls");

FILE * arq;
FILE * arq2;

cliente c;
int num=0,num2=0;
char cpf[15];
int achei = 0;
int i=0,j=0;

	do{
		if ((arq = fopen(arquivoClientes, "rb")) == NULL)
        {
			fprintf(stderr, "\n\tErro: Nao existe nenhum cliente cadastrado!\n");
		    printf("\n\n");
        	system("pause");
            return;
		}
		if((arq2 = fopen(arqLista"PesquisaClienteCPF.txt", "w")) == NULL)
        {
			fprintf(stderr, "\n\tErro de abertura do arquivo %s!\n", arqLista"PesquisaClienteCPF.txt");
			printf("\n\n");
            system("pause");
    		return;
		}
		printf("\n\n\t   Consultar Cliente por cpf    \n\n");
	 do{
			printf("\tCPF do Cliente: ");
			fflush(stdin);
			gets(cpf);
		    printf("\n\n");

			rewind(arq);

			printf("\n\n\t\tCliente com esse cpf: %s\n\n",cpf);
	        printf("==========================================================================\n");
	        printf("Cod. Nome\tEndereco\tCpf\t   tel.    \n");
	        printf("==========================================================================\n\n");
	        printf("--------------------------------------------------------------------------\n");

			while(fread(&c, sizeof(cliente), 1, arq) > 0)
            {
			  for(i=0;i< (strlen(cpf));i++)
              {
			  	cpf[i]=toupper(cpf[i]);
				  for(j=0;j<(strlen(c.cpf));j++)
                  {
			  		c.cpf[j]=toupper(c.cpf[j]);
			  	  }
			  }
			  if(strncmp(cpf,c.cpf, strlen(cpf)) == 0)
              {
                printf("%04d %-10s %-15s %-10s %-10d \n",c.codigo,c.nome,c.endereco,c.cpf,c.telefone);
                printf("--------------------------------------------------------------------------\n");
				achei = 1;
 			  }
			}
	        printf("==========================================================================\n");

		    if (!achei){
			  printf("\n\n\tNao existe cliente cadastrado com  esse CPF: %s\n\n",cpf);
			  printf("\n\tDigite Novamente !\n\n");
			}

		}while(!achei);

		fseek(arq,0,SEEK_SET);

	    printf("\n\n\tDeseja Gerar Um Relatorio ?\n\n\tDigite:\n\n\t1- Sim\n\n\t2- Nao\n\n\t ");
		scanf("%d", &num);
		while(num<1||num>2)
        {
           	system ("cls");
			printf("\n\tOpcao Invalida!!!\n\n");
            printf("\tDeseja Gerar Um Relatorio ?\n\n");
            printf("\tDigite novamente:\n\n\t\t 1- Sim\n\n\t\t 2- Nao\n");
		    scanf("%d", &num);
        }
		if(num==1)
        {
			   fprintf(arq2,"\n\n\t\t\t\t\tCliente com esse CPF: %s\n\n",cpf);
	           fprintf(arq2,"================================================================================\n");
	           fprintf(arq2,"Cod. Nome\tEndereco\tCpf\t   tel.    \n");
	           fprintf(arq2,"================================================================================\n\n");
	           fprintf(arq2,"--------------------------------------------------------------------------------\n");
			while(fread(&c, sizeof(cliente), 1, arq) > 0)
            {
			  for(i=0;i< (strlen(cpf));i++)
              {
			  	cpf[i]=toupper(cpf[i]);
			    for(j=0;j<(strlen(c.cpf));j++)
                {
			  		c.cpf[j]=toupper(c.cpf[j]);
			  	}
			  }
			  if(strncmp(cpf,c.cpf, strlen(cpf)) == 0)
              {
 			    fprintf(arq2," %04d %-20s %-20s %-15s %-12d  \n",c.codigo,c.nome,c.endereco,c.cpf,c.telefone);
	            fprintf(arq2,"--------------------------------------------------------------------------------\n");
				achei = 1;
			  }
			}
            fprintf(arq2,"================================================================================\n\n");
		 	system ("cls");
			printf("\n\n\tRelatorio gerado com sucesso!!\n\n");
			system("pause");
		}
	    system("cls");
	    fclose(arq);
	    fclose(arq2);

		printf("\n\tDeseja Realizar Outra Pesquisa ?\n\n\t1- Sim\n\n\t2- Nao\n\n ");
		scanf("%d", &num2);
		while(num2 < 0 || num2 > 2)
        {
			system ("cls");
			printf("\n\tOpcao Invalida!!!\n\n\tDigite novamente:\n\n\t\t 1-Sim \n\t\t 2- Nao).\n");
		    scanf("%d", &num2);
		}
  		system("cls");
	}while(num2==1);
}

              /*--------------- Produto ----------------*/

void consultaProdutos(void) //Função consulta Produtos
{
system("cls");

FILE * arq;
FILE * arq2;
int num=0;

produto c;

	if ((arq = fopen(arquivoProduto, "rb")) == NULL) {
		fprintf(stderr, "\n\tErro: Nao existe nenhum Produto cadastrado!\n\n\n");
		printf("\n\n");
        system("pause");
		return;
	}
	if((arq2 = fopen(arqLista"TodosProdutos.txt", "w")) == NULL) {
		fprintf(stderr, "\n\tErro de abertura do arquivo %s!\n", arqLista"TodosProdutos.txt");
		printf("\n\n");
        system("pause");
		return;
	}
	printf("\n\n\t\t\t\tProdutos cadastrados\n\n");
	printf("=========================================================================\n");
	printf(" Cod.: Descrição:                       Tipo:    Preço:    Quantidade:  \n");
	printf("=========================================================================\n\n");
	printf("-------------------------------------------------------------------------\n");
	while (fread(&c, sizeof(produto), 1, arq) > 0) {
	 printf(" %04d %-30s %-10s %.2f  %d   \n",c.codigo, c.descricao, c.tipo, c.preco, c.qnt);
	 printf("-------------------------------------------------------------------------\n");
	}
	printf("\n=========================================================================\n\n");

	fseek(arq,0,SEEK_SET);

    printf("\n\n\tDeseja Gerar Um Relatorio ?\n\n\tDigite:\n\n\t1- Sim\n\n\t2- Nao\n\n\t");
	scanf("%d", &num);
	while(num<1||num>2)
    {
	  	system ("cls");
	  	printf("\n\tNumero Invalido!!!\n\n\tDigite novamente");
	  	scanf("%d", &num);
	}
	if(num==1){
	
			fprintf(arq2,"\n\n\t\t\t\tProdutos cadastrados\n\n");
			fprintf(arq2,"=========================================================================\n");
			fprintf(arq2,"  Cod.: Descrição:                       Tipo:    Preço:    Quantidade:  \n");
			fprintf(arq2,"=========================================================================\n\n");
			fprintf(arq2,"-------------------------------------------------------------------------\n");
			while(fread(&c, sizeof(produto), 1, arq) > 0) {
			  fprintf(arq2," %04d %-30s %-10s %.2f  %d   \n",c.codigo, c.descricao, c.tipo, c.preco, c.qnt);
	 		  fprintf(arq2,"-------------------------------------------------------------------------\n");
	        }
			 fprintf(arq2,"\n=========================================================================\n\n");
		     system ("cls");
			 printf("\n\n\tRelatorio gerado com sucesso!!\n\n");

		}else{
		   system ("cls");
		  	return;
		}


    system("pause");
	system ("cls");
    fclose(arq);
    fclose(arq2);
}

void consultaProdutosCodigo(void) //Função consulta produto por codigo
{
	FILE * arq;
	FILE * arq2;
	produto c;
	int codigo,num=0,num2=0;

	int achei = 0;
	int i=0,j=0;


	do{

		if ((arq = fopen(arquivoProduto, "rb")) == NULL) {
			fprintf(stderr, "\n\tErro: Nao existe nenhum Produto cadastrado!\n");
      		printf("\n\n");
            system("pause");
			return;
		}

		if((arq2 = fopen(arqLista"PesquisaProdutoCodigo.txt", "w")) == NULL) {
			fprintf(stderr, "\n\tErro de abertura do arquivo %s!\n",arqLista"PesquisaProdutoCodigo.txt");
            printf("\n\n");
			system("pause");
    		return;
		}

	 do{
			printf("\tCodigo do Produto: ");
			fflush(stdin);
			scanf("%d", &codigo);
		    printf("\n\n");

			rewind(arq);

			printf("\n\n\t\t\t\tProduto cadastrado com o codigo: %d\n\n",codigo);
			printf("=========================================================================\n");
			printf(" Cod.: Descrição:                       Tipo:    Preço:    Quantidade:  \n");
			printf("=========================================================================\n\n");
			printf("-------------------------------------------------------------------------\n");
			while(fread(&c, sizeof(produto), 1, arq) > 0) {

				if( codigo == c.codigo){
		 			printf(" %04d %-30s %-10s %.2f  %d   \n",c.codigo, c.descricao, c.tipo, c.preco, c.qnt);
					printf("-------------------------------------------------------------------------\n");

						 achei = 1;
				}
			}
			printf("\n=========================================================================\n\n");

		    if (!achei){

			  system ("cls");
			  printf("\n\n\tNao existe Produto cadastrado com esse codigo: %d\n\n",codigo);
			  printf("\n\tDigite Novamente !\n\n");

			}

		}while(!achei);

		fseek(arq,0,SEEK_SET);

		printf("\n\n\tDeseja Gerar Um Relatorio ?\n\n\tDigite:\n\n\t1- Sim\n\n\t2- Nao\n\n\t ");
		scanf("%d", &num);
		while(num<1||num>2)
        {
			system ("cls");
			printf("\n\tOpcao Invalida!!!\n\n\tDigite novamente:\n\n\t\t 1- Sim \n\t\t 2- Nao\n");
       		scanf("%d", &num);
		}
		if(num==1)
        {
				fprintf(arq2,"\n\n\t\t\t\tProduto cadastrado com o codigo: %d\n\n",codigo);
				fprintf(arq2,"=========================================================================\n");
				fprintf(arq2," Cod.: Descrição:                       Tipo:    Preço:    Quantidade:  \n");
				fprintf(arq2,"=========================================================================\n\n");
				fprintf(arq2,"-------------------------------------------------------------------------\n");
			    while(fread(&c, sizeof(produto), 1, arq) > 0)
                {
					if( codigo == c.codigo){
		 			fprintf(arq2," %04d %-30s %-10s %.2f  %d   \n",c.codigo, c.descricao, c.tipo, c.preco, c.qnt);
					fprintf(arq2,"-------------------------------------------------------------------------\n");
 				    achei = 1;
	       			}
			   }
			fprintf(arq2,"\n=========================================================================\n\n");
			system ("cls");
			printf("\n\n\tRelatorio gerado com sucesso!!\n\n");
			system("pause");
      	}
	    system("cls");
	    fclose(arq);
	    fclose(arq2);

		printf("\n\tDeseja Realizar Outra Pesquisa ?\n\n\t1- Sim\n\n\t2- Nao\n\n ");
		scanf("%d", &num2);
		while(num2 < 0 || num2 > 2)
        {
			system ("cls");
			printf("\n\tOpcao Invalida!!!\n\n\tDeseja Realizar Outra Pesquisa ?\n\n\tDigite novamente:\n\n\t\t 1-Sim \n\t\t 2- Nao).\n");
		    scanf("%d", &num2);
        }
    system("cls");
	}while(num2==1);
}

void consultaProdutosDescricao(void) //Função consulta produto por descrição
{
	FILE * arq;
	FILE * arq2;
	produto c;
	char descricao[30];
	int codigo,num=0,num2=0;
	int achei = 0;
	int i=0,j=0;

	do{

		if ((arq = fopen(arquivoProduto, "rb")) == NULL) {
			fprintf(stderr, "\n\tNao existe nenhum produto cadastrado!\n");
			printf("\n\n");
            system("pause");
			return;
		}

		if((arq2 = fopen(arqLista"PesquisaProdutoDescricao.txt", "w")) == NULL) {
			fprintf(stderr, "\n\tErro de abertura do arquivo %s!\n", arqLista"PesquisaProdutoDescricao.txt");
			printf("\n\n");
            system("pause");
            return;
		}

		printf("\n\n\t    Consulta de Produto \n\n");
	 do{

			printf("\tDescricao do Produto: ");
			fflush(stdin);
			gets(descricao);
		    printf("\n\n");

			rewind(arq);


				printf("\n\n\t\t\t\tConsulta de Produto por Descrição %s\n\n",descricao);
				printf("=========================================================================\n");
				printf("Cod.: Descrição:                       Tipo:    Preço:    Quantidade:  \n");
				printf("=========================================================================\n\n");
				printf("-------------------------------------------------------------------------\n");

					while(fread(&c, sizeof(produto), 1, arq) > 0) {
					  for(i=0;i< (strlen(descricao));i++){
					  	descricao[i]=toupper(descricao[i]);
						  for(j=0;j<(strlen(c.descricao));j++){
					  		c.descricao[j]=toupper(c.descricao[j]);
					  	  }
					  }
						if(strncmp(descricao,c.descricao, strlen(descricao)) == 0){
			 			 printf("  %04d %-30s %-10s %.2f  %d   \n",c.codigo, c.descricao, c.tipo, c.preco, c.qnt);
        				 printf("-------------------------------------------------------------------------\n");
					     achei = 1;
						}
					}
				printf("\n=========================================================================\n\n");
			    if (!achei){
				  system ("cls");
				  printf("\n\n\tNao existe Produto cadastrado com essa descrição: %d\n\n",codigo);
				  printf("\n\tDigite Novamente !\n\n");

				}

			}while(!achei);

			fseek(arq,0,SEEK_SET);

			printf("\n\n\tDeseja Gerar Um Relatorio ?\n\n\tDigite:\n\n\t1- Sim\n\n\t2- Nao\n\n\t ");
			scanf("%d", &num);
			while(num<1||num>2)
            {
					system ("cls");
					printf("\n\tOpcao Invalida!!!\n\n\tDeseja Gerar Um Relatorio ?\n\n\tDigite novamente:\n\n\t\t 1- Sim \n\n\t\t 2- Nao\n");
					scanf("%d", &num);
			}
			if(num==1)
            {
					fprintf(arq2,"\n\n\t\t\t\tConsulta Produto por Descrição %d\n\n",descricao);
					fprintf(arq2,"=========================================================================\n");
					fprintf(arq2,"Cod.: Descrição:                       Tipo:    Preço:    Quantidade:  \n");
					fprintf(arq2,"=========================================================================\n\n");
					fprintf(arq2,"-------------------------------------------------------------------------\n");

					while(fread(&c, sizeof(produto), 1, arq) > 0)
                    {
					  for(i=0;i< (strlen(descricao));i++)
                      {
					  	descricao[i]=toupper(descricao[i]);
						  for(j=0;j<(strlen(c.descricao));j++)
                          {
					  		c.descricao[j]=toupper(c.descricao[j]);
					  	  }
					  }
					  if(strncmp(descricao,c.descricao, strlen(descricao)) == 0)
                      {
			 			 fprintf(arq2,"  %04d %-30s %-10s %.2f  %d   \n",c.codigo, c.descricao, c.tipo, c.preco, c.qnt);
						 fprintf(arq2,"-------------------------------------------------------------------------\n");
                         achei = 1;
					  }
				    }
					fprintf(arq2,"\n=========================================================================\n\n");
					system ("cls");
					printf("\n\n\tRelatorio gerado com sucesso!!\n\n");
					system("pause");
				}
		    system("cls");
		    fclose(arq);
		    fclose(arq2);

			printf("\n\tDeseja Realizar Outra Pesquisa ?\n\n\t\t 1- Sim\n\n\t\t 2- Nao\n\n ");
			scanf("\t%d", &num2);
   		    while(num2 < 0 || num2 > 2)
            {
				system ("cls");
			  	printf("\n\tOpcao Invalida!!!\n\n\tDigite novamente: \n\n\t\t 1- Sim\n\n\t\t 2- Nao\n");
  				scanf("\t%d", &num2);
			}
  		system("cls");
		}while(num2==1);
}

              /*--------------- Venda ----------------*/
              
void consultaVendas(void) //Função consulta Vendas
{
system("cls");

FILE * arq;
FILE * arq2;
int num=0;

venda c;

	if ((arq = fopen(arquivoVenda, "rb")) == NULL) {
		fprintf(stderr, "\n\tErro: Nao existe nenhuma Venda cadastrada!\n\n\n");
		printf("\n\n");
        system("pause");
		return;
	}
	if((arq2 = fopen(arqLista"TodasVendas.txt", "w")) == NULL) {
		fprintf(stderr, "\n\tErro de abertura do arquivo %s!\n", arqLista"TodasVendas.txt");
		printf("\n\n");
        system("pause");
		return;
	}
	printf("\n\n\t\t\t\tVendas cadastradas\n\n");
	printf("=========================================================================\n");
	printf(" Cod.: Vendedor:                 CPF Cliente:    Codigo Produto:    Quantidade:  Data Lanc.:  \n");
	printf("=========================================================================\n\n");
	printf("-------------------------------------------------------------------------\n");
	while (fread(&c, sizeof(venda), 1, arq) > 0) {
	 printf(" %04d %-15s %d %04d  %d  %02d/%02d/%04d \n",c.codigo, c.vendedor, c.cpf_cliente, c.cod_produto, c.quantidade, c.data_lanc.dia,c.data_lanc.mes,c.data_lanc.ano);
	 printf("-------------------------------------------------------------------------\n");
	}
	printf("\n=========================================================================\n\n");

	fseek(arq,0,SEEK_SET);

    printf("\n\n\tDeseja Gerar Um Relatorio ?\n\n\tDigite:\n\n\t1- Sim\n\n\t2- Nao\n\n\t");
	scanf("%d", &num);
	while(num<1||num>2)
    {
	  	system ("cls");
	  	printf("\n\tNumero Invalido!!!\n\n\tDigite novamente");
	  	scanf("%d", &num);
	}
	if(num==1){
	
			fprintf(arq2,"\n\n\t\t\t\tVendas cadastradas\n\n");
			fprintf(arq2,"=========================================================================\n");
			fprintf(arq2,"  Cod.: Vendedor:                 CPF Cliente:    Codigo Produto:    Quantidade:  Data Lanc.:  \n");
			fprintf(arq2,"=========================================================================\n\n");
			fprintf(arq2,"-------------------------------------------------------------------------\n");
			while(fread(&c, sizeof(venda), 1, arq) > 0) {
			  fprintf(arq2," %04d %-15s %d %04d  %d  %02d/%02d/%04d \n",c.codigo, c.vendedor, c.cpf_cliente, c.cod_produto, c.quantidade, c.data_lanc.dia,c.data_lanc.mes,c.data_lanc.ano);
	 		  fprintf(arq2,"-------------------------------------------------------------------------\n");
	        }
			 fprintf(arq2,"\n=========================================================================\n\n");
		     system ("cls");
			 printf("\n\n\tRelatorio gerado com sucesso!!\n\n");

		}else{
		   system ("cls");
		  	return;
		}


    system("pause");
	system ("cls");
    fclose(arq);
    fclose(arq2);
}

void consultaVendasCPFCliente(void) //Função consulta venda por CPF
{
	FILE * arq;
	FILE * arq2;
	venda c;
	int codigo,num=0,num2=0;

	int achei = 0;
	int i=0,j=0;


	do{

		if ((arq = fopen(arquivoVenda, "rb")) == NULL) {
			fprintf(stderr, "\n\tErro: Nao existe nenhuma venda cadastrada!\n");
      		printf("\n\n");
            system("pause");
			return;
		}

		if((arq2 = fopen(arqLista"PesquisaVendCPF.txt", "w")) == NULL) {
			fprintf(stderr, "\n\tErro de abertura do arquivo %s!\n",arqLista"PesquisaVendaCPF.txt");
            printf("\n\n");
			system("pause");
    		return;
		}

	 do{
			printf("\tCPF do Cliente (ex. 12345678900): ");
			fflush(stdin);
			scanf("%d", &codigo);
		    printf("\n\n");

			rewind(arq);

			printf("\n\n\t\t\t\tVendas cadastradas no CPF: %d\n\n",codigo);
			printf("=========================================================================\n");
			printf(" Cod.: Vendedor:                 CPF Cliente:    Codigo Produto:    Quantidade:  Data Lanc.:  \n");
			printf("=========================================================================\n\n");
			printf("-------------------------------------------------------------------------\n");
			while(fread(&c, sizeof(venda), 1, arq) > 0) {

				if( codigo == c.codigo){
		 			printf(" %04d %-15s %d %04d  %d  %02d/%02d/%04d \n",c.codigo, c.vendedor, c.cpf_cliente, c.cod_produto, c.quantidade, c.data_lanc.dia,c.data_lanc.mes,c.data_lanc.ano);
					printf("-------------------------------------------------------------------------\n");

						 achei = 1;
				}
			}
			printf("\n=========================================================================\n\n");

		    if (!achei){

			  system ("cls");
			  printf("\n\n\tNao existe venda cadastrada CPF: %d\n\n",codigo);
			  printf("\n\tDigite Novamente !\n\n");

			}

		}while(!achei);

		fseek(arq,0,SEEK_SET);

		printf("\n\n\tDeseja Gerar Um Relatorio ?\n\n\tDigite:\n\n\t1- Sim\n\n\t2- Nao\n\n\t ");
		scanf("%d", &num);
		while(num<1||num>2)
        {
			system ("cls");
			printf("\n\tOpcao Invalida!!!\n\n\tDigite novamente:\n\n\t\t 1- Sim \n\t\t 2- Nao\n");
       		scanf("%d", &num);
		}
		if(num==1)
        {
				fprintf(arq2,"\n\n\t\t\t\tVenda cadastrada no CPF: %d\n\n",codigo);
				fprintf(arq2,"=========================================================================\n");
				fprintf(arq2," Cod.: Vendedor:                 CPF Cliente:    Codigo Produto:    Quantidade:  Data Lanc.:  \n");
				fprintf(arq2,"=========================================================================\n\n");
				fprintf(arq2,"-------------------------------------------------------------------------\n");
			    while(fread(&c, sizeof(produto), 1, arq) > 0)
                {
					if( codigo == c.codigo){
		 			fprintf(arq2," %04d %-15s %d %04d  %d  %02d/%02d/%04d \n",c.codigo, c.vendedor, c.cpf_cliente, c.cod_produto, c.quantidade, c.data_lanc.dia,c.data_lanc.mes,c.data_lanc.ano);
					fprintf(arq2,"-------------------------------------------------------------------------\n");
 				    achei = 1;
	       			}
			   }
			fprintf(arq2,"\n=========================================================================\n\n");
			system ("cls");
			printf("\n\n\tRelatorio gerado com sucesso!!\n\n");
			system("pause");
      	}
	    system("cls");
	    fclose(arq);
	    fclose(arq2);

		printf("\n\tDeseja Realizar Outra Pesquisa ?\n\n\t1- Sim\n\n\t2- Nao\n\n ");
		scanf("%d", &num2);
		while(num2 < 0 || num2 > 2)
        {
			system ("cls");
			printf("\n\tOpcao Invalida!!!\n\n\tDeseja Realizar Outra Pesquisa ?\n\n\tDigite novamente:\n\n\t\t 1-Sim \n\t\t 2- Nao).\n");
		    scanf("%d", &num2);
        }
    system("cls");
	}while(num2==1);
}

void consultaVendasVendedor(void) //Função consulta vendas por vendedor
{
	FILE * arq;
	FILE * arq2;
	venda c;
	char vendedor[15];
	int codigo,num=0,num2=0;
	int achei = 0;
	int i=0,j=0;

	do{

		if ((arq = fopen(arquivoVenda, "rb")) == NULL) {
			fprintf(stderr, "\n\tNao existe nenhuma venda cadastrada!\n");
			printf("\n\n");
            system("pause");
			return;
		}

		if((arq2 = fopen(arqLista"PesquisaVendaVendedor.txt", "w")) == NULL) {
			fprintf(stderr, "\n\tErro de abertura do arquivo %s!\n", arqLista"PesquisaVendaVendedor.txt");
			printf("\n\n");
            system("pause");
            return;
		}

		printf("\n\n\t    Consulta de Vendas \n\n");
	 do{

			printf("\tNome do vendedor: ");
			fflush(stdin);
			gets(vendedor);
		    printf("\n\n");

			rewind(arq);


				printf("\n\n\t\t\t\tConsulta de Venda por Vendedor %s\n\n",vendedor);
				printf("=========================================================================\n");
				printf("Cod.: Vendedor:                 CPF Cliente:    Codigo Produto:    Quantidade:  Data Lanc.:  \n");
				printf("=========================================================================\n\n");
				printf("-------------------------------------------------------------------------\n");

					while(fread(&c, sizeof(venda), 1, arq) > 0) {
					  for(i=0;i< (strlen(vendedor));i++){
					  	vendedor[i]=toupper(vendedor[i]);
						  for(j=0;j<(strlen(c.vendedor));j++){
					  		c.vendedor[j]=toupper(c.vendedor[j]);
					  	  }
					  }
						if(strncmp(vendedor,c.vendedor, strlen(vendedor)) == 0){
			 			 printf(" %04d %-15s %d %04d  %d  %02d/%02d/%04d \n",c.codigo, c.vendedor, c.cpf_cliente, c.cod_produto, c.quantidade, c.data_lanc.dia,c.data_lanc.mes,c.data_lanc.ano);
        				 printf("-------------------------------------------------------------------------\n");
					     achei = 1;
						}
					}
				printf("\n=========================================================================\n\n");
			    if (!achei){
				  system ("cls");
				  printf("\n\n\tNao existe Venda cadastrado com esse vendedor: %d\n\n",codigo);
				  printf("\n\tDigite Novamente !\n\n");

				}

			}while(!achei);

			fseek(arq,0,SEEK_SET);

			printf("\n\n\tDeseja Gerar Um Relatorio ?\n\n\tDigite:\n\n\t1- Sim\n\n\t2- Nao\n\n\t ");
			scanf("%d", &num);
			while(num<1||num>2)
            {
					system ("cls");
					printf("\n\tOpcao Invalida!!!\n\n\tDeseja Gerar Um Relatorio ?\n\n\tDigite novamente:\n\n\t\t 1- Sim \n\n\t\t 2- Nao\n");
					scanf("%d", &num);
			}
			if(num==1)
            {
					fprintf(arq2,"\n\n\t\t\t\tConsulta de Venda por Vendedor %d\n\n",vendedor);
					fprintf(arq2,"=========================================================================\n");
					fprintf(arq2,"Cod.: Vendedor:                 CPF Cliente:    Codigo Produto:    Quantidade:  Data Lanc.:  \n");
					fprintf(arq2,"=========================================================================\n\n");
					fprintf(arq2,"-------------------------------------------------------------------------\n");

					while(fread(&c, sizeof(venda), 1, arq) > 0)
                    {
					  for(i=0;i< (strlen(vendedor));i++)
                      {
					  	vendedor[i]=toupper(vendedor[i]);
						  for(j=0;j<(strlen(c.vendedor));j++)
                          {
					  		c.vendedor[j]=toupper(c.vendedor[j]);
					  	  }
					  }
					  if(strncmp(vendedor,c.vendedor, strlen(vendedor)) == 0)
                      {
			 			 fprintf(arq2,"  %04d %-15s %d %04d  %d  %02d/%02d/%04d \n",c.codigo, c.vendedor, c.cpf_cliente, c.cod_produto, c.quantidade, c.data_lanc.dia,c.data_lanc.mes,c.data_lanc.ano);
						 fprintf(arq2,"-------------------------------------------------------------------------\n");
                         achei = 1;
					  }
				    }
					fprintf(arq2,"\n=========================================================================\n\n");
					system ("cls");
					printf("\n\n\tRelatorio gerado com sucesso!!\n\n");
					system("pause");
				}
		    system("cls");
		    fclose(arq);
		    fclose(arq2);

			printf("\n\tDeseja Realizar Outra Pesquisa ?\n\n\t\t 1- Sim\n\n\t\t 2- Nao\n\n ");
			scanf("\t%d", &num2);
   		    while(num2 < 0 || num2 > 2)
            {
				system ("cls");
			  	printf("\n\tOpcao Invalida!!!\n\n\tDigite novamente: \n\n\t\t 1- Sim\n\n\t\t 2- Nao\n");
  				scanf("\t%d", &num2);
			}
  		system("cls");
		}while(num2==1);
}





/*-------------------Função Principal------------------*/
int main(){
    int op;
	do {
		printf("\n\n\t---------------SISTEMA DE CONTROLE DE VENDAS DE VESTUARIO----------------\n");
		printf("\n\n\t-------------------------------\n");
		printf("\t   Escolha uma das opcoes      \n");
		printf("\t-------------------------------\n");
		printf("\n\t1- Cadastrar Clientes\n");
		printf("\n\t2- Cadastrar Produtos\n");
		printf("\n\t3- Cadastrar Venda\n");
		printf("\n\t4- Mostrar todos os Clientes Cadastrados\n");
        printf("\n\t5- Consultar Clientes por Nome\n");
		printf("\n\t6- Consultar Clientes por CPF\n");
		printf("\n\t7- Mostrar todos os Produtos\n");
		printf("\n\t8- Consultar Produtos por Codigos\n");
		printf("\n\t9- Consultar Produtos por Descrição\n");
		printf("\n\t10- Mostrar todos as Vendas\n");
		printf("\n\t11- Consultar Vendas por CPF cliente\n");
		printf("\n\t12- Consultar Vendas por Vendedor\n");
		printf("\n\t0- Sair do programa\n\n");
		printf("\tEscola uma Opcao: ");
		scanf("%d", &op);
		switch(op){
		    case 1:
			        system ("cls");
					cadastraCliente();
		         break;
		    case 2:
					system ("cls");
					cadastraProduto();
		         break;
		    case 3:
					system ("cls");
					cadastravenda();
		         break;
		    case 4:
					system ("cls");
					consultaClientes();
		         break;
		    case 5:
			        system ("cls");
					consultaClienteNome();
		         break;
		    case 6:
			        system ("cls");
					consultaClienteCPF();
		         break;
		    case 7:
			        system ("cls");
					consultaProdutos();
		         break;
		    case 8:
			        system ("cls");
					consultaProdutosCodigo();
		         break;
		    case 9:
			        system ("cls");
					consultaProdutosDescricao();
		         break;
		    case 10:
					system ("cls");
					consultaVendas();
		         break;
		    case 11:
			        system ("cls");
					consultaVendasCPFCliente();
		         break;
		    case 12:
			        system ("cls");
					consultaVendasVendedor();
		         break;
			case 0:
					system ("cls");
			     break;
			default:
			        printf("\n\tOpcao invalida!\n\n");
			        system("pause");
                    break;
        }
	}while(op != 0);
	return 0;
}

