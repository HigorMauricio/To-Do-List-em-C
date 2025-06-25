#ifndef TAREFAS_H
#define TAREFAS_H
#define MAX_CARACTER 100
#define CHAVE 100

typedef struct Tarefa {
    char descricao[MAX_CARACTER];
    int concluida; //0 nao concluida, 1 concluida
} Tarefa;

typedef struct No {
    Tarefa tarefa;
    struct No* proximo;
} No;

//criar lista-to-do
No* criar_lista();

//criar no
No* criar_no();

//criar tarefa
Tarefa* criar_tarefa();

//visualizar lista
void visualizar_lista(No* lista);

//inserir tarefa
void inserir_tarefa_final(No** lista);
void inserir_tarefa_inicio(No** lista);
void inserir_tarefa_posicao(No** lista);

//remover tarefa
void remover_tarefa_final(No** lista);
void remover_tarefa_inicio(No** lista);
void remover_tarefa_posicao(No** lista);

//alterar conclusa da tarefa
void marcar_concluido(No** lista);
void desmarcar_concluido(No** lista);

//apagar llista
void apagar_lista(No** lista);

//salvar lista
void salvar_lista(No* lista);

//carregar lista
void carregar_lista(No** lista);

//adicionar tarefa carregada
void adicionar_tarefa_carregada(No** lista, Tarefa tarefa);

//criptografar as tarefas antes de salvar
void criptografar(void *tarefa, size_t tamanho, char chave);

#endif