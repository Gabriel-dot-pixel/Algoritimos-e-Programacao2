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
    struct funcionarios cadastro[10];
    FILE *p;
    int cont;
    p=fopen("arq2.rec","rb");
    fread(&cadastro,sizeof(cadastro),3,p);
    for (cont=0; cont< 3; cont++)
    {
        printf("Nome:%s\t",cadastro[cont].nome);
        printf("Identificacao:%d\t",cadastro[cont].id);
        printf("Salario:%.2f",cadastro[cont].salario);
        printf("\n");
    }
    fclose(p);
}
