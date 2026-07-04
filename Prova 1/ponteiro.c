#include <stdio.h>

void main()
{
    int x = 10;
    int z = 3;

    int *y;

    printf("Valor de x = %d\n", x);
    printf("Endereco de x = %d\n", &x); // & indica que eu quero a posicao de memória onde está armazenado

    y = &x; //

    *y = 25; // o valor para onde o ponteiro y esta apontando vai ter o valor 25

    y = &z;

    *y = 45;

    printf("Posicao de memoria para onde Y aponta %d\n", y);
    printf("Valor para onde y aponta = %d\n", *y); // asterisco indica que eu quero o valor armazenado na posição

    printf("Valor de x = %d\n", x);
    printf("Valor de z = %d\n", z);
}
