#include "atendimento.h"
#include <stdio.h>
#include <stdlib.h>

// Inicializa uma fila vazia
void inicializarFila(Fila *fila) {
    fila->head = NULL;
    fila->tail = NULL;
    fila->qtde = 0;
}

// Adiciona um paciente ao final da fila
void enfileirarPaciente(Fila *fila, Registro *paciente) {
    EFila *novo = (EFila*)malloc(sizeof(EFila));
    if (!novo) {
        fprintf(stderr, "Erro de alocação de memória!\n");
        return;
    }
    
    novo->dados = paciente;
    novo->proximo = NULL;
    
    if (filaVazia(fila)) {
        fila->head = novo;
    } else {
        fila->tail->proximo = novo;
    }
    
    fila->tail = novo;
    fila->qtde++;
}

// Remove e retorna o paciente do início da fila
Registro* desenfileirarPaciente(Fila *fila) {
    if (filaVazia(fila)) {
        return NULL;
    }
    
    EFila *temp = fila->head;
    Registro *paciente = temp->dados;
    
    fila->head = fila->head->proximo;
    if (fila->head == NULL) {
        fila->tail = NULL;
    }
    
    free(temp);
    fila->qtde--;
    return paciente;
}

// Mostra todos os pacientes na fila
void mostrarFila(Fila *fila) {
    if (filaVazia(fila)) {
        printf("Fila vazia!\n");
        return;
    }
    
    EFila *atual = fila->head;
    int posicao = 1;
    
    printf("\n--- FILA DE ATENDIMENTO (%d pacientes) ---\n", fila->qtde);
    while (atual != NULL) {
        printf("%d. %s (RG: %s)\n", posicao++, atual->dados->nome, atual->dados->rg);
        atual = atual->proximo;
    }
}

// Verifica se a fila está vazia
int filaVazia(Fila *fila) {
    return fila->head == NULL;
}
