#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pesquisa.h"

// Funções auxiliares
static int compararRegistros(Registro *a, Registro *b, CriterioOrdenacao criterio) {
    switch(criterio) {
        case POR_ANO:
            if (a->entrada.ano != b->entrada.ano)
                return a->entrada.ano - b->entrada.ano;
            if (a->entrada.mes != b->entrada.mes)
                return a->entrada.mes - b->entrada.mes;
            return a->entrada.dia - b->entrada.dia;
        
        case POR_MES:
            if (a->entrada.mes != b->entrada.mes)
                return a->entrada.mes - b->entrada.mes;
            if (a->entrada.dia != b->entrada.dia)
                return a->entrada.dia - b->entrada.dia;
            return a->entrada.ano - b->entrada.ano;
        
        case POR_DIA:
            if (a->entrada.dia != b->entrada.dia)
                return a->entrada.dia - b->entrada.dia;
            if (a->entrada.mes != b->entrada.mes)
                return a->entrada.mes - b->entrada.mes;
            return a->entrada.ano - b->entrada.ano;
        
        case POR_IDADE:
            if (a->idade != b->idade)
                return a->idade - b->idade;
            return strcmp(a->nome, b->nome);
    }
    return 0;
}

static void inserirRec(EABB **raiz, Registro *paciente, CriterioOrdenacao criterio) {
    if (*raiz == NULL) {
        *raiz = malloc(sizeof(EABB));
        (*raiz)->dados = paciente;
        (*raiz)->esq = (*raiz)->dir = NULL;
        return;
    }

    if (compararRegistros(paciente, (*raiz)->dados, criterio) < 0) {
        inserirRec(&(*raiz)->esq, paciente, criterio);
    } else {
        inserirRec(&(*raiz)->dir, paciente, criterio);
    }
}

static void emOrdem(EABB *raiz, CriterioOrdenacao criterio) {
    if (raiz) {
        emOrdem(raiz->esq, criterio);
        
        printf("| %-20s | ", raiz->dados->nome);
        switch(criterio) {
            case POR_ANO: printf("%-4d |\n", raiz->dados->entrada.ano); break;
            case POR_MES: printf("%-4d |\n", raiz->dados->entrada.mes); break;
            case POR_DIA: printf("%-4d |\n", raiz->dados->entrada.dia); break;
            case POR_IDADE: printf("%-4d |\n", raiz->dados->idade); break;
        }
        
        emOrdem(raiz->dir, criterio);
    }
}

static void liberarRec(EABB *raiz) {
    if (raiz) {
        liberarRec(raiz->esq);
        liberarRec(raiz->dir);
        free(raiz);
    }
}

// Implementação das funções públicas
void inicializarABB(ABB *arvore) {
    arvore->raiz = NULL;
    arvore->qtde = 0;
}

void inserirNaABB(ABB *arvore, Registro *paciente, CriterioOrdenacao criterio) {
    inserirRec(&arvore->raiz, paciente, criterio);
    arvore->qtde++;
}

void mostrarPorCriterio(ABB *arvore, CriterioOrdenacao criterio) {
    printf("\n=== RESULTADOS ===\n");
    printf("+----------------------+-------+\n");
    printf("| %-20s | ", "Nome");
    
    switch(criterio) {
        case POR_ANO: printf("%-4s |\n", "Ano"); break;
        case POR_MES: printf("%-4s |\n", "Mes"); break;
        case POR_DIA: printf("%-4s |\n", "Dia"); break;
        case POR_IDADE: printf("%-4s |\n", "Idade"); break;
    }
    
    printf("+----------------------+-------+\n");
    emOrdem(arvore->raiz, criterio);
    printf("+----------------------+-------+\n");
    printf("Total: %d pacientes\n", arvore->qtde);
}

void liberarArvore(ABB *arvore) {
    liberarRec(arvore->raiz);
    arvore->raiz = NULL;
    arvore->qtde = 0;
}
