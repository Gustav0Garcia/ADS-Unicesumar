#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>
#define MAX 5

typedef struct dados{
	int codigo;
	char nome[30];

}base_projetos;

int posicao = 0;

void cadastrarProjeto(base_projetos cadastro[MAX]);
void relatorioProjeto(base_projetos cadastro[MAX]);
void buscarCodigo(base_projetos cadastro[MAX]);
void buscarNome(base_projetos cadastro[MAX]);

int main(){
	setlocale(LC_ALL, "Portuguese");
	base_projetos cadastro[MAX];
	
	int escolha;
	
	system("cls");	
	do{
		system("cls");
		printf("****************************************************");
		printf("\n GESTÃO DE PROJETO ");
		printf("\n****************************************************");
		printf("\n 1 - Cadastro");
		printf("\n 2 - Impressão");
		printf("\n 3 - Busca por Código");
		printf("\n 4 - Busca por Nome");
		printf("\n 5 - Sair");
		printf("\n << Escolha uma opção do menu: ");
		scanf("%d", &escolha);
		
		switch(escolha){
			case 1:
				cadastrarProjeto(cadastro);			
				break;
			case 2:
				relatorioProjeto(cadastro);
				break;
			case 3:
				buscarCodigo(cadastro);
				break;
			case 4:
				buscarNome(cadastro);
				break;
			case 5:
				printf("\nSaindo da Aplicação\n");
				system("Pause");
				break;
			default:
				printf("\nEscolha errada!!!\n");
				system("Pause");
		}
	}while(escolha != 5);
	return 0;
}

void cadastrarProjeto(base_projetos cadastro[MAX]){
	system("cls");
	printf("***************************************");
	printf("\n CADASTRO");
	printf("\n***************************************");
	char resp = 's';
	
	while(resp == 's' && posicao <= MAX){
		posicao++;
		printf("\nCódigo: %d ", posicao);
		//scanf("%d", &cadastro[posicao].codigo);
		cadastro[posicao].codigo = posicao;
		printf("\nInforme o nome: ");
		fflush(stdin);
		gets(cadastro[posicao].nome);	
		
		if(posicao < MAX){
			printf("\n\nDeseja cadastrar novo Projeto? [s] Sim [n] Não: ");
			fflush(stdin);
			scanf("%c", &resp);
		}else{
			printf("\nSua base de Dados já chegou ao limite!!!\n");
			resp = 'n';
		}
	}
}
void relatorioProjeto(base_projetos cadastro[MAX]){
	system("cls");
	printf("***************************************");
	printf("\n RELATORIO ");
	printf("\n***************************************\n");
	int linha=1;
	
	if(posicao >= 1){
		while(linha <= posicao){
			printf("%d - %s\n", cadastro[linha].codigo, cadastro[linha].nome);
			linha++;
		}	
			
	}else{
		printf("\nSem Registros Cadastrados\n");
	}	
	system("Pause");
}

void buscarCodigo(base_projetos cadastro[MAX])
{
	system("cls");
	int codigo, achou;
	printf("***************************************");
	printf("\n BUSCA POR CÓDIGO ");
	printf("\n***************************************");
	printf("\nEntre com o código: ");
	scanf("%d", &codigo);
	achou = 0;
	int j = 0;
	while((achou == 0) && (j <= posicao)){
		if(codigo == cadastro[j].codigo){
			printf("\n%d - %s\n", cadastro[j].codigo, cadastro[j].nome);
			achou = 1;
			system("Pause");
		}
		j++;
	}
		if(achou == 0 ){
			printf("\nRegistro não encontrado com o código %d \n", codigo);
			system("Pause");
		}
}
void buscarNome(base_projetos cadastro[MAX]){
	system("cls");
	char nome[30];
	int achou, j;
	printf("***************************************");
	printf("\n BUSCA POR NOME ");
	printf("\n***************************************");
	printf("\nEntre com o nome (idêntico ao digitado): ");
	fflush(stdin);
	gets(nome);
	achou = 0;
	j = 0;
	while((achou == 0) && (j < MAX)){
		if(strcmp(cadastro[j].nome,nome)==0){
			printf("\n%d - %s\n", cadastro[j].codigo, cadastro[j].nome);
			achou = 1;
			system("Pause");
		}
		j++;
	}
	if(achou == 0 ){
		printf("\nRegistro não encontrado com o nome %s \n", nome);
		system("Pause");
	}
}
