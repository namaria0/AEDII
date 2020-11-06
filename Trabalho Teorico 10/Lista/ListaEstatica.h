#ifndef LISTA2_H_INCLUDED
#define LISTA2_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "Pessoa.h"

typedef struct Lista
{
    Pessoa *dados;
    int max;
    int qtd;

} Lista;

//Procedimento para criar lista
void criar_lista(Lista *lista, int n)
{
    lista->max = n;
    lista->dados = (Pessoa *)malloc(n * sizeof(Pessoa));
    lista->qtd = 0;
}
// ------------------------------------------

bool adiciona_p(Lista *lista, Pessoa pessoa)
{

    if (lista->qtd == lista->max)
    {
        printf("\nLista cheia!\n");
        return false;
    }

    pessoa.id = lista->qtd + 1;

    lista->dados[lista->qtd++] = pessoa;

    return true;
}
// ------------------------------------------

//Procedimento para printar lista
void printa_lista(Lista *lista)
{

    for (int i = 0; i < lista->qtd; i++)
    {
        printa_pessoa(lista->dados[i]);
    }
}
// ------------------------------------------

//Função booleana para ediatr dado de uma pessoa da lista
void edita_lista(Lista *lista)
{
    int id;
    printf("\nDigite o id da pessoa: ");
    scanf("%d", &id);
    fflush(stdin);

    for (int i = 0; i < lista->qtd; i++)
    {
        if (lista->dados[i].id == id)
        {
            printf("\nDigite novo nome: ");
            scanf("%s", lista->dados[i].nome);
            printf("Digite nova idade: ");
            scanf("%i", &lista->dados[i].idade);
            printf("\nDados da pessoa editado!\n");
            return;
        }
    }
    printf("id nao encontrado");
    edita_lista(lista);
}
// ------------------------------------------

//Função booleana para deletar uma pessoa da lista
bool delete_lista(Lista *lista, int id)
{
    //Verificando se existi pessoa com ID digitado
    if (id <= 0 || id > lista->qtd)
    {
        printf("Id não encontrado");
        return false;
    }

    //Laço de repetição para para encontrar pessoa com ID digitado
    for (int i = id; i < lista->qtd; i++)
    {
        lista->dados[i - 1] = lista->dados[i];
        lista->dados[i - 1].id--;
    }

    lista->qtd--;
    return true;
}
// ------------------------------------------

//Procedimento para clonar lista
void clonar_lista(Lista *lista, Lista *clone)
{
    clone->qtd = lista->qtd;
    clone->max = lista->max;

    for (int x = 0; x < lista->qtd; x++)
    {
        clone->dados[x].id = lista->dados[x].id;
        clone->dados[x].idade = lista->dados[x].idade;
        strcpy(clone->dados[x].nome, lista->dados[x].nome);
    }

    printf("\n-----------------------\n");
    //Laço de repetação para printar lista clonada
    for (int i = 0; i < clone->qtd; i++)
    {
        printa_pessoa(clone->dados[i]);
    }

    printf("LISTA CLONADA!\n");
}
// ------------------------------------------

//Procedimento para concatenar duas listas
void concatenar_lista(Lista *lista, Lista *lista2)
{

    // if (lista == NULL)
    // {
    //     return;
    // }

    for (int x = 0; x < lista->qtd; x++)
    {
        adiciona_p(lista, lista2->dados[x]);
        lista->qtd++;
    }
    printa_lista(lista);
}
// ------------------------------------------

//-------Procedimento para achar pessoa com maoir idade------
void maior(Lista *lista)
{
    int maior = 0, id;
    char nome[100];

    for (int x = 0; x < lista->qtd; x++)
    {
        if (lista->dados[x].idade > maior)
        {
            id = lista->dados[x].id;
            strcpy(nome, lista->dados[x].nome);
            maior = lista->dados[x].idade;
        }
    }
    printf("\nPessoa mais velha\n");
    printf("Id: %i\n", id);
    printf("Nome: %s\n", nome);
    printf("Idade: %i", maior);
}
// ------------------------------------------

//Função para pesquisar pessoa na lista.
int pesquisa_pessoa(Lista *lista)
{
    char nome[100];

    printf("\nDigite o nome da pessoa que deseja pesquisar: ");
    scanf("%s", nome);

    for (int x = 0; x < lista->qtd; x++)
    {
        if (strcmp(nome, lista->dados[x].nome) == 0)
        {
            return lista->dados[x].id;
        }
    }

    return -1;
}
// ------------------------------------------

//------Procedimento para inverter lista----
void swap(Lista *lista, int x, int y)
{
    //Variaveis aux
    char nome[100];
    int idade, id;

    //variaveis aux recebe dados que estão em x(primeiras posições)
    id = lista->dados[x].id;
    idade = lista->dados[x].idade;
    strcpy(nome, lista->dados[x].nome);

    //
    lista->dados[x].id = lista->dados[y].id;
    lista->dados[x].idade = lista->dados[y].idade;
    strcpy(lista->dados[x].nome, lista->dados[y].nome);

    lista->dados[y].id = id;
    lista->dados[y].idade = idade;
    strcpy(lista->dados[y].nome, nome);
}
void inverter_lista(Lista *lista)
{
    for (int x = 0; x < (lista->qtd / 2); x++)
    {
        //x = primeira posição da lista que vai aumentando conforme o FOR rodar
        //lista->qtd - x - 1 = ultima posição(tamanho) da lista menos o x
        swap(lista, x, lista->qtd - x - 1);
    }
}
// ------------------------------------------

void inserir_ordenado(Lista *lista, Pessoa pessoa)
{
    char nome[100];
    int idade, id;

    for (int i = 0; i < lista->qtd; i++)
    {
        if (pessoa.idade <= lista->dados[i].idade)
        {
            id = lista->dados[i].id;
            idade = lista->dados[i].idade;
            strcpy(nome, lista->dados[i].nome);
            lista->dados[i].id = pessoa.id;
            lista->dados[i].idade = pessoa.idade;
            strcpy(lista->dados[i].nome, pessoa.nome);
            lista->dados[i + 1].id = id;
            lista->dados[i + 1].idade = idade;
            strcpy(lista->dados[i + 1].nome, nome);
        }
    }
}

//Procedimneto para ordenar lista pelo ID
void ordenar_lista(Lista *lista, int n)
{
    int min;
    char nome[100];
    int idade, id;
    for (int i = 0; i < (n - 1); i++)
    {
        min = i;
        for (int j = (i + 1); j < n; j++)
        {
            if (lista->dados[j].idade < lista->dados[min].idade)
                min = j;
        }
        if (i != min)
        {
            id = lista->dados[i].id;
            idade = lista->dados[i].idade;
            strcpy(nome, lista->dados[i].nome);
            lista->dados[i].id = lista->dados[min].id;
            lista->dados[i].idade = lista->dados[min].idade;
            strcpy(lista->dados[i].nome, lista->dados[min].nome);
            lista->dados[min].id = id;
            lista->dados[min].idade = idade;
            strcpy(lista->dados[min].nome, nome);
        }
    }
}
//--------------------------------------------------

// void ordem_alfabetica(Lista *lista)
// {
//     for (int i = 0; i < (lista->qtd - 1); i++)
//     {
//         min = i;
//         for (int j = (lista->qtd + 1); j < n; j++)
//         {
//             if (lista->dados[j].nome < lista->dados[min].nome)
//                 min = j;
//         }
//     }
// }

#endif