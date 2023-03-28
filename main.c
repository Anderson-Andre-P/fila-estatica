/*
O que é uma Fila?​
Segundo Tenenbaum, Uma fila é um conjunto ordenado de itens a partir do qual podem-se eliminar
itens numa extremidade (chamada início da fila) e no qual podem-se inserir
itens na outra extremidade (chamada final da fila).

Qual a sua importância e aplicabilidade em Ciência da Computação?​
Filas são importantes para organizar a ordem de chegada e ordem de atendimento dos processos. 

Descreva brevemente seu funcionamento.
Por exemplo, se não tiver uma fila nas lotéricas para apostar na loteria iria virar uma bagunça, mas com uma fila de ordem de chegada o primeiro a chegar vai ser o primeiro a ser atendido.

*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int tamanho = 0;

struct fila{
    int vet[MAX];
    int inicio, fim;
};

typedef struct fila Fila;

Fila q;

//Função que inicia com Vazio
void criaFila (Fila *q){
    q = (Fila*)malloc(sizeof(Fila));

    q->inicio = 0;
    q->fim = 0;
}

int filaVazia(Fila *q){
    if(tamanho == 0){
        printf("Fila Vazia \n");
        return 1;
    }
    return 0;
}

int inserirElemento(Fila *q, int valor){
    if(tamanho == MAX){
        printf("Fila Cheia \n\n");
        return 0;
    }

    q->vet[q->fim] = valor;
    printf("Inserido %d \n\n", q->vet[q->fim]);
    q->fim++;

    if(q->fim == MAX){
        q->fim = 0;
    }

    tamanho++;
    return 1;
}

int removeElemento(Fila *q){
    if(tamanho == 0){
        printf("Fila Vazia \n\n");
        return 0;
    }

    //printf("Inicio %d \n", q->inicio);
    //printf("Fim %d \n", q->fim);

    int valor = q->vet[q->inicio];
    q->inicio++;

    if(q->inicio == MAX){
        q->inicio = 0;
    }

    printf("Removido %d \n\n", valor);

    tamanho--;

    return valor;
}

void limpaFila(Fila *q){
    q->inicio = 0;
    q->fim = 0;
    tamanho = 0;
}


int main(void) {
    
    criaFila(&q);
    inserirElemento(&q, 10);
    inserirElemento(&q, 20);
    inserirElemento(&q, 30);
    inserirElemento(&q, 40);
    inserirElemento(&q, 50);
    inserirElemento(&q, 60);
    
    removeElemento(&q);
    removeElemento(&q);
    removeElemento(&q);
    removeElemento(&q);
    removeElemento(&q);
    removeElemento(&q);

    return 0;
}