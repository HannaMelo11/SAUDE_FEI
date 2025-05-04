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

#endif
