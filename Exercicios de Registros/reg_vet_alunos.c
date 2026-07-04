/*
Defina uma estrutura ALUNO contendo nome, nota1 e nota2. Em
seguida, cadastre 20 alunos e calcule a media das notas,
apresentando a situação (aprovado (media>=6) ou reprovado)
*/
#include<stdio.h>
#define T 30    // tamanho maximo do campo nome
#define TAM 2  // 20 alunos

//define a estrutura aluno
struct aluno
{
    char nome[T];
    float nota1;
    float nota2;
};

/*
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

void ler_vetor(struct aluno x[])
{
   for (int i=0;i<TAM;i++)
   {
      x[i]=ler();
   }
}
*/

void ler_vetor(struct aluno x[])
{
    int i;
    for (i=0; i<TAM; i++)
    {
        printf("nome do aluno: ");
        fflush(stdin); // limpar o buffer
        fgets(x[i].nome,T,stdin);
        printf("nota 1:");
        scanf("%f",&x[i].nota1);
        printf("nota 2:");
        scanf("%f",&x[i].nota2);
    }
}

void verificar_situacao (float m)
{
    if (m>=6)
    {
        printf("aprovado!!\n");
    }
    else
    {
        printf("reprovado!!\n");
    }
}


void calcular_media (struct aluno x[])
{
    float media;
    int i;
    for (i=0; i<TAM; i++)
    {
        media = (x[i].nota1 + x[i].nota2)/2;
        // chamando função para verificar a media
        // e apresentar a situação (aprovado ou reprovado)
        verificar_situacao(media);
        printf("media do aluno %d = %.2f\n",i+1,media);
    }
}

void apresentar_vetor(struct aluno x[])
{
    int i;
    for (i=0; i<TAM; i++)
    {
        printf("nome = %s\n",x[i].nome);
        printf("nota 1= %.2f\n", x[i].nota1);
        printf("nota 2= %.2f\n", x[i].nota2);
    }
}

void main()
{
    struct aluno alunos[TAM]; //cria vetor alunos do tipo struct aluno
    float media_final;
    // chamada da função ler_vetor()
    ler_vetor(alunos);
    // chamada da função calcular_media()
    calcular_media(alunos);
    // chamada da função apresentar_vetor()
    apresentar_vetor(alunos);
}
