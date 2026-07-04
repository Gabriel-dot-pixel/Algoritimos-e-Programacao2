#include <stdio.h>

void main()
{
    int c, l; //controle dos laços

    int mat[4][4]; //matriz

    for(l=0; l<4; l++) //fazer a leitura de todas as linhas
    {
        for(c=0; c<4; c++) //fazer a leitura de todos os elementos de uma linha
        {
            printf("Mat[%d][%d] = ", l, c);
            scanf("%d", &mat[l][c]); //le somente um inteiro
        }
    }
}
