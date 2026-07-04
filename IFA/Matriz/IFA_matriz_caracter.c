#include <stdio.h>

void main()
{
    int c, l; //controle dos laços

    char texto[20][20]; //matriz

    printf("Digite o texto a ser armazenado\n");
    for(l=0; l<10; l++) //fazer a leitura de todas as linhas
    {
        for(c=0; c<10; c++) //fazer a leitura de todos os elementos de uma linha
        {
            scanf("%c", &texto[l][c]); //le somente um inteiro
        }
    }

    for(l=0; l<10; l++) //apresenta todas as linhas
    {
        for(c=0; c<10; c++) //apresenta uma linha
        {
                printf("%c", texto[l][c]);
        }
        printf("\n");
    }

    for(l=0; l<10; l++) //apresentar o texto sem as vogais
    {
        for(c=0; c<10; c++) //apresenta uma linha
        {
            if(texto[l][c] == 'a' || texto[l][c] == 'o' || texto[l][c] == 'i' || texto[l][c] == 'o' || texto[l][c] == 'u')
            {
                printf(" ");
            }
            else
            {
                printf("%c", texto[l][c]);
            }
        }
        printf("\n");
    }
}
