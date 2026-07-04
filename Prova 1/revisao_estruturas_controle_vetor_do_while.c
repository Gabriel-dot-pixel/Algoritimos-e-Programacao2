#include <stdio.h>

// somar uma compra realizada em um supermercado, onde eu não sei a quantodade de produtos comprados

void main()
{
    // definição de variaveis - alocar espaço onde a variavel vai estar na memoria
    float valor;
    char temmais;

    float soma = 0;

    // não tem como utilizar o for. Posso utilizar while ou do..while
    // for(i=0; i<quant; i++)

    do{
          printf("Digite o valor do produto....: ");
          // lê somente um elemento
          scanf("%f", &valor);

          soma = soma + valor;

          printf("Total da compra ate agora = %f\n", soma);

          printf("Tem mais produtos <S/N>: ");
          scanf(" %c", &temmais);
    } while(temmais == 'S' || temmais == 's');

    printf("Total da compra....: %f\n", soma);

}

