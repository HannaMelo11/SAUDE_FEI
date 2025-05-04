📋 Sistema de Gerenciamento de Saúde - Estrutura de Dados
📌 Visão Geral
Projeto desenvolvido para a disciplina de Estrutura de Dados (4º ciclo de Ciência da Computação) que implementa um sistema completo de gerenciamento de pacientes com múltiplas estruturas de dados interconectadas.

🏗️ Estrutura do Projeto
saude_fei/
├── main.c                # Programa principal e menus
├── estruturas.h          # Tipos de dados compartilhados
├── cadastro/
│   ├── cadastro.h        # Interface do módulo
│   └── cadastro.c        # Implementação (lista encadeada)
├── atendimento/
│   ├── atendimento.h     # Interface da fila normal
│   └── atendimento.c
├── prioritario/
│   ├── prioritario.h     # Interface da fila prioritária (heap)
│   └── prioritario.c
├── pesquisa/
│   ├── pesquisa.h        # Interface da árvore binária
│   └── pesquisa.c
└── desfazer/
    ├── desfazer.h        # Interface da pilha de operações
    └── desfazer.c
🔧 Funcionalidades Implementadas
1. Módulo de Cadastro (Lista Encadeada)
void cadastrarPaciente(Lista *lista, Registro novo)

Registro* consultarPaciente(Lista *lista, const char *rg)

void mostrarLista(Lista *lista)

void atualizarPaciente(Lista *lista, const char *rg, Registro novos_dados)

void removerPaciente(Lista *lista, const char *rg)

2. Módulo de Atendimento (Fila)
void enfileirarPaciente(Fila *fila, Registro *paciente)

Registro* desenfileirarPaciente(Fila *fila)

void mostrarFila(Fila *fila)

3. Módulo Prioritário (Heap Máximo)
void inserirPrioritario(FilaPrioritaria *fila, Registro *paciente)

Registro* removerPrioritario(FilaPrioritaria *fila)

4. Módulo de Pesquisa (Árvore Binária)
void inserirNaArvore(Arvore *arvore, Registro *paciente, int criterio)

void mostrarArvore(NoArvore *raiz, int criterio)

5. Módulo Desfazer (Pilha)
void empilharOperacao(PilhaLog *pilha, const char *descricao, Registro *paciente)

Operacao desempilharOperacao(PilhaLog *pilha)
