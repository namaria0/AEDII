#ifndef LISTA2_H_INCLUDED
#define LISTA2_H_INCLUDED
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
    struct Celula *ant;
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
    tmp->ant = NULL;

    lista->inicio = tmp;
    lista->fim = tmp;
    lista->qtd = 0;
}

//===============================================

bool adicionar_p(Lista *lista, Pessoa pessoa)
{

    Celula *nova = (Celula *)malloc(sizeof(Celula));

    if (nova == NULL)
    {
        printf("\nLista Cheia!\n");
        return false;
    }

    nova->dados = pessoa;
    nova->prox = NULL;

    lista->fim->prox = nova;
    nova->ant = lista->fim;
    lista->fim = nova;
    lista->qtd++;

    return true;
}

void print_lista(Lista *lista)
{

    Celula *tmp = lista->inicio->prox;

    while (tmp != NULL)
    {
        print_produto(tmp->dado);
        tmp = tmp->prox;
    }
}

void print_lista_invertida(Lista *lista)
{

    Celula *tmp = lista->fim;

    while (tmp->ant != NULL)
    {
        print_produto(tmp->dado);
        tmp = tmp->ant;
    }
}

//===============================================

bool update_lista(Lista *lista, Pessoa pessoa)
{

    bool achou = false;

    for (Celula *tmp = lista->inicio->prox; tmp != NULL; tmp = tmp->prox)
    {

        if (tmp->dados.id == pessoa.id)
        {
            tmp->dados = p;
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
            else
                tmp->prox->ant = ant;

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

//===============================================

#endif // FILA_H_INCLUDED
