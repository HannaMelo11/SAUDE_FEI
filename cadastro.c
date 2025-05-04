#include "cadastro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inicializa lista vazia
void inicializarLista(Lista *lista) {
    lista->inicio = NULL;
    lista->qtde = 0;
}

// Cadastra paciente no início da lista
void cadastrarPaciente(Lista *lista, Registro novo) {
    ELista *novo_no = (ELista*)malloc(sizeof(ELista));
    if (!novo_no) {
        fprintf(stderr, "Erro de alocação de memória!\n");
        return;
    }

    // Verifica se o RG já existe
    if (consultarPaciente(lista, novo.rg)) {
        printf("Erro: RG %s já cadastrado!\n", novo.rg);
        free(novo_no);
        return;
    }

    novo_no->dados = novo;
    novo_no->proximo = lista->inicio;
    lista->inicio = novo_no;
    lista->qtde++;
    printf("Paciente cadastrado com sucesso!\n");
    
    // Limpa o buffer de entrada
    while (getchar() != '\n'); 
}

// Consulta paciente por RG
Registro* consultarPaciente(Lista *lista, const char *rg) {
    ELista *atual = lista->inicio;
    while (atual) {
        if (strcmp(atual->dados.rg, rg) == 0) {
            return &(atual->dados);
        }
        atual = atual->proximo;
    }
    return NULL;
}

// Mostra todos os pacientes
void mostrarLista(Lista *lista) {
    if (lista->qtde == 0) {
        printf("Nenhum paciente cadastrado.\n");
        return;
    }

    ELista *atual = lista->inicio;
    while (atual) {
        printf("Nome: %s\n", atual->dados.nome);
        printf("RG: %s\n", atual->dados.rg);
        printf("Idade: %d\n", atual->dados.idade);
        printf("Data: %02d/%02d/%04d\n\n", 
               atual->dados.entrada.dia, 
               atual->dados.entrada.mes, 
               atual->dados.entrada.ano);
        atual = atual->proximo;
    }
}

// Atualiza dados de um paciente
void atualizarPaciente(Lista *lista, const char *rg, Registro novos_dados) {
    ELista *atual = lista->inicio;
    while (atual) {
        if (strcmp(atual->dados.rg, rg) == 0) {
            // Mantém o RG original
            strcpy(novos_dados.rg, rg);
            atual->dados = novos_dados;
            printf("Dados atualizados com sucesso!\n");
            
            // Limpa o buffer de entrada
            while (getchar() != '\n');
            return;
        }
        atual = atual->proximo;
    }
    printf("Erro: Paciente não encontrado!\n");
    while (getchar() != '\n'); // Limpa o buffer mesmo em caso de erro
}

// Remove paciente da lista
void removerPaciente(Lista *lista, const char *rg) {
    ELista *atual = lista->inicio;
    ELista *anterior = NULL;

    while (atual) {
        if (strcmp(atual->dados.rg, rg) == 0) {
            if (anterior) {
                anterior->proximo = atual->proximo;
            } else {
                lista->inicio = atual->proximo;
            }
            free(atual);
            lista->qtde--;
            printf("Paciente removido!\n");
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    printf("Erro: Paciente não encontrado!\n");
}

// Libera memória da lista
void liberarLista(Lista *lista) {
    ELista *atual = lista->inicio;
    while (atual) {
        ELista *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    lista->inicio = NULL;
    lista->qtde = 0;
}
