#include <stdio.h>

void main()
{
    float nota1[10], nota2[10], media_aluno[10], media_global;
    int i, j, k, l;

    for(i=0; i<10; i++)
    {
        printf("\nNota 1 do aluno %d: ", i+1);
        scanf("%f", &nota1[i]);
    }

    for(j=0; j<10; j++)
    {
        printf("\nNota 2 do aluno %d: ", j+1);
        scanf("%f", &nota2[j]);
    }

    for(k=0; k<10; k++)
    {
        media_aluno[k] = (nota1[k] + nota2[k])/2;
        printf("Media do aluno %d - %10.2f\n", k+1, media_aluno[k]);
    }

    for(l=0; l<10; l++)
    {
        media_global = (media_aluno[l] + media_aluno[l+1])/2;
    }
    printf("\nMedia global da turma: %10.2f", media_global);
}
