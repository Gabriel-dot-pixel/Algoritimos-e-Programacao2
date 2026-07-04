#include <stdio.h>
/**
Na sua turma será realizada a eleição para representante de sala, as turmas tem no máximo 50 alunos, os candidatos foram:
Marcos da Silva e a Ana Claudia de Alcantara. Para controlar a eleição deve ser implementado um programa em linguagem C
capaz de representar uma urna eletrônica, onde todos os alunos da turma poderão votar, sendo que as opções são
M – Marcos da Silva, A - Ana Claudia de Alcantara, B - Branco, X – para finalizar e qualquer outro valor é um voto nulo.
Após a finalização da eleição deve-se apresentar um resumo contendo:

a) Total de alunos que votaram; x

b) Total de votos para o Marcos da Silva; x

c) Total de votos para a Ana Claudia; x

d) Quantidade de votos brancos; x

e) Quantidade de votos nulos; x

f) Percentual de votos válidos, ou seja, sem contar brancos e nulos; x

g) Percentual de votos de cada um dos candidatos, considerando apenas os votos válidos; x

h) Caso a quantidade de votos válidos não alcance 50% deve-se apresentar a mensagem “A eleição não foi válida”; x

i) Se a eleição for válida apresentar o nome do novo representante de sala ou se houve empate. x

*/
void ler_votos(char quant_votos[], int *num_al)
{

    int i;

    printf("Digite a quantidade de alunos na turma (maximo 50 alunos):");
    scanf("%d", num_al);

    for(i=0; i<*num_al; i++)
    {
        printf("\nVoto do aluno %d: ", i+1);
        scanf(" %c", &quant_votos[i]);
    }
}

int contar_votos(char votos[], int num_al, char tipo)
{
    int soma = 0;
    for (int i = 0; i < num_al; i++)
    {
        if (tipo == 'N')   // votos nulos
        {
            if (votos[i] != 'M' && votos[i] != 'A' && votos[i] != 'B')
                soma++;
        }
        else if (votos[i] == tipo)
        {
            soma++;
        }
    }
    return soma;
}

int total_votos(char votos[], int num_al)
{
    return num_al;
}

int total_votos_marcos(char votos[], int num_al)
{

    int soma, i;

    soma=0;
    for(i=0; i<num_al; i++)
    {
        if (votos[i] == 'M')
        {
            soma++;
        }
    }

    return soma;
}

int total_votos_ana(char votos[], int num_al)
{

    int soma, i;

    soma=0;
    for(i=0; i<num_al; i++)
    {
        if (votos[i] == 'A')
        {
            soma++;
        }
    }

    return soma;
}

int total_votos_branco(char votos[], int num_al)
{

    int soma, i;

    soma=0;
    for(i=0; i<num_al; i++)
    {
        if (votos[i] == 'B')
        {
            soma++;
        }
    }

    return soma;
}

int total_votos_nulo(char votos[], int num_al)
{

    int soma, i;

    soma=0;
    for(i=0; i<num_al; i++)
    {
        if (votos[i] != 'M' && votos[i] != 'A' && votos[i] != 'B')
        {
            soma++;
        }
    }

    return soma;
}

float percentual(int qtd, int total)
{
    if (total == 0) return 0;
    return (float)qtd / total * 100;
}

float percentual_votos_marcos(char votos[], int num_al)
{

    int soma, i;
    float percent;

    soma=0;
    for(i=0; i<num_al; i++)
    {
        if (votos[i] == 'M')
        {
            soma++;
        }
    }

    percent = (float) soma / num_al;

    return percent;
}

float percentual_votos_ana(char votos[], int num_al)
{

    int soma, i;
    float percent;

    soma=0;
    for(i=0; i<num_al; i++)
    {
        if (votos[i] == 'A')
        {
            soma++;
        }
    }

    percent = (float) soma / num_al;

    return percent;
}

void validar_eleicao(char votos[], int num_al)
{
    int votos_marcos = contar_votos(votos, num_al, 'M');
    int votos_ana = contar_votos(votos, num_al, 'A');
    int votos_branco = contar_votos(votos, num_al, 'B');
    int votos_nulo = contar_votos(votos, num_al, 'N');

    int votos_validos = votos_marcos + votos_ana;

    if (votos_validos < num_al / 2.0)
    {
        printf("\nA eleição não foi válida.\n");
    }
    else
    {
        float perc_marcos = percentual(votos_marcos, votos_validos);
        float perc_ana = percentual(votos_ana, votos_validos);

        if (perc_marcos > perc_ana)
        {
            printf("\nMarcos da Silva foi eleito com %.2f%% dos votos validos.\n", perc_marcos);
        }
        else if (perc_ana > perc_marcos)
        {
            printf("\nAna Claudia foi eleita com %.2f%% dos votos validos.\n", perc_ana);
        }
        else
        {
            printf("\nHouve empate entre os candidatos.\n");
        }
    }
}


void main()
{

    char votos[50];
    int alunos;

    printf("--- ELEICOES IFSP ---\n");
    ler_votos(votos, &alunos);

    int votos_marcos = contar_votos(votos, alunos, 'M');
    int votos_ana = contar_votos(votos, alunos, 'A');
    int votos_branco = contar_votos(votos, alunos, 'B');
    int votos_nulo = contar_votos(votos, alunos, 'N');

    printf("\nTotal de votos: %d", alunos);
    printf("\nVotos para Marcos da Silva: %d", votos_marcos);
    printf("\nVotos para Ana Claudia: %d", votos_ana);
    printf("\nVotos em branco: %d", votos_branco);
    printf("\nVotos nulos: %d", votos_nulo);

    printf("\nPercentual de votos validos: %.2f%%", percentual(votos_marcos + votos_ana, alunos));
    printf("\nPercentual de votos Marcos: %.2f%%", percentual(votos_marcos, votos_marcos + votos_ana));
    printf("\nPercentual de votos Ana: %.2f%%", percentual(votos_ana, votos_marcos + votos_ana));

    validar_eleicao(votos, alunos);

}
