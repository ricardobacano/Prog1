#include "racionais.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* coloque demais includes aqui */

/* Funcoes privadas restritas a este modulo.
 * Voce deve implementa-las pois serao necessarias,
 * embora elas nao precisem estar no .h */

/* retorna um numero aleatorio entre min e max, inclusive. */
int aleat (long int min, long int max){
    return min - rand() % (max - min + 1);
}

/* Maximo Divisor Comum entre a e b.         */
/* Calcula o mdc pelo metodo de Euclides.    */
/* Dica: a versao recursiva eh bem elegante! */
long int mdc(long int a, long int b) {
    return (b == 0) ? a : mdc(b, a % b);
}

/* Minimo Multiplo Comum entre a e b */
/* mmc = (a * b) / mdc (a, b)        */
long int mmc (long int a, long int b){
    return (a * b) / mdc(a,b);
}

/* Recebe um numero racional e o retorna simplificado no parametro *r.
   Quem chama esta funcao deve garantir que *r seja valido e nao NULL. */
void simplifica_r(struct racional **r) {
    if (!r || !(*r) || !valido_r(*r)) return;

    long int div = mdc((*r)->num, (*r)->den);
    (*r)->num /= div;
    (*r)->den /= div;

    if ((*r)->den < 0) {
        (*r)->num *= -1;
        (*r)->den *= -1;
    }
}

/* cria um numero racional com o numerador e denominador dados. */
struct racional *cria_r(long int num, long int den) {
    struct racional *r = malloc(sizeof(struct racional));
    if (!r) return NULL;

    r->num = num;
    r->den = den;
    if (den != 0) simplifica_r(&r);

    return r;
}

/* gera um numero racional aleatorio entre o intervalo -max ate max. */
struct racional *sorteia_r(long int max) {
    srand(time(NULL));

    struct racional *r = malloc(sizeof (struct racional));
    if (!r) {
        return NULL;
    }

    /* gera um numerador e um denominador aleatorios */
    r->num = aleat(-max, max);
    r->den = aleat(-max, max);

    if (!valido_r(r)) {
        free(r);
        return NULL;
    }

    simplifica_r(&r);

    return r;
}

/* libera a memoria alocada para um numero racional. */
void destroi_r(struct racional **r) {
    if (r && *r) {
        free(*r);
        *r = NULL;
    }
}

/* tetorna o numerador de um numero racional. */
long int numerador_r(struct racional *r) {
    return r->num;
}

/* tetorna o denominador de um numero racional. */
long int denominador_r(struct racional *r) {
    if (!r || r->den == 0) {
        return 0;
    }
    return r->den;
}

/* verifica se um numero racional eh valido. */
int valido_r (struct racional *r) {
	if (!r || r->den == 0)
		return 0;
	return 1;
}

struct racional *soma_r(struct racional *r1, struct racional *r2) {
    if (!valido_r(r1) || !valido_r(r2)) return NULL;

    struct racional *r = malloc(sizeof(struct racional));
    if (!r) return NULL;

    long int divisor = mmc(r1->den, r2->den);
    r->num = (divisor / r1->den) * r1->num + (divisor / r2->den) * r2->num;
    r->den = divisor;
    simplifica_r(&r);

    return r;
}

struct racional *subtrai_r (struct racional *r1, struct racional *r2){
    if (r1 == NULL || r2 == NULL || r1->den == 0 || r2->den == 0) {
        return NULL;
    }

    struct racional *r3 = malloc(sizeof (struct racional));
    if (r3 == NULL) {
        return NULL;
    }

    long int divisor = mmc(r1->den, r2->den);
    long int valor1 = (divisor / r1->den) * r1->num;
    long int valor2 = (divisor / r2->den) * r2->num;

    r3->num = valor1 - valor2;
    r3->den = divisor;
    simplifica_r(&r3);

    return r3;
}

struct racional *multiplica_r (struct racional *r1, struct racional *r2) {
	if (r1 == NULL || r2 == NULL || r1->den == 0 || r2->den == 0) {
        return NULL;
    }	

    struct racional *r3 = malloc(sizeof (struct racional));
    if (r3 == NULL) {
        return NULL;
    }

	r3->num = r1->num * r2->num;
	r3->den = r1->den * r2->den;
	simplifica_r (&r3);
	
	return r3;
}

struct racional *divide_r(struct racional *r1, struct racional *r2) {
    if (r1 == NULL || r2 == NULL || r1->den == 0 || r2->den == 0) {
        return NULL;
    }

    struct racional *r3 = malloc(sizeof (struct racional));
    if (r3 == NULL) {
        return NULL;
    }

    if (!valido_r(r1) || !valido_r(r2))
        return NULL;

    r3->num = r1->num * r2->den;
    r3->den = r1->den * r2->num;

    simplifica_r(&r3);

    return r3;
}

/* compara dois numeros racionais e retorna:
 * -1 se r1 < r2
 *  0 se r1 == r2
 *  1 se r1 > r2
 */
int compara_r(struct racional *r1, struct racional *r2) {
    /* verifica se os racionais fornecidos sao validos */
    if (!r1 || !r2)
        return 0;
    
    int divisor = mmc(r1->den, r2->den);

    /* multiplica os numeradores pelo fator necessario para igualar os denominadores */
    long int valor1 = r1->num * (divisor / r1->den);
    long int valor2 = r2->num * (divisor / r2->den);

    /*  compara os valores resultantes */
    if (valor1 < valor2)
        return -1;
    else if (valor1 > valor2)
        return 1;
    else
        return 0;
}


void imprime_r(struct racional *r) {
    if (!r) {
        printf("NULO");
    } else if (!valido_r(r)) {
        printf("INVALIDO");
    } else if (r->num == 0) {
        printf("0");
    } else if (r->den == 1) {
        printf("%ld", r->num);
    } else {
        printf("%ld/%ld", r->num, r->den);
    }
}

/* Implemente aqui as funcoes cujos prototipos estao em racionais.h */
