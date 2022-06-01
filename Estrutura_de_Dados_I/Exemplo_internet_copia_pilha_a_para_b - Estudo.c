//Estudo utilizando código encontrado na internet
//Apresentando lista dinâmica utilizadno ponteiro e transferência de Pilha A para Piha B

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


//Declara a estrutura da pilha
struct tpilha
{
    int dados;
    struct tpilha *proximo;
};

//Declara as funções
void cria_pilha(struct tpilha **topo);
void mostra_pilha(struct tpilha *topo, char desc);
int conta_nodos(struct tpilha *topo);
void insere_pilha_a(struct tpilha **topo, int valor, int *status);
void copia_valores(struct tpilha **topo, struct tpilha **topo2, int *status);


// Função para inicializar a pilha

void cria_pilha(struct tpilha **topo)
{
    *topo = NULL;
}


//Função para imprimir o conteúdo da pilha
void mostra_pilha(struct tpilha *topo, char desc)
{
    struct tpilha *aux;
    int numero_nodos;

    aux=topo;
    numero_nodos = conta_nodos(topo);

    printf("\n");
    printf("Valores da PILHA: %c", desc);
    printf("\n\n");
    printf("-------------------");
    printf("\n\n");
    printf(" Endereco -- Valor");
    printf("\n\n");

    //Enquanto não for o topo da lista
    while (aux != NULL)
    {
        printf(" %p -> %i ",&aux->dados , aux->dados);
        printf("\n");
        aux = aux->proximo;
    }

    printf("\n");
    printf("-------------------");
    printf("\n\n");
    printf("- PILHA A tem %i nodos.",numero_nodos);

    getch();
}

// Função que retorna o número de elementos da pilha
int conta_nodos(struct tpilha *topo)
{
    int cont=0;
    struct tpilha *aux;

    aux=topo;

    //Enquanto não for final da pilha
    while (aux != NULL)
    {
        cont = cont+1;
        aux = aux->proximo;
    }

    return cont;
}


// Função que insere na pilha
void insere_pilha(struct tpilha **topo, int valor, int *status)
{
    struct tpilha *p;

    p = (struct tpilha *) malloc (sizeof(struct tpilha));

    if (p == NULL)
        *status=1;
    else
    {
        p->dados = valor;
        p->proximo = *topo;
        *topo = p;
        *status = 0;
    }
}

// Função que copia os valores da pilha A para pilha B
void copia_valores(struct tpilha **topo , struct tpilha **topo2, int *status)
{
    struct tpilha *tmp; /* Pilha temporaria */
    struct tpilha *ptr; /* Ponteiro que percorrera a pilha A */
    struct tpilha *ptr2; /* Ponteiro que percorrera a pilha B */

    cria_pilha(&tmp);

    ptr = *topo;
    ptr2 = *topo2;

    if (*topo == NULL)
    {
            *status = 1;
    }
    else
    {
        if ( *topo2 == NULL)
        {
            tmp = malloc( sizeof(struct tpilha) );
            tmp->dados = ptr->dados;
            tmp->proximo = NULL;

            *topo2 = tmp;
            ptr = ptr->proximo;
        }

        /* Copia para pilha temporaria */
        while(ptr != NULL)
        {
            tmp = malloc( sizeof(struct tpilha) );
            tmp->dados = ptr->dados;

            tmp->proximo = *topo2;
            *topo2 = tmp;

            ptr = ptr->proximo;

        }

        printf("DEBUG: Mostra pilha intermediaria:\n");
        mostra_pilha(*topo2, 'C');

        ptr = NULL;
        ptr2 = NULL;
        /* Copia para a pilha B */
        while(*topo2 != NULL)
        {
            if (ptr == NULL)
            {
                ptr = *topo2; /* Copia primeiro valor do topo2 para ptr */
                *topo2 = (*topo2)->proximo; /* Desloca topo2 em 1 */
                ptr->proximo = NULL; /* Define NULL, pois se tornara o elemento mais recente da pilha */
            }
            else
            {
                ptr2 = *topo2;
                *topo2 = (*topo2)->proximo;
                ptr2->proximo = ptr;
                ptr = ptr2;
            }
        }

        *topo2 = ptr;

    }

}

//Função principal
int main(void)
{
    //Declaracao das variaveis
    int num = 0 ,
    ok = 0,
    opcao = 0,
    i = 0,
    n_nodo = 0,
    retorno = 0;

    struct tpilha
    *topo = NULL,
    *topo2 = NULL;


    //Cria a pilha antes de mostrar o menu ao usuario
    cria_pilha(&topo);
    cria_pilha(&topo2);

    do
    {
        system("cls");
        printf("----------------------------------");
        printf("\n");
        printf(" ------- Pilhas Encadeadas ------ ");
        printf("\n");
        printf("----------------------------------");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("Digite:");
        printf("\n");
        printf("\n");
        printf("1 - Inserir na Pilha A ");
        printf("\n");
        printf("\n");
        printf("2 - Copiar o conteúdo de Pilha A para Pilha B ");
        printf("\n");
        printf("\n");
        printf("3 - Imprimir Pilha A ");
        printf("\n");
        printf("\n");
        printf("4 - Imprimir Pilha B ");
        printf("\n");
        printf("\n");
        printf("5 - Sair");
        printf("\n");
        printf("\n");
        printf("Opcao: ");
        scanf("%d",&opcao);

        switch (opcao)
        {

            //--------------------------------------------------------------------------//

            case 1: //Inclusão dos elementos na pilha A

                printf("\n\n");
                printf("---- ATENCAO: Informe cinco valores -----");

                if (conta_nodos(topo) == 0)
                    i = 0;

                do
                {
                    printf("\n");
                    printf("\n");
                    printf("- Informe o valor do nodo %i: ",i+1);
                    scanf("%d",&num);

                    fflush(stdin);

                    if (num != 0)
                    {
                        insere_pilha(&topo, num, &ok);

                        i++;

                        if (ok == 1)
                        {
                            printf("\n");
                            printf("- Problema na Alocacao de Memoria !");
                            getch();
                        }
                    }
                }
                while (i < 5);

                mostra_pilha(topo, 'A');

                break;

            //--------------------------------------------------------------------------//

            case 2: //Copiar o conteúdo da pilha A para pilha B

                copia_valores(&topo, &topo2, &ok);
                if (ok==1)
                {
                    printf("\n");
                    printf("- Problema na Alocacao de Memoria !");
                    getch();
                }
                else
                {
                    printf("\n");
                    printf("- Os valores foram copiados !");
                    getch();
                }

                printf("\n");
                printf("- Imprimindo as pilhas A e B....");
                getch();

                mostra_pilha(topo2, 'B');
                mostra_pilha(topo, 'A');

                break;

            //--------------------------------------------------------------------------//

            case 3: //Imprimir a pilha A

                mostra_pilha(topo, 'A');
                break;

            //--------------------------------------------------------------------------//

            case 4: //Imprimir a pilha B

                mostra_pilha(topo2, 'B');
                break;

            //--------------------------------------------------------------------------//

            case 5: //Sair do programa

                printf("Programa Finalizado!");
                getch();

                break;

            //--------------------------------------------------------------------------//

            default: //Opcao invalida

                system("cls");
                printf("- Opcao Invalida!!");
                getch();
        }
    }
    while (opcao != 5);

    return 0;
}
