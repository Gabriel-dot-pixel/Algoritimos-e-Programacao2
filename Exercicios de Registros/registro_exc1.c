/**
    Defina uma estrutura para armazenar o cadastro de funcionários de uma empresa contendo o
número de inscrição do funcionário, o departamento, horas de trabalho e horas extras em cada dia do
mês. Em seguida, declare dois funcionários e faça as seguintes funções:
a) leitura dos dados;
b) cálculo do salario de cada funcionário, sabendo que ele ganha 40,00 para cada hora trabalhada e
60,00 para cada hora extra trabalhada;
c) apresentação dos dados.
*/
#include <stdio.h>
#define T 30

typedef struct funcionario
{
    int num_inscricao;
    char depto[T];
    int horas_trab;
    int horas_extra;
} funcionario;

struct funcionario ler()
{
    funcionario f;

    printf("Numero de inscricao do funcionario: ");
    scanf("%d", &f.num_inscricao);

    printf("Departamento do funcionario: ");
    fflush(stdin);
    fgets(f.depto,T,stdin);

    printf("Horas trabalhadas: ");
    scanf("%d", &f.horas_trab);

    printf("Horas extras:");
    scanf("%d", &f.horas_extra);

    return f;
};

float calcular_salario(funcionario f)
{
    float salario;

    salario = (f.horas_trab * 40.0) + (f.horas_extra * 60);

    return salario;
}

void apresentar(funcionario f)
{
    printf("\n");
    printf("Numero de inscricao: %d\n", f.num_inscricao);
    printf("Departamento: %s\n", f.depto);
    printf("Horas trabalhadas: %d\n", f.horas_trab);
    printf("Horas extras: %d\n", f.horas_extra);
}

void main()
{
    funcionario f1, f2;
    float salario;

    f1 = ler();
    f2 = ler();

    salario = calcular_salario(f1);

    apresentar(f1);
    printf("Salario do funcionario: R$ %.2f", salario);

    salario = calcular_salario(f2);

    apresentar(f2);
    printf("Salario do funcionario: R$ %.2f", salario);
}
