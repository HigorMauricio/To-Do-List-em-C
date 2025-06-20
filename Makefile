CC = gcc
CRFLAGS = -Wall -Wextra -Iinclude
SRC = src/main.c src/tarefas.c 
OBJ = main.o tarefas.o 
EXEC = gerenciador_tarefas

$(EXEC): $(OBJ)
	$(CC) $(CRFLAGS) -o $(EXEC) $(OBJ)

main.o: src/main.c include/tarefas.h
	$(CC) $(CRFLAGS) -c src/main.c -o main.o 

tarefas.o: src/tarefas.c include/tarefas.h
	$(CC) $(CRFLAGS) -c src/tarefas.c -o tarefas.o 

clean:
	rm -f $(OBJ) $(EXEC)