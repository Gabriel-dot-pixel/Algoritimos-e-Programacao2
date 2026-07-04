#include <stdio.h>

/**
Fazer um programa em linguagem C utilizando funções, que trabalhe com vetores de caracteres de até 50 posições e seja capaz de:
a) Excluir um caracter de uma determinada posição; x

b) Incluir um caracter em uma determinada posição; x

c) Copiar uma parte dos caracteres para dentro de outro vetor, para isso deve-se conhecer a posição inicial e o final a ser copiada; x

d) Copiar a última palavra para outro vetor; x

e) Copiar a primeira palavra para outro vetor; x

f) Retirar os espaços em branco repetidos; x

g) Contar a quantidade de palavras; x

h) Contar a quantidade de vogais. x
*/

int comprimento(char str[])
{
    int i = 0;
    while (str[i] != '\0') i++;
    return i;
}

char converter_minusculo(char c)
{
    if (c >= 'A' && c <= 'Z') return c + 32;
    return c;
}

void excluir_caractere(char str[], int pos)
{
    int i = pos;
    while (str[i] != '\0')
    {
        str[i] = str[i+1];
        i++;
    }
}

void incluir_caractere(char str[], char c, int pos)
{
    int len = comprimento(str);
    if (len >= 49 || pos < 0 || pos > len) return;

    for (int i = len; i >= pos; i--)
    {
        str[i+1] = str[i];
    }
    str[pos] = c;
}

void copiar_intervalo(char origem[], char destino[], int ini, int fim)
{
    int j = 0;
    for (int i = ini; i <= fim && origem[i] != '\0'; i++)
    {
        destino[j++] = origem[i];
    }
    destino[j] = '\0';
}

void copiar_ultima_palavra(char origem[], char destino[])
{
    int len = comprimento(origem);
    int i = len - 1;

    while (i >= 0 && origem[i] == ' ') i--;
    int fim = i;
    while (i >= 0 && origem[i] != ' ') i--;
    copiar_intervalo(origem, destino, i + 1, fim);
}

void copiar_primeira_palavra(char origem[], char destino[])
{
    int i = 0;
    while (origem[i] == ' ') i++;
    int ini = i;
    while (origem[i] != ' ' && origem[i] != '\0') i++;
    copiar_intervalo(origem, destino, ini, i - 1);
}

void remover_espacos_repetidos(char str[])
{
    int i = 0, j = 0;
    int espaco_anterior = 0;

    while (str[i] != '\0')
    {
        if (str[i] != ' ')
        {
            str[j++] = str[i];
            espaco_anterior = 0;
        }
        else if (!espaco_anterior)
        {
            str[j++] = str[i];
            espaco_anterior = 1;
        }
        i++;
    }
    str[j] = '\0';
}

int contar_palavras(char str[])
{
    int i = 0, em_palavra = 0, cont = 0;
    while (str[i] != '\0')
    {
        if (str[i] != ' ' && em_palavra == 0)
        {
            em_palavra = 1;
            cont++;
        }
        else if (str[i] == ' ')
        {
            em_palavra = 0;
        }
        i++;
    }
    return cont;
}

// h) Contar vogais
int contar_vogais(char str[])
{
    int i = 0, cont = 0;
    while (str[i] != '\0')
    {
        char c = converter_minusculo(str[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            cont++;
        }
        i++;
    }
    return cont;
}

void main()
{
    char texto[50];
    char copia[50];

    printf("--- MODIFICADOR DE STRING IFSP ---\n");
    printf("Digite um texto (ate 49 caracteres):\n");
    scanf(" %[^\n]", texto);

    printf("\nTexto digitado: \"%s\"\n", texto);

    excluir_caractere(texto, 2);
    printf("Apos excluir posicao 2: \"%s\"\n", texto);

    incluir_caractere(texto, 'X', 4);
    printf("Apos incluir 'X' na posicao 4: \"%s\"\n", texto);

    copiar_intervalo(texto, copia, 0, 6);
    printf("Copia do intervalo 0 a 6: \"%s\"\n", copia);

    copiar_ultima_palavra(texto, copia);
    printf("Ultima palavra: \"%s\"\n", copia);

    copiar_primeira_palavra(texto, copia);
    printf("Primeira palavra: \"%s\"\n", copia);

    remover_espacos_repetidos(texto);
    printf("Sem espacos repetidos: \"%s\"\n", texto);

    printf("Quantidade de palavras: %d\n", contar_palavras(texto));
    printf("Quantidade de vogais: %d\n", contar_vogais(texto));
}
