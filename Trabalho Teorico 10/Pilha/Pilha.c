#include <stdio.h>
#include <string.h>
#include "PilhaEstatica.h"
//#include "PilhaDinamica.h"
//#include "RetiraImpares.h"

//===========================================

//Procedimento para clonar pilha para verão usando arranjo e versão usando ponteiro
void clonar_pilha(Pilha *pilha, Pilha *clone)
{
    Pilha pilha_tmp; //Pilhar para auxiliar na hora de clonar
    create_pilha(&pilha_tmp);

    char *elemento;

    elemento = pop(pilha);
    while (elemento != NULL)
    {
        push(&pilha_tmp, elemento);
        elemento = pop(pilha);
    }

    elemento = pop(&pilha_tmp);
    while (elemento != NULL)
    {
        push(pilha, elemento);
        push(clone, elemento);
        elemento = pop(&pilha_tmp);
    }
}

//Procedimento para inverter pilha para verão usando arranjo e versão usando ponteiro
void inverter_pilha(Pilha *pilha)
{
    Pilha pilha_tmp;
    Pilha pilha_aux;
    create_pilha(&pilha_tmp);
    create_pilha(&pilha_aux);

    char *elemento;

    elemento = pop(pilha);
    while (elemento != NULL)
    {
        push(&pilha_tmp, elemento);
        elemento = pop(pilha);
    }

    elemento = pop(&pilha_tmp);
    while (elemento != NULL)
    {
        push(&pilha_aux, elemento);
        elemento = pop(&pilha_tmp);
    }
    elemento = pop(&pilha_aux);
    while (elemento != NULL)
    {
        push(pilha, elemento);
        elemento = pop(&pilha_aux);
    }
}

//===========================================

void ordenar_lista(Pilha *pilha)
{

    int tam = qtd_elemento(pilha);

    String *array = (String *)malloc(tam * sizeof(String));

    //array recebe elementos que estão na pilha
    for (int i = 0; i < tam; i++)
    {
        strcpy(array[i].nome, pop(pilha));
    }

    char aux[100];
    int r;

    //laço de repetição para ordenar nomes em ordem alfabetica
    for (int x = 0; x < tam; x++)
    {
        for (int y = x + 1; y < tam; y++)
        {
            r = strcmp(array[x].nome, array[y].nome);
            if (r > 0)
            {
                strcpy(aux, array[x].nome);
                strcpy(array[x].nome, array[y].nome);
                strcpy(array[y].nome, aux);
            }
        }
    }

    //Pilha recebe elementos do array(ordenados)
    for (int i = 0; i < tam; i++)
    {
        push(pilha, array[i].nome);
    }
}

void verifica_parenteses()
{
    Pilha pilha;
    create_pilha(&pilha);
    char expressao[100];
    char aux[1];
    int qtd = 0;

    printf("Digite a expressao: ");
    scanf("%s", expressao);

    for (int i = 0; i < strlen(expressao); i++)
    {
        if (expressao[i] == '(')
        {
            aux[0] = expressao[i];
            push(&pilha, aux);
        }
        if (expressao[i] == ')')
        {
            if (is_empty(&pilha))
            {
                printf("\nExpressao matematica incorreta\n");
                return;
            }
            pop(&pilha);
        }
        if (expressao[i] == '{')
        {
            aux[0] = expressao[i];
            push(&pilha, aux);
        }
        if (expressao[i] == '}')
        {
            if (is_empty(&pilha))
            {
                printf("\nExpressao matematica incorreta\n");
                return;
            }
            pop(&pilha);
        }
        if (expressao[i] == '[')
        {
            aux[0] = expressao[i];
            push(&pilha, aux);
        }
        if (expressao[i] == ']')
        {
            if (is_empty(&pilha))
            {
                printf("\nExpressao matematica incorreta\n");
                return;
            }
            pop(&pilha);
        }
    }

    if (is_empty(&pilha))
    {
        printf("\nExpressao matematica correta\n");
    }
    else
    {
        printf("\nExpressao matematica incorreta\n");
    }
}

void trab_linha(char *text, int n)
{
    Pilha pilha;
    create_pilha(&pilha);
    int cont = 0;
    char aux[1];

    for (int i = n; i < strlen(text); i++)
    {
        if (cont >= 70)
        {
            print_linha(&pilha);
            trab_linha(text, i);
            return;
        }
        aux[0] = text[i];
        switch (aux[0])
        {
        case '#':
            pop(&pilha);
            break;
        case '/':
            trab_linha(text, i);
            return;
            break;
        case '@':
            print_linha(&pilha);
            printf("\n");
            trab_linha(text, i);
            return;
            break;
        default:
            push(&pilha, aux[0]);
            break;
        }
    }
}
void editar_text()
{
    char text[500];

    printf("Digite o texto: ");
    scanf("%[^\n]s\n", text);

    trab_linha(text, 0);
}
//===========================================

int main(void)
{

    int opcao;

    Pilha pilha;
    Pilha clone;

    char nome[100], aux;

    create_pilha(&pilha);

    while (opcao != 0)
    {
        printf("\n----------------------\n");
        printf("\n");
        printf("---Menu---\n");
        printf("1 - Adiciona nome\n");
        printf("2 - Printar pilha\n");
        printf("3 - Clonar pilha\n");
        printf("4 - Concatenar pilha\n");
        printf("5 - Inverter pilha\n");
        printf("6 - Ordenar pilha\n");
        printf("7 - Verificar parenteses\n");
        printf("8 - Editar texto\n");
        printf("0 - Sair\n");
        printf("\n");
        printf("Digite a opcao desejada: ");
        scanf("%i", &opcao);
        fflush(stdin);

        switch (opcao)
        {
        case 1:
            printf("Digite um nome: ");
            scanf("%s", nome);
            push(&pilha, nome);
            break;
        case 2:
            print_pilha(&pilha);
            break;
        case 3:
            create_pilha(&clone);
            printf("--- Pilha clonada ---\n");
            clonar_pilha(&pilha, &clone);
            print_pilha(&clone);
            break;
        case 4:
            break;
        case 5:
            printf("--- Pilha invertida ---\n");
            inverter_pilha(&pilha);
            print_pilha(&pilha);
            break;
        case 6:
            printf("--- Lista ordenada ---\n");
            ordenar_lista(&pilha);
            print_pilha(&pilha);
            break;
        case 7:
            verifica_parenteses(&pilha);
            break;
        case 8:
            editar_text(&pilha);
            print_linha(&pilha);
            break;
        case 0:
            return 0;
            break;
        default:
            printf("Opcao invalida, tente novamente!");
            break;
        }

        // systemPause();
    }
    return 0;
}