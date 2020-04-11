CC = gcc
INCLUDE = -I include
CFLAGS = -O3 -Wall -g -ansi

SRC := src
OBJ := obj

SOURCES := $(wildcard $(SRC)/*.c)

ifeq ($(TESTE),yes)
	SOURCES := $(filter-out $(SRC)/main.c, $(SOURCES))
	NAME = teste
else
	SOURCES := $(filter-out $(SRC)/teste.c, $(SOURCES))
	NAME = program
endif

OBJECTS := $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SOURCES))

all: $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(NAME) $(OBJECTS)
	@echo Compilado
	doxygen src/Doxyfile &> /dev/null
	@echo Documentação gerada

clean:
	rm -r $(OBJ)
	rm -f program
	rm -f teste

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(shell mkdir -p $(OBJ))
