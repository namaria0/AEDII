#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int codigo;
    char descricao[50];
    float valor;
} produto;

//Procedimento para cadastrar produto
int cadastrar_produto(produto *lista, int q_produto)
{

    printf("-- Dados produto --\n");
    printf("Codigo: ");
    scanf("%i", &(lista + q_produto)->codigo);
    fflush(stdin);

    //Verificando se ja existe produto com o codigo digitado
    for (int i = 0; i < q_produto; i++)
    {
        if ((lista + q_produto)->codigo == (lista + i)->codigo)
        {
            printf("Codigo ja existente!\n\n");
            return cadastrar_produto(lista, q_produto);
        }
    }
    //Validado codigo do produto
    if ((lista + q_produto)->codigo == -1)
    {
        printf("Codigo invalido!\n\n");
        return cadastrar_produto(lista, q_produto);
    }
    else
    {
        printf("Descricao: ");
        scanf("%s", (lista + q_produto)->descricao);
        fflush(stdin);
        printf("Valor: ");
        scanf("%f", &(lista + q_produto)->valor);
    }
}

//Procedimento para exibir produtos cadastrados
void exibir_produto(produto *lista, int q_produto)
{
    printf("--- PRODUTOS ---\n");
    for (int i = 0; i < q_produto; i++)
    {
        if ((lista + i)->codigo != -1)
        {
            printf("\n--PRODUTO %i--\n", i + 1);
            printf("Codigo: %i\n", (lista + i)->codigo);
            printf("Descricao: %s\n", (lista + i)->descricao);
            printf("Valor: %0.2f\n", (lista + i)->valor);
            printf("\n");
        }
    }
    printf("------------------\n");
}

//Procedimento recursivo para editar dados de um produto
void editar_produto(produto *lista, int q_produto)
{
    int codigo;

    printf("Digite o codigo do produto para ser editado: ");
    scanf("%i", &codigo);
    for (int i = 0; i < q_produto; i++)
    {
        if ((lista + i)->codigo == codigo)
        {
            printf("\nDigite nova descricao: ");
            scanf("%s", (lista + i)->descricao);
            printf("Digite novo valor: ");
            scanf("%f", &(lista + i)->valor);
            printf("\nDados do produto editado!\n");
            return;
        }
    }
    printf("Codigo nao encontrado\n");
    return editar_produto(lista, q_produto);
}

//Procedimento recursivo para deletar produto
void deletar_produto(produto *lista, int q_produto)
{
    int codigo;

    printf("Digite o codigo do produto que deseja deletar: ");
    scanf("%i", &codigo);
    for (int i = 0; i < q_produto; i++)
    {
        if ((lista + i)->codigo == codigo)
        {
            (lista + i)->codigo = -1;
            printf("Produto deletado!\n");
            q_produto--;
            return;
        }
    }

    printf("Codigo nao encontrado\n");
    return deletar_produto(lista, q_produto);
}

int main()
{
    int n, opcao;
    int q_produto = 0;

    printf("Total de produto: ");
    scanf("%i", &n);

    produto *lista = malloc(n * sizeof(produto));

    while (opcao != 0)
    {
        printf("\n");
        printf("------- MENU ------\n\n");
        printf("1 - Cadastrar um novo produto\n");
        printf("2 - Editar os dados de um produto\n");
        printf("3 - Excluir um produto\n");
        printf("4 - Exibir todos os produtos cadastrados\n");
        printf("5 - Exibir a quantidade total de produtos\n");
        printf("0 - Sair\n\n");
        printf("Digite a opcao desejada: ");
        scanf("%i", &opcao);
        fflush(stdin);
        printf("\n");

        switch (opcao)
        {
        case 1:
            if (q_produto != n)
            {
                cadastrar_produto(lista, q_produto);
                q_produto++;
            }
            else
            {
                printf("Nao e possivel cadastrar mais produtos!\n");
            }
            break;
        case 2:
            editar_produto(lista, q_produto);
            break;
        case 3:
            deletar_produto(lista, q_produto);
            break;
        case 4:
            exibir_produto(lista, q_produto);
            break;
        case 5:
            if (q_produto == 0)
            {
                printf("Nenhum produto\n");
            }
            else
            {
                printf("Quantidade de produto = %i\n", q_produto);
            }

            break;
        case 0:
            return 0;
            break;

        default:
            printf("Opção inválida, tente novamente!");
            break;
        }
    }
    system("pause");

    return 0;
}