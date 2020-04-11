CC = gcc
INCLUDE = -I include
CFLAGS = -Wno-unused-result -O3 -Wall -g -ansi

SRC := src
OBJ := obj

SOURCES := $(wildcard $(SRC)/*.c)

SOURCES := $(filter-out $(SRC)/teste.c, $(SOURCES))
NAME = program

OBJECTS := $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SOURCES))

program: $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(NAME) $(OBJECTS)
	@echo Compilado

docs:
	doxygen Doxyfile
	@echo Documentação gerada

clean:
	rm -r $(OBJ)
	rm -f program
	rm -r docs/html

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(shell mkdir -p $(OBJ))
