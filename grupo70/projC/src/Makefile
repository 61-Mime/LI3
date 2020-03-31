IDIR=../include
ODIR=obj

CC = gcc
CFLAGS = -O3 -Wall -g -I$(IDIR)

_DEPS = clientes.h produtos.h sales.h faturacao.h filial.h sort.h sgv.h querie.h intrepertador.h apresentacao.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o clientes.o produtos.o sales.o faturacao.o filial.o sort.o sgv.o querie.o intrepertador.o  apresentacao.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

program: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f obj/*.o
	rm -f program
	rm -f ..file/Vendas_1MValidas.txt
