#ifndef PESSOA_H_INCLUDED
#define PESSOA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct Pessoa
{
    char nome[100];
    int idade;
    int id;

} Pessoa;

void printa_pessoa(Pessoa pessoa)
{
    printf("Id: %i\n", pessoa.id);
    printf("Nome: %s\n", pessoa.nome);
    printf("Idade: %d\n", pessoa.idade);
    //printf("quantidade: %d\n", pessoa.qtd);

    printf("\n");
}

Pessoa novo_pessoa()
{
    Pessoa pessoa;

    // pessoa.id = rand() % 10;

    printf("----Dados da pessoa----\n");
    printf("\nNome: ");
    scanf("%s", pessoa.nome);
    printf("Idade: ");
    scanf("%i", &pessoa.idade);

    return pessoa;
}

#endif