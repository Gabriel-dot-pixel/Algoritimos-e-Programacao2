#include <stdio.h>
#include "estruturas.h"
#include "alunos_arquivo.h"
#include "alunos_interface.h"

int apresentar_menu()
{
    int op;
    do {
        printf("Quantidade de registros = %d\n", retorna_quant_reg());
        printf("1 - Inclusao\n");
        printf("2 - Relatorio\n");
        printf("3 - Pesquisa\n");
        printf("4 - Alterar\n");
        printf("5 - Excluir\n");
        printf("0 - Sair\n\n");
        printf("Digite a opcao: ");
        scanf("%d", &op);
        if (op < 0 || op > 5)
            printf("Opcao inválida. Selecione outra.\n\n");
    } while (op < 0 || op > 5);
    return op;
}

void main()
{
    int op;

    printf("\n\n");

    op = apresentar_menu();
    while (op != 0)
    {
        switch(op)
        {
            case 1: cadastrar_alunos();
                    break;

            case 2: apresentar_todos();
                    break;

            case 3: pesquisar_prontuario();
                    break;

            case 4: alterar_aluno();
                    break;

            case 5: excluir_aluno();
                    break;
        }
        op = apresentar_menu();
    }
}




