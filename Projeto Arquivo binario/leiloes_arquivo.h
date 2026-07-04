//função para incluir um produto no final do arquivo
void incluir(tp_produto p)
{
    FILE *arq;

    // ab faz a inclusão ao final em arquivo binário
    arq = fopen("produtos.dat", "ab");

    if(arq == NULL)
    {
        arq = fopen("produtos.dat", "wb");
    }
    else if(arq == NULL)
    {
        printf("Nao foi Possivel Abrir o Arquivo para Gravacao!\n");
    }
    else
    {
        /// gravando o conteúdo de p, que possui o
        /// tamanho sizeof(tp_produtos), somente 1 vez,
        /// em arq
        p.lance = 0;
        p.situacao = 'A';
        p.statuts = 1;
        p.nome_cliente[0] ='\0';
        p.telefone[0] = '\0';
        strcat(p.nome_cliente," ");
        strcat(p.telefone," ");
        fwrite(&p, sizeof(tp_produto), 1, arq);
        fclose(arq);
    }

}

int retornar_quantidade_structs()
{
    FILE *arq;
    int qtd = 0;
    tp_produto p;

    arq = fopen("produtos.dat", "rb");

    if(arq == NULL)
    {
        printf("Nao foi Possivel Abrir o Arquivo para Leitura!\n");
    }
    else
    {
        while(fread(&p,sizeof(tp_produto),1,arq) == 1)
        {
            qtd++;
        }

        fclose(arq);
    }

    return qtd;
}

int localizar_produto(int num)
{
    FILE *arq;
    tp_produto p;
    int i=0, posicao = -1; /// posicao -1 não existe o prontuario

    // ab faz a inclusão ao final em arquivo binário
    arq = fopen("produtos.dat", "rb");

    if (arq == NULL) /// não existe o arquivo
    {
        printf("Nao foi Possivel Abrir o Arquivo para Leitura!\n");
    }
    else
    {
        fread(&p, sizeof(tp_produto), 1, arq);
        while(!feof(arq) && posicao == -1)
        {
            if (p.codigo == num)
            {
                posicao = i;
            }
            fread(&p, sizeof(tp_produto), 1, arq);
            i++;
        }
        fclose(arq);
    }
    return posicao;
}

/// recebe a posicao do registro no arquivo e faz a leitura
tp_produto pegar_produto(int posicao)
{
    FILE *arq;
    tp_produto p;

    arq = fopen("produtos.dat", "rb");

    if (arq == NULL) /// não existe o arquivo
    {
        printf("Nao foi Possivel Abrir o Arquivo para Leitura!\n");
    }
    else
    {
        /// desloca o ponteiro do aquivo para uma determinada
        /// posicao
        fseek(arq, posicao*sizeof(tp_produto),SEEK_SET);
        fread(&p, sizeof(tp_produto), 1, arq);
        fclose(arq);
    }
    return p;
}

void sobreescrever_produto(tp_produto p, int posicao)
{
    FILE *arq;

    arq = fopen("produtos.dat", "rb+");

    if (arq == NULL) /// não existe o arquivo
    {
        printf("Nao foi possivel abrir o arquivo para leitura e gravacao");
    }
    else
    {
        fseek(arq, posicao*sizeof(tp_produto),SEEK_SET);
        fwrite(&p, sizeof(tp_produto), 1, arq);
        fclose(arq);
    }
}

void excluir_produtos_fisicamente()
{
    tp_produto p;
    FILE *arq, *temp;

    arq = fopen("produtos.dat", "rb");
    temp = fopen("temp.dat", "wb");

    if (arq == NULL && temp == NULL)
    {
        printf("Nao foi Possivel Abrir os Arquivos para Leitura e Gravacao!\n");
    }
    else
    {
        fread(&p, sizeof(tp_produto), 1, arq);
        while(!feof(arq))
        {
            if (p.statuts == 1)
            {
                fwrite(&p, sizeof(tp_produto), 1, temp);
            }
            fread(&p, sizeof(tp_produto), 1, arq);
        }
        fclose(arq);
        fclose(temp);
        remove("produtos.dat");
        rename("temp.dat", "produtos.dat");
        printf("Registros inativos removidos!\n");
    }
}
