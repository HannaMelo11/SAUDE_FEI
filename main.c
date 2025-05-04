#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"
#include "cadastro.h"

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
                printf("\n--- NOVO PACIENTE ---\n");
                printf("Nome: ");
                scanf(" %99[^\n]", novo.nome);
                printf("Idade: ");
                scanf("%d", &novo.idade);
                printf("RG: ");
                scanf(" %19[^\n]", novo.rg);
                printf("Data de cadastro (DD MM AAAA): ");
                scanf("%d %d %d", &novo.entrada.dia, &novo.entrada.mes, &novo.entrada.ano);
                
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
        }
    } while (opcao != 0);
}

int main() {
    Lista lista;
    inicializarLista(&lista);
    int opcao;

    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. SOBRE\n");
        printf("2. CADASTRAR\n");
        printf("0. SAIR\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                menu_sobre();
                break;
            case 2:
                menu_cadastrar(&lista);
                break;
            case 0:
                printf("Encerrando o sistema...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    liberarLista(&lista);
    return 0;
}
