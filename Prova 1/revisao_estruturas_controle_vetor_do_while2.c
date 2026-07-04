#include <stdio.h>

// somar uma compra realizada em um supermercado, onde eu não sei a quantodade de produtos comprados

void main()
{
    // definição de variaveis - alocar espaço onde a variavel vai estar na memoria
    float valores[30];
    char temmais;
    int tl = 0, i; // tamanho logico do vetor - quantidade de elementos utilizados

    float soma = 0;

    // não tem como utilizar o for. Posso utilizar while ou do..while
    // for(i=0; i<quant; i++)

    do{
          printf("Digite o valor do produto....: ");
          // lê somente um elemento
          scanf("%f", &valores[tl]);
          tl++; // contando a quantidade de elementos que estou guardando no vetor

          printf("Tem mais produtos <S/N>: ");
          scanf(" %c", &temmais);
    } while(temmais == 'S' || temmais == 's');

    // nesse ponto eu tenho o vetor preenchido e a quantidade de elementos do vetor
    for(i=0; i<tl; i++)
    {
        soma = soma + valores[i];
    }

    printf("Total da compra....: %f\n", soma);

    printf("Lista dos valores dos produtos comprados\n");
    for(i=0; i<tl; i++)
    {
        printf("%10.2f\n", valores[i]);
    }

}

