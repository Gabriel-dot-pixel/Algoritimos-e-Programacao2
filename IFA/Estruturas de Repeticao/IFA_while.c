#include <stdio.h>

//somar uma compra realizada em um supermaercado, onde eu não sei a quantidade de produtos comprados

void main()
{
    //definição de variaveis
    float valor;
    char temmais = 'S';

    float soma = 0;

    //não tem como utilizar o for. Posso utilizar o while ou do..while
    //for(i=0; i<quant; i++)

    while(temmais == 'S' || temmais == 's')
    {
        printf("Digite o valor do produto....: ");
        //le somente um elemento
        scanf("%f", &valor);

        soma += valor;

        printf("Subtotal...: R$ %.2f\n", soma);

        printf("Tem mais produtos <S/N>: ");
        scanf(" %c", &temmais);
    }

    printf("Total da compra = R$ %.2f\n", soma);
}

