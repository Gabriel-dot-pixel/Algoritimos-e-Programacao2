#include <stdio.h>
#define T 30

typedef struct funcionario
{
    int id;
    char nome[T];
    float salario;
    int ativo;
} funcionario;

void criar()
{
    funcionario f;

    FILE *arq;

    arq = fopen("teste.dat","ab");

    if(arq == NULL)
    {
        printf("Nao foi possivel abrir o arquivo\n");
    }
    else
    {
        printf("Digite o ID.....: ");
        scanf("%d",&f.id);
        printf("Digite o nome...: ");
        fflush(stdin);
        fgets(f.nome,T,stdin);
        printf("Digite o salario: ");
        scanf("%f",&f.salario);
        f.ativo = 1;
        fwrite(&f,sizeof(f),3,arq);
        fclose(arq);
    }
}

void ler()
{
    funcionario f;

    FILE *arq;

    arq = fopen("teste.dat","rb");

    if(arq == NULL)
    {
        printf("Nao foi possivel abrir o arquivo\n");
    }
    else
    {
//        fread(&f,sizeof(f),3, arq);
        while(fread(&f,sizeof(f),3, arq))
        {
            printf("ID.....: %d\n",f.id);
            printf("Nome...: %s\n",f.nome);
            printf("Salario: R$ %.2f\n",f.salario);
            printf("\n");
//            fread(&f,sizeof(f),3, arq);
        }
        fclose(arq);
    }
}

void pesquisar()
{
    int id_procurado;
    funcionario f;

    FILE *arq;

    arq = fopen("teste.dat","rb");

    if(arq == NULL)
    {
        printf("Nao foi possivel abrir o arquivo\n");
    }
    else
    {
        printf("Qual ID deseja pesquisar?: ");
        scanf("%d", &id_procurado);

        fseek(arq,offset,0);
    }
}

void main()
{
    char opc;

    do
    {
        printf("\n====== CRUD de Arquivo Binario ======\n");
        printf("C - Criar\n");
        printf("R - Ler\n");
        printf("P - Pesquisar\n");
        printf("S - Sair\n");
        printf("Digite a opcao (somente letras maiusculas): ");
        scanf(" %c", &opc);

        switch(opc)
        {
        case 'C':
            criar();
            break;

        case 'R':
            ler();
            break;

        case 'P':
            pesquisar();
            break;

        case 'S':
            printf("Saindo...\n");
            break;

        default:
            printf("Opcao inexistente ou digitou uma opcao sem CapsLock ligado!\n");
        }
    }
    while(opc != 'S');




}
