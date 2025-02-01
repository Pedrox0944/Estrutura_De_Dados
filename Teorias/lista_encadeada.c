#include <complex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{ // Criação de um nó, que recebe um valor e um ponteiro que aponta para o próximo da lista
  int valor;
  struct no *prox;
}no;

no *inicio = NULL; // Como a lista está vazia, o início que é um ponteiro que situa o início da lista 
no *fim = NULL; // Assim como o início, é um ponteiro que serve para situar qual nó é o final da lista
int tam = 0; // Tamanho da lista

void add(int valor, int pos){
    
  no *novo = malloc(sizeof(no)); // Criação de um novo nó
  novo->valor = valor; // O ponteiro novo entra dentro do campo valor e faz ele receber o valor
  novo->prox = NULL; // O ponteiro novo entra no campo prox e faz ele apontar pro nada até então

  // Caso a lista esteja vazia
  if (inicio == NULL){ // Se o início não está recebendo nada então a lista está vazia
    inicio = novo; // Já que a lista está vazia e o nó que eu coloquei agora é o primeiro da lista, faço o início apontar para o novo nó
    fim = novo; // Como só tem esse nó na lista, então ao mesmo tempo que o novo nó é o inicio ele também é o fim
  }
  // Adicionando no primeiro da lista
  else if (pos==0){ // A lista não está vazia e o usuário quer colocar no início na lista
  novo->prox = inicio; // Então o novo nó entra dentro do campo prox e faz ele apontar pro início
  inicio = novo; // Então o início recebe o novo e faz com que o nó se torne o inicial
  }
  // Adicionando no fim da fila
  else if (pos == tam) { // Se o usuário colocou a posição igual ao tamanho da lista, então ele quer inserir no fim 
  fim->prox = novo; // O fim entra no campo prox do último no e faz ele apontar para o novo nó criado
  fim = novo; // Agora o novo nó é o último
  }
  // Adicionando no meio da lista
  else {
  no *aux = inicio; // Criação de um ponteiro auxiliar que começa lá no início
  for (int i = 0; i < pos-1; i++) { // É passado um for que faz o aux percorrer até onde o usuário colocou a posição menos 1, que é pra colocar no meio
  aux  = aux->prox; // o aux entra dentro do prox e segue percorrendo a lista
  }
  novo->prox = aux->prox; // Depois de chegar no ponto certo, o ponteiro novo e o aux apontam para o prox
  aux->prox = novo; // Faz o prox receber um novo nó
  }
  tam ++; // A lista ganha um elemento após toda chamada da função
}

void imprimir(){
  no *aux = inicio; // Criação de um nó auxiliar que começa lá do início
  for (int i = 0; i <tam; i++){ // Passa pela a lista e vai printando valor
    printf("valor: %d\n", aux->valor); // O aux entra dentro do campo valor e imprime na tela
    aux = aux->prox; // O aux entra dentro do campo prox e segue percorrendo a lista
  }
}

int remover(int pos){
    // Verifica se a lista está vazia
    if (pos >= 0 && pos < tam) {
        no *lixo = inicio; // Cria o ponteiro lixo que está lá no início
        if (tam == 1) { // Se a lista só tem um elemento
            lixo = inicio; // O nó inicial é o lixo
            inicio = NULL; // Faz o início virar um NULL
            fim = NULL; // Não existe mais nó inicial nem final
        }
        // Removendo do início da lista
        else if (pos == 0) { // Excluindo do início da lista
            lixo = inicio; // O ponteiro lixo recebe o início que é o nó
            inicio = inicio->prox; // O início vai receber o próximo nó
        }
        else if (pos == tam-1) { // Excluindo do final da lista
            no *aux = inicio; // Criação de um ponteiro auxiliar
            for (int i = 0; i < pos-1; i++) { // O ponteiro percorre toda a lista até chegar no último
                aux = aux->prox; // Ele avança fazendo o aux receber o proximo nó
            }
            lixo = fim; // O lixo recebe o ultimo nó
            fim = aux; // Faz com que o penúltimo elemento vire o último
            fim->prox = NULL; // com isso não existe elemento pós o fim
        }
        else { // Removendo do meio
            no *aux = inicio; // Criação de um ponteiro auxiliar
            for (int i; i < pos-1 ; i++) {
                aux = aux->prox; // Percore até o elemeto anterior ao que nós vamos apagar
            }
            lixo = aux->prox; // Faz o lixo receber o nó que queremos
            aux->prox = lixo->prox; // Então o elemento anterior ao que nós queriamos passa a apontar para o elemento sucessor do nosso elemento procurado
        }
        tam --; // Diminui um tamanho da lista
        int valor = lixo->valor; // O valor recebe o valor do lixo
        free(lixo); // Ele libera o lixo
        return valor; // E retorna o valor liberado
    }
    else {
        printf("Posição inválida!");
        return -1;
    }
}

int main()
{
  add(10,0);
  add(5, 1);
  add(10, 2);
  remover(2);
  add(100, 2);
  remover(2);
  imprimir();

return 0;
}

