#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *prox;
}No;

typedef struct{
    No *inicio;
    No *fim;
    No *aux;
    int tam;
}Fila;

Fila *criar_fila(){
    Fila *nova = malloc(sizeof(Fila));
    nova->inicio = NULL;
    nova->fim = NULL;
    nova->tam = 0;
    return nova;
}

No *criar_no(int valor){
    No *novo = malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;
    return novo;
}

void add(Fila *fila, No *no){
    if (fila->inicio == NULL) {
        fila->inicio = no;
        fila->fim = no;
    }
    else{
        fila->fim->prox = no;
        fila->fim = no;
    }
    fila->tam++;
}

int remover(Fila *fila, No *no){
    
    int valor = -1;
    if (fila->tam == 0) {
        printf("Erro, a fila está vazia!");
        return -1;
    }
    else{
        fila->aux = fila->inicio;
        fila->inicio = fila->inicio->prox;
        if (fila->tam == 1) {
            fila->fim = NULL;
        }
        no->valor = fila->aux->valor;
        free(fila->aux);
        fila->tam--;
    }
    return no->valor;
}

void imprimir(Fila *fila){
    fila->aux = fila->inicio;
    for (int i = 0; i < fila->tam; i++) {
        printf("Valor: %d\n", fila->aux->valor);
        fila->aux = fila->aux->prox;
    }
}

int main(){
    Fila *fila_dos_numeros_inteiros = criar_fila();
    No *novo_no = criar_no(10);
    No *novo_no2 = criar_no(5);
    add(fila_dos_numeros_inteiros, novo_no);
    add(fila_dos_numeros_inteiros, novo_no2);
    remover(fila_dos_numeros_inteiros, novo_no);
    imprimir(fila_dos_numeros_inteiros);
    return 0;
}