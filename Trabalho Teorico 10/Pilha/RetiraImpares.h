#include <stdio.h>
#include "PilhaEstatica.h"
//#include "PilhaDinamica.h"

void RetiraImpares(Pilha *original)
{
    Pilha pilha_aux;
    create_pilha(&pilha_aux);

    while (!is_empty(original))
    {
        int d = pop(original);
        if (d % 2 == 0)
            push(&pilha_aux, d);
    }
    while (!is_empty(&pilha_aux))
    {
        int d = pop(&pilha_aux);
        push(original, d);
    }
}