#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define max 2
#define N 40

typedef struct dados
{
	char titulo[N], autor[N], editora[N];
	int edicao, ano;
}livro;

int main()
{
	livro livros[max] ;
	int i;

	setlocale(LC_ALL, "Portuguese");

	for (i = 0; i < max; i++)
	{
		printf("Digite os dados do %d livro", i+1);
		printf("\nTítulo: ");
		gets(livros[i].titulo);
		fflush(stdin);
		printf("\nAutor: ");
		gets(livros[i].autor);
		fflush(stdin);
		printf("\nEditora: ");
		gets(livros[i].editora);
		fflush(stdin);
		printf("\nEdição: ");
		scanf("%d", &livros[i].edicao);
		fflush(stdin);
		printf("\nAno: ");
		scanf("%d", &livros[i].ano);
		fflush(stdin);
	}
	printf("\n** Livros Cadastrados **\n");
	system("pause");
	system("cls");

	for (i = 0; i < max; i++)
	{
		printf("\nTítulo: %s\nAutor: %s\nEditora: %s\nEdição: %d\nAno: %d\n", livros[i].titulo, livros[i].autor, livros[i].editora, livros[i].edicao, livros[i].ano);
	}
	system("pause");
	return(0);
}