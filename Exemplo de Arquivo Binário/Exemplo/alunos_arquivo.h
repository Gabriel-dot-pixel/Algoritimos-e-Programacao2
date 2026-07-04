void incluir(tp_aluno a)
{
    FILE *arq;

    // ab faz a inclusão ao final em arquivo binário
    arq = fopen("alunos.dat", "ab");
    if (arq == NULL) /// não existe o arquivo
        arq = fopen("alunos.dat", "wb");
    if (arq == NULL)
    {
        printf("Não foi possível abrir o arquivo para gravação");
    }
    else
    {
        /// gravando o conteúdo de a, que possui o
        /// tamanho sizeof(tp_aluno), somente 1 vez,
        /// em arq
        a.ativo = 1;
        fwrite(&a, sizeof(tp_aluno), 1, arq);
        fclose(arq);
    }
}

int localizar_aluno(char pront[])
{
    FILE *arq;
    tp_aluno a;
    int i=0, posicao = -1; /// posicao -1 não existe o prontuario

    // ab faz a inclusão ao final em arquivo binário
    arq = fopen("alunos.dat", "rb");
    if (arq == NULL) /// não existe o arquivo
    {
        printf("Não existe o arquivo.");
    }
    else
    {
        fread(&a, sizeof(tp_aluno), 1, arq);
        while(!feof(arq) && posicao==-1)
        {
            if (strcmp(a.pront,pront)==0)
                posicao = i;
            fread(&a, sizeof(tp_aluno), 1, arq);
            i++;
        }
        fclose(arq);
    }
    return posicao;
}

/// recebe a posicao do registro no arquivo e faz a leitura
tp_aluno pegar_aluno(int posicao)
{
    FILE *arq;
    tp_aluno a;

    arq = fopen("alunos.dat", "rb");
    if (arq == NULL) /// não existe o arquivo
    {
        printf("Não existe o arquivo.");
    }
    else
    {
        /// desloca o ponteiro do aquivo para uma determinada
        /// posicao
        fseek(arq, posicao*sizeof(tp_aluno),SEEK_SET);
        fread(&a, sizeof(tp_aluno), 1, arq);
        fclose(arq);
    }
    return a;
}

void sobreescrever_aluno(tp_aluno a, int posicao)
{
    FILE *arq;

    arq = fopen("alunos.dat", "rb+");
    if (arq == NULL) /// não existe o arquivo
    {
        printf("Não existe o arquivo.");
    }
    else
    {
        fseek(arq, posicao*sizeof(tp_aluno),SEEK_SET);
        fwrite(&a, sizeof(tp_aluno), 1, arq);
        fclose(arq);
    }
}

int retorna_quant_reg()
{
    int quantidade = 0;
    long qte_bytes;
    FILE *arq;

    arq = fopen("alunos.dat", "rb");
    if (arq != NULL) /// se o arquivo existe
    {
        /// posiciona no final do arquivo
        fseek(arq, 0, SEEK_END);

        /// quantos bytes tem desde o início do aquivo
        qte_bytes = ftell(arq);
        quantidade = qte_bytes / sizeof(tp_aluno);
        fclose(arq);
    }
    return quantidade;
}
