#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"
#include "cadastro/cadastro.h"
#include "atendimento/atendimento.h" 

// Função para exibir os dados do desenvolvedor
void menu_sobre() {
    printf("\n=== SOBRE ===\n");
    printf("Nome do aluno: Hanna de Oliveira Melo\n");
    printf("Ciclo: 4 ciclo\n");
    printf("Curso: Ciencia da Computacao\n");
    printf("Disciplina: Estrutura de Dados\n");
    printf("Data: 03/05/2025\n");
}

// Função para o menu de cadastro
void menu_cadastrar(Lista *lista) {
    int opcao;
    char rg[20];
    Registro *paciente;

    do {
        printf("\n=== CADASTRAR PACIENTES ===\n");
        printf("1. Cadastrar novo paciente\n");
        printf("2. Consultar paciente\n");
        printf("3. Mostrar lista completa\n");
        printf("4. Atualizar dados de paciente\n");
        printf("5. Remover paciente\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                Registro novo;
                printf("\n--- NOVO PACIENTEee ---\n");
                printf("Nome: ");
                scanf(" %99[^\n]", novo.nome);
                printf("Idade: ");
                scanf("%d", &novo.idade);
                
                // Limpa o buffer do teclado
                while(getchar() != '\n');
                
                printf("RG: ");
                scanf(" %19[^\n]", novo.rg);
                
                // Leitura robusta da data
                int dia, mes, ano;
                do {
                    printf("Data de cadastro (DD MM AAAA): ");
                    int result = scanf("%d %d %d", &dia, &mes, &ano);
                    
                    
                    if(result != 3) {
                        printf("Formato invalido! Use DD MM AAAA\n");
                        continue;
                    }
                    
                    // Validação básica da data
                    if(dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano < 1900 || ano > 2100) {
                        printf("Data invalida! Valores aceitos:\n");
                        printf("Dia: 1-31\nMes: 1-12\nAno: 1900-2100\n");
                        continue;
                    }
                    break;
                } while(1);
                
                novo.entrada.dia = dia;
                novo.entrada.mes = mes;
                novo.entrada.ano = ano;
                
                cadastrarPaciente(lista, novo);
                break;
            }
            case 2: {
                printf("\n--- CONSULTAR PACIENTE ---\n");
                printf("Digite o RG: ");
                scanf(" %19[^\n]", rg);
                paciente = consultarPaciente(lista, rg);
                
                if (paciente != NULL) {
                    printf("\nDADOS DO PACIENTE:\n");
                    printf("Nome: %s\n", paciente->nome);
                    printf("Idade: %d\n", paciente->idade);
                    printf("RG: %s\n", paciente->rg);
                    printf("Data de cadastro: %02d/%02d/%04d\n", 
                           paciente->entrada.dia, 
                           paciente->entrada.mes, 
                           paciente->entrada.ano);
                } else {
                    printf("Paciente não encontrado!\n");
                }
                break;
            }
            case 3: {
                printf("\n--- LISTA COMPLETA DE PACIENTES ---\n");
                mostrarLista(lista);
                break;
            }
            case 4: {
                printf("\n--- ATUALIZAR DADOS ---\n");
                printf("Digite o RG do paciente: ");
                scanf(" %19[^\n]", rg);
                
                Registro novos_dados;
                printf("Novo nome: ");
                scanf(" %99[^\n]", novos_dados.nome);
                printf("Nova idade: ");
                scanf("%d", &novos_dados.idade);
                printf("Nova data de cadastro (DD MM AAAA): ");
                scanf("%d %d %d", &novos_dados.entrada.dia, &novos_dados.entrada.mes, &novos_dados.entrada.ano);
                
                atualizarPaciente(lista, rg, novos_dados);
                break;
            }
            case 5: {
                printf("\n--- REMOVER PACIENTE ---\n");
                printf("Digite o RG do paciente: ");
                scanf(" %19[^\n]", rg);
                removerPaciente(lista, rg);
                break;
            }
            liberarLista(lista);
        }
    } while (opcao != 0);
}

void menu_atendimento(Lista *lista_pacientes, Fila *fila_atendimento) {
    int opcao;
    char rg[20];
    Registro *paciente;
    
    do {
        printf("\n=== MENU ATENDIMENTO ===\n");
        printf("1. Adicionar paciente a fila\n");
        printf("2. Chamar proximo paciente\n");
        printf("3. Mostrar fila de atendimento\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        
        while(getchar() != '\n');  // Limpa buffer
        
        switch(opcao) {
            case 1:
                printf("Digite o RG do paciente: ");
                scanf(" %19[^\n]", rg);
                paciente = consultarPaciente(lista_pacientes, rg);
                
                if (paciente) {
                    enfileirarPaciente(fila_atendimento, paciente);
                    printf("Paciente adicionado a fila!\n");
                } else {
                    printf("Paciente não encontrado!\n");
                }
                break;
                
            case 2:
                paciente = desenfileirarPaciente(fila_atendimento);
                if (paciente) {
                    printf("\n--- PROXIMO PACIENTE ---\n");
                    printf("Nome: %s\n", paciente->nome);
                    printf("RG: %s\n", paciente->rg);
                } else {
                    printf("Fila vazia!\n");
                }
                break;
                
            case 3:
                mostrarFila(fila_atendimento);
                break;
        }
    } while(opcao != 0);
}

int main() {
    Lista lista;
    Fila fila_atendimento;

    inicializarLista(&lista);
    inicializarFila(&fila_atendimento);
    int opcao;

    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. SOBRE\n");
        printf("2. CADASTRAR\n");
        printf("3. ATENDIMENTO\n");  // <-- Nova opção
        printf("0. SAIR\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1: 
                menu_sobre();
                break;
            case 2:
                menu_cadastrar(&lista);
                break;
            case 3:  // <-- Novo caso
                menu_atendimento(&lista, &fila_atendimento);
                break;
            case 0:
                printf("Encerrando o sistema...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 0);

    liberarLista(&lista);
    return 0;
}
