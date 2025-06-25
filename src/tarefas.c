#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tarefas.h"

Tarefa* criar_tarefa(){
    Tarefa* tarefa = (Tarefa*) malloc(sizeof(Tarefa));

    //verificação do malloc
    if(tarefa == NULL){
        printf("Erro de alocacao de memoria ao criar tarefa\n");
        return NULL;
    }

    printf("Digite a descricao da tarefa: ");
    tarefa -> concluida = 0;
    fgets(tarefa -> descricao, MAX_CARACTER, stdin);

    return tarefa;
}

No* criar_no(){
     //criação de um novo nó
    No* novo_no = (No*)malloc(sizeof(No));

    //verificação do malloc
    if(novo_no == NULL){
        printf("Erro de alocação de memoria\n");
        return NULL;
    }

    return novo_no;
}

No* criar_lista(){
    No* lista_to_do = NULL;
    return lista_to_do;
}

void visualizar_lista(No* lista){
    //se lista estievr vazia
    if(lista == NULL){
        printf("Lista vazia!\n");
        return;
    }

    No* temporario = lista;
    printf("\n--- Sua Lista de Tarefas ---\n");
    int contador = 1;
    while(temporario != NULL){
        Tarefa tarefa = temporario -> tarefa;
        printf("\nTAREFA-%d\n", contador);
        printf("%s", tarefa.descricao);
        if(tarefa.concluida){
            printf("Concluida\n");
        }else{
            printf("Pendente\n");
        }
        contador ++;
        temporario = temporario -> proximo;
    }

    printf("\n---------------------------\n");
}

void inserir_tarefa_final(No** lista){
    //criar tarefa
    Tarefa* tarefa = criar_tarefa();

    //criacao do novo no
    No* novo_no = criar_no();

    novo_no -> tarefa = *tarefa;
    free(tarefa);
    novo_no -> proximo = NULL;

    if(*lista == NULL){
        *lista = novo_no;
    } else{
        No* temporario = *lista;
        while(temporario -> proximo != NULL){
            temporario = temporario -> proximo;
        }

        temporario -> proximo = novo_no;
    }
}

void inserir_tarefa_inicio(No** lista){
    // criação de uma nova tarefa
    Tarefa* tarefa = criar_tarefa();

    //criação de um novo nó
    No* novo_no = criar_no();

    novo_no -> tarefa = *tarefa;
    free(tarefa);
    novo_no -> proximo = *lista;
    *lista = novo_no;
}

void inserir_tarefa_posicao(No** lista){

    int posicao;
    printf("Informe a posicao: ");
    scanf("%d", &posicao);
    getchar(); //remoção do \n no buffer

    posicao --;
    if(posicao == 0 || *lista == NULL){
        inserir_tarefa_inicio(lista);
    } else {
        //criação de uma nova tarefa
        Tarefa* tarefa = criar_tarefa();

        //criação de um novo nó
        No* novo_no = criar_no();

        novo_no -> tarefa = *tarefa;
        free(tarefa);

        No* temporario = *lista;
        for(int i=0; i < posicao - 1 && temporario != NULL; i++){
            temporario = temporario -> proximo;
        }

        if(temporario == NULL){
            printf("Posicao Invalida! posicao maior que a lista atual\n");
            return;
        }

        novo_no -> proximo = temporario -> proximo;
        temporario -> proximo = novo_no;
    }
}

void remover_tarefa_final(No** lista){
    //cado de lista vazia
    if(*lista == NULL){
        printf("Lista vazia! Nada para remover.\n");
        return;
    }
    //caso de so ter um nó
    if((*lista) -> proximo == NULL){
        free(*lista);
        *lista = NULL;
        return;
    }

    No* temporario = *lista;
    while(temporario -> proximo -> proximo != NULL){
        temporario = temporario -> proximo;
    }

    free(temporario -> proximo);
    temporario -> proximo = NULL;
}

void remover_tarefa_inicio(No** lista){
    //caso de lista vazia
    if(*lista == NULL){
        printf("Lista vazia! Nada para remover\n");
        return;
    }

    No* temporario = *lista;
    *lista = (*lista) -> proximo;
    free(temporario);
}

void remover_tarefa_posicao(No** lista){
    //caso de lista vazia
    if(*lista == NULL){
        printf("Lista vazia! Nada para remover\n");
        return;
    }

    int posicao;
    printf("Informe a posicao: ");
    scanf("%d", &posicao);
    getchar(); //remoção do \n no buffer
    posicao --;

    No* temporario = *lista;

    if(posicao == 0){
        remover_tarefa_inicio(lista);
    } else{
        for(int i=0; i < posicao - 1 && temporario != NULL; i++){
            temporario = temporario -> proximo;
        }

        if(temporario -> proximo == NULL || temporario == NULL){
            printf("Posicao Invalida! posicao maior que a lista atual\n");
            return;
        }

        No* temporario_remover = temporario -> proximo;
        temporario -> proximo = temporario_remover -> proximo;
        free(temporario_remover);
    }
}

void marcar_concluido(No** lista){
    //verificação se a lista esta vazia
    if(*lista == NULL){
        printf("Lista vazia!zn");
        return;
    }

    int opcao;
    printf("Informe a tarefa: ");
    scanf("%d", &opcao);
    getchar();
    opcao --;

    No* temporario = *lista;
    for(int i=0; i<opcao && temporario != NULL; i++){
        temporario = temporario -> proximo;
    }

    if(temporario == NULL){
        printf("Tarefa nao existente!\n");
        return;
    }

    //verificação se ja esta concluida
    if((temporario -> tarefa).concluida){
        printf("Tarefa ja marcada como concluida,\n");
    } else{
        (temporario -> tarefa).concluida = 1;
        printf("Tarefa marcada como concluida.\n");
    }
}

void desmarcar_concluido(No** lista){
    if(*lista == NULL){
        printf("Lista Vazia!\n");
        return;
    }

    int opcao;
    printf("Informe a tarefa: ");
    scanf("%d", &opcao);
    getchar();
    opcao --;

    No* temporario = *lista;
    for(int i=0; i<opcao && temporario != NULL; i++){
        temporario = temporario -> proximo;
    }

    if(temporario == NULL){
        printf("Tarefa nao existente!\n");
        return;
    }

    if((temporario->tarefa).concluida == 0){
        printf("Tarefa ja esta desmarcada.\n");
    } else{
        (temporario -> tarefa).concluida = 0;
        printf("Tarefa desmarcada como concluida.\n");
    }

}

void apagar_lista(No** lista){
    while(*lista != NULL){
        No* temporario = *lista;
        *lista = (*lista) -> proximo;
        free(temporario);
    }
}

void salvar_lista(No* lista){
    FILE *arquivo = fopen("lista.txt", "w");
    if(arquivo == NULL) {
        printf("Erro ao salvar lista\n");
        return;
    }

    No* temporario = lista;
    while(temporario != NULL){
        fprintf(arquivo, "%d %s", (temporario -> tarefa).concluida, (temporario -> tarefa).descricao);
        temporario = temporario -> proximo;
    }
    fclose(arquivo);
    printf("Lista salva com sucesso\n");
}

void adicionar_tarefa_carregada(No** lista, Tarefa tarefa){
    No* novo_no = criar_no();

    novo_no->tarefa = tarefa;
    novo_no->proximo = NULL;

    if(*lista == NULL){
        *lista = novo_no;
    }
    else{
        No* temporario = *lista;
        while(temporario -> proximo != NULL){
            temporario = temporario -> proximo;
        }

        temporario -> proximo = novo_no;
    }
}

void carregar_lista(No** lista){
    FILE *arquivo = fopen("lista.txt", "r");

    //caso da lista vazia
    if(arquivo == NULL){
        printf("Nenhuma lista encontrar, iniciando uma nova lista\n");
        return;
    }
    Tarefa tarefa;
    while(fscanf(arquivo, "%d ", &(tarefa.concluida)) == 1){
        
        if(fgets(tarefa.descricao, MAX_CARACTER, arquivo) == NULL){
            break;
        }

        adicionar_tarefa_carregada(lista, tarefa);
    }
    
}