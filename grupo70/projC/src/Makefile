IDIR=../include
ODIR=obj

CC = gcc
CFLAGS = -O3 -Wall -g -I$(IDIR)

_DEPS = catalogo.h sales.h faturacao.h filial.h sort.h sgv.h 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o catalogo.o sales.o faturacao.o filial.o sort.o sgv.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

program: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	doxygen Doxyfile

clean:
	rm -f obj/*.o
	rm -f program
