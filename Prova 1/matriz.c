#include <stdio.h>

/// programa capaz de ler uma matriz e apresentar essa matriz formatada na tela.

void main()
{
    int mat[3][5]; // matriz de 3 linhas por 5 colunas - 15 elementos

    int l, c; // variaveis de controle de laço, uma indicando a linha e outra a coluna

    int menor;

//    for(c=0; c<5; c++) // varre a linha 0 da matriz
//    {
//        scanf("%d", &mat[0][c]);
//    }
//
//    for(c=0; c<5; c++) // varre a linha 1 da matriz
//    {
//        scanf("%d", &mat[1][c]);
//    }
//
//    for(c=0; c<5; c++) // varre a linha 2 da matriz
//    {
//        scanf("%d", &mat[2][c]);
//    }

    printf("Digite os valores da matriz\n");
    for(l=0; l<3; l++)
    {
        // printf("Linha %d\n", l);
        for(c=0; c<5; c++)
        {
            printf("Matriz [%d][%d] = ", l, c);
            scanf("%d", &mat[l][c]);
        }
    }

    printf("Matriz\n");
    for(l=0; l<3; l++)
    {
        for(c=0; c<5; c++)
        {
            printf("%d\t", mat[l][c]);
        }
        printf("\n");
    }

    printf("Menor elemento da matriz\n");
    menor = mat[0][0]; // o menor elemento inicialmente é o primeiro elemento da matriz
    for(l=0; l<3; l++)
    {
        for(c=0; c<5; c++)
        {
            if(mat[l][c] < menor)
            {
                menor = mat[l][c];
            }
        }
    }

    printf("O menor elemento da matriz = %d\n", menor);

}
