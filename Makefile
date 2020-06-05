.PHONY: clean all run_Game_of_Life
FLAGS := -std=c99
FLAG := -std=c11
SRC_DIR := ./src
BIN_DIR := ./bin
OBJ_DIR := ./build
all: $(BIN_DIR)/Game_of_Life

$(BIN_DIR)/Game_of_Life:  $(OBJ_DIR)/main.o  $(OBJ_DIR)/curs_library.o  $(OBJ_DIR)/curs_neighbours.o
	gcc -Wall -Wextra  $(OBJ_DIR)/main.o  $(OBJ_DIR)/curs_library.o  $(OBJ_DIR)/curs_neighbours.o -o $(BIN_DIR)/Game_of_Life -lm $(FLAGS)

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c
	gcc -Wall -Wextra -c  $(SRC_DIR)/main.c -o  $(OBJ_DIR)/main.o $(FLAGS)

$(OBJ_DIR)/curs_library.o: $(SRC_DIR)/curs_library.c
		gcc -Wall -Wextra -c  $(SRC_DIR)/curs_library.c -o  $(OBJ_DIR)/curs_library.o -lm $(FLAGS)

$(OBJ_DIR)/curs_neighbours.o: $(SRC_DIR)/curs_neighbours.c
		gcc -Wall -Wextra -c  $(SRC_DIR)/curs_neighbours.c -o  $(OBJ_DIR)/curs_neighbours.o -lm $(FLAGS)

clean:
	rm $(OBJ_DIR)/*.o	
	rm $(BIN_DIR)/Game_of_Life

run_Game_of_Life:
	$(BIN_DIR)/Game_of_Life
