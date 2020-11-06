#ifndef PESSOA_H_INCLUDED
#define PESSOA_H_INCLUDED
//=====================================
typedef struct Pessoa
{
    int id;
    char nome[100];
    int idade;
} Pessoa;
//=====================================
void print_pessoa(Pessoa p)
{
    printf("Id: %d\n", p.id);
    printf("Nome: %s\n", p.nome);
    printf("Idade: %i\n", p.idade);

    printf("\n");
}
//=====================================
Pessoa nova_pessoa()
{
    Pessoa p;

    p.id = rand() % 1000;

    printf("----Dados da pessoa----\n");
    printf("\nNome: ");
    scanf("%s", p.nome);
    printf("Idade: ");
    scanf("%i", &p.idade);
    //p.idade = rand() % 100 + 15;

    return p;
}
//=====================================
Pessoa invalida_pessoa()
{
    Pessoa p;

    p.id = -1;
    sprintf(p.nome, "Pessoa: %d", p.id);
    p.idade = 0;

    return p;
}

//=====================================
#endif // PESSOA_H_INCLUDED