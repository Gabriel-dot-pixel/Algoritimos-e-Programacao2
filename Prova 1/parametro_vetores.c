#include <stdio.h>

int preencher_vetor(int vet[]) // vet parâmetro
{
    int i, tam; // local
    printf("Qual o tamanho do vetor...: ");
    scanf("%d", &tam);

    printf("Vetor: ");
    for(i=0; i<tam; i++)
    {
        scanf("%d", &vet[i]);
    }
    printf("\n");

    return tam;
}

void imprimir_vetor(int vet[], int tam) // vet parâmetro
{
    int i; // local
    printf("Vetor: ");
    for(i=0; i<tam; i++)
    {
        printf("%d\t", vet[i]);
    }
    printf("\n");
}

void main()
{
    int vetor[10] = {0};
    int tam = 0;

    tam = preencher_vetor(vetor);

    imprimir_vetor(vetor, tam);
}

