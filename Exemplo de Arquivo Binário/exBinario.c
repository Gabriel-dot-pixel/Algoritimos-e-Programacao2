/* Desenvolver um programa, em C, para gerenciar registros de funcionários utilizando operações
CRUD (Criar, Ler, Atualizar, Deletar). O sistema deve ser capaz de armazenar informações sobre os
funcionários em um arquivo binário. Cada registro de funcionário deverá conter as seguintes
informações:
• ID: Um número inteiro único que identifica o funcionário.
• Nome: Uma string de caracteres (até 30 caracteres) que representa o nome do funcionário.
• Salário: Um valor numérico do tipo float que representa o salário do funcionário.
• Ativo: Zero para inativo e 1 para ativo;
OBS: o campo ativo deve estar com 1 na criação
Descrição das funcionalidades:
• Criar (C): Adicionar um novo funcionário ao arquivo binário;
• Ler (R): Exibir todos os registros de funcionários;
• Alterar (A): Atualizar o registro de um funcionário (alterar nome ou salário);
• Pesquisar (P): Pesquisar pelo ID do funcionário;
• Deletar (D):
• Logicamente (L): Remover um registro de funcionário;
• Fisicamente (F): Remover TODOS os registros inativos do arquivo. */

/* Desenvolver um programa, em C, para gerenciar registros de funcionários utilizando operações CRUD... */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TEXT 30
#define TF 100

typedef struct funcionario
{
    int id;
    char nome[TEXT];
    float salario;
    int ativo;
} Funcionario;


void remover_enter(char t[TEXT])
{
    int x = strlen(t);
    if (x > 0 && t[x-1] == '\n')
        t[x-1] = '\0';
}

int verificar_arquivo(char nome_file[TEXT])
{
    int ok = 1;
    FILE *f = fopen(nome_file, "rb");
    if (f == NULL)
    {
        ok=0;
    }
    fclose(f);
    return ok;
}


char ler_menu_delete()
{
    char op;
    do
    {
        printf("\n===== REMOÇÃO =====\n");
        printf("L - Remocao logica (inativar)\n");
        printf("F - Remocao fisica (limpar inativos)\n");
        printf("C - Cancelar\n");
        // fflush(stdin);
        scanf(" %c", &op);
        op = toupper(op);
        if (op!='L' && op!='F' && op!='C')
        {
            printf("Opcao invalida!\n");
        }
    }
    while(op!='L' && op!='F' && op!='C');
    return op;
}

char ler_menu()
{
    char op;
    do
    {
        printf("\n=========== MENU ==========\n");
        printf("C - Criar funcionario\n");
        printf("L - Ler arquivo\n");
        printf("A - Atualizar registro\n");
        printf("P - Pesquisar pelo ID\n");
        printf("D - Deletar (Lógica/Física)\n");
        printf("S - Sair\n");
        printf("===========================\n");
        // fflush(stdin);
        scanf(" %c", &op);
        op = toupper(op);
        if(op!='C' && op!='L' && op!='A' && op!='P' && op!='D' && op!='S')
        {
            printf("Opcao invalida!\n");
        }
    }
    while(op!='C' && op!='L' && op!='A' && op!='P' && op!='D' && op!='S');
    return op;
}


int localizar_id(char nome_file[TEXT], int idp)
{
    FILE *arq = fopen(nome_file, "rb");
    Funcionario f;
    int pos = -1, i = 0, achou = 0;
    if (arq != NULL)
    {
        while(achou == 0 && fread(&f, sizeof(Funcionario), 1, arq))
        {
            if (f.id == idp)
            {
                pos = i;
                achou = 1;
            }
            else
            {
                i++;
            }
        }
        fclose(arq);
    }
    return pos;
}


void criar(char nome_file[TEXT])
{
    FILE *arq;
    Funcionario f;
    int existe;

    if (verificar_arquivo(nome_file) == 1)
    {
        arq = fopen(nome_file, "ab");
    }
    else
    {
        arq = fopen(nome_file, "wb");
    }
    if (arq != NULL)
    {
        fflush(stdin);
        printf("Nome: ");
        fgets(f.nome, TEXT, stdin);
        remover_enter(f.nome);
        printf("ID: ");
        scanf("%d", &f.id);
        existe = localizar_id(nome_file, f.id);
        if (existe != -1)
        {
            printf("ERRO: ID já existe!\n");
        }
        else
        {
            printf("Salario: ");
            scanf("%f", &f.salario);
            f.ativo = 1;
            fwrite(&f, sizeof(Funcionario), 1, arq);
            printf("Funcionario criado!\n");
        }
        fclose(arq);
    }
}


void ler_arquivo(char nome_file[TEXT])
{
    FILE *arq = fopen(nome_file, "rb");
    Funcionario f;
    if (arq == NULL)
    {
        printf("Nao foi possivel abrir o arquivo!\n");
    }
    else
    {
        printf("\n===== LISTA DE FUNCIONARIOS =====\n");
        while(fread(&f, sizeof(Funcionario), 1, arq))
        {
            printf("-----------------------\n");
            printf("Nome: %s\n", f.nome);
            printf("ID: %d\n", f.id);
            printf("Salario: %.2f\n", f.salario);
            printf("Ativo: %d\n", f.ativo);
        }
        fclose(arq);
    }
}


void alterar(char nome_file[TEXT], int pos)
{
    FILE *arq;
    Funcionario lista[TF], f;
    int i = 0, escolha;
    char novo_nome[TEXT];
    float novo_salario;
    printf("1 - Nome\n2 - Salario\n3 - Ambos\nEscolha: ");
    scanf("%d", &escolha);
    if (escolha == 1 || escolha == 3)
    {
        fflush(stdin);
        printf("Novo nome: ");
        fgets(novo_nome, TEXT, stdin);
        remover_enter(novo_nome);
    }
    if (escolha == 2 || escolha == 3)
    {
        printf("Novo salario: ");
        scanf("%f", &novo_salario);
    }
    arq = fopen(nome_file, "rb");
    while(fread(&f, sizeof(Funcionario), 1, arq))
    {
        lista[i] = f;
        i++;
    }
    fclose(arq);
    if (escolha == 1 || escolha == 3)
    {
        strcpy(lista[pos].nome, novo_nome);
    }
    if (escolha == 2 || escolha == 3)
    {
        lista[pos].salario = novo_salario;
    }
    arq = fopen(nome_file, "wb");
    fwrite(lista, sizeof(Funcionario), i, arq);
    printf("Registro atualizado!\n");
    fclose(arq);
}


void apresentar(char nome_file[TEXT], int pos)
{
    FILE *arq = fopen(nome_file, "rb");
    Funcionario f;
    if (arq != NULL)
    {
        fseek(arq, pos * sizeof(Funcionario), SEEK_SET);
        fread(&f, sizeof(Funcionario), 1, arq);
        printf("-----------------------\n");
        printf("Nome: %s\n", f.nome);
        printf("ID: %d\n", f.id);
        printf("Salario: %.2f\n", f.salario);
        printf("Ativo: %d\n", f.ativo);
        fclose(arq);
    }
}


void remover_logico(char nome_file[TEXT], int pos)
{
    FILE *arq = fopen(nome_file, "rb+");
    Funcionario f;
    if (arq != NULL)
    {
        fseek(arq, pos * sizeof(Funcionario), SEEK_SET);
        fread(&f, sizeof(Funcionario), 1, arq);
        f.ativo = 0;
        fseek(arq, pos * sizeof(Funcionario), SEEK_SET);
        fwrite(&f, sizeof(Funcionario), 1, arq);
        printf("Funcionario inativado!\n");
        fclose(arq);
    }
}


void remover_fisico(char nome_file[TEXT])
{
    FILE *arq = fopen(nome_file, "rb");
    FILE *temp = fopen("temp.bin", "wb");
    Funcionario f;
    if (arq != NULL && temp != NULL)
    {
        while(fread(&f, sizeof(Funcionario), 1, arq))
        {
            if (f.ativo == 1)
            {
                fwrite(&f, sizeof(Funcionario), 1, temp);
            }
        }
        fclose(arq);
        fclose(temp);
        remove(nome_file);
        rename("temp.bin", nome_file);
        printf("Registros inativos removidos!\n");
    }
}


void executar(char op, char nome_file[TEXT])
{
    int id, pos;
    char subop;
    switch(op)
    {
    case 'C':
        criar(nome_file);
        break;
    case 'L':
        ler_arquivo(nome_file);
        break;
    case 'A':
        printf("ID para alterar: ");
        scanf("%d", &id);
        pos = localizar_id(nome_file, id);
        if (pos == -1)
        {
            printf("ID nao encontrado!\n");
        }
        else
        {
            alterar(nome_file, pos);
        }
        break;
    case 'P':
        printf("ID para pesquisar: ");
        scanf("%d", &id);
        pos = localizar_id(nome_file, id);
        if (pos == -1)
        {
            printf("ID nao encontrado!\n");
        }
        else
        {
            apresentar(nome_file, pos);
        }
        break;

    case 'D':
        subop = ler_menu_delete();
        switch(subop)
        {
        case 'L':
            printf("ID para inativar: ");
            scanf("%d", &id);
            pos = localizar_id(nome_file, id);
            if (pos == -1)
            {
                printf("ID nao encontrado!\n");
            }
            else
            {
                remover_logico(nome_file, pos);
            }
            break;
        case 'F':
            remover_fisico(nome_file);
            break;
        case 'C':
            break;
        }
    }
}

void main()
{
    char op, nome_file[TEXT];
    fflush(stdin);
    printf("Nome do arquivo: ");
    fgets(nome_file, TEXT, stdin);
    remover_enter(nome_file);
    do
    {
        op = ler_menu();
        if (op != 'S')
        {
            executar(op, nome_file);
        }
    }
    while(op != 'S');
}
