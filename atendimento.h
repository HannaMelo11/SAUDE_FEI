#ifndef ATENDIMENTO_H
#define ATENDIMENTO_H

#include "estruturas.h"

// Inicialização
void inicializarFila(Fila *fila);

// Operações
void enfileirarPaciente(Fila *fila, Registro *paciente);
Registro* desenfileirarPaciente(Fila *fila);
void mostrarFila(Fila *fila);
int filaVazia(Fila *fila);

#endif
