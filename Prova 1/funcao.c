#include <stdio.h>

int soma(int a, int b)
{
    int x;
    x = a + b;
    return x;
}

int subtracao(int a, int b)
{
    return a - b;
}

int multiplicacao(int a, int b)
{
    int z;
    z = a * b;
    return z;
}

float divisao(int x, int y)
{
    float resultado;
    resultado = (float)x/y;
    return resultado;
}

void main()
{
    int uma = 5;
    int outra = 15;
    int soma_valores, m;

    soma_valores = soma(uma, outra);

    printf("A soma = %d\n", soma_valores);

    printf("A subtracao de a e b = %d\n", subtracao(uma, outra));

    m = multiplicacao(uma, outra);
    printf("A multiplicacao de a e b = %d\n", m);

    printf("A divisao = %f\n", divisao(outra, uma));

}
