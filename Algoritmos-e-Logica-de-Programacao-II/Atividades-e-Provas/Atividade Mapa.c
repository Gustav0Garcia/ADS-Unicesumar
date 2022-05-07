#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define maxproj 200
#pragma warning(disable : 4996)

typedef struct dados
{
	int codigo;
	int status;
	int ano;
	char mes[10];
	char gerente[30];
	char titulo[30];
	char descricao[100];
	char dataFinal[11];
	float verba;

}cadastroProjeto;

void menu();
void cabecalhoProjeto();
void cabecalhoCadastro();
void listagem(cadastroProjeto projeto[maxproj]);
void listagemStatus(cadastroProjeto projeto[maxproj]);
void buscaCodigo(cadastroProjeto projeto[maxproj]);
void buscaTitulo(cadastroProjeto projeto[maxproj]);

int totalProj = 0;

int main()
{
	cadastroProjeto projeto[maxproj];

	setlocale(LC_ALL, "Portuguese");

	int i, aux;
	char op;

	do
	{
		system("cls");
		printf("=================================================================\n=\t\t\t\t\t\t\t\t=\n=\t Curso: Análise e Desenvolvimento de Sistemas\t\t=\n=\t Matéria: Algoritmos e Lógica de Programação II\t\t=\n=\t Aluno: Gustavo Garcia\t\t\t\t\t=\n=\t RA: 21025427-5\t\t\t\t\t\t=\n=\t\t\t\t\t\t\t\t=\n=================================================================\n_________________________________________________________________\n\n");
		menu();
		printf("\nInforme a opção desejada: "); 
		op = getchar();

		switch (op)
		{
		case '1':
			system("cls");
			cabecalhoProjeto();
			cabecalhoCadastro();
			printf("\n\nQuantidade máxima de Projetos: 200\n_________________________________________________________________\n\n\n");
			system("cls");
			fflush(stdin);

			for (i = 0; i < maxproj; i++)
			{
				projeto[i].codigo = 0;
			}

			for (i = 0; i < maxproj; i++)
			{
				if (totalProj < maxproj)
				{
					cabecalhoProjeto();
					cabecalhoCadastro();
					printf("\nQuantidade máxima de Projetos: 200\n_________________________________________________________________\n\n\n");

					totalProj++;

					printf("PROJETO: 0%d", i + 1);
					printf("\nCódigo do Projeto: %d", totalProj);
					printf("\n\nDigite o Status do Projeto:\n[1 - A Fazer | 2 - Fazendo | 3 - Concluído]: ");
					fflush(stdin);
					scanf("%d", &projeto[i].status);
					fflush(stdin);

					while ((projeto[i].status != 1) && (projeto[i].status != 2) && (projeto[i].status != 3))
					{
						system("cls");
						cabecalhoProjeto();
						cabecalhoCadastro();
						printf("\nQuantidade máxima de Projetos: 200\n_________________________________________________________________\n\n\n");
						printf("PROJETO: 0%d", i + 1);
						printf("\nCódigo do Projeto: %d", totalProj);

						printf("\n\n\nStatus inválido!\n_________________________________________________________________\n\n\nAperte qualquer tecla para informar o Status novamente!");
						getch();

						system("cls");
						cabecalhoProjeto();
						cabecalhoCadastro();
						printf("\nQuantidade máxima de Projetos: 200\n_________________________________________________________________\n\n\n");
						printf("PROJETO: 0%d", i + 1);
						printf("\nCódigo do Projeto: %d", totalProj);

						printf("\n\nDigite o Status do Projeto:\n[1 - A Fazer | 2 - Fazendo | 3 - Concluído]: ");
						fflush(stdin);
						scanf("%d", &projeto[i].status);
						fflush(stdin);
					}

					while ((projeto[i].status > 3) || (projeto[i].status < 1))
					{
						system("cls");
						cabecalhoProjeto();
						cabecalhoCadastro();
						printf("\nQuantidade máxima de Projetos: 200\n_________________________________________________________________\n\n\n");
						printf("PROJETO: 0%d", i + 1);
						printf("\nCódigo do Projeto: %d", totalProj);

						printf("\n\n\nStatus inválido!\n_________________________________________________________________\n\n");

						printf("Digite o Status do Projeto:\n[1 - A Fazer | 2 - Fazendo | 3 - Concluído]: ");
						fflush(stdin);
						scanf("%d", &projeto[i].status);
						fflush(stdin);
					}

					printf("\nInforme o Título: ");
					gets(projeto[i].titulo);
					fflush(stdin);
					printf("\nInforme o Gerente: ");
					gets(projeto[i].gerente);
					fflush(stdin);
					printf("\nInforme a Descrição: ");
					gets(projeto[i].descricao);
					fflush(stdin);
					printf("\nInforme a Verba do Projeto [R$ xxxxxx,xx]: R$ ");
					scanf("%f", &projeto[i].verba);
					fflush(stdin);
					printf("\nInforme o mês de início: ");
					gets(projeto[i].mes);
					fflush(stdin);
					printf("\ninforme o ano de início [xxxx]: ");
					scanf("%d", &projeto[i].ano);
					fflush(stdin);
					printf("\nInforme a Data Final ou Data final aproximada [xx/xx/xxxx]: ");
					gets(projeto[i].dataFinal);
					fflush(stdin);
					printf("\n\n\nProjeto Cadastrado!\n_________________________________________________________________\n\n\n");

					projeto[i].codigo += totalProj;

					printf("Aperte qualquer tecla para continuar!");
					getch();
					system("cls");
				}
			}
			if (totalProj >= maxproj)
			{
				system("cls");
				cabecalhoProjeto();
				cabecalhoCadastro();
				printf("\n\nCapacidade máxima de 200 Projetos atingida\n_________________________________________________________________\n\n\n");
				printf("Aperte qualquer tecla para voltar ao Menu!");
				getch();
			}
			break;
		case '2':
			listagem(projeto);
			break;
		case '3':
			listagemStatus(projeto);
			break;
		case '4':
			buscaCodigo(projeto);
			break;
		case '5':
			buscaTitulo(projeto);
			break;
		case '0':
			system("cls");
			printf("=================================================================\n=\t\t\t\t\t\t\t\t=\n=\t Curso: Análise e Desenvolvimento de Sistemas\t\t=\n=\t Matéria: Algoritmos e Lógica de Programação II\t\t=\n=\t Aluno: Gustavo Garcia\t\t\t\t\t=\n=\t RA: 21025427-5\t\t\t\t\t\t=\n=\t\t\t\t\t\t\t\t=\n=================================================================\n_________________________________________________________________\n\n");
			cabecalhoProjeto();
			printf("\n\n\nPrograma encerrado!\n_________________________________________________________________\n\n\n\nAperte qualquer tecla para Sair!");
			getch();
			break;
		}
	} while (op != '0');
	return(0);
}

void menu()
{
	printf("=================================================================\n=\t\t\tGESTÃO DE PROJETOS\t\t\t=\n=================================================================");
	printf("\n\n=================================================================\n=\t\t\t       MENU\t\t\t\t=\n=\t\t\t\t\t\t\t\t=\n=\t\t1 - Cadastro de Projeto\t\t\t\t=\n=\t\t2 - Listar todos os Projetos\t\t\t=\n=\t\t3 - Listar Projeto por Status\t\t\t=\n=\t\t4 - Busca de Projeto por Código\t\t\t=\n=\t\t5 - Busca de Projeto por Título\t\t\t=\n=\t\t\t\t\t\t\t\t=\n=\t\t0 - Para sair\t\t\t\t\t=\n=\t\t\t\t\t\t\t\t=\n=================================================================\n"); 
}

void cabecalhoProjeto()
{
	printf("=================================================================\n=\t\t\tGESTÃO DE PROJETOS\t\t\t=\n=================================================================");
}

void cabecalhoCadastro()
{
	printf("\n\n=================================================================\n=\t\t\tCADASTRO DE PROJETO\t\t\t=\n=================================================================\n\n");
}

void listagem(cadastroProjeto projeto[maxproj])
{
	int i;

	system("cls");
	printf("=================================================================\n=\t\t\tGESTÃO DE PROJETOS\t\t\t=\n=================================================================");
	printf("\n\n=================================================================\n=\t\t   LISTAGEM DE TODOS OS PROJETOS\t\t=\n=================================================================\n\n");

	for (i = 0; i < totalProj; i++)
	{
		printf("\nPROJETO: 0%d\n\nCódigo: %d\nStatus: %d\nTítulo: %s\nGerente: %s\nDescrição: %s\nVerba: R$ %.2f\nMês de início: %s\nAno de início: %d\nData final ou data final aproximada: %s\n\n", i+1, projeto[i].codigo, projeto[i].status, projeto[i].titulo, projeto[i].gerente, projeto[i].descricao, projeto[i].verba, projeto[i].mes, projeto[i].ano, projeto[i].dataFinal);
	}

	if (totalProj < 1)
	{
		printf("\n\nNão constam Projetos cadastrados\n_________________________________________________________________\n\n\n");
	}

	printf("\nListagem encerrada!\n_________________________________________________________________\n\nAperte qualquer tecla para voltar ao Menu!");
	getch();
	system("cls");
}

void listagemStatus(cadastroProjeto projeto[maxproj])
{
	int status, i, aux, aux2;

	system("cls");
	printf("=================================================================\n=\t\t\tGESTÃO DE PROJETOS\t\t\t=\n=================================================================");
	printf("\n\n=================================================================\n=\t\t       LISTAGEM POR STATUS\t\t\t=\n=================================================================\n\n");

	printf("Informe o Status a ser listado \n\n[1 - A Fazer | 2 - Fazendo | 3 - Concluído | 0 - Voltar ao Menu]: ");
	scanf("%d", &status);
	fflush(stdin);
	system("cls");

	while ((status == 1) || (status == 2) || (status == 3))
	{
		system("cls");
		printf("=================================================================\n=\t\t\tGESTÃO DE PROJETOS\t\t\t=\n=================================================================");
		printf("\n\n=================================================================\n=\t\t       LISTAGEM POR STATUS\t\t\t=\n=================================================================\n\n");

		i = 0;
		aux = 0;


		while (i <= totalProj)
		{
			if (status == projeto[i].status)
			{
				printf("\nPROJETO: 0%d\n\nCódigo: %d\nStatus: %d\nTítulo: %s\nGerente: %s\nDescrição: %s\nVerba: R$ %.2f\nMês de início: %s\nAno de início: %d\nData final ou data final aproximada: %s\n\n", i + 1, projeto[i].codigo, projeto[i].status, projeto[i].titulo, projeto[i].gerente, projeto[i].descricao, projeto[i].verba, projeto[i].mes, projeto[i].ano, projeto[i].dataFinal);
				aux = 1;
			}
			i++;
		}

		if (aux == 0)
		{
			system("cls");
			printf("=================================================================\n=\t\t\tGESTÃO DE PROJETOS\t\t\t=\n=================================================================");
			printf("\n\n=================================================================\n=\t\t       LISTAGEM POR STATUS\t\t\t=\n=================================================================\n\n");

			printf("\nStatus \"%d\" não localizado!\n_________________________________________________________________\n\n\n", status);
		}

		printf("\nAperte qualquer tecla para continuar!");
		getch();
		system("cls");
		printf("=================================================================\n=\t\t\tGESTÃO DE PROJETOS\t\t\t=\n=================================================================");
		printf("\n\n=================================================================\n=\t\t       LISTAGEM POR STATUS\t\t\t=\n=================================================================\n\n");

		printf("Informe o Status a ser listado \n\n[1 - A Fazer | 2 - Fazendo | 3 - Concluído | 0 - Voltar ao Menu]: ");
		scanf("%d", &status);
		fflush(stdin);

		while ((status != 0) && (status != 1) && (status != 2) && (status != 3))
		{
			system("cls");
			printf("=================================================================\n=\t\t\tGESTÃO DE PROJETOS\t\t\t=\n=================================================================");
			printf("\n\n=================================================================\n=\t\t       LISTAGEM POR STATUS\t\t\t=\n=================================================================\n\n");

			printf("\nStatus \"%d\" inválido!\n_________________________________________________________________\n\n\n", status);

			printf("Informe o Status a ser listado \n\n[1 - A Fazer | 2 - Fazendo | 3 - Concluído | 0 - Voltar ao Menu]: ");
			scanf("%d", &status);
		}
	}
}

void buscaCodigo(cadastroProjeto projeto[maxproj])
{
	int cod, i, aux;

	system("cls");
	printf("=================================================================\n=\t\t\tGESTÃO DE PROJETOS\t\t\t=\n=================================================================");
	printf("\n\n=================================================================\n=\t\t\tBUSCA POR CÓDIGO\t\t\t=\n=================================================================\n\n");

	printf("Informe o Código [0 - Voltar ao Menu]: ");
	scanf("%d", &cod);
	fflush(stdin);
	system("cls");


	while (cod != 0)
	{
		system("cls");
		printf("=================================================================\n=\t\t\tGESTÃO DE PROJETOS\t\t\t=\n=================================================================");
		printf("\n\n=================================================================\n=\t\t\tBUSCA POR CÓDIGO\t\t\t=\n=================================================================\n\n");

		i = 0;
		aux = 0;

		while ((aux == 0) && (i <= totalProj))
		{
			if (cod == projeto[i].codigo)
			{
				printf("\nPROJETO: 0%d\n\nCódigo: %d\nStatus: %d\nTítulo: %s\nGerente: %s\nDescrição: %s\nVerba: R$ %.2f\nMês de início: %s\nAno de início: %d\nData final ou data final aproximada: %s\n\n", i + 1, projeto[i].codigo, projeto[i].status, projeto[i].titulo, projeto[i].gerente, projeto[i].descricao, projeto[i].verba, projeto[i].mes, projeto[i].ano, projeto[i].dataFinal);
				aux = 1;
			}
			i++;
		}

		if (aux == 0)
		{

			printf("\nCódigo \"%d\" não encontrado!\n_________________________________________________________________\n\n\n", cod);
		}

		printf("\nAperte qualquer tecla para continuar!");
		getch();
		system("cls");
		printf("=================================================================\n=\t\t\tGESTÃO DE PROJETOS\t\t\t=\n=================================================================");
		printf("\n\n=================================================================\n=\t\t\tBUSCA POR CÓDIGO\t\t\t=\n=================================================================\n\n");

		printf("Informe o Código [0 - Voltar ao Menu]: ");
		scanf("%d", &cod);
		fflush(stdin);

		while (cod > 200)
		{
			system("cls");
			printf("=================================================================\n=\t\t\tGESTÃO DE PROJETOS\t\t\t=\n=================================================================");
			printf("\n\n=================================================================\n=\t\t\tBUSCA POR CÓDIGO\t\t\t=\n=================================================================\n\n");

			printf("\nCódigo \"%d\" inválido. \n\nNumeração dos códigos vão até 200!\n_________________________________________________________________\n\n\n", cod);

			printf("Informe o Código [0 - Voltar ao Menu]: ");
			scanf("%d", &cod);
			fflush(stdin);
		}
	} 
}

void buscaTitulo(cadastroProjeto projeto[maxproj])
{
	int i, aux;
	char titulo[30], verif;


	system("cls");
	printf("=================================================================\n=\t\t\tGESTÃO DE PROJETOS\t\t\t=\n=================================================================");
	printf("\n\n=================================================================\n=\t\t\tBUSCA POR TÍTULO\t\t\t=\n=================================================================\n\n");

	printf("INFORMAÇÕES:\n\nTítulo buscado deve ser igual ao cadastrado, diferenciando \nmaiúculo e minúsculo!\n_________________________________________________________________\n\n\n");

	printf("Informe o Título: ");
	fflush(stdin);
	gets(titulo);

	verif = '2';

	while (verif != '0')
	{
		system("cls");
		printf("=================================================================\n=\t\t\tGESTÃO DE PROJETOS\t\t\t=\n=================================================================");
		printf("\n\n=================================================================\n=\t\t\tBUSCA POR TÍTULO\t\t\t=\n=================================================================\n\n");

		printf("INFORMAÇÕES:\n\nTítulo buscado deve ser igual ao cadastrado, diferenciando \nmaiúculo e minúsculo!\n_________________________________________________________________\n\n\n");

		i = 0;
		aux = 0;

		while ((aux == 0) && (i <= totalProj))
		{
			if (strcmp(projeto[i].titulo, titulo) == 0)
			{
				printf("\nPROJETO: 0%d\n\nCódigo: %d\nStatus: %d\nTítulo: %s\nGerente: %s\nDescrição: %s\nVerba: R$ %.2f\nMês de início: %s\nAno de início: %d\nData final ou data final aproximada: %s\n\n", i + 1, projeto[i].codigo, projeto[i].status, projeto[i].titulo, projeto[i].gerente, projeto[i].descricao, projeto[i].verba, projeto[i].mes, projeto[i].ano, projeto[i].dataFinal);
				aux = 1;
			}
			i++;
		}

		if (aux == 0)
		{
			printf("\n\nTítulo \"%s\" não encontrado!\n_________________________________________________________________\n\n\n", titulo);
		}
	
		printf("\nAperte qualquer tecla para continuar!");
		getch();
		system("cls");
		printf("=================================================================\n=\t\t\tGESTÃO DE PROJETOS\t\t\t=\n=================================================================");
		printf("\n\n=================================================================\n=\t\t\tBUSCA POR TÍTULO\t\t\t=\n=================================================================\n\n");

		printf("INFORMAÇÕES:\n\nTítulo buscado deve ser igual ao cadastrado, diferenciando \nmaiúculo e minúsculo!\n_________________________________________________________________\n\n\n");

		do
		{
			system("cls");
			printf("=================================================================\n=\t\t\tGESTÃO DE PROJETOS\t\t\t=\n=================================================================");
			printf("\n\n=================================================================\n=\t\t\tBUSCA POR TÍTULO\t\t\t=\n=================================================================\n\n");

			printf("INFORMAÇÕES:\n\nTítulo buscado deve ser igual ao cadastrado, diferenciando \nmaiúculo e minúsculo!\n_________________________________________________________________\n\n\n");

			printf("\n\nDeseja realizar nova busca? [1 - Sim | 0 - Voltar ao Menu]: ");
			verif = getchar();
			fflush(stdin);

		} while ((verif != '0') && (verif != '1'));

		if (verif == '1')
		{
			system("cls");
			printf("=================================================================\n=\t\t\tGESTÃO DE PROJETOS\t\t\t=\n=================================================================");
			printf("\n\n=================================================================\n=\t\t\tBUSCA POR TÍTULO\t\t\t=\n=================================================================\n\n");

			printf("INFORMAÇÕES:\n\nTítulo buscado deve ser igual ao cadastrado, diferenciando \nmaiúculo e minúsculo!\n_________________________________________________________________\n\n\n");

			printf("\nInforme o Título: ");
			gets(titulo);
			fflush(stdin);
		}
	}
}