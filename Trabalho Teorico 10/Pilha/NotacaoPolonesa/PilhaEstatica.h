#ifndef PILHA1_H_INCLUDED
#define PILHA1_H_INCLUDED
//==================================================
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 10
//==================================================

typedef struct Pilha
{
    char dados[100];
    int topo;
} Pilha;

//==================================================
void create_pilha(Pilha *p)
{
    p->topo = 0;
}
//==================================================
bool push(Pilha *p, char dado)
{
    if (p->topo == MAX)
    {
        return false;
    }

    p->dados[p->topo] = dado;
    p->topo++;
    return true;
}

//==================================================
char pop(Pilha *p)
{

    if (p->topo == 0)
    {
        //printf("\nPilha Vazia!\n");
        return -1;
    }

    p->topo--;
    return p->dados[p->topo];
}
//==================================================
void print_pilha(Pilha *p)
{

    printf("\nTamanho: %d\n", p->topo);
    printf("----- expressao ------\n");
    for (int i = p->topo - 1; i >= 0; i--)
    {
        printf("%c \n", p->dados[i]);
    }
}

int qtd_elemento(Pilha *p)
{
    return p->topo;
}

//==================================================
int is_empty(Pilha *p)
{
    return p->topo == 0;
}
//==================================================

#endif // PILHA_H_INCLUDED