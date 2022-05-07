#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 20

struct livro
{
	int codigo, ano;
	char titulo[50], autor[30], area[30], editora[30];
};

int main()
{
	struct livro ficha[TAM];
	struct livro troca;
	int busca, i, j, acha, op;

	op = 0;

	setlocale(LC_ALL, "portuguese");

	while (op != 5)
	{
		printf("1 - Cadastrar os livros \n2 - Imprimir os livros cadastrados \n3 - Pesquisar livros por código \n4 - Ordenar os livros por ano \n5 - Sair \n\nDigite a opção desejada: ");
		scanf("%d", &op);
		fflush(stdin);
		
		if (op == 1)
		{
			system("cls");

			for (i = 0; i < TAM; i++)
			{
				printf("Digite o código do livro da posição %d: ", i + 1);
				scanf("%d", &ficha[i].codigo);
				fflush(stdin);
				printf("\nDigite o título do livro: ");
				scanf("%50[^\n]s", &ficha[i].titulo);
				fflush(stdin);
				printf("\nDigite o nome do autor: ");
				scanf("%30[^\n]s", &ficha[i].autor);
				fflush(stdin);
				printf("\nDigite a área do livro: ");
				scanf("%30[^\n]s", &ficha[i].area);
				fflush(stdin);
				printf("\nDigite o ano: ");
				scanf("%30[^\n]s", &ficha[i].ano);
				fflush(stdin);
				printf("\nDigite o nome da editora: ");
				scanf("%30[^\n]s", &ficha[i].editora);
				fflush(stdin);
			}
		}
		else
		{
			if (op == 2)
			{
				system("cls");

				for (i = 0; i < TAM; i++)
				{
					printf("\nCódigo: %d \nTítulo: %s \nAutor: %s \nÁrea: %s \nAno: %d \nEditora: %s\n", ficha[i].codigo, ficha[i].titulo, ficha[i].autor, ficha[i].area, ficha[i].ano, ficha[i].editora);
				}
			}
			else
			{
				if (op == 3)
				{
					system("cls");

					printf("Digite o código que deseja buscar: ");
					scanf("%d", &busca);

					i = 1;
					acha = 0;

					while ((i < TAM) && (acha == 0))
					{
						if (ficha[i].codigo == busca)
						{
							acha = 1;
						}
						else
						{
							i++;
						}
						if (acha == 1)
						{
							printf("\nCódigo: %d \nTítulo: %s \nAutor: %s \nÁrea: %s \nAno: %d \nEditora: %s\n", ficha[i].codigo, ficha[i].titulo, ficha[i].autor, ficha[i].area, ficha[i].ano, ficha[i].editora);
						}
						else
						{
							printf("\nRegistro não encontrado\n");
						}
					}
				}
				else
				{
					if (op == 4)
					{
						system("cls");

						for (i = 0; i < TAM; i++)
						{
							for (j = i + 1; j < TAM; j++)
							{
								if (ficha[i].ano > ficha[j].ano)
								{
									troca = ficha[i];
									ficha[i] = ficha[j];
									ficha[j] = troca;
								}
							}
						}
						for (i = 0; i < TAM; i++)
						{
							printf("\nCódigo: %d \nTítulo: %s \nAno: %d \n", ficha[i].codigo, ficha[i].titulo, ficha[i].ano);
						}
					}

				}

			}
		}
	}
	return(0);
}