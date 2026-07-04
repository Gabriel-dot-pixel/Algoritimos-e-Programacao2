/**
Crie uma estrutura para armazenar a ficha média de um paciente (peso, altura, idade). Em seguida,
declare uma variável para armazenar a informação de 35 pacientes e leia as informações dos 35
pacientes. Desenvolva uma função que calcule a média de idade dos pacientes que tenham peso menor
que p kg, onde p é o parâmetro da função.
*/
#include <stdio.h>
#define T 35

typedef struct paciente
{
    float peso;
    float altura;
    int idade;
} paciente;

void ler_vetor(paciente x[])
{
    int i;

    for(i=0; i<T; i++)
    {
        printf("Peso do paciente: ");
        scanf("%f", &x[i].peso);
        printf("Altura do paciente (em metros): ");
        scanf("%f", &x[i].altura);
        printf("Idade do paciente: ");
        scanf("%d", &x[i].idade);
    }
}

float calcular_media_peso(paciente x[], float p)
{
    float soma = 0.0;
    int i, tl = 0;

    for(i=0; i<T; i++)
    {
        if(x[i].peso < p)
        {
            soma += x[i].peso;
            tl++;
        }
    }

    return soma/tl;
}

void main()
{
    paciente pacientes[T];
    float p;

    ler_vetor(pacientes);

    printf("Qual o valor de p: ");
    scanf("%f", &p);
    printf("Media de peso dos pacientes com peso menor que %.2f kg: %.2f", p, calcular_media_peso(pacientes, p));

}
