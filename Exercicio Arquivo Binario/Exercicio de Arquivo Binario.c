#include <stdio.h>

struct funcionario{

    int id;
    char nome[30];
    float salario;
    int ativo;
};

void criar_funcionario()
{
    struct funcionario cadastrado;
    FILE *f;
    f = fopen("exercicio_binario.dat", "ab");

    printf("Por favor me informe o id do funcionario: ");
    scanf("%d", &cadastrado.id);

    printf("Por favor digite agora o nome deste funcionario: ");
    scanf("%s", &cadastrado.nome);

    printf("Por favor por ultimo me informe agora o salario deste funcionario: ");
    scanf("%f", &cadastrado.salario);

    cadastrado.ativo = 1;

    fwrite(&cadastrado,sizeof(cadastrado),1,f);
    fclose(f);

}

void ler_funcionarios()
{
   struct funcionario cadastrado;
    FILE *f;

    f = fopen("exercicio_binario.dat", "rb");

    if(!f)
    {
        printf("O arquivo nao existe!\n");
    }

    while(fread(&cadastrado,sizeof(struct funcionario),1,f))
    {
        printf("\n");
        printf("Id do funcionario: %d\n", cadastrado.id);
        printf("Nome do funcionario: %s\n", cadastrado.nome);
        printf("Salario do funcionario: R$ %.2f\n", cadastrado.salario);
        printf("Status do funcionario: %d\n", cadastrado.ativo);
        printf("\n");
    }

    fclose(f);
}

void atualizar_funcionario()
{

    int id_funcionario;
    struct funcionario cadastrado;
    FILE *f;

    f = fopen("exercicio_binario.dat", "rb+");

    if(!f)
    {
        printf("O arquivo nao existe!\n");
    }

    printf("Me informe o id do funcionario que voce deseja alterar: ");
    scanf("%d", & id_funcionario);

    while(fread(&cadastrado,sizeof(struct funcionario),1,f))
    {
        if(cadastrado.id == id_funcionario && cadastrado.ativo == 1)
        {

            printf("\n");
            printf("Nome do funcionario: ");
            scanf("%s", &cadastrado.nome);

            printf("Salario do funcionario: ");
            scanf("%f", &cadastrado.salario);

            fseek(&cadastrado, -sizeof(struct funcionario), SEEK_CUR);
            fwrite(&cadastrado, sizeof(struct funcionario), 1, f);
        }
    }

    fclose(f);

}

void deletar_logicamente()
{

    struct funcionario cadastrado;
    FILE *f;
    int id_funcionario;

    f = fopen("exercicio_binario.dat", "rb");

    printf("Digite o id do funcionario que deseja: ");
    scanf("%d", &id_funcionario);

    while(fread(&cadastrado, sizeof(struct funcionario), 1, f))
    {
        if(id_funcionario == cadastrado.id)
        {
            cadastrado.ativo = 0;

            fseek(&cadastrado, -sizeof(struct funcionario), SEEK_CUR);
            fwrite(&cadastrado, sizeof(struct funcionario), 1, f);
        }
    }

    fclose(f);
}

void main()
{

    int x, op = -1;

    do
    {
        printf("_________________Menu de Opcoes_________________\n");
        printf("1) Cadastrar Funcionario.\n");
        printf("2) Mostrar todos os funcionarios ja registrados.\n");
        printf("3) Atualizar algum funcionario ja cadastrado.\n");
        printf("4) Deletar logicamente algum funcionario.\n");
        printf("5) Deletar fisicamente os funcionrios.\n");
        printf("0) Sair do menu.\n");
        printf("Digite a opcao desejada: \n");
        scanf("%d", &op);

        switch(op)
        {

        case 1:
            criar_funcionario();
            printf("Funcionario cadastrado com sucesso!\n");

            break;

        case 2:

            ler_funcionarios();

            break;

        case 3:

            atualizar_funcionario();

            printf("Funcionario alterado com sucesso!\n");

            break;

        case 4:

            deletar_logicamente();

            printf("Funcionario excluido logicamente com sucesso!\n");

            break;

        case 5:

            printf("Funcionario(s) excluido(s) fisicamente com sucesso!\n");

            break;

        case 0:

            printf("Saindo....................................................\n");

            break;

        }
    }while(op != 0);
}
