#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 8
#define MAX_VIDAS 3

void inicializarTabuleiro(int tab[MAX][MAX], int num)
{
    srand(time(NULL));

    for (int l=0; l<num; l++)
        for (int c=0; c<num; c++)
            tab[l][c] = rand() % 10;
}

void preencherVetLinha(int vet[MAX], int num){
    for(int i=0; i<num-1; i++){
        vet[i] = i+1;
    }
}

void apresentarMatriz(int mat[MAX][MAX], int num) {
    int l, c;

    // Imprime o cabeçalho das colunas (vetor linha)
    printf("\n");
    printf("  ");
    for(c=0; c<num; c++){
        printf("%3d", c + 1);
    }
    printf("\n");

    // Imprime o vetor coluna e a matriz alinhados
    for(l=0; l<num; l++) {
        // Imprime o número da linha (vetor coluna)
        printf("%2d", l + 1);

        // Imprime a linha da matriz
        for(c=0; c<num; c++) {
            printf("%3d", mat[l][c]);
        }
        printf("\n");
    }
}



void main()
{
    int num;
    int matrizSolucao[MAX][MAX];
    int matrizJogador[MAX][MAX];
    int vet[MAX];


    do
    {
        printf("Digite o tamanho do tabuleiro (max 8): ");
        scanf("%d", &num);
    }
    while (num < 1 || num > MAX);


    inicializarTabuleiro(matrizJogador, num);
    apresentarMatriz(matrizJogador, num);

}
