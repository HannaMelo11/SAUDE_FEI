#include "atendimento_prioritario.h"
#include <stdio.h>
#include <stdlib.h>

void inicializar_fila_prioritaria(FilaPrioritaria* fila) {
    fila->qtde = 0;
    for (int i = 0; i < MAX_PRIORITARIO; i++) {
        fila->dados[i] = NULL;
    }
}

int fila_prioritaria_cheia(FilaPrioritaria* fila) {
    return fila->qtde == MAX_PRIORITARIO;
}

int fila_prioritaria_vazia(FilaPrioritaria* fila) {
    return fila->qtde == 0;
}

void ajustar_heap_subindo(FilaPrioritaria* fila, int pos) {
    int pai;
    Registro* temp;
    
    pai = (pos - 1) / 2;
    
    while (pos > 0 && fila->dados[pai]->idade < fila->dados[pos]->idade) {
        temp = fila->dados[pai];
        fila->dados[pai] = fila->dados[pos];
        fila->dados[pos] = temp;
        
        pos = pai;
        pai = (pos - 1) / 2;
    }
}

void enfileirar_prioritario(FilaPrioritaria* fila, Registro* paciente) {
    if (fila_prioritaria_cheia(fila)) {
        printf("\n");
        printf("Fila prioritária cheia!\n");
        return;
    }
    
    fila->dados[fila->qtde] = paciente;
    ajustar_heap_subindo(fila, fila->qtde);
    fila->qtde++;
}

void ajustar_heap_descendo(FilaPrioritaria* fila, int pos) {
    int filho_esq, filho_dir, filho_max;
    Registro* temp;
    
    filho_esq = 2 * pos + 1;
    filho_dir = 2 * pos + 2;
    
    if (filho_esq < fila->qtde) {
        filho_max = filho_esq;
        
        if (filho_dir < fila->qtde && fila->dados[filho_dir]->idade > fila->dados[filho_esq]->idade) {
            filho_max = filho_dir;
        }
        
        if (fila->dados[pos]->idade < fila->dados[filho_max]->idade) {
            temp = fila->dados[pos];
            fila->dados[pos] = fila->dados[filho_max];
            fila->dados[filho_max] = temp;
            
            ajustar_heap_descendo(fila, filho_max);
        }
    }
}

Registro* desenfileirar_prioritario(FilaPrioritaria* fila) {
    if (fila_prioritaria_vazia(fila)) {
        printf("\n");
        printf("Fila prioritária vazia!\n");
        return NULL;
    }
    
    Registro* paciente = fila->dados[0];
    fila->qtde--;
    fila->dados[0] = fila->dados[fila->qtde];
    ajustar_heap_descendo(fila, 0);
    
    return paciente;
}

void mostrar_fila_prioritaria(FilaPrioritaria* fila) {
    if (fila_prioritaria_vazia(fila)) {
        printf("\n");
        printf("Fila prioritária vazia!\n");
        return;
    }
    
    printf("\n--- FILA PRIORITARIA POR IDADE ---\n");
    for (int i = 0; i < fila->qtde; i++) {
        printf("%d: %s (Idade: %d)\n", i+1, fila->dados[i]->nome, fila->dados[i]->idade);
    }
}
