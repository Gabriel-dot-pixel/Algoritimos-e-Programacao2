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

void importar(tp_aluno alunos[], int *tl)
{
    FILE *arquivo;
    char texto[30];
    int i;

    arquivo = fopen("dados_alunos.txt", "r");
    if (arquivo != NULL)
    {
        /// peguei do arquivo a quantidade de alunos
        /// e coloquei no tl
        fgets(texto, 30, arquivo);
        *tl = atoi(texto);

        for(i=0; i<*tl; i++)
        {
            fgets(alunos[i].pront, 10, arquivo);
            fgets(alunos[i].nome, 50, arquivo);
            fgets(alunos[i].curso, 5, arquivo);
            fgets(texto, 30, arquivo);
            alunos[i].media = atof(texto);
            fgets(texto, 30, arquivo);
            alunos[i].freq = atof(texto);
        }
        fclose(arquivo);
    }
    else
    {
        printf("\nNao foi possivel abrir o arquivo\n");
    }
}

void apresentar_todos(tp_aluno alunos[], int tl)
{
    int i;
    for(i=0; i<tl; i++)
    {
        apresentar_aluno(alunos[i]);
        printf("\n");
    }
}

void main()
{
    tp_aluno alunos[10];
    int tl;
    importar(alunos, &tl);
    printf("\n\n");
    apresentar_todos(alunos, tl);
}
