IDIR=../include
ODIR=obj

CC = gcc
CFLAGS = -O3 -Wall -g -I$(IDIR)

_DEPS = clientes.h produtos.h sales.h faturacao.h sort.h sgv.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o clientes.o produtos.o sales.o faturacao.o sort.o sgv.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f obj/*.o
	rm -f exe
	rm -f ..file/Vendas_1MValidas.txt
