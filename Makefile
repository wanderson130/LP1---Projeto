#MAKEFILE
RM = rm -rf 

# Compilador
CC=g++ 

# Variaveis para os subdiretorios
LIB_DIR=./lib
INC_DIR=./include
SRC_DIR=./src
OBJ_DIR=./build
BIN_DIR=./bin
DOC_DIR=./doc
TEST_DIR=./test
 
# Opcoes de compilacao
CFLAGS=-Wall -pedantic -ansi -std=c++11 -I. -I$(INC_DIR)

# Garante que os alvos desta lista nao sejam confundidos com arquivos de mesmo nome
.PHONY: all clean doxy debug doc

# Define o alvo (target) para a compilacao completa.
# Ao final da compilacao, remove os arquivos objeto.
all: empresa

debug: CFLAGS += -g -O0
debug: empresa

# Alvo (target) para a construcao do executavel
# Define os arquivos *.o como dependencias
empresa: $(OBJ_DIR)/funcionarios.o $(OBJ_DIR)/animais.o $(OBJ_DIR)/main1.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel 'empresa' criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto funcionarios.o
# Define os arquivos funcionarios.cpp e funcionarios.hpp como dependencias.
$(OBJ_DIR)/funcionarios.o: $(SRC_DIR)/funcionarios.cpp $(INC_DIR)/funcionarios.hpp
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a construcao do objeto animais.o
# Define os arquivos animais.cpp e animais.hpp como dependencias.
$(OBJ_DIR)/animais.o: $(SRC_DIR)/animais.cpp $(INC_DIR)/animais.hpp
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a construcao do objeto main1.o
# Define o arquivo main1.cpp como dependencia.
$(OBJ_DIR)/main1.o: $(SRC_DIR)/main1.cpp
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a geração automatica de documentacao usando o Doxygen.
# Sempre remove a documentacao anterior (caso exista) e gera uma nova.
doxy:
	$(RM) $(DOC_DIR)/*
	doxygen -g

doc:
	doxygen

# Alvo (target) usado para limpar os arquivos temporarios (objeto)
# gerados durante a compilacao, assim como os arquivos binarios/executaveis.
clean:
	$(RM) $(BIN_DIR)/* 
	$(RM) $(OBJ_DIR)/*
