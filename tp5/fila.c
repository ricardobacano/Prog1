#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

/* 
 * Cria e retorna uma nova fila.
 * Retorna NULL em caso de erro de alocação.
*/
struct fila *fila_cria () {
    struct fila *f = (struct fila *) malloc(sizeof(struct fila));
    if (f == NULL) 
        return NULL;
    
    f->ini = NULL;
    f->fim = NULL;
    f->tamanho = 0;
    
    return f;
}

/* Desaloca toda memoria da fila e faz fila receber NULL. */
void fila_destroi (struct fila **fila) {
    if (fila == NULL || *fila == NULL) 
        return;
    
    struct nodo *current = (*fila)->ini;
    while (current != NULL) {
        struct nodo *temp = current;
        current = current->prox;
        free(temp);
    }
    
    free(*fila);
    *fila = NULL;
}

/* 
 * Insere dado na fila (politica FIFO). Retorna 1
 * em caso de sucesso e 0 em caso de falha.
*/
int enqueue (struct fila *fila, int dado) {
    if (fila == NULL) 
        return 0;
    
    struct nodo *new_node = (struct nodo *) malloc(sizeof(struct nodo));
    if (new_node == NULL) 
        return 0;
    
    new_node->chave = dado;
    new_node->prox = NULL;
    
    if (fila->fim == NULL) {
        fila->ini = new_node;
    } else {
        fila->fim->prox = new_node;
    }
    
    fila->fim = new_node;
    fila->tamanho++;
    
    return 1;
}

/* 
 * Remove dado da fila (politica FIFO) e retorna o elemento 
 * no parametro dado. A funcao retorna 1 em caso de 
 * sucesso e 0 no caso da fila estar vazia.
*/
int dequeue (struct fila *fila, int *dado) {
    if (fila == NULL || fila->ini == NULL) 
        return 0;
    
    struct nodo *temp = fila->ini;
    *dado = temp->chave;
    
    fila->ini = temp->prox;
    if (fila->ini == NULL) {
        fila->fim = NULL;
    }
    
    free(temp);
    fila->tamanho--;
    
    return 1;
}
 
/* Retorna o numero de elementos da pilha, que pode ser 0. */
int fila_tamanho (struct fila *fila) {
    if (fila == NULL) 
        return 0;
    return fila->tamanho;
}

/* Retorna 1 se fila vazia, 0 em caso contrario. */ 
int fila_vazia (struct fila *fila) {
    if (fila == NULL) 
        return 1;
    return (fila->tamanho == 0);
}
