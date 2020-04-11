CC = gcc
INCLUDE = -I include
CFLAGS = -Wunused-command-line-argument -O3 -Wall -g -ansi

SRC := src
OBJ := obj

SOURCES := $(wildcard $(SRC)/*.c)

SOURCES := $(filter-out $(SRC)/teste.c, $(SOURCES))
NAME = program

OBJECTS := $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SOURCES))

program: $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(NAME) $(OBJECTS)
	@echo Compilado

.PHONY: docs
docs:
	doxygen Doxyfile
	@echo Documentação gerada

.PHONY: clean
clean:
	rm -r $(OBJ)
	rm -f program

.PHONY: clean
cleanall: clean
	rm -r docs/html

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(shell mkdir -p $(OBJ))
