#include "racionais.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void trocar(struct racional **v, int a, int b) {
    struct racional *aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

int minimo(struct racional **v, int inicio, int n) {
    if (!v || inicio >= n) return inicio;
    int m = minimo(v, inicio, n - 1);
    return (compara_r(v[n], v[m]) == -1) ? n : m;
}

void selectionSort(struct racional **v, int inicio, int n) {
    if (!v || inicio >= n) return;
    int m = minimo(v, inicio, n);
    trocar(v, inicio, m);
    selectionSort(v, inicio + 1, n);
}

void imprimeVetor(int n, struct racional **v) {
    for (int i = 0; i < n; i++) {
        imprime_r(v[i]);
        if (i < n - 1) { // Adiciona espaço apenas entre os elementos
            printf(" ");
        }
    }
    printf("\n"); // Nova linha no final
}

int main() {
    srand(0);

    struct racional **v;
    int n, i, dado1, dado2;

    do {
        scanf("%d", &n);
    } while (n < 0 || n >= 100);

    v = malloc(n * sizeof(struct racional *));
    for (i = 0; i < n; i++) {
        scanf("%d %d", &dado1, &dado2);
        v[i] = cria_r(dado1, dado2);
    }

    imprimeVetor(n, v);

    /* Remoção de elementos inválidos */
    struct racional **validos = malloc(n * sizeof(struct racional *));
    int count = 0;

    for (i = 0; i < n; i++) {
        if (valido_r(v[i])) {
            validos[count++] = v[i];
        } else {
            destroi_r(&v[i]);
        }
    }
    free(v);
    v = validos;
    n = count;

    imprimeVetor(n, v);

    /* Ordenação */
    selectionSort(v, 0, n - 1);
    imprimeVetor(n, v);

    /* Soma */
    struct racional *soma = cria_r(0, 1);
    for (i = 0; i < n; i++) {
        struct racional *temp = soma_r(v[i], soma);
        destroi_r(&soma);
        soma = temp;
    }

    printf("a soma de todos os elementos eh: ");
    imprime_r(soma);
    printf("\n");

    /* Liberação de memória */
    for (i = 0; i < n; i++) {
        destroi_r(&v[i]);
    }
    free(v);

    imprime_r(soma);
    destroi_r(&soma);
    printf("\n");

    return 0;
}
