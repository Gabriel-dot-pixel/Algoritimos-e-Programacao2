#include <stdio.h>

/**
Fazer um programa em linguagem C capaz de trabalhar com operação sobre vetores inteiros.
fazer um menu de opções que permita que o usuário selecione a operação a ser realizada, contendo as seguintes operações:
a) Ler dois vetores inteiros a e b, com 5 elementos; x

b) Colocar os elementos dos dois vetores a e b, em um terceiro vetor c com tamanho de 10 elementos; x

c) Imprimir qual dos dois (a e b) tem a maior soma de elementos; x

d) Multiplicar os elementos do vetor c (tamanho 10) por um valor x (inteiro) digitado pelo usuário e apresentar esse vetor; x

e) Trocar os elementos entre os vetores a e b. x

f) Apresentar os elementos dos vetores a e b.
*/

void ler_vetor(int v[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        printf("Digite o elemento %d: ", i);
        scanf("%d", &v[i]);
    }
}

void juntar_vetores(int a[], int b[], int c[]) {
    int i;
    for (i = 0; i < 5; i++) {
        c[i] = a[i];
    }
    for (i = 0; i < 5; i++) {
        c[i + 5] = b[i];
    }
}

int somar_vetor(int v[], int tamanho) {
    int soma = 0, i;
    for (i = 0; i < tamanho; i++) {
        soma += v[i];
    }
    return soma;
}

void multiplicar_vetor(int v[], int tamanho, int x) {
    int i;
    for (i = 0; i < tamanho; i++) {
        v[i] = v[i] * x;
    }
}

void trocar_elementos(int a[], int b[], int tamanho) {
    int i, aux;
    for (i = 0; i < tamanho; i++) {
        aux = a[i];
        a[i] = b[i];
        b[i] = aux;
    }
}

void imprimir_vetor(int v[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void main() {
    int a[5], b[5], c[10];
    int opc;
    int x;
    int lidos = 0; // flag para saber se já leu os vetores A e B

    do {
        printf("\n===== OPERADOR DE VETORES IFSP =====\n");
        printf("1) Ler vetores A e B\n");
        printf("2) Formar vetor C com A e B\n");
        printf("3) Mostrar qual vetor (A ou B) tem a maior soma\n");
        printf("4) Multiplicar elementos de C por um valor X\n");
        printf("5) Trocar elementos entre A e B\n");
        printf("6) Mostrar elementos de A e B\n");
        printf("0) Sair\n");
        printf("Escolha: ");
        scanf("%d", &opc);

        switch (opc) {
            case 1:
                printf("\nLendo vetor A:\n");
                ler_vetor(a, 5);
                printf("Lendo vetor B:\n");
                ler_vetor(b, 5);
                lidos = 1;
                break;

            case 2:
                if (lidos) {
                    juntar_vetores(a, b, c);
                    printf("Vetor C formado: ");
                    imprimir_vetor(c, 10);
                } else {
                    printf("Primeiro leia os vetores A e B (opcao 1).\n");
                }
                break;

            case 3:
                if (lidos) {
                    int somaA = somar_vetor(a, 5);
                    int somaB = somar_vetor(b, 5);
                    printf("Soma de A = %d, Soma de B = %d\n", somaA, somaB);
                    if (somaA > somaB) {
                        printf("Vetor A tem a maior soma.\n");
                    } else if (somaB > somaA) {
                        printf("Vetor B tem a maior soma.\n");
                    } else {
                        printf("As somas sao iguais.\n");
                    }
                } else {
                    printf("Primeiro leia os vetores A e B (opcao 1).\n");
                }
                break;

            case 4:
                if (lidos) {
                    juntar_vetores(a, b, c);
                    printf("Digite o valor X para multiplicar: ");
                    scanf("%d", &x);
                    multiplicar_vetor(c, 10, x);
                    printf("Vetor C multiplicado: ");
                    imprimir_vetor(c, 10);
                } else {
                    printf("Primeiro leia os vetores A e B (opcao 1).\n");
                }
                break;

            case 5:
                if (lidos) {
                    trocar_elementos(a, b, 5);
                    printf("Os vetores A e B foram trocados!\n");
                } else {
                    printf("Primeiro leia os vetores A e B (opcao 1).\n");
                }
                break;

            case 6:
                if (lidos) {
                    printf("Vetor A: ");
                    imprimir_vetor(a, 5);
                    printf("Vetor B: ");
                    imprimir_vetor(b, 5);
                } else {
                    printf("Primeiro leia os vetores A e B (opcao 1).\n");
                }
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida! Digite uma opcao entre 0 e 6!\n");
        }

    } while (opc != 0);
}
