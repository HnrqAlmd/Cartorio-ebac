#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por administrar as strings

int registro() //Fun��o respons�vel por vadastrar os usu�rios no sistmea
{
	//in�cio cria��o de vari�veis/string
	char arquivo[40];//char = car�cteres. o valor a frente representa quantos car�cteres ser�o salvos na string
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da cria��o de vari�veis/string
	
	
	printf("Digite o CPF a ser cadastrado:");//coletando informa��o do usu�rio
	scanf("%s", cpf);//registra a vari�vel/caracteres na string. a string selecionada � a "cpf" "%s" referencia ser uma string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores da string
	
	FILE *file;//cria o arquivo no banco de dados e o nomeia como "file"
	file = fopen(arquivo, "w"); //abre o arquivo "w" significa "write", tamb�m existe "r" de "read"
	fprintf(file, cpf);//salva o valor da vari�vel(cpf a ser cadastrado)
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo criado "a" se refere a add
	fprintf(file,",");//salva a v�rgula no arquivo, uso est�tico/organizacional
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome a ser cadastrado:");//coleta informa��o do usu�rio
	scanf("%s", nome);//registra a resposta do usu�rio na string em forma de caracteres
	
	file = fopen(arquivo, "a");//abre o arquivo
	fprintf(file, nome);//salva o valor da vari�vel(nome)
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo
	fprintf(file,",");//salva o valor da vari�vel
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado:");//coleta a informa��o do usu�rio
	scanf("%s", sobrenome);//fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	printf("Digite o cargo respectivo:");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	

	system("pause");//congela o programa para uma resposta do usu�rio
	
	
}

int consulta()
{
	
	setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	
	char cpf[40];
	char conteudo[200];//conte�do se refere a resposta do usu�rio
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file== NULL)//se o arquivo n�o for encontrado
	{
		printf("CPF inv�lido. O arquivo n�o foi localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)//enquanto(captura o que for digitado, at� 200 caracteres, no arquivo) para se encontrar uma resposta inv�lida como "space"
	{
		printf("\nEssas s�o as informa��es do usu�rio:");
		printf("%s", conteudo);//exp�e ao usu�rio o que foi capturado na string conte�do
		printf("\n\n");//pula linha/new line
	}
	
	system("pause");
	
	
}

int deletar()
{
    char cpf[40];
    
    printf("Digite o cpf a ser deletado: ");
    scanf("%s",cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)//se(arquivo obtver uma resposta invalida, como n�o existir, apresenta a primeira resposta "usu�rio n�o cadastrado")
    {
    	printf("Usu�rio n�o cadastrado!\n");
    	system("pause");
	}
	
	if(file != NULL )//se(arquivo for encontrado, apresenta a resposta "usu�rio deletado com sucesso")
	{
		printf("Usu�rio deletado com sucesso!\n");
		system("pause");
	}
}

int main()
{
	int opcao=0;//definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
	
	
        setlocale(LC_ALL, "Portuguese");//definindo a linguagem
    
        printf("#### CART�RIO EBAC ####\n\n");//in�cio do menu
        printf("Escolha a op��o desejada no menu: \n");
        printf("\t1 - Regristrar nome:\n");
        printf("\t2 - Consultar base de dados:\n");
	    printf("\t3 - Excluir nome:\n ");//fim do menu
	    printf("\t4 - Sair do sistema\n");//sair do sistema
	    printf("Op��o: ");
	
	
	scanf("%d", &opcao);//armazenando a escolha do usu�rio
	
	system("cls");//limpar tela
	
	switch(opcao)//equivalente a if, no entanto melhora o desempenho por ter menos linhas de c�digo!
	{
		case 1://caso o usu�rio selecione "1", pausa e vai para fun��o escolhida
			registro();
		    break;
		    
		case 2:
			consulta();
		    break;
		    
		case 3:
			deletar();
		    break;  
		
		case 4:  
		    printf("Obrigado por ultilizar o sistema!\n");
		    return 0;
		    break;
		    
		default://caso a resposta do usu�rio n�o seja 1,2 ou 3, apresenta resposta e volta o menu
			printf("Essa op��o n�o est� dispon�vel!\n");//fim da sele��o
	        system("pause");
	        break;
		    
		    
		    
			
	}
	

}
}
