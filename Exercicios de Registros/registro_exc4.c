/**
Crie uma estrutura para armazenar o cadastro de estoque (código da peça, preço unitário da peça e
quantidade em estoque). Crie uma variável para armazenar 1000 peças, leia as informações das 1000
peças e depois, supondo que exista um estoque de segurança de 100 peças no estoque para cada tipo,
informe, através de uma função, quais peças precisam de reposição no estoque.
*/
#include <stdio.h>
#define T 1000

typedef struct peca
{
    int codigo;
    float preco;
    int qtde;
} peca;

void ler_vetor(peca x[])
{
    int i;

    for(i=0; i<T; i++)
    {
        printf("Codigo da peca: ");
        scanf("%d", &x[i].codigo);
        printf("Preco unitario da peca: ");
        scanf("%f", &x[i].preco);
        printf("Quantidade em estoque: ");
        scanf("%d", &x[i].qtde);
    }
}

void apresentar_peca_sem_estoque(peca x[])
{
    int i;

    for(i=0; i<T; i++)
    {
        if(x[i].qtde < 100)
        {
            printf("Peca com codigo %d precisa de estoque!\n", x[i].codigo);
        }
    }
}

void main()
{
    peca pecas[T];

    ler_vetor(pecas);

    apresentar_peca_sem_estoque(pecas);
}
