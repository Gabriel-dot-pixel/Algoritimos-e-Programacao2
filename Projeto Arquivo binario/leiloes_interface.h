#include "leiloes_arquivo.h"

//função para remover o \n do final da string
void limpar_string(char string[])
{
    if(string[strlen(string)-1]=='\n')
    {
        string[strlen(string)-1]='\0';
    }
}

//função para ler os dados de um produto
tp_produto ler_produto()
{
    tp_produto p;

    //validação do codigo do produto
    do
    {
        printf("Codigo do Produto: ");
        scanf("%d", &p.codigo);

        if(p.codigo < 0)
        {
            printf("O Codigo Precisa ser um Valor Positivo!\n");
        }
    }
    while(p.codigo < 0);

    ///Limpar o buffer do teclado
    fflush(stdin);
    printf("Nome do Produto..: ");
    fgets(p.nome_produto,45,stdin);
    limpar_string(p.nome_produto);

    printf("Valor Inicial....: ");
    scanf("%f", &p.valor_inicial);

    return p;
}

//função para cadastrar um produto
void cadastrar_produtos()
{
    tp_produto produto;
    char continua;

    do
    {
        produto = ler_produto();
        incluir(produto);

        //validação da resposta do usuario (S ou N)
        do
        {
            printf("\nCadastrar outro Leilao? <S/N>: ");
            scanf(" %c", &continua);
            continua = toupper(continua);

            if(continua != 'S' && continua != 'N')
            {
                printf("Digite apenas S ou N!\n");
            }
        }
        while(continua != 'S' && continua != 'N');
    }
    while (continua == 'S');
}

//função para apresentar a linha da tabela
void apresentar_linha(tp_produto p)
{
    printf("%0.6d %-30s %-7.2f %0.6d %c   %-30s %-20s\n",
           p.codigo, p.nome_produto, p.valor_inicial, p.lance, p.situacao, p.nome_cliente, p.telefone);
}

//funcao para apresentar o cabecalho da tabela
void apresentar_cabecalho()
{
    printf("%-6s %-30s %-6s  %-6s %-3s %-30s %-20s\n",
           "Codigo", "Produto", "Valor", "Lances", "Situacao", "Nome", "Telefone");
}

void apresentar_todos_produtos()
{
    int i, tl;
    tp_produto p;

    tl = retornar_quantidade_structs();

    apresentar_cabecalho();

    for(i=0; i<tl; i++)
    {
        p = pegar_produto(i);

        if(p.statuts == 1)
        {
            apresentar_linha(p);
        }
    }
}

int retornar_qtde_lances_abertos()
{
    int tl, i, cont = 0;
    tp_produto p;

    tl = retornar_quantidade_structs();

    for(i=0; i<tl; i++)
    {
        p = pegar_produto(i);

        if(p.statuts == 1 && p.situacao == 'A')
        {
            cont += p.lance;
        }
    }

    return cont;
}

int retornar_qtde_lances_finalizados()
{
    int tl, i, cont = 0;
    tp_produto p;

    tl = retornar_quantidade_structs();

    for(i=0; i<tl; i++)
    {
        p = pegar_produto(i);

        if(p.statuts == 1 && p.situacao == 'F')
        {
            cont += p.lance;
        }
    }

    return cont;
}

int retornar_qtde_situacoes(char sit)
{
    int tl, i, cont = 0;
    tp_produto p;

    tl = retornar_quantidade_structs();

    for(i=0; i<tl; i++)
    {
        p = pegar_produto(i);

        if(p.statuts == 1 && p.situacao == sit)
        {
            cont++;
        }
    }

    return cont;
}

float retornar_total_arrecadado()
{
    int tl, i;
    float cont = 0.0;
    tp_produto p;

    tl = retornar_quantidade_structs();

    for(i=0; i<tl; i++)
    {
        p = pegar_produto(i);

        if(p.statuts == 1 && p.situacao == 'F')
        {
            cont += p.valor_inicial;
        }
    }

    return cont;
}

void apresentar_produtos_finalizados()
{
    int tl, i, lances, ativos;
    float arrecadado;
    tp_produto p;

    tl = retornar_quantidade_structs();

    apresentar_cabecalho();
    for(i=0; i<tl; i++)
    {
        p = pegar_produto(i);

        if(p.statuts == 1 && p.situacao == 'F')
        {
            apresentar_linha(p);
        }
    }

    lances = retornar_qtde_lances_finalizados();
    ativos = retornar_qtde_situacoes('F');
    arrecadado = retornar_total_arrecadado();

    printf("Quantidade Total de Lances: %d\n", lances);
    printf("Quantidade Total de Leiloes: %d\n", ativos);
    printf("Total Arrecadado: R$ %.2f", arrecadado);
}


void apresentar_produtos_abertos()
{
    int tl, i, lances, ativos;
    tp_produto p;

    tl = retornar_quantidade_structs();

    apresentar_cabecalho();
    for(i=0; i<tl; i++)
    {
        p = pegar_produto(i);

        if(p.statuts == 1 && p.situacao == 'A')
        {
            apresentar_linha(p);
        }
    }

    lances = retornar_qtde_lances_abertos();
    ativos = retornar_qtde_situacoes('A');

    printf("Quantidade Total de Lances: %d\n", lances);
    printf("Quantidade Total de Leiloes: %d\n", ativos);
}

void apresentar_produto(tp_produto p)
{
    printf("Codigo: %d\n", p.codigo);
    printf("Nome..: %s\n", p.nome_produto);
    printf("Valor.: R$ %.2f\n", p.valor_inicial);
}

void pesquisar_produto()
{
    int codigo;
    tp_produto p;
    int pos;

    printf("Digite o Codigo do Produto: ");
    scanf("%d", &codigo);
    pos = localizar_produto(codigo);
    if(pos == -1)
    {
        printf("Produto nao Localizado!\n");
    }
    else
    {
        p = pegar_produto(pos);
        if (p.statuts == 0)
        {
            printf("Produto esta Excluido ou nao Existe!\n");
        }
        else
        {
            apresentar_produto(p);
        }
    }
}

void incluir_lance()
{
    int codigo, pos;
    float valor;
    tp_produto p;

    printf("Digite o Codigo do Produto: ");
    scanf("%d", &codigo);
    pos = localizar_produto(codigo);
    if(pos == -1)
    {
        printf("Produto nao Localizado!\n");
    }
    else
    {
        p = pegar_produto(pos);
        if (p.statuts == 0)
        {
            printf("Produto esta Excluido!\n");
        }
        else
        {
            if(p.situacao == 'F')
            {
                printf("Produto esta Finalizado!\n");
            }
            else
            {
                apresentar_produto(p);
                do
                {
                    printf("Digite o valor do lance: ");
                    scanf("%f", &valor);
                    if(valor <= p.valor_inicial)
                    {
                        printf("O Valor do Lance Deve ser Maior que o Valor Inicial do Produto!\n");
                    }
                }
                while(valor <= p.valor_inicial);

                printf("Digite o nome do cliente: ");
                fflush(stdin);
                fgets(p.nome_cliente,45,stdin);
                limpar_string(p.nome_cliente);

                printf("Digite o telefone do cliente: ");
                fflush(stdin);
                fgets(p.telefone,14,stdin);
                limpar_string(p.telefone);

                p.valor_inicial = valor;
                p.lance++;

                sobreescrever_produto(p,pos);
            }
        }

    }
}

//função para alterar nome e valor de um produto
tp_produto ler_produto_alterado(tp_produto p)
{
    printf("Digtite o nome do produto: ");
    fflush(stdin);
    fgets(p.nome_produto,45,stdin);
    limpar_string(p.nome_produto);
    do
    {
        printf("Digite o valor inicial do produto: ");
        scanf("%f", &p.valor_inicial);

        if(p.valor_inicial < 0)
        {
            printf("Digite um Valor Positivo!\n");
        }
    }
    while(p.valor_inicial < 0);

    return p;
}

//função para alterar um produto
void alterar_produto()
{
    int codigo;
    tp_produto p;
    int pos;

    printf("Digite o Codigo do Produto: ");
    scanf("%d", &codigo);
    pos = localizar_produto(codigo);
    if(pos == -1)
    {
        printf("Produto nao Localizado!\n");
    }
    else
    {
        p = pegar_produto(pos);
        apresentar_produto(p);
        if (p.situacao == 'A' && p.statuts == 1)
        {
            printf("\nDigite os novos dados do produto:\n");
            p = ler_produto_alterado(p);
            sobreescrever_produto(p, pos);
        }
        else
        {
            printf("Produto Finalizado ou Excluido, nao e possivel alterar!\n");
        }
    }
}

void excluir_produto_logicamente()
{
    char excluir;
    int pos, codigo;
    tp_produto p;

    printf("Digite o Codigo do Produto: ");
    scanf("%d", &codigo);
    pos = localizar_produto(codigo);
    if(pos == -1)
    {
        printf("Produto nao Localizado!\n");
    }
    else
    {
        p = pegar_produto(pos);
        apresentar_produto(p);
        if (p.statuts == 1)
        {
            do
            {
                printf("Deseja Excluir o Produto? <S/N>: ");
                scanf(" %c", &excluir);
                excluir = toupper(excluir);

                if(excluir != 'S' && excluir != 'N')
                {
                    printf("Digite Apenas S ou N!\n");
                }
            }
            while(excluir != 'S' && excluir != 'N');
            if (excluir == 'S')
            {
                p.statuts = 0;
                sobreescrever_produto(p, pos);
                printf("Produto Excluido com Sucesso!\n");
            }
        }
        else
        {
            printf("Produto ja foi Excluido!\n");
        }
    }
}

void recuperar_produto()
{
    char excluir;
    int pos, codigo;
    tp_produto p;

    printf("Digite o Codigo do Produto: ");
    scanf("%d", &codigo);
    pos = localizar_produto(codigo);
    if(pos == -1)
    {
        printf("Produto nao Localizado!\n");
    }
    else
    {
        p = pegar_produto(pos);
        apresentar_produto(p);
        if (p.statuts == 0)
        {
            do
            {
                printf("Deseja Recuperar o Produto? <S/N>: ");
                scanf(" %c", &excluir);
                excluir = toupper(excluir);

                if(excluir != 'S' && excluir != 'N')
                {
                    printf("Digite Apenas S ou N\n");
                }
            }
            while(excluir != 'S' && excluir != 'N');

            if (excluir == 'S')
            {
                p.statuts = 1;
                sobreescrever_produto(p, pos);
                printf("Produto esta Ativo Novamente!\n");
            }
        }
        else
        {
            printf("Produto ja Estava Ativo!\n");
        }
    }
}

void finalizar_produto()
{
    int pos, codigo;
    char op;
    tp_produto p;

    printf("Digite o Codigo do Produto: ");
    scanf("%d", &codigo);
    pos = localizar_produto(codigo);
    if(pos == -1)
    {
        printf("Produto nao Localizado!\n");
    }
    else
    {
        p = pegar_produto(pos);
        if(p.statuts == 1 && p.situacao == 'A')
        {
            apresentar_produto(p);
            printf("Finalizar Produto? <S/N>: ");
            scanf(" %c", &op);
            op = toupper(op);
            if(op == 'S')
            {
                p.situacao = 'F';
                sobreescrever_produto(p, pos);
                printf("Produto Finalizado com Sucesso!\n");
            }
        }
        else
        {
            printf("Produto foi Excluido ou ja foi Finalizado!\n");
        }
    }
}
