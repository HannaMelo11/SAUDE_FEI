#ifndef PESQUISA_H
#define PESQUISA_H

#include "../estruturas.h"

// Inicialização
void inicializarABB(ABB *arvore);

// Inserção
void inserirNaABB(ABB *arvore, Registro *paciente, CriterioOrdenacao criterio);

// Exibição
void mostrarPorCriterio(ABB *arvore, CriterioOrdenacao criterio);

// Liberação de memória
void liberarArvore(ABB *arvore);

#endif
