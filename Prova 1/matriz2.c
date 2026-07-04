#include <stdio.h>

void main()
{
    int col, lin; // controle dos laços

    int mat[4][4]; // matriz

    for(lin=0; lin<4; lin++) // faz a leitura de todas as linhas
    {
        for(col=0; col<4; col++) // fazer a leitura de todos os elementos de uma linha
        {
            printf("Mat[%d][%d] = ", lin, col);
            scanf("%d", &mat[lin][col]); // lê somente um inteiro
        }
    }

}
