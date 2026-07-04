#include <stdio.h>

void main()
{
    int col, lin; // controle dos laços

    char texto[20][20]; // matriz

    printf("Digite o texto a ser armazenado\n");

    for(lin=0; lin<10; lin++) // faz a leitura de todas as linhas
    {
        for(col=0; col<10; col++) // fazer a leitura de todos os elementos de uma linha
        {
            scanf("%c", &texto[lin][col]); // lê somente um inteiro
        }
    }

    for(lin=0; lin<10; lin++) // apresenta todas as linhas
    {
        for(col=0; col<10; col++) // apresenta uma linha
        {
            printf("%c", texto[lin][col]); // lê somente um inteiro
        }
        printf("\n");
    }

    for(lin=0; lin<10; lin++) // apresenta o texto sem as vogais
    {
        for(col=0; col<10; col++) // apresenta uma linha
        {
            if(texto[lin][col] == 'a' || texto[lin][col] == 'e' || texto[lin][col] == 'i' || texto[lin][col] == 'o' || texto[lin][col] == 'u')
            {
                printf(" ");
            }
            else
            {
                printf("%c", texto[lin][col]); // lê somente um inteiro
            }
        }
        printf("\n");
    }

}

