#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define DESCRICAO 100

typedef struct pedido
{
    int protocolo;
    char descricao[DESCRICAO];
    struct pedido *prox;
}pedido;

typedef struct 
{
    pedido *inicio;
    pedido *fim;
    int tamanho_fila;
}fila_de_pedido;

fila_de_pedido *criar_fila()
{
    fila_de_pedido *novo = malloc(sizeof(fila_de_pedido));
    novo->inicio = NULL;
    novo->fim = NULL;
    novo->tamanho_fila = 0;
    return novo;
}

pedido *criar_pedido(int protocolo, char descricao[DESCRICAO])
{
    pedido *novo = malloc(sizeof(pedido));
    strcpy(novo->descricao, descricao);
    novo->protocolo = protocolo;
    novo->prox = NULL;
    return novo;
}

void cadastro_de_pedido(fila_de_pedido *fila_de_pedido)
{
    system("clear");
    int protocolo;
    char descricao[DESCRICAO];

    do
    {
        puts("Digite a descrição do serviço(MÁX 100 CARACTERES)");
        printf("Descrição: ");
        while(getchar() != '\n' && getchar() != EOF);
        fgets(descricao, DESCRICAO, stdin);
        descricao[strcspn(descricao, "\n")] = 0;

        if (strlen(descricao) > DESCRICAO)
        {
            puts("Erro! A descrição ultrapassou o limte de caracteres válidos!");
            continue;
        }

    } while (strlen(descricao) > DESCRICAO);
    
    srand(time(NULL));
    protocolo = rand() % 100000 + 1;

    pedido *novo_pedido = criar_pedido(protocolo, descricao);

    if (novo_pedido == NULL) return;
    
    if (fila_de_pedido->inicio == NULL)
    {
        fila_de_pedido->inicio = novo_pedido;
        fila_de_pedido->fim = novo_pedido;
    }
    else
    {
        fila_de_pedido->fim->prox = novo_pedido;
        fila_de_pedido->fim = novo_pedido;
    }

    fila_de_pedido->tamanho_fila++;
    puts("Pedido registrado!");
    sleep(1);
    system("clear");
}

void mostrar_fila_de_pedidos(fila_de_pedido *fila_de_pedido)
{
    system("clear");
    pedido *aux = fila_de_pedido->inicio;
    if (fila_de_pedido->inicio == NULL)
    {
        puts("Sem pedidos por aqui!");
        return;
    }

    while (aux != NULL)
    {
        printf("Protocolo de pedido: %d || Descricao de servico: %s\n", aux->protocolo, aux->descricao);
        aux = aux->prox;
    }
}

int concluir_pedido(fila_de_pedido *fila_de_pedido)
{
    if (fila_de_pedido->tamanho_fila == 0)
    {
        puts("Nao há a pedidos para serem concluídos!");
        return -1;
    }
    
    pedido *lixo = fila_de_pedido->inicio;
    int valor = lixo->protocolo;
    if (fila_de_pedido->tamanho_fila == 1)
    {
        fila_de_pedido->inicio = NULL;
        fila_de_pedido->fim = NULL;
    }
    else
    {
        fila_de_pedido->inicio = fila_de_pedido->inicio->prox;
    }
    free(lixo);
    fila_de_pedido->tamanho_fila--;
    return valor;
}

int main()
{
    int escolha = 0;
    fila_de_pedido *fila_de_pedidos = criar_fila();
    
    while (escolha < 4)
    {
        puts("---SISTEMA DE CADASTRO DE SERVIÇOS---");
        printf("[1] - Cadastrar pedido\n[2] - Fila de pedidos\n[3] - Concluir pedido\n[4] - Sair\n");
        printf("Sua escolha: ");
        scanf(" %d", &escolha);

        switch (escolha)
        {
        case 1:
            cadastro_de_pedido(fila_de_pedidos);
            break;
        case 2:
            mostrar_fila_de_pedidos(fila_de_pedidos);
            break;
        case 3:
            concluir_pedido(fila_de_pedidos);
            break;
        case 4:
            system("clear");
            puts("Tchau!");
            break;
        default:
            puts("Erro! Sua escolha não existe no menu!");
            break;
        }
    }
    
    return 0;
}