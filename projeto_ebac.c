#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel pelas strings


int registro() // fun��o responsavel por cadastrar os usuarios do sistema
{	
	setlocale(LC_ALL,"Portuguese");
	//inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado:");//coletando informa��o do usu�rio
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo,cpf); //Responsavel por copiar os valores das strings
	
	FILE *file; // cria o arquivo 
	file = fopen(arquivo, "w"); //cria arquivo e o "w" significa escrever
	fprintf(file,"CPF:");
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); // fecha o arquivo 
	
	file = fopen(arquivo,"a");
	fprintf(file,"\n");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,"Nome:");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,"\n");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,"Sobrenome:");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,"\n");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,"Cargo:");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}
int consulta()
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	printf("\n### informa��es do usu�rio ### \n\n");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o, arquivo n�o localizado!");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s",conteudo);
	}
	
	printf("\n\n");
	
	system("pause");
}
int deletar()
{
	setlocale(LC_ALL,"Portuguese");
	
	char cpf[40];
	
	printf("Digite o cpf a ser deletado:");
	scanf("%s",cpf);
	
	remove(cpf);	
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
    {
        printf("O usu�rio n�o se encontra no mais sistema!\n");
    }
	
	system("pause");
}	

int main()
{
	int opcao = 0;//Definindo vari�veis
	int x = 1;
	
	for(x = 1;x = 1;)
	{
		
		system("cls");//apagando informa��es
		
		setlocale(LC_ALL,"Portuguese");//Definindo a linguagem
		
		printf(">>>>>Cart�rio EBAC<<<<<\n\n");//inicio do menu
		printf("Digite o numero referente a op��o:\n\n\n");
		printf("\t1-Registrar nomes\n");
		printf("\t2-Consultar nomes\n");
		printf("\t3-Deletar nomes\n\n");//fim do menu
		printf("\t4-Sair do sistema\n\n\n");
		printf("Digite sua op��o:");
		
		scanf("%d",&opcao);//armazenando a escolha do usu�rio
		
		system("cls");//apagando informa��es
		
		switch(opcao)
		{
			case 1:
			registro();//chamada de fun��es
			break;
			
			case 2:
			consulta();//chamada de fun��es
			break;
			
			case 3:
			deletar();//chamada de fun��es
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema\n");
			return 0;
			break;	
			
			default:
			printf("Op��o n�o disponivel\n");
			system("pause");
			break;	
		}
    }
}	

