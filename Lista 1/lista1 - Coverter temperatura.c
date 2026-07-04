#include <stdio.h>

/**
Faça um programa com um menu com duas opções:
a)  Celsius -> Fahrenheit - onde será solicitado ao usuário uma temperatura em graus Celsius e apresentá-la convertida em graus Fahrenheit.
Fazer uma função que resolva a seguinte fórmula de conversão: F = (9 * C + 160) / 5, sendo F a temperatura em Fahrenheit e C a temperatura em Celsius. x

b)  Fahrenheit -> Celsius – onde será solicitado ao usuário uma temperatura em graus Farenheit e apresentá-la convertida em graus Celsius. x
A fórmula de conversão é: C = (F – 32) * (5/9), sendo F a temperatura em Farenheit e C a temperatura em Celsius.
*/

float converter_celsius_fahrenheit(float C)
{

    float F;

    F = (9 * C + 160) / 5;

    return F;
}

float converter_fahrenheit_celsius(float F)
{

    float C;

    C = (F - 32) * ((float) 5 / 9); //usar casting em divisão de inteiros, divisão entre inteiros zera

    return C;
}

void main()
{

    float C, F, resultado;
    int opc;

    do
    {
        printf("\n--- CLIMA-TEMPO IFSP ---\n");
        printf("\n1. Converter a temperatura de Celsius para Fahrenheit");
        printf("\n2. Converter a temperatura de Fahrenheit para Celsius");
        printf("\n3. Sair");
        printf("\nDigite uma das opcoes: ");

        scanf("%d", &opc);

        switch(opc)
        {

        case 1:
            printf("Digite a temperatura em Celsius: ");
            scanf("%f", &C);
            resultado = converter_celsius_fahrenheit(C);
            printf("Resultado em Fahrenheit: %.2f\n", resultado);
            break;

        case 2:
            printf("Digite a temperatura em Fahrenheit: ");
            scanf("%f", &F);
            resultado = converter_fahrenheit_celsius(F);
            printf("Resultado em Celsius: %.2f\n", resultado);
            break;

        case 3:
            break;

        default:
            printf("Opcao invalida, digite uma opcao entre 1 e 3.");
        }
    }
    while(opc != 3);

}
