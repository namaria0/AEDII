#include <stdio.h>
#include <string.h>
#include "PilhaEstatica.h"
//#include "PilhaDinamica.h"
//#include "RetiraImpares.h"

//===========================================

void notacao_polonesa(Pilha *pilha)
{
    char expressao[100];
    int n = qtd_elemento(pilha);
    int x, y, soma = 0;

    printf("Digite a expressao: ");
    scanf("%c", expressao);

    for (int i = 0; i < n; i++)
    {
        switch (expressao[i])
        {
        case '+':
            x = pop(pilha);
            y = pop(pilha);
            // soma = (int)(y + x);
            // push(pilha, soma);
            break;
        case '-':
            x = pop(pilha);
            y = pop(pilha);
            break;
        case '*':
            x = pop(pilha);
            y = pop(pilha);
            break;
        case '/':
            x = pop(pilha);
            y = pop(pilha);
            break;
        default:
            push(pilha, expressao[i]);
            break;
        }
    }
    printf("%c\n\n", expressao);
}

//===========================================

//===========================================

int main(void)
{

    int opcao;

    Pilha pilha;

    create_pilha(&pilha);

    while (opcao != 0)
    {
        printf("\n----------------------\n");
        printf("\n");
        printf("---Menu---\n");
        printf("1 - Notacao polonesa\n");
        printf("2 - Printar\n");
        printf("0 - Sair\n");
        printf("\n");
        printf("Digite a opcao desejada: ");
        scanf("%i", &opcao);
        fflush(stdin);

        switch (opcao)
        {
        case 1:
            notacao_polonesa(&pilha);
            break;
        case 2:
            print_pilha(&pilha);
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
    return 0;
}