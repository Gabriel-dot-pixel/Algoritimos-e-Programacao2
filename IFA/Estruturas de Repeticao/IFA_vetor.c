#include <stdio.h>

void main()
{
    //definição de variaveis
    int i = 0; //aloquei o espaço de um inteiro para a variavel i
    int quant;
    int elementos[30];

    int conta50 = 0;
    int soma = 0;
    float media;

    do
    {
        printf("Digite a quantidade de elementoss (maximo 30)...: ");
        scanf("%d", &quant);
    }
    while(quant > 30 || quant < 1);

    //fazer a leitura
    for(i=0; i<quant; i++)
    {
        printf("Digite um numero inteiro....: ");
        //le somente um elementos
        scanf("%d", &elementos[i]);
    }

    //fazer a contagem dos elementoss
    for(i=0; i<quant; i++)
    {
        // se o elementos digitado for maior que 50 eu acrescento um na contagem
        if(elementos[i] > 50)
        {
            conta50++;
        }
    }

    printf("Quatidade de elementoss maiores que 50 = %d\n", conta50);

    printf("Relacao dos elementoss menores que 50\n");
    //apresentar os elementoss menores ou iguais que 50
    for(i=0; i<quant; i++)
    {
        // se o elementos digitado for maior que 50 eu acrescento um na contagem
        if(elementos[i] <= 50)
        {
            printf("%d\n", elementos[i]);
        }
    }

    for(i=0; i<quant; i++)
    {
        soma += elementos[i];
    }

    printf("A soma dos elementos e = %d\n", soma);

    media = (float) soma/quant;

    printf("A media dos elementos e = %.2f\n", media);
}
