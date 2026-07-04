/**
Fazer um programa capaz de ler um arquivo texto .css contendo formatação CSS de páginas web e apresentar somente os elementos, classes e identificadores que estão sendo formatados.
No texto apresentado deve-se identificar o tipo de formatação, se iniciar por ponto é uma classe, se iniciar por # é um identificador e se não tiver nada antes é um elemento HTML.
Lembrando que os elementos iniciam no primeira coluna da linha.
*/
#include <stdio.h>
#include <string.h>

void main()
{
    char texto[100];
    char elemento[100], classe[100], identificador[100];

    FILE *arq;

    arq = fopen("teste.css", "r");

    if(arq == NULL)
    {
        printf("Nao foi possivel abrir o arquivo\n");
    }
    else
    {
        fgets(texto, 199, arq);

        while(!feof(arq))
        {
            if(strchr(texto, '{'))
                {
                    if(texto[0] == '.')
                    {
                        sscanf(texto, "%[^ {]", classe);
                    }

                    if(texto[0] == '#')
                    {
                        sscanf(texto, "%[^ {]", identificador);
                    }

                    if((texto[0] >= 'a' && texto[0] <= 'z') || (texto[0] >= 'A' && texto[0] <= 'Z'))
                    {
                        sscanf(texto, "%[^ {]", elemento);
                    }
                }

            fgets(texto, 199, arq);
        }

        fclose(arq);

        printf("Classe.........: %s\n", classe);
        printf("Identificador..: %s\n", identificador);
        printf("Elemento.......: %s\n", elemento);
    }
}
