#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char *nome_produto;
    float valor;
    char *prioridade;
    struct produto *proximo;
}produto;

produto *inicio = NULL;
produto *fim = NULL;
int tam = 0;

void add(char *nome_do_produto, float valor, char *prioridade, int pos){
    produto *novo_produto = malloc(sizeof(produto));
    novo_produto->nome_produto = (char *)malloc( 50 * sizeof(char));
    novo_produto->valor = valor;
    novo_produto->prioridade = (char *)malloc(10 * sizeof(char));
    strcpy(novo_produto->nome_produto, nome_do_produto);
    strcpy(novo_produto->prioridade, prioridade);
    
    if (inicio == NULL) {
        inicio = novo_produto;
        fim = novo_produto;
    } else if (pos == 0) {
        novo_produto->proximo = inicio;
        inicio = novo_produto;
    } else if (pos == tam) {
        fim->proximo = novo_produto;
        fim = novo_produto;
        novo_produto->proximo = NULL;
    } else {
        produto *aux = inicio;
        for (int i = 0; i < pos-1 ; i++) {
            aux = aux->proximo;
        }
        novo_produto->proximo = aux->proximo;
        aux->proximo = novo_produto;
    }
    tam ++;
}

void exibir(){
    produto *aux = inicio;
    while (aux != NULL) {
        printf("Nome do produto: %.50s | Valor: %.2f R$ | Prioridade: %.10s\n", aux->nome_produto, aux->valor, aux->prioridade);
        aux = aux->proximo;
    }
}

void remover(int pos){
    if (pos >= 0 && pos < tam){
        produto *lixo = inicio;
       if (pos == 1) {
           lixo = inicio;
           inicio = inicio->proximo;
       } else if (pos == tam-1) {
           produto *aux = inicio;
           for (int i = 0; i < pos-1; i++) {
               aux = aux->proximo;
           }
           lixo = fim;
           fim = aux;
           fim->proximo = NULL;
       } else {
           produto *aux = inicio;
           for (int i = 0; i < pos-1; i++) {
               aux = aux->proximo;
           }
           lixo = aux->proximo;
           aux->proximo = lixo->proximo;
       }
       tam --;
       free(lixo->nome_produto);
       free(lixo->prioridade);
       free(lixo);
    }
    else {
        printf("Error. Não tem nada para ser apagado na lista!");
    }
}

int main(){
    int pos;
    add("Sabão", 10.00, "Alta", 0);
    add("Biscoito", 3.25, "Baixa", 1);
    add("Água", 1.25, "Alta", 2);
    remover(1);
    exibir();
    return 0;
}