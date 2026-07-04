#include <stdio.h>

void preencher_vetor(int vet[10], int *ponteiro_tam) //função retorna o tamanho do vetor
{
    int i;

    printf("Digite o tamanho do vetor...: ");
    scanf("%d", ponteiro_tam);

    printf("Vetor: ");
    for(i=0; i<*ponteiro_tam; i++)
    {
        scanf("%d", &vet[i]);
    }
    printf("\n");
}

void imprimir_vetor(int vet[], int tam)
{
    int i;

    printf("Vetor: ");
    for(i=0; i<tam; i++)
    {
        printf("%d\t", vet[i]);
    }
    printf("\n");
}

void main()
{
    int vetor[10] = {0}; //vetor vai estar com todos os valores com 0
    int tam = 0;

    preencher_vetor(vetor, &tam); //para que o valor de tam possa ser alterado pela função e essa alteração reflita na variavel do main()

    imprimir_vetor(vetor, tam);
}

