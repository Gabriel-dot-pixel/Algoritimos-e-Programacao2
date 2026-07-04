tp_aluno ler_aluno()
{
    tp_aluno a;

    fflush(stdin);
    printf("Pront...: ");
    gets(a.pront);
    printf("Nome....: ");
    gets(a.nome);
    printf("Curso...: ");
    gets(a.curso);
    printf("Nota 1..: ");
    scanf("%f", &a.n1);
    printf("Nota 2..: ");
    scanf("%f", &a.n2);
    printf("Freq....: ");
    scanf("%f", &a.freq);
    return a;
}

void cadastrar_alunos()
{
    tp_aluno aluno;
    char continua;

    printf("Inclusão de alunos\n");
    do {
        aluno = ler_aluno();
        incluir(aluno);
        printf("\nCadastrar outro aluno ?");
        scanf(" %c", &continua);
    } while (continua == 's' || continua == 'S');
}

void apresentar_linha(tp_aluno a)
{
    printf("%-10s %-30s %-5s %5.2f %5.2f %6.2f\n",
           a.pront, a.nome, a.curso, a.n1, a.n2, a.freq);
}

void apresentar_cabecalho()
{
   printf("%-10s %-30s %-5s %5s %5s %6s\n","Pront","Nome", "Curso",
            "1 bim", "2 bim", "freq");
}

void apresentar_todos()
{
    FILE *arq;
    tp_aluno a;

    // ab faz a inclusão ao final em arquivo binário
    arq = fopen("alunos.dat", "rb");
    if (arq == NULL) /// não existe o arquivo
    {
        printf("Não existe o arquivo.");
    }
    else
    {
        fread(&a, sizeof(tp_aluno), 1, arq);
        apresentar_cabecalho();
        while(!feof(arq)) /// enquanto nã for o fim do arquivo
        {
            if (a.ativo)
                apresentar_linha(a);
            fread(&a, sizeof(tp_aluno), 1, arq);
        }
        fclose(arq);
    }
}

void apresentar_por_curso(char curso[])
{
    FILE *arq;
    tp_aluno a;

    // ab faz a inclusão ao final em arquivo binário
    arq = fopen("alunos.dat", "rb");
    if (arq == NULL) /// não existe o arquivo
    {
        printf("Não existe o arquivo.");
    }
    else
    {
        fread(&a, sizeof(tp_aluno), 1, arq);
        apresentar_cabecalho();
        while(!feof(arq)) /// enquanto nã for o fim do arquivo
        {
            if (strcmp(curso, a.curso)==0)
                apresentar_linha(a);
            fread(&a, sizeof(tp_aluno), 1, arq);
        }
        fclose(arq);
    }
}


void apresentar_aluno(tp_aluno a)
{
    printf("Pront...: %s\n", a.pront);
    printf("Nome....: %s\n", a.nome);
    printf("Curso...: %s\n", a.curso);
    printf("Nota 1..: %5.2f\n", a.n1);
    printf("Nota 2..: %5.2f\n", a.n2);
    printf("Freq....: %6.2f\n", a.freq);
}

void pesquisar_prontuario()
{
    char prontuario[10];
    tp_aluno a;
    int pos;

    fflush(stdin);
    printf("Digite o prontuário...: ");
    gets(prontuario);
    pos = localizar_aluno(prontuario);
    if(pos == -1)
    {
        printf("Prontuário não localizado.");
    }
    else
    {

        a = pegar_aluno(pos);
        if (!a.ativo)
            printf("Aluno está excluído.");
        apresentar_aluno(a);
    }
}


void alterar_aluno()
{
    char prontuario[10];
    tp_aluno a;
    int pos;

    fflush(stdin);
    printf("Digite o prontuário...: ");
    gets(prontuario);
    pos = localizar_aluno(prontuario);
    if(pos == -1)
    {
        printf("Prontuário não localizado.");
    }
    else
    {
        a = pegar_aluno(pos);
        apresentar_aluno(a);
        if (a.ativo)
        {
            printf("\n\nDigite os novos dados do aluno\n");
            a = ler_aluno();
            sobreescrever_aluno(a, pos);
        }
        else
        {
            printf("Aluno excluído, não é possível alterar\n");
        }
    }
}

void excluir_aluno()
{
    char prontuario[10], excluir;
    tp_aluno a;
    int pos;

    fflush(stdin);
    printf("Digite o prontuário...: ");
    gets(prontuario);
    pos = localizar_aluno(prontuario);
    if(pos == -1)
    {
        printf("Prontuário não localizado.");
    }
    else
    {
        a = pegar_aluno(pos);
        apresentar_aluno(a);
        if (a.ativo)
        {
            printf("Deseja excluir o aluno <S/N>: ");
            scanf(" %c", &excluir);
            if (excluir == 'S' || excluir == 's')
            {
                a.ativo = 0;
                sobreescrever_aluno(a, pos);
            }
        }
        else
        {
            printf("Aluno excluído, não é possível alterar\n");
        }
    }
}

