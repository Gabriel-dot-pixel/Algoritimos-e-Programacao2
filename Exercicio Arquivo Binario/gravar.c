#include <stdio.h>
#define T 30
struct funcionarios
{
    char nome[T];
    int id;
    float salario;
};
void main()
{
    struct funcionarios cadastro[3];
    FILE *p;
    int cont;
    p=fopen("arq2.rec","wb");
    for (cont=0; cont< 3; cont++)
    {
        printf ("Digite o nome do funcionario: ");
        scanf("%s",cadastro[cont].nome);
        printf("Digite o numero de identificacao: ");
        scanf("%d",&cadastro[cont].id);
        printf("Digite o salario: ");
        scanf("%f",&cadastro[cont].salario);
    }
    fwrite(&cadastro,sizeof(cadastro),3,p);
    fclose(p);
}

