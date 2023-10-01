#include <stdio.h> // biblioteca responsável pela comunicação com o usuário;
#include <stdlib.h> // biblioteca responsável pela alocação de espaço em memória;
#include <locale.h> // biblioteca responsável pela alocação do texto por região;
#include <string.h> // biblioteca responsável por cuidar das strings;

int registro(){ // função responsável por cadastrar os usuários no sistema!
	setlocale(LC_ALL, "Portuguese");
	char arquivo[50]; // criação das variáveis
	char cpf[50]; // criação das variáveis
	char nome[50]; // criação das variáveis
	char sobrenome [50]; // criação das variáveis
	char cargo[40]; // criação das variáveis
	
	printf("Agora, digite o seu CPF para realizar o cadastro: ");
	scanf("%s", cpf); //"%s" se refere as strings
	
	strcpy(arquivo, cpf); // Responsável por copiar os valores das strings
	
	FILE *file; // criar o arquivo
	file = fopen(arquivo, "w"); // fopen -> serve para abrir um arquivo para escrever algo nele, por isso utilizou o "w"
	fprintf (file,cpf); // fprint serve para salvar o valor da variável
	fclose (file); // fecha o arquivo.
	
	file = fopen(arquivo, "a"); // apenas atualizar o arquivo
	fprintf (file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf ("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); // apenas atualizar o arquivo
	fprintf (file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf ("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);

	file = fopen(arquivo, "a"); // apenas atualizar o arquivo
	fprintf (file, ",");
	fclose(file);	
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf ("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);

	system ("pause");
	
}

int consulta(){
	setlocale(LC_ALL, "Portuguese");
	char cpf [50];
	char conteudo [200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // "r" é para ler o arquivo  ( read )
	
	if(file == NULL){
		printf(" Certeza que você digitou o CPF certo? Não localizamos ele!\n");
	}
	
	while (fgets(conteudo, 200, file) != NULL){
		printf("\n Essas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n\n");
	}

	system("pause");
}

int deletar(){
	setlocale(LC_ALL, "Portuguese");
	char cpf [50];
	
	printf("Digite o CPF que você quer deletar: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL){
		printf("CPF deletado com sucesso!\n");
		system("pause");
	}
}

int main(){
	int opcao=0;
	int laco=1;

	for (laco=1;laco=1;)
	{
		system("cls"); // responsável por limpar a tela, tudo que já foi escrito, ele limpa e recomeça.
		setlocale(LC_ALL, "Portuguese");
		
		printf(" CARTÓRIO DA EBAC - Escola Britânica de Artes Criativas e Tecnologia\n\n");
		printf("Escolha a opção desejada do menu: \n\n");
		printf(" \tOPÇÃO 1 - Registrar Nomes\n");
		printf(" \tOPÇÃO 2 - Consultar Nomes\n");
		printf(" \tOPÇÃO 3 - Deletar Nomes\n");
		printf("Opção: ");
		
		scanf("%d", &opcao);
	
	
		switch(opcao)
		{
			case 1: 
				registro(); // chamada de funções
				break;
			
			case 2: 
				consulta(); // chamada de funções
				break;
				
			case 3:
				deletar(); // chamada de funções
				break;
				
			default:
				printf("Você digitou o número errado.\n\n");
				system("pause");
				break;
		}
	}
}
