#include <stdio.h>
#include <stdlib.h>

typedef float tp_real;

typedef struct {
    char pront[10], nome[50], curso[5];
    tp_real media, freq;
} tp_aluno;

void apresentar_aluno(tp_aluno a)
{
  printf("Prontuario...: %s\n", a.pront);
  printf("Nome.........: %s\n", a.nome);
  printf("Curso........: %s\n", a.curso);
  printf("Media........: %6.2f\n", a.media);
  printf("Frequencia...: %6.2f\n", a.freq);
}

tp_aluno importar()
{
    FILE *arquivo;
    tp_aluno a;
    char texto[30];

    arquivo = fopen("dados_alunos.txt", "r");
    if (arquivo != NULL)
    {
        fgets(a.pront, 10, arquivo);
        fgets(a.nome, 50, arquivo);
        fgets(a.curso, 5, arquivo);
        fgets(texto, 30, arquivo);
        a.media = atof(texto);
        fgets(texto, 30, arquivo);
        a.freq = atof(texto);
        fclose(arquivo);
    }
    else
    {
        printf("\nNao foi possivel abrir o arquivo\n");
    }
    return a;
}

void main()
{
    tp_aluno a;
    a = importar();
    printf("\n\n");
    apresentar_aluno(a);
}
