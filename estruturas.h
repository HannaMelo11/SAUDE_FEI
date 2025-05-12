#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

// Estrutura para data
typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

// Estrutura para paciente
typedef struct {
    char nome[100];
    int idade;
    char rg[20];      // Identificador único
    Data entrada;     // Data de cadastro
} Registro;

// Nó da lista encadeada
typedef struct ELista {
    Registro dados;
    struct ELista *proximo;
} ELista;

// Lista de pacientes
typedef struct {
    ELista *inicio;  // Ponteiro para o primeiro nó
    int qtde;        // Contador de pacientes
} Lista;

//-----------------------------------------------

typedef struct EFila {
    Registro *dados;          // Ponteiro para os dados do paciente
    struct EFila *proximo;    // Ponteiro para o próximo nó
} EFila;

typedef struct {
    EFila *head;    // Ponteiro para o início da fila
    EFila *tail;    // Ponteiro para o fim da fila
    int qtde;       // Contador de pacientes na fila
} Fila;

// ------------------------------------------------
#endif
