# Gerenciador de Tarefas (to-Do-List) em C

Este projeto é um gerenciador de tarefas (To-Do List) feito em linguagem C, utilizando lista ligada para armazenar as tarefas dinamicamente.

## Funcionalidades

- Adicionar tarefa ao final, início ou em uma posição específica
- Remover tarefa do final, início ou de uma posição específica
- Visualizar todas as tarefas e seus status (concluída ou pendente)
- Marcar e desmarcar tarefas como concluídas
- Liberação automática de memória ao sair

## Estrutura do Projeto

```
.
├── include/
│   └── tarefas.h
├── src/
│   ├── main.c
│   └── tarefas.c
├── Makefile
```

## Como compilar

No terminal, execute:

```sh
mingw32-make
```
ou, se estiver em Linux:

```sh
make
```

## Como executar

No Windows:
```sh
.\gerenciador_tarefas
```
No Linux:
```sh
./gerenciador_tarefas
```

## Uso

O programa apresenta um menu interativo para gerenciar suas tarefas. Basta seguir as instruções na tela para adicionar, remover, visualizar ou marcar tarefas.

## Exeplos

### Menu principal
![Image](imagens/tela_inicio.png)

### Visualização da lista após modificaçõs

![Image](imagens/lista.png)

## Contribuição

Sinta-se à vontade para abrir issues ou pull requests com sugestões, correções ou melhorias!

