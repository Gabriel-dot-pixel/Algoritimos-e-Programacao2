#include <stdio.h>

// lendo notas de uma prova
// parametros são valores que serão utilizados em outros trechos do programa, ou, valores essenciais para a execução da função
void ler_notas(float notas[])
{

    int i;

    for(i=0; i<10; i++)
    {
        printf("\nNota do aluno %d: ", i+1);
        scanf("%f", &notas[i]);
    }

}

void calc_media_aluno(float nota1[10], float nota2[10], float medias[])
{

    int i;

    for(i=0; i<10; i++)
    {
        medias[i] = (nota1[i] + nota2[i]) / 2;
    }
}

// a partir das medias calculadas, calcular a media da turma
float calc_media_turma(float medias[]){

    float media, soma;
    int i;

    soma = 0;
    for(i=0; i<10; i++){
        soma += medias[i];
    }
    media = soma/10;

    return media;
}

void apresentar_notas(float notas[])
{

    int i;

    for(i=0; i<10; i++)
    {
        printf("\nNota do aluno %2d - %6.2f\n", i+1, notas[i]);
    }

}


// determinar a quantidade de alunos com nota maior ou igual a 6
int calc_acima6(float notas[])
{

    int quant, i;

    quant=0;
    for(i=0; i<10; i++)
    {
        if(notas[i] >= 6)
        {
            quant++;
        }
    }


    return quant;
}

// determinar a quantidade de alunos com nota menor que 6
int calc_abaixo6(float medias[])
{
    return 10 - calc_acima6(medias);
}

void main()
{
    float nota1[10], nota2[10], medias[10];
    int i;

    printf("Digite as notas na primeira avaliacao");
    ler_notas(nota1); // apos a execução da função nota1 tera valores

    printf("\nDigite as notas na segunda avaliacao");
    ler_notas(nota2); // apos a execução da função nota2 tera valores

    printf("\nNotas da primeira avaliacao");
    apresentar_notas(nota1);

    printf("\nNotas da segunda avaliacao");
    apresentar_notas(nota2);

    printf("\nNa primeira avaliacao %d alunos tiveram notas acima de 6\n", calc_acima6(nota1));

    printf("\nNa segunda avaliacao %d alunos tiveram notas acima de 6\n", calc_acima6(nota2));

    printf("\nNa primeira avaliacao %d alunos tiveram notas abaixo de 6\n", calc_abaixo6(nota1));

    printf("\nNa segunda avaliacao %d alunos tiveram notas abaixo de 6\n", calc_abaixo6(nota2));

//     calcula a media de cada um dos alunos
    calc_media_aluno(nota1, nota2, medias);

    printf("\n Media Final dos alunos\n");
    apresentar_notas(medias);

    // calcula a media da turma
    calc_media_turma(medias);

    printf("\nMedia da turma = %.2f\n", calc_media_turma(medias));
}
