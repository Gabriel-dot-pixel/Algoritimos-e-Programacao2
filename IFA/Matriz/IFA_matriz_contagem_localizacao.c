#include <stdio.h>

void main()
{
    int c, l; //controle dos laços

    int mat[4][4]; //matriz

    int linha_selecionada;

    int coluna_selecionada;

    int conta_pares = 0;

    srand(time(NULL));

    for(l=0; l<4; l++) //fazer a leitura de todas as linhas
    {
        for(c=0; c<4; c++) //fazer a leitura de todos os elementos de uma linha
        {
            mat[l][c] = rand() % 20 + 1; //gera um numero aleatorio entre 1 e 100
            printf("Mat[%d][%d] = %d\n", l, c, mat[l][c]);
        }
    }

    //apresentação total da matriz
    for(l=0; l<4; l++) //todas as colunas
    {
        for(c=0; c<4; c++) //todas as colunas
        {
            printf("\t%d", mat[l][c]);
        }
        printf("\n");
    }

    //apresentar o valor e a posição dos valores maiores que 10
    printf("\n\nApresentando os elementos maiores que 10\n");
    for(l=0; l<4; l++) //todas as colunas
    {
        for(c=0; c<4; c++) //todas as colunas
        {
            if(mat[l][c] > 10)
            {
                printf("Mat[%d][%d] = %d\n", l, c, mat[l][c]);
            }
        }
    }

    //apresentar a matriz somente com os valores menores ou iguais a 10
    printf("\n\nApresentando os elementos menores ou iguais que 10\n");
    for(l=0; l<4; l++) //todas as colunas
    {
        for(c=0; c<4; c++) //todas as colunas
        {
            if(mat[l][c] <= 10)
            {
                printf("\t%d", mat[l][c]);
            }
            else
            {
                printf("\t-");
            }
        }
        printf("\n");
    }

    //contar a quantidade de numeros pares na matriz
    for(l=0; l<4; l++) //todas as colunas
    {
        for(c=0; c<4; c++) //todas as colunas
        {
            if(mat[l][c]%2 == 0)
            {
                conta_pares++;
            }
        }
    }
    printf("\n\nQuantidade de numeros pares na matriz = %d", conta_pares);

    //duplicar os valores dos elementos da segunda linha
    for(c=0; c<4; c++)
    {
        mat[1][c] *= 2;
    }

    printf("\n\nMatiz com os elementos da segunda linha duplicados\n");
    //apresentação total da matriz
    for(l=0; l<4; l++) //todas as colunas
    {
        for(c=0; c<4; c++) //todas as colunas
        {
            printf("\t%d", mat[l][c]);
        }
        printf("\n");
    }


}
