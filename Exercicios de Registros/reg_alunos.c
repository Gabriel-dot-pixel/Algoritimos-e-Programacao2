/*
Defina uma estrutura ALUNO contendo nome, nota1 e nota2. Em
seguida, cadastre 1 aluno e calcule a media das notas,
apresentando a situação (aprovado (media>=6) ou reprovado)
*/
#include<stdio.h>
#define T 30

//define a estrutura aluno
struct aluno
{
    char nome[T];
    float nota1;
    float nota2;
};

struct aluno ler ()
{
    struct aluno a;
    printf("nome do aluno: ");
    fflush(stdin); // limpar o buffer
    fgets(a.nome,T,stdin);
    printf("nota 1:");
    scanf("%f",&a.nota1);
    printf("nota 2:");
    scanf("%f",&a.nota2);
    return a;
}

float calcular_media (struct aluno a)
{
    float media;
    media = (a.nota1 + a.nota2)/2;
    return media;
}

void apresentar(struct aluno a)
{
    printf("nome = %s\n",a.nome);
    printf("nota 1= %.2f\n", a.nota1);
    printf("nota 2= %.2f\n", a.nota2);
}

void main()
{
    struct aluno a1; //cria variavel a1 do tipo struct aluno
    float media_final;
    // chamada da função ler()
    a1= ler();
    // chamada da função calcular_media()
    media_final = calcular_media(a1);
    // chamada da função apresentar()
    apresentar(a1);
    printf("media do aluno = %.2f\n", media_final);
}
