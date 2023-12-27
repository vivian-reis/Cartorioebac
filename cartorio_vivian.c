#include <stdio.h> //biblioteca de comunicação com o usuário.
#include <stdlib.h> //biblioteca de alocação de espaço em memória.
#include <locale.h> //biblioteca de alocações de texto por região.
#include <string.h> //biblioteca responsável por cuidar das strings.

int registro()
{	
	printf("\t** TELA DE REGISTRO DE NOMES **\n\n");
	
	char arquivo[40]; // essa variável é essencial para criar o banco de dados!!!
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings.
		
	FILE *file; //cria o arquivo para o banco de dados.
	file = fopen(arquivo, "w"); // o w vem da palavra write (escrever).
	fprintf(file,cpf); // é o mesmo printf, mas é salvo no arquivo que foi criado.
	fclose(file); // é muito importante porque precisamos fechar o arquivo.
		
	file = fopen(arquivo, "a"); // o a é para atualizar o arquivo que foi criado.
	fprintf(file," // Nome: "); // Usei esta formatação para separar os dados no arquivo e na consulta.
	fclose(file);
	
	printf("Digite o Nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome); // o segundo parâmetro não pode ser colocado entre "", senão aparecerá esta informação no arquivo e não o dado digitado!
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
	
	if(file == NULL)// Essa é uma validação quando o dado informado não for localizado.
	{
		printf("CPF não encontrado! Tente novamente.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // Enquanto ele fizer a buscar do conteudo no arquivo em até 200x. Se não encontrar nada, será considerado nulo.
	{
		printf("\nSeguem as informações solicitadas: \nCPF: ");
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
	fclose(file); // antes de incluir esta função, aparecia a mensagem de que o arquivo foi deletado, mas só foi possível, após a inclusão deste comando.
	
	if(file == NULL)// Essa é uma validação quando o dado informado não for localizado.
	{
		printf("\nCPF não encontrado! Tente novamente.\n\n");
		system("pause");
	}
	
	remove(cpf); // comando para deletar arquivos e precisa ter muito cuidado para não deletar o arquivo incorreto!
	// foi necessário colocar após o if anterior para aparecer a mensagem correta na execução.
	
	if(file != NULL)
	{
		printf("\nCPF deletado com sucesso!\n\n");
		system("pause");
	}
}

int main()
{
	int opcao = 0;// Definindo variáveis.
	int laco = 1;// Variável para o retorno de tela.
	
	for(laco = 1; laco = 1;) //Função para retornar na tela inicial. Está sem a incrementação para criar o looping infinito!
  	{
		system("cls");// Foi necessáio colocar no início da função For para não misturar as telas do menu inicial com a tela seguinte da opção desejada.
		setlocale(LC_ALL, "Portuguese"); // esta função serve para usar caracteres da lingua portuguesa.
	
	    printf ("\t*** CARTÓRIO DA EBAC ***\n\n"); // o \t é uma tabulação e serve para centralizar o texto.
		printf ("Escolha a opção desejada no Menu:\n\n"); // o \n serve para pular linha.
		printf ("\t1. Registrar Nomes\n");
		printf ("\t2. Consultar Nomes\n");
		printf ("\t3. Deletar Nomes\n");
		printf("\t4. Sair do Sistema\n\n");
	
		printf ("Qual a opção desejada? "); 
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
				printf("OPÇÃO INCORRETA, TENTE NOVAMENTE!\n\n");
				system("pause");
				break;
		}
	}
}

