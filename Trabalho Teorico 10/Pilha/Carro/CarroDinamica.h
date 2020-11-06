#ifndef PILHA2_H_INCLUDED
#define PILHA2_H_INCLUDED
//==================================================
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 10

typedef struct Celula
{
    char dado[100];
    struct Celula *prox;
} Celula;
//==================================================
typedef struct Pilha
{
    Celula *topo;
    int tam;
} Pilha;
//==================================================
void create_pilha(Pilha *p)
{
    p->topo = NULL;
    p->tam = 0;
}
//==================================================
bool push(Pilha *p, char *dado)
{

    Celula *nova = (Celula *)malloc(sizeof(Celula));
    if (nova == NULL)
    {
        printf("\nPilha Cheia!\n");
        return false;
    }
    strcpy(nova->dado, dado);

    nova->prox = p->topo;
    p->topo = nova;
    p->tam++;
    return true;
}

//==================================================
char *pop(Pilha *p)
{

    if (p->tam == 0)
    {
        //printf("\nPilha Vazia!\n");
        return NULL;
    }

    char dado = p->topo->dado;

    Celula *tmp = p->topo;
    p->topo = p->topo->prox;
    free(tmp);

    p->tam--;
    return dado;
}

//==================================================
void print_pilha(Pilha *p)
{

    Celula *tmp = p->topo;
    printf("\nTamanho: %d\n", p->tam);
    while (tmp != NULL)
    {
        printf("%s\n", tmp->dado);
        tmp = tmp->prox;
    }
}

void print_linha(Pilha *p)
{

    Celula *tmp = p->topo;

    while (tmp != NULL)
    {
        printf("%s", tmp->dado);
        tmp = tmp->prox;
    }
}

// void sort_pilha(Pilha *p)
// {

//     for (int i = 0; i < p->tam - 1; i++)
//     {
//         Celula *tmp = p->topo;
//         for (int j = 0; j < p->tam - i - 1; j++)
//         {
//             if (tmp->dado > tmp->prox->dado)
//             {
//                 strcpy(aux, tmp->dado);
//                 strcpy(tmp->dado, tmp->prox->dado);
//                 strcpy(tmp->prox->dado, aux);
//             }
//             tmp = tmp->prox;
//         }
//     }
// }

int qtd_elemento(Pilha *p)
{
    return p->tam;
}

//==================================================
bool is_empty(Pilha *p)
{
    return p->tam == 0;
}

//==================================================
#endif // PILHA_H_INCLUDED