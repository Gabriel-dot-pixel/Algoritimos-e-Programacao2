#include <stdio.h>

void ler_notas(float vet[10])
{
    int i;

    for(i=0; i<10; i++)
    {
        printf("Aluno %d = ", i+1);
        scanf("%f", &vet[i]);
    }
}

void apresentar_media_por_aluno(float p1[10], float p2[10], float media[10])
{
    int i;

    for(i=0; i<10; i++)
    {
        media[i] = (p1[i] + p2[i]) / 2;
        printf("Media do Aluno %d = %.2f\n", i+1, media[i]);
    }
}

void apresentar_media_global(float media[10])
{
    int i;
    float media_global, soma = 0.0;

    for(i=0; i<10; i++)
    {
        soma += media[i];
    }

    media_global = soma / 10;

    printf("A media global da turma = %.2f\n", media_global);
}

int calcular_media_acima_6(float media[10])
{
    int i, acima = 0;

    for(i=0; i<10; i++)
    {
        if(media[i] >= 6)
        {
            acima++;
        }
    }

    return acima;
}

void apresentar_notas(float notas[])
{
    int i;

    for(i=0; i<10; i++)
    {
        printf("Aluno %d = %.2f\n", i+1, notas[i]);
    }
}

int calcular_media_abaixo_6(float media[10])
{
    int i, abaixo = 0;

    for(i=0; i<10; i++)
    {
        if(media[i] < 6)
        {
            abaixo++;
        }
    }

    return abaixo;
}

void main()
{
    float p1[10], p2[10], medias[10];
    int aprovado, reprovado;

    ler_notas(p1);
    ler_notas(p2);

    printf("\n\nNotas da primeira prova\n");
    apresentar_notas(p1);

    printf("\n\nNotas da segunda prova\n");
    apresentar_notas(p2);

    printf("\n\nMedias dos alunos\n");
    apresentar_media_por_aluno(p1, p2, medias);
    apresentar_media_global(medias);

    aprovado = calcular_media_acima_6(medias);
    printf("Quantidade de notas acima de 6 = %d\n", aprovado);

    reprovado = calcular_media_abaixo_6(medias);
    printf("Quantidade de notas abaixo de 6 = %d\n", reprovado);
}
