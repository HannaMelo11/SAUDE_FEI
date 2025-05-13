#ifndef ATENDIMENTO_PRIORITARIO_H
#define ATENDIMENTO_PRIORITARIO_H

#include "estruturas/estruturas.h" // Assumindo que temos um arquivo registro.h com a estrutura de pacientes

void inicializar_fila_prioritaria(FilaPrioritaria* fila);
int fila_prioritaria_cheia(FilaPrioritaria* fila);
int fila_prioritaria_vazia(FilaPrioritaria* fila);
void enfileirar_prioritario(FilaPrioritaria* fila, Registro* paciente);
Registro* desenfileirar_prioritario(FilaPrioritaria* fila);
void mostrar_fila_prioritaria(FilaPrioritaria* fila);
void ajustar_heap_subindo(FilaPrioritaria* fila, int pos);
void ajustar_heap_descendo(FilaPrioritaria* fila, int pos);

#endif
