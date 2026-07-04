#include <stdio.h>

void main()
{
    int col, lin; // controle dos laços

    int mat[4][4]; // matriz

    int linha_selecionada;
    int coluna_selecionada;

    int conta_pares = 0;

    srand(time(NULL));

    for(lin=0; lin<4; lin++) // faz a leitura de todas as linhas
    {
        for(col=0; col<4; col++) // fazer a leitura de todos os elementos de uma linha
        {
            mat[lin][col] = rand()%20+1; // gera um numero aleatorio entre 1 e 100
            printf("Mat[%d][%d] = %d \n", lin, col, mat[lin][col]);
        }
    }

    // apresentação total da matriz
    for(lin=0; lin<4; lin++) // todas as linhas
    {
        for(col=0; col<4; col++) // todas as colunas
        {
            printf("\t%d", mat[lin][col]); // apresenta um inteiro
        }
        printf("\n");
    }

    // apresentar o valor e a posição dos valores maiores que 10
    printf("\nApresentando todos os valores maiores que 10\n");
    for(lin=0; lin<4; lin++) // todas as linhas
    {
        for(col=0; col<4; col++) // todas as colunas
        {
           if(mat[lin][col] > 10)
           {
               printf("%d - linha %d e coluna %d\n", mat[lin][col], lin, col);
           }
        }
    }

    // apresentar a matriz somente com os valores menores ou iguais a 10
    printf("\nApresentando todos os valores menores ou iguais a 10\n");
    for(lin=0; lin<4; lin++) // todas as linhas
    {
        for(col=0; col<4; col++) // todas as colunas
        {
           if(mat[lin][col] <= 10)
           {
               printf("\t%d", mat[lin][col], lin, col);
           }
           else
           {
               printf("\t-");
           }
        }
        printf("\n");
    }

    // contar a quantidade de numero pares na matriz

    for(lin=0; lin<4; lin++) // todas as linhas
    {
        for(col=0; col<4; col++) // todas as colunas
        {
            if(mat[lin][col]%2 == 0)
            {
                conta_pares++;
            }
        }
    }
    printf("\nA quantidade de numeros pares = %d\n", conta_pares);

    // duplicar o valor dos elementos da segunda linha
    for(col=0; col<4; col++)
    {
        mat[1][col] = mat[1][col] * 2;
    }

    // apresentação total da matriz
    printf("\nMatriz alterada\n");

    for(lin=0; lin<4; lin++) // todas as linhas
    {
        for(col=0; col<4; col++) // todas as colunas
        {
           printf("\t%d", mat[lin][col]); // apresenta um inteiro
        }
        printf("\n");
    }

}
