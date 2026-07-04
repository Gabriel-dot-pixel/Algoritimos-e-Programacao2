/**
Defina uma estrutura para armazenar o código, nome e preço de um produto. Crie uma variável
para armazenar 25 produtos. Leia as informações dos produtos e depois faça uma função que mostre
os nomes dos produtos com preço superior a R$1000.00.
*/
#include <stdio.h>
#define T 30
#define TAM 25

typedef struct produto
{
    int codigo;
    char nome[T];
    float preco;
} produto;

void ler_vetor(produto x[])
{
    int i;

    for(i=0; i<TAM; i++)
    {
        printf("Codigo do produto: ");
        scanf("%d", &x[i].codigo);
        printf("Nome do produto: ");
        fflush(stdin);
        fgets(x[i].nome,T,stdin);
        printf("Preco do produto: ");
        scanf("%f", &x[i].preco);
    }
}

void apresentar_produto_superior(produto x[])
{
    int i;

    for(i=0; i<TAM; i++)
    {
        if(x[i].preco > 1000.00)
        {
            printf("\n");
            printf("Nome: %s\n", x[i].nome);
        }
    }
}

void main()
{
    produto produtos[TAM];

    ler_vetor(produtos);

    printf("Produtos com o preco superior a R$ 1000,00\n");
    apresentar_produto_superior(produtos);
}
