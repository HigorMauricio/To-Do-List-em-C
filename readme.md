# Gerenciador de Tarefas (to-Do-List) em C

Este projeto é um gerenciador de tarefas (To-Do List) feito em linguagem C, utilizando lista ligada para armazenar as tarefas dinamicamente.

É utilizado um arquivo `.dat` criptografado pelo método XOR para o salvamento da lista.

## Funcionalidades

- Adicionar tarefa ao final, início ou em uma posição específica
- Remover tarefa do final, início ou de uma posição específica
- Visualizar todas as tarefas e seus status (concluída ou pendente)
- Marcar e desmarcar tarefas como concluídas
- Liberação automática de memória ao sair
- Criptografia das tarefas na lista para o seu salvamento e descriptografia para o carregamento de dados
- Salvamento, de forma binária, automática das tarefas em arquivo `.dat` e carregamento ao iniciar o programa

## Tecnologias Utilizadas

- **Linguagem:** C
- **Estrutura de Dados:** Lista Ligada
- **Conceitos:** Alocação Dinâmica de Memória, Ponteiros, Modularização de Código
- **Criptografia:** Cifra XOR para embaralhamento de dados binários
- **Automação de Build:** Makefile
- **Compilador:** GCC (via MinGW no Windows)

## Salvamento e Carregamento Automático

Todas as tarefas são salvas de forma binária e criptografada automaticamente no arquivo `lista.dat` ao sair do programa.  
Quando você executa o gerenciador novamente, suas tarefas são descriptografadas e carregadas desse arquivo, permitindo continuar de onde parou.

- O arquivo `lista.dat` é criado na mesma pasta do executável.
- Os dados de cada tarefa são salvos como um bloco de bytes sequencial no arquivo, e não em formato de texto legível..
  
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

## Exemplos

### Menu principal
![Image](imagens/tela_inicio.png)

### Visualização da lista após modificações

![Image](imagens/lista.png)

## Contribuição

Sinta-se à vontade para abrir issues ou pull requests com sugestões, correções ou melhorias!

