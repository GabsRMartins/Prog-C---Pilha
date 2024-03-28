#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *anterior;
} No;

// Função para empilhar
void push(No **topo, int x) {
    No *novo = malloc(sizeof(No));
    if (novo) {
        novo->valor = x;
        novo->anterior = *topo;
        *topo = novo;
        printf("\nNovo elemento na pilha: %d", (*topo)->valor);
    } else {
        printf("\nErro ao alocar memória");
    }
}

// Função para desempilhar
int pop(No **topo) {
    No *removido;
    if (*topo) {
        removido = *topo;
        *topo = (*topo)->anterior;
        printf("\nO elemento removido foi %d", removido->valor);
        free(removido); // Liberando a memória alocada para o nó removido
    } else {
        printf("\nA pilha está vazia");
    }
}

int main() {
    No *topo = NULL;
    push(&topo, 10);
    push(&topo, 20);
    pop(&topo);
    return 0;
}