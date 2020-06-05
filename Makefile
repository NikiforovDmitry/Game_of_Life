.PHONY: clean all run_Game_of_Life run_testing
FLAGS := -std=c99
FLAG := -std=c11
SRC_DIR := ./src
BIN_DIR := ./bin
OBJ_DIR := ./build
OBJ_TEST_DIR := ./build/test
TEST_DIR := ./test
all: $(BIN_DIR)/Game_of_Life $(BIN_DIR)/testing

$(BIN_DIR)/Game_of_Life:  $(OBJ_DIR)/main.o  $(OBJ_DIR)/curs_library.o  $(OBJ_DIR)/curs_neighbours.o
	gcc -Wall -Wextra  $(OBJ_DIR)/main.o  $(OBJ_DIR)/curs_library.o  $(OBJ_DIR)/curs_neighbours.o -o $(BIN_DIR)/Game_of_Life -lm $(FLAGS)

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c
	gcc -Wall -Wextra -c  $(SRC_DIR)/main.c -o  $(OBJ_DIR)/main.o $(FLAGS)

$(OBJ_DIR)/curs_library.o: $(SRC_DIR)/curs_library.c
		gcc -Wall -Wextra -c  $(SRC_DIR)/curs_library.c -o  $(OBJ_DIR)/curs_library.o -lm $(FLAGS)

$(OBJ_DIR)/curs_neighbours.o: $(SRC_DIR)/curs_neighbours.c
		gcc -Wall -Wextra -c  $(SRC_DIR)/curs_neighbours.c -o  $(OBJ_DIR)/curs_neighbours.o -lm $(FLAGS)

$(BIN_DIR)/testing: $(OBJ_TEST_DIR)/main.o $(OBJ_TEST_DIR)/curs_neighbours_test.o $(OBJ_DIR)/curs_neighbours.o
		gcc   $(OBJ_TEST_DIR)/main.o  $(OBJ_TEST_DIR)/curs_neighbours_test.o  $(OBJ_DIR)/curs_neighbours.o -o $(BIN_DIR)/testing -lm $(FLAG)

$(OBJ_TEST_DIR)/main.o: $(TEST_DIR)/main.c
	gcc -I thirdparty -I src -c $(TEST_DIR)/main.c -o  $(OBJ_TEST_DIR)/main.o $(FLAG)

$(OBJ_TEST_DIR)/curs_neighbours_test.o: $(TEST_DIR)/curs_neighbours_test.c
	gcc -I thirdparty -I src -c $(TEST_DIR)/curs_neighbours_test.c -o  $(OBJ_TEST_DIR)/curs_neighbours_test.o -lm $(FLAG)

clean:
	rm $(OBJ_DIR)/*.o	
	rm $(BIN_DIR)/Game_of_Life
	rm $(OBJ_TEST_DIR)/*.o	
	rm $(BIN_DIR)/testing

run_Game_of_Life:
	$(BIN_DIR)/Game_of_Life

run_testing:
	$(BIN_DIR)/testing
