#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tarefas.h"

void exibir_menu(){
    printf("\n--- Gerenciador de Tarefas ---\n");
    printf("1. Adicionar Tarefa\n");
    printf("2. Remover Tarefa\n");
    printf("3. Visualizar Tarefas\n");
    printf("4. Marcar como concluida\n");
    printf("5. Desmarcar concluido\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
}

int main(){
    //criação da lista-to-do
    No* lista_to_do = criar_lista();
    int opcao;

    do{
        exibir_menu();
        scanf("%d", &opcao);
        getchar(); //limpar o buffer do teclado 

        switch(opcao){
            case 1: {
                int escolha;
                printf("\n");
                printf("1. Adicionar tarefa ao final\n");
                printf("2. Adicionar tarefa ao inicio\n");
                printf("3. Adicionar tarefa em uma determinada posicao\n");
                printf("Escolha uma opcao: ");
                scanf("%d", &escolha);
                getchar();

                switch(escolha){
                    case 1:{
                        inserir_tarefa_final(&lista_to_do);
                        break;
                    }
                    case 2:{
                        inserir_tarefa_inicio(&lista_to_do);
                        break;
                    }
                    case 3:{
                        inserir_tarefa_posicao(&lista_to_do);
                        break;
                    }
                }
                break;
            }
            case 2:{
                int escolha;
                printf("\n");
                printf("1. Remover tarefa ao final\n");
                printf("2. Remover tarefa ao inicio\n");
                printf("3. Remover tarefa em uma determinada posicao\n");
                printf("Escolha uma opcao: ");
                scanf("%d", &escolha);
                getchar();

                switch(escolha){
                    case 1:{
                        remover_tarefa_final(&lista_to_do);
                        break;
                    }
                    case 2:{
                        remover_tarefa_inicio(&lista_to_do);
                        break;
                    }
                    case 3:{
                        remover_tarefa_posicao(&lista_to_do);
                        break;
                    }
                }
                break;
            }
            case 3:{
                visualizar_lista(lista_to_do);
                break;
            }
            case 4:{
                marcar_concluido(&lista_to_do);
                break;
            }
            case 5:{
                desmarcar_concluido(&lista_to_do);
                break;
            }
            default:
                printf("Opcao Invalida!\n");
                break;
        }
    }while(opcao != 0);

    apagar_lista(&lista_to_do);

    return 0;
}