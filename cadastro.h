#ifndef CADASTRO_H
#define CADASTRO_H

#include "estruturas.h"

// Inicialização
void inicializarLista(Lista *lista);

// Operações
void cadastrarPaciente(Lista *lista, Registro novo);
Registro* consultarPaciente(Lista *lista, const char *rg);
void mostrarLista(Lista *lista);
void atualizarPaciente(Lista *lista, const char *rg, Registro novos_dados);
void removerPaciente(Lista *lista, const char *rg);

// Liberação de memória
void liberarLista(Lista *lista);

#endif
