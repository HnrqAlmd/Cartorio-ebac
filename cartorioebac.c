#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por administrar as strings

int registro() //Função responsável por vadastrar os usuários no sistmea
{
	//início criação de variáveis/string
	char arquivo[40];//char = carácteres. o valor a frente representa quantos carácteres serão salvos na string
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da criação de variáveis/string
	
	
	printf("Digite o CPF a ser cadastrado:");//coletando informação do usuário
	scanf("%s", cpf);//registra a variável/caracteres na string. a string selecionada é a "cpf" "%s" referencia ser uma string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores da string
	
	FILE *file;//cria o arquivo no banco de dados e o nomeia como "file"
	file = fopen(arquivo, "w"); //abre o arquivo "w" significa "write", também existe "r" de "read"
	fprintf(file, cpf);//salva o valor da variável(cpf a ser cadastrado)
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo criado "a" se refere a add
	fprintf(file,",");//salva a vírgula no arquivo, uso estético/organizacional
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome a ser cadastrado:");//coleta informação do usuário
	scanf("%s", nome);//registra a resposta do usuário na string em forma de caracteres
	
	file = fopen(arquivo, "a");//abre o arquivo
	fprintf(file, nome);//salva o valor da variável(nome)
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo
	fprintf(file,",");//salva o valor da variável
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado:");//coleta a informaçõo do usuário
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
	

	system("pause");//congela o programa para uma resposta do usuário
	
	
}

int consulta()
{
	
	setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	
	char cpf[40];
	char conteudo[200];//conteúdo se refere a resposta do usuário
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file== NULL)//se o arquivo não for encontrado
	{
		printf("CPF inválido. O arquivo não foi localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)//enquanto(captura o que for digitado, até 200 caracteres, no arquivo) para se encontrar uma resposta inválida como "space"
	{
		printf("\nEssas são as informações do usuário:");
		printf("%s", conteudo);//expõe ao usuário o que foi capturado na string conteúdo
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
    
    if(file == NULL)//se(arquivo obtver uma resposta invalida, como não existir, apresenta a primeira resposta "usuário não cadastrado")
    {
    	printf("Usuário não cadastrado!\n");
    	system("pause");
	}
	
	if(file != NULL )//se(arquivo for encontrado, apresenta a resposta "usuário deletado com sucesso")
	{
		printf("Usuário deletado com sucesso!\n");
		system("pause");
	}
}

int main()
{
	int opcao=0;//definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
	
	
        setlocale(LC_ALL, "Portuguese");//definindo a linguagem
    
        printf("#### CARTÓRIO EBAC ####\n\n");//início do menu
        printf("Escolha a opção desejada no menu: \n");
        printf("\t1 - Regristrar nome:\n");
        printf("\t2 - Consultar base de dados:\n");
	    printf("\t3 - Excluir nome:\n ");//fim do menu
	    printf("\t4 - Sair do sistema\n");//sair do sistema
	    printf("Opção: ");
	
	
	scanf("%d", &opcao);//armazenando a escolha do usuário
	
	system("cls");//limpar tela
	
	switch(opcao)//equivalente a if, no entanto melhora o desempenho por ter menos linhas de código!
	{
		case 1://caso o usuário selecione "1", pausa e vai para função escolhida
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
		    
		default://caso a resposta do usuário não seja 1,2 ou 3, apresenta resposta e volta o menu
			printf("Essa opção não está disponível!\n");//fim da seleção
	        system("pause");
	        break;
		    
		    
		    
			
	}
	

}
}
