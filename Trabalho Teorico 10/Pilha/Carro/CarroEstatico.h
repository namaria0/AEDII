#ifndef PILHA1_H_INCLUDED
#define PILHA1_H_INCLUDED
//==================================================
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "carro.h"
#define MAX 15
//==================================================

typedef struct Pilha
{
    Carro dados[MAX];
    int topo;
} Pilha;

//==================================================
void create_pilha(Pilha *p)
{
    p->topo = 0;
}
//==================================================
bool push(Pilha *p, Carro dado)
{

    if (p->topo == MAX)
    {
        printf("\nPilha Cheia!\n");
        return false;
    }

    p->dados[p->topo] = dado;
    p->topo++;
    return true;
}

//==================================================
Carro pop(Pilha *p)
{

    if (p->topo == 0)
    {
        //printf("\nPilha Vazia!\n");
        return;
    }

    p->topo--;
    return p->dados[p->topo];
}
//==================================================
void print_pilha(Pilha *p)
{

    printf("\nTamanho: %d\n", p->topo);
    printf("----- Carro ------\n");
    for (int i = p->topo - 1; i >= 0; i--)
    {
        printf("%s \n", p->dados[i].placa);
    }
}

//procedimento para tiarr carro indicado pelo usuario
void tirar_carro(Pilha *pilha)
{
    Pilha aux;
    Pilha tmp;
    char placa[15];

    create_pilha(&aux);
    create_pilha(&tmp);

    printf("Digite a placa do carro: ");
    scanf("%[^\n]s\n", placa);

    Carro elemento;
    for (int i = 0; i < pilha->topo; i++)
    {
        elemento = pop(pilha);
        if (elemento == placa)
        {
            pop(pilha);
            return;
        }
        push(&aux, elemento);
    }

    elemento = pop(&aux);
    for (int i = 0; i < pilha->topo; i++)
    {
        push(&tmp, elemento);
        elemento = pop(&aux);
    }

    elemento = pop(&tmp);
    for (int i = 0; i < pilha->topo; i++)
    {
        push(pilha, elemento);
        elemento = pop(&tmp);
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