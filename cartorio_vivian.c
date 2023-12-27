#include <stdio.h> //biblioteca de comunica��o com o usu�rio.
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria.
#include <locale.h> //biblioteca de aloca��es de texto por regi�o.
#include <string.h> //biblioteca respons�vel por cuidar das strings.

int registro()
{	
	printf("\t** TELA DE REGISTRO DE NOMES **\n\n");
	
	char arquivo[40]; // essa vari�vel � essencial para criar o banco de dados!!!
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings.
		
	FILE *file; //cria o arquivo para o banco de dados.
	file = fopen(arquivo, "w"); // o w vem da palavra write (escrever).
	fprintf(file,cpf); // � o mesmo printf, mas � salvo no arquivo que foi criado.
	fclose(file); // � muito importante porque precisamos fechar o arquivo.
		
	file = fopen(arquivo, "a"); // o a � para atualizar o arquivo que foi criado.
	fprintf(file," // Nome: "); // Usei esta formata��o para separar os dados no arquivo e na consulta.
	fclose(file);
	
	printf("Digite o Nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome); // o segundo par�metro n�o pode ser colocado entre "", sen�o aparecer� esta informa��o no arquivo e n�o o dado digitado!
	fclose(file);	
	
	file = fopen(arquivo, "a");
	fprintf(file," // Sobrenome: ");
	fclose(file);
	
	printf("Digite o Sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);	
	
	file = fopen(arquivo, "a");
	fprintf(file," // Cargo: ");
	fclose(file);
	
	printf("Digite o Cargo a ser cadastrado: ");
	scanf("%s", cargo);
	printf("\n");
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,".");
	fclose(file);	
		
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	printf("\t** TELA PARA CONSULTA DE NOMES **\n\n");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Qual o CPF a ser consultado? ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // r de read (ler).
	
	if(file == NULL)// Essa � uma valida��o quando o dado informado n�o for localizado.
	{
		printf("CPF n�o encontrado! Tente novamente.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // Enquanto ele fizer a buscar do conteudo no arquivo em at� 200x. Se n�o encontrar nada, ser� considerado nulo.
	{
		printf("\nSeguem as informa��es solicitadas: \nCPF: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese");
	
	printf("\t** TELA PARA DELETAR NOMES **\n\n");
	
	char cpf[40];
	
	printf("Qual o CPF a ser deletado? ");
	scanf("%s", cpf);
	
	FILE *file; // entrar na biblioteca e puxar o arquivo file.
	file = fopen(cpf, "r"); // ler o cpf no arquivo
	fclose(file); // antes de incluir esta fun��o, aparecia a mensagem de que o arquivo foi deletado, mas s� foi poss�vel, ap�s a inclus�o deste comando.
	
	if(file == NULL)// Essa � uma valida��o quando o dado informado n�o for localizado.
	{
		printf("\nCPF n�o encontrado! Tente novamente.\n\n");
		system("pause");
	}
	
	remove(cpf); // comando para deletar arquivos e precisa ter muito cuidado para n�o deletar o arquivo incorreto!
	// foi necess�rio colocar ap�s o if anterior para aparecer a mensagem correta na execu��o.
	
	if(file != NULL)
	{
		printf("\nCPF deletado com sucesso!\n\n");
		system("pause");
	}
}

int main()
{
	int opcao = 0;// Definindo vari�veis.
	int laco = 1;// Vari�vel para o retorno de tela.
	
	for(laco = 1; laco = 1;) //Fun��o para retornar na tela inicial. Est� sem a incrementa��o para criar o looping infinito!
  	{
		system("cls");// Foi necess�io colocar no in�cio da fun��o For para n�o misturar as telas do menu inicial com a tela seguinte da op��o desejada.
		setlocale(LC_ALL, "Portuguese"); // esta fun��o serve para usar caracteres da lingua portuguesa.
	
	    printf ("\t*** CART�RIO DA EBAC ***\n\n"); // o \t � uma tabula��o e serve para centralizar o texto.
		printf ("Escolha a op��o desejada no Menu:\n\n"); // o \n serve para pular linha.
		printf ("\t1. Registrar Nomes\n");
		printf ("\t2. Consultar Nomes\n");
		printf ("\t3. Deletar Nomes\n");
		printf("\t4. Sair do Sistema\n\n");
	
		printf ("Qual a op��o desejada? "); 
		scanf("%d", &opcao);
	
		system("cls"); // serve para limpar a tela.
	
		switch(opcao)
		{
			case 1:
				registro();
				break;
			case 2:
				consulta();
				break;
			case 3:
				deletar();
				break;
			case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
			default:
				printf("OP��O INCORRETA, TENTE NOVAMENTE!\n\n");
				system("pause");
				break;
		}
	}
}

