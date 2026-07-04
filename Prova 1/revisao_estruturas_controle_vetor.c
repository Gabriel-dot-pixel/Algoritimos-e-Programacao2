#include <stdio.h>

void main()
{
    // definição de variaveis - alocar espaço onde a variavel vai estar na memoria
    int i = 0; // aloquei o espaço de um inteiro para a variavel i
    int quant, elemento;

    int conta50 = 0;

    // saida para informar o que o usuario deve fazer
    printf("Digite a quantidade de elementos...: ");

    // entrada -> scanf
    scanf("%d", &quant); // & significa endereço da variavel

    // ler varios elementos
    // quantidade de elementos maiores que 50

    // estrutura de repetição - utilizada para repetir algo varias vezes
    // for, while e do..while

    // for é utilizado quando eu sei quantas vezes algo vai ser repetido

    for(i=0; i<quant; i++)
    {
        printf("Digite um numero inteiro....: ");
          // lê somente um elemento
          scanf("%d", & elemento);

          // se o elemento digitado for maior que 50 eu acrescento um na contagem
          if(elemento > 50)
          {
              conta50++;
          }
    }

    printf("Quantidade de elementos maiores que 50 = %d\n", conta50);

}
