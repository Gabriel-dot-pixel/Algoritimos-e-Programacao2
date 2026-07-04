#include <stdio.h>

int soma(int a, int b)
{
    int x;

    x = a + b;

    return x;
}

int subtracao(int a, int b)
{
    int y;

    y = a - b;

    return y;
}

int multiplicacao(int a, int b)
{
    int z;

    z = a * b;

    return z;
}

float divisao(int a, int b)
{
    float w;

    w = (float) a / b;

    return w;
}

void main()
{
    int uma, outra;
    int som, sub, mul;
    float div;

    printf("Digite o valor de uma: ");
    scanf("%d", &uma);

    printf("Digite o valor de outra: ");
    scanf("%d", &outra);

    som = soma(uma, outra);
    printf("A soma de uma com outra = %d\n", som);

    sub = subtracao(uma, outra);
    printf("A subtracao de uma com outra = %d\n", sub);

    mul = multiplicacao(uma, outra);
    printf("A multiplicacao de uma com outra = %d\n", mul);

    div = divisao(uma, outra);
    printf("A divisao de uma por outra = %.2f\n", div);
}
