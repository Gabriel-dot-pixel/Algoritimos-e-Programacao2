#include <stdio.h>

void imprimir_vetor(int vet[5]) // vet parâmetro
{
    int i; // local
    printf("Vetor: ");
    for(i=0; i<5; i++)
    {
        printf("%d\t", vet[i]);
    }
    printf("\n");
}

void alterar_valores(int a, int vet[5]) // a e vet são parâmetro
{
    a = 3;
    vet[0] = 10;
    vet[1] = 18;
    vet[2] = 1;
    vet[3] = 8;
    vet[4] = 3;

    printf("\nEstamos dentro da funcao alterar_valores\n");
    printf("Variavel a = %d\n", a);
    imprimir_vetor(vet);
}

void main()
{
    int vetor[5] = {0}; // vetor vai estar com todos os valores com 0
    int b = 6;

    imprimir_vetor(vetor);

    alterar_valores(b, vetor);

    printf("\nEstamos dentro da funcao main novamente\n");
    printf("Variavel b = %d\n", b);
    imprimir_vetor(vetor);
}
