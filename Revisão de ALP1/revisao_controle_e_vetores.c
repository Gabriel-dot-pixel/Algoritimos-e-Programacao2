#include <stdio.h>

void main()
{
    // definição de variaveis - alocar um espaço para a variavel
    int i = 0; //aloquei o espaço de um inteiro para a variavel i - tambei joguei o valor 0 na variavel
    int quant, elemento;

    //saida para informar o que o usuario deve fazer
    printf("Digite a quantidade de elementos...: ")

    //entrada -> scanf - entrada da variavel, le somente um elemento
    scanf("%d", &quant);
    //%d faz referencia a um valor inteiro
    //%f faz referencia a valores reais
    //%c faz referencia a caracteres
    //& diz em qual endereço a variavel sera guardada

    // ler varios elementos - usa-se estruturas de repetição (for, while e do..while)

    // for é usado quando eu sei quantas vezes algo vai ser repetido
    for(i=0; i<quant; i++)
    {
        scanf("%d", &elemento);
    }




}
