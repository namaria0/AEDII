#ifndef LISTA1_H_INCLUDED
#define LISTA1_H_INCLUDED
//===============================================
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Pessoa.h"
//===============================================
typedef struct Celula
{
    Pessoa dados;
    struct Celula *prox;
} Celula;
//===============================================
typedef struct Lista
{
    Celula *inicio;
    Celula *fim;
    int qtd;
} Lista;
//===============================================
void criar_lista(Lista *lista)
{

    Celula *tmp = (Celula *)malloc(sizeof(Celula));
    tmp->prox = NULL;

    lista->inicio = tmp;
    lista->fim = tmp;
    lista->qtd = 0;
}

//===============================================

bool adiciona_p(Lista *lista, Pessoa pessoa)
{

    Celula *nova = (Celula *)malloc(sizeof(Celula));

    if (nova == NULL)
    {
        printf("\nLista Cheia!\n");
        return false;
    }

    pessoa.id = lista->qtd + 1;

    nova->dados = pessoa;
    nova->prox = NULL;

    lista->fim->prox = nova;
    lista->fim = nova;
    lista->qtd++;

    return true;
}

void printa_lista(Lista *lista)
{

    Celula *tmp = lista->inicio->prox;

    while (tmp != NULL)
    {
        printa_pessoa(tmp->dados);
        tmp = tmp->prox;
    }
}

//===============================================

bool edita_lista(Lista *lista, Pessoa pessoa)
{
    bool achou = false;

    for (Celula *tmp = lista->inicio->prox; tmp != NULL; tmp = tmp->prox)
    {

        if (tmp->dados.id == pessoa.id)
        {
            tmp->dados = pessoa;
            achou = true;
            break;
        }
    }

    if (achou)
        return true;
    else
    {
        printf("\nProduto nao encontrado na lista!\n");
        return false;
    }
}
//===============================================

bool delete_lista(Lista *lista, int id)
{

    bool achou = false;
    Celula *ant, *tmp;

    for (ant = lista->inicio, tmp = lista->inicio->prox; tmp != NULL; tmp = tmp->prox, ant = ant->prox)
    {

        if (tmp->dados.id == id)
        {

            ant->prox = tmp->prox;

            if (tmp->prox == NULL)
                lista->fim = ant;

            free(tmp);
            lista->qtd--;
            achou = true;
            break;
        }
    }

    if (achou)
        return true;
    else
    {
        printf("\nProduto nao encontrado na lista!\n");
        return false;
    }
}

// //Procedimento para clonar lista
void clonar_lista(Lista *lista, Lista *clone)
{
    clone->qtd = lista->qtd;
    clone->max = lista->max;

    for (Celula *tmp = lista->inicio->prox; tmp != NULL; tmp = tmp->prox)
    {
        clone->dados.id = lista->dados.id;
        clone->dados.idade = lista->dados.idade;
        strcpy(clone->dados.nome, lista->dados.nome);
    }

    printf("\n-----------------------\n");
    //Laço de repetação para printar lista clonada
    for (int i = 0; i < clone->qtd; i++)
    {
        printa_pessoa(clone->dados);
    }

    printf("LISTA CLONADA!\n");
}
// // ------------------------------------------

// //Procedimento para concatenar duas listas
// void concatenar_lista(Lista *lista, Lista *lista2)
// {

//     // if (lista == NULL)
//     // {
//     //     return;
//     // }

//     for (Celula *tmp = lista->inicio->prox; tmp != NULL; tmp = tmp->prox)
//     {
//         adiciona_p(lista, lista2->dados);
//         lista->qtd++;
//     }
//     printa_lista(lista);
// }
// // ------------------------------------------

// //-------Procedimento para achar pessoa com maoir idade------
// void maior(Lista *lista)
// {
//     int maior = 0, id;
//     char nome[100];

//     for (Celula *tmp = lista->inicio->prox; tmp != NULL; tmp = tmp->prox)
//     {
//         if (lista->dados.idade > maior)
//         {
//             id = lista->dados.id;
//             strcpy(nome, lista->dados.nome);
//             maior = lista->dados.idade;
//         }
//     }
//     printf("\nPessoa mais velha\n");
//     printf("Id: %i\n", id);
//     printf("Nome: %s\n", nome);
//     printf("Idade: %i", maior);
// }
// // ------------------------------------------

// //Função para pesquisar pessoa na lista.
// int pesquisa_pessoa(Lista *lista)
// {
//     char nome[100];

//     printf("\nDigite o nome da pessoa que deseja pesquisar: ");
//     scanf("%s", nome);

//     for (Celula *tmp = lista->inicio->prox; tmp != NULL; tmp = tmp->prox)
//     {
//         if (strcmp(nome, lista->dados.nome) == 0)
//         {
//             return lista->dados.id;
//         }
//     }

//     return -1;
// }
// // ------------------------------------------

// //------Procedimento para inverter lista----
// void swap(Lista *lista, int x, int y)
// {
//     //Variaveis aux
//     char nome[100];
//     int idade, id;

//     //variaveis aux recebe dados que estão em x(primeiras posições)
//     id = lista->dados[x].id;
//     idade = lista->dados[x].idade;
//     strcpy(nome, lista->dados[x].nome);

//     //
//     lista->dados[x].id = lista->dados[y].id;
//     lista->dados[x].idade = lista->dados[y].idade;
//     strcpy(lista->dados[x].nome, lista->dados[y].nome);

//     lista->dados[y].id = id;
//     lista->dados[y].idade = idade;
//     strcpy(lista->dados[y].nome, nome);
// }
// void inverter_lista(Lista *lista)
// {
//     for (Celula *tmp = lista->inicio->prox; tmp != NULL; tmp = tmp->prox)
//     {
//         //x = primeira posição da lista que vai aumentando conforme o FOR rodar
//         //lista->qtd - x - 1 = ultima posição(tamanho) da lista menos o x
//         swap(lista, x, lista->qtd - x - 1);
//     }
// }
// // ------------------------------------------

// // void inserir_ordenado(Lista *lista)
// // {
// //     for (int x = 0; x < lista->qtd; x++)
// //     {
// //         if ()
// //         {
// //         }
// //     }
// // }

// void ordenar_lista(Lista *lista, int n)
// {
//     int min;
//     char nome[100];
//     int idade, id;
//     for (Celula *tmp = lista->inicio->prox; tmp != NULL; tmp = tmp->prox)
//     {
//         min = i;
//         for (Celula *tmp = lista->inicio->prox; tmp != NULL; tmp = tmp->prox)
//         {
//             if (lista->dados[j].id < lista->dados[min].id)
//                 min = j;
//         }
//         if (i != min)
//         {
//             id = lista->dado.id;
//             idade = lista->dado.idade;
//             strcpy(nome, lista->dado.nome);
//             lista->dado.id = lista->dados[min].id;
//             lista->dado.idade = lista->dados[min].idade;
//             strcpy(lista->dado.nome, lista->dados[min].nome);
//             lista->dados[min].id = id;
//             lista->dados[min].idade = idade;
//             strcpy(lista->dados[min].nome, nome);
//         }
//     }
// }

// void ordem_alfabetica(Lista *lista)
// {
//     int letra = 65;
//     for (int x = 0; x < lista->qtd; x++)
//     {
//         if (lista->dados[x].nome)
//         {
//         }
//     }
// }

#endif