#ifndef FILA2_H_INCLUDED
#define FILA2_H_INCLUDED
//======================================
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "pessoa.h"
#define MAX 5
//====================================
typedef struct Fila
{
    Pessoa dados[MAX];
    int inicio, fim;
    int tam;
} Fila;
//======================================
void create_fila(Fila *f)
{
    f->inicio = 0;
    f->fim = 0;
    f->tam = 0;
}
//======================================
// Queue
bool enqueue(Fila *f, Pessoa dado)
{

    if ((f->fim + 1) % MAX == f->inicio)
        return false;

    f->fim = (f->fim + 1) % MAX;
    f->dados[f->fim] = dado;
    f->tam++;

    return true;
}
//======================================
void print_fila(Fila *f)
{

    int pos = (f->inicio + 1) % MAX;

    printf("\n--- Pessoas ---\n");
    for (int i = 0; i < f->tam; i++)
    {
        print_pessoa(f->dados[pos]);
        pos = (pos + 1) % MAX;
    }
}
//======================================
Pessoa dequeue(Fila *f)
{

    if (f->tam == 0)
    {
        return invalida_pessoa();
    }

    f->inicio = (f->inicio + 1) % MAX;
    f->tam--;
    return f->dados[f->inicio];
}

void inverter_fila(Fila *fila)
{
}

//Procedimneto para ordenar fila pelo ID
void ordenar_fila(Fila *fila)
{
    int min;
    char nome[100];
    int idade, id;
    int n = fila->tam;

    for (int i = 0; i < (n - 1); i++)
    {
        min = i;
        for (int j = (i + 1); j < n; j++)
        {
            if (fila->dados[j].id < fila->dados[min].id)
                min = j;
        }
        if (i != min)
        {
            id = fila->dados[i].id;
            idade = fila->dados[i].idade;
            strcpy(nome, fila->dados[i].nome);
            fila->dados[i].id = fila->dados[min].id;
            fila->dados[i].idade = fila->dados[min].idade;
            strcpy(fila->dados[i].nome, fila->dados[min].nome);
            fila->dados[min].id = id;
            fila->dados[min].idade = idade;
            strcpy(fila->dados[min].nome, nome);
        }
    }
}
//======================================
#endif // FILA_H_INCLUDED
