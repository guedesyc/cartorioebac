#include <stdio.h> // biblioteca respons�vel pela comunica��o com o usu�rio;
#include <stdlib.h> // biblioteca respons�vel pela aloca��o de espa�o em mem�ria;
#include <locale.h> // biblioteca respons�vel pela aloca��o do texto por regi�o;
#include <string.h> // biblioteca respons�vel por cuidar das strings;

int registro(){ // fun��o respons�vel por cadastrar os usu�rios no sistema!
	setlocale(LC_ALL, "Portuguese");
	char arquivo[50]; // cria��o das vari�veis
	char cpf[50]; // cria��o das vari�veis
	char nome[50]; // cria��o das vari�veis
	char sobrenome [50]; // cria��o das vari�veis
	char cargo[40]; // cria��o das vari�veis
	
	printf("Agora, digite o seu CPF para realizar o cadastro: ");
	scanf("%s", cpf); //"%s" se refere as strings
	
	strcpy(arquivo, cpf); // Respons�vel por copiar os valores das strings
	
	FILE *file; // criar o arquivo
	file = fopen(arquivo, "w"); // fopen -> serve para abrir um arquivo para escrever algo nele, por isso utilizou o "w"
	fprintf (file,cpf); // fprint serve para salvar o valor da vari�vel
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
	file = fopen(cpf, "r"); // "r" � para ler o arquivo  ( read )
	
	if(file == NULL){
		printf(" Certeza que voc� digitou o CPF certo? N�o localizamos ele!\n");
	}
	
	while (fgets(conteudo, 200, file) != NULL){
		printf("\n Essas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n\n");
	}

	system("pause");
}

int deletar(){
	setlocale(LC_ALL, "Portuguese");
	char cpf [50];
	
	printf("Digite o CPF que voc� quer deletar: ");
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
		system("cls"); // respons�vel por limpar a tela, tudo que j� foi escrito, ele limpa e recome�a.
		setlocale(LC_ALL, "Portuguese");
		
		printf(" CART�RIO DA EBAC - Escola Brit�nica de Artes Criativas e Tecnologia\n\n");
		printf("Escolha a op��o desejada do menu: \n\n");
		printf(" \tOP��O 1 - Registrar Nomes\n");
		printf(" \tOP��O 2 - Consultar Nomes\n");
		printf(" \tOP��O 3 - Deletar Nomes\n");
		printf("Op��o: ");
		
		scanf("%d", &opcao);
	
	
		switch(opcao)
		{
			case 1: 
				registro(); // chamada de fun��es
				break;
			
			case 2: 
				consulta(); // chamada de fun��es
				break;
				
			case 3:
				deletar(); // chamada de fun��es
				break;
				
			default:
				printf("Voc� digitou o n�mero errado.\n\n");
				system("pause");
				break;
		}
	}
}
