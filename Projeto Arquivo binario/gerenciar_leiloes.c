//Gabriel Marinho e Robert

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "estrutura_leiloes.h"
#include "leiloes_interface.h"

int apresentar_menu()
{
    int op;
    do
    {
        printf("\n======= Leilao LeiloaTudoAteVc =======\n");
        printf("1 - Incluir Novo Leilao\n");
        printf("2 - Alterar Leilao\n");
        printf("3 - Excluir Logicamente um Leilao\n");
        printf("4 - Excluir Fisicamente um Leilao\n");
        printf("5 - Recuperar um Leilao\n");
        printf("6 - Pesquisar um Leilao\n");
        printf("7 - Apresentar todos os Leiloes\n");
        printf("8 - Incluir um Lance\n");
        printf("9 - Finalizar Leilao\n");
        printf("10 - Relatorio Produtos em Aberto\n");
        printf("11 - Relatorio Produtos Finalizados\n");
        printf("0 - Sair\n\n");
        printf("Digite a opcao: ");
        scanf("%d", &op);
        if (op < 0 || op > 11)
        {
            printf("Opcao invalida. Selecione outra.\n\n");
        }
    }
    while (op < 0 || op > 11);
    return op;
}

void main()
{
    int op;
    tp_produto p;

    printf("\n\n");

//    printf("%d", validar_se_tem_algo_arquivo());

    op = apresentar_menu();
    while (op != 0)
    {
        switch(op)
        {
        case 1:
            cadastrar_produtos();
            break;

        case 2:
            alterar_produto();
            break;

        case 3:
            excluir_produto_logicamente();
            break;

        case 4:
            excluir_produtos_fisicamente();
            break;

        case 5:
            recuperar_produto();
            break;

        case 6:
            pesquisar_produto();
            break;

        case 7:
            apresentar_todos_produtos();
            break;

        case 8:
            incluir_lance();
            break;

        case 9:
            finalizar_produto();
            break;

        case 10:
            apresentar_produtos_abertos();
            break;

        case 11:
            apresentar_produtos_finalizados();
            break;

        case 0:
            break;

        default:
            printf("Opcao nao existente!\n");
        }
        op = apresentar_menu();
    }
}
