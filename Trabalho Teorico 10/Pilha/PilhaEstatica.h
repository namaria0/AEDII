#ifndef PILHA1_H_INCLUDED
#define PILHA1_H_INCLUDED
//==================================================
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 10
//==================================================

typedef struct String
{
    char nome[100];
} String;

typedef struct Pilha
{
    String dados[MAX];
    int topo;
} Pilha;

//==================================================
void create_pilha(Pilha *p)
{
    p->topo = 0;
}
//==================================================
bool push(Pilha *p, char *dado)
{

    if (p->topo == MAX)
    {
        printf("\nPilha Cheia!\n");
        return false;
    }

    strcpy(p->dados[p->topo].nome, dado);
    p->topo++;
    return true;
}

//==================================================
char *pop(Pilha *p)
{

    if (p->topo == 0)
    {
        //printf("\nPilha Vazia!\n");
        return NULL;
    }

    p->topo--;
    return p->dados[p->topo].nome;
}
//==================================================
void print_pilha(Pilha *p)
{

    printf("\nTamanho: %d\n", p->topo);
    printf("----- Nome ------\n");
    for (int i = p->topo - 1; i >= 0; i--)
    {
        printf("%s \n", p->dados[i].nome);
    }
}

void print_linha(Pilha *p)
{
    for (int i = p->topo - 1; i >= 0; i--)
    {
        printf("%s", p->dados[i]);
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