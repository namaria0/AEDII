#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CarroEstatico.h"
//#include "CarroDinamica.h"
#include "carro.h"

int main(void)
{
    int opcao;
    Pilha pilha;
    Carro carro;
    char placa[15];

    create_pilha(&pilha);

    while (opcao != 0)
    {
        printf("\n----------------------\n");
        printf("\n");
        printf("---Menu---\n");
        printf("1 - Encostar carro\n");
        printf("2 - Printar carros\n");
        printf("3 - Tirar carro\n");
        printf("4 - \n");
        printf("0 - Sair\n");
        printf("\n");
        printf("Digite a opcao desejada: ");
        scanf("%i", &opcao);
        fflush(stdin);

        switch (opcao)
        {
        case 1:
            carro = novo_carro();
            fflush(stdin);
            push(&pilha, carro);
            break;
        case 2:
            print_pilha(&pilha);
            break;
        case 3:
            tirar_carro(&pilha);
            break;
        case 0:
            return 0;
            break;
        default:
            printf("Opcao invalida, tente novamente!");
            break;
        }

        // systemPause();
    }
}