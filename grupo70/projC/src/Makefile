IDIR=../include
ODIR=obj

CC = gcc
CFLAGS = -O3 -Wall -g -ansi -D_GNU_SOURCE -I$(IDIR)

_DEPS = catalogo.h sales.h faturacao.h filial.h sgv.h interface.h auxintrepertador.h querie.h apresentacao.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o catalogo.o sales.o faturacao.o filial.o sgv.o interface.o auxintrepertador.o querie.o apresentacao.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

program: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	doxygen Doxyfile &> /dev/null

clean:
	rm -f obj/*.o
	rm -f program
	rm -rf ../docs/html
