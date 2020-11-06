#ifndef PESSOA_H_INCLUDED
#define PESSOA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct Carro
{
    char placa[15];

} Carro;

void printa_carro(Carro carro)
{

    printf("Placa: %s\n", carro.placa);
    //printf("quantidade: %d\n", carro.qtd);

    printf("\n");
}

Carro novo_carro()
{
    Carro carro;
    // carro.id = rand() % 10;

    printf("----Dados da carro----\n");
    printf("\nPlaca: ");
    scanf("%[^\n]s\n", carro.placa);
    fflush(stdin);

    return carro;
}

#endif