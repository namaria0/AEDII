#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "Pessoa.h"
#include "ListaDinamica.h"
//#include "ListaEstatica.h"
//#include "ListaDupla.h"

int main()
{
    int opcao;

    Lista lista;
    Lista clone;
    Lista lista2;
    Pessoa pessoa;
    int n, id;

    printf("Digite o tamanho da lista: ");
    scanf("%i", &n);

    criar_lista(&lista);
    //criar_lista(&lista, n);

    while (opcao != 0)
    {
        printf("\n----------------------\n");
        printf("\n");
        printf("---Menu---\n");
        printf("1 - Adicionar Pessoa na lista\n");
        printf("2 - Exibir listas pessoas\n");
        printf("3 - Editar dados\n");
        printf("4 - Remover pessoa da lista\n");
        printf("5 - Clonar lista\n");
        printf("6 - Concatenar listas\n");
        printf("7 - Pessoa mais velha\n");
        printf("8 - Pesquisar pessoa\n");
        printf("9 - Inverter lista\n");
        printf("10 - Inserir ordenado\n");
        printf("11 - Ordenar lista\n");
        printf("0 - Sair\n");
        printf("\n");
        printf("Digite a opcao desejada: ");
        scanf("%i", &opcao);
        fflush(stdin);

        switch (opcao)
        {
        case 1:
            pessoa = novo_pessoa();
            adiciona_p(&lista, pessoa);
            break;
        case 2:
            printf("-----Pessoas da lista-----\n\n");
            printa_lista(&lista);
            break;
        case 3:
            edita_lista(&lista);
            edita_lista(&lista, pessoa);
            break;
        case 4:
            printf("\nDigite o codigo da pessoa: ");
            scanf("%d", &id);

            delete_lista(&lista, id);
            break;
        case 5:
            criar_lista(&clone);
            //criar_lista(&clone, n);
            clonar_lista(&lista, &clone);
            break;
        // case 6:
        //     // printf("Digite o tamanho da lista: ");
        //     // scanf("%i", &n);
        //     // criar_lista(&lista2, 3);
        //     // novo_pessoa();
        //     concatenar_lista(&lista, &lista2);
        //     break;
        // case 7:
        //     maior(&lista);
        //     break;
        // case 8:
        //     printf("%i", pesquisa_pessoa(&lista));
        //     break;
        // case 9:
        //     inverter_lista(&lista);
        //     printf("Lista invertida\n");
        //     printa_lista(&lista);
        //     break;
        // case 10:
        //     pessoa = novo_pessoa();
        //     inserir_ordenado(&lista, pessoa);
        //     printa_lista(&lista);
        //     break;
        // case 11:
        //     ordenar_lista(&lista, n);
        //     printa_lista(&lista);
        //     break;
        case 0:
            return 0;
            break;
        default:
            printf("Opção inválida, tente novamente!");
            break;
        }

        // systemPause();
    }

    return 0;
}