#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "FilaEstatica.h"
//#include "Fila.h"
#include "Pessoa.h"

/*
FILA DE PESSOAS
PESSOA (ID, NOME, IDADE)
CRUD - criar, enfileirar, desenfileirar, tamanho, listar, destroy
*/

//Procedimento para clonar fila de pssoas. Versão arranjo e versão usando ponteiro
void clonar_fila(Fila *fila, Fila *clone)
{
    Pessoa tmp;        //variavel auxiliar
    int n = fila->tam; //tamanho da fila

    for (int x = 0; x < n; x++)
    {
        tmp = dequeue(fila);
        enqueue(fila, tmp);
        enqueue(clone, tmp);
    }

    printf("\nFila clonada!");
}

int main(void)
{

    int opcao, x;
    Fila fila;
    Fila clone;
    char buffer;
    Pessoa pessoa;
    create_fila(&fila);
    create_fila(&clone);

    while (opcao != 0)
    {
        printf("\n----------------------\n");
        printf("\n");
        printf("---Menu---\n");
        printf("1 - Adiciona pessoa\n");
        printf("2 - Printar fila\n");
        printf("3 - Chamar proximo da fila\n");
        printf("4 - Clonar fila\n");
        printf("5 - Inverter fila\n");
        printf("6 - Ordenar fila\n");
        printf("0 - Sair\n");
        printf("\n");
        printf("Digite a opcao desejada: ");
        scanf("%i", &opcao);
        fflush(stdin);

        switch (opcao)
        {
        case 1:
            pessoa = nova_pessoa();
            enqueue(&fila, pessoa);
            break;
        case 2:
            print_fila(&fila);
            break;
        case 3:
            pessoa = dequeue(&fila);
            print_fila(&fila);
            break;
        case 4:
            clonar_fila(&fila, &clone);
            print_fila(&clone);
            break;
        case 5:
            inverter_fila(&fila);
            print_fila(&fila);
            break;
        case 6:
            ordenar_fila(&fila);
            print_fila(&fila);
            break;
        case 0:
            return 0;
            break;
        default:
            printf("Opcao invalida, tente novamente!");
            break;
        }
    }

    //system("PAUSE");

    return 0;
}