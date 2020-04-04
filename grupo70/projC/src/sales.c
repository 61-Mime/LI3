#include "sales.h"

#define SMAX 10
#define MAX 64
#define SIZE 26

int vendaVal(int posp, int posc, float preco, int uni, char type, int mes, int branch) {
  int r;
  if(posp!=(-1) && posc!=(-1) && preco >= 0.0 && preco < 1000.0
    && uni > 0 && uni <= 200 && (type == 'N' || type == 'P')
    && mes > 0 && mes <= 12 && branch > 0 && branch <= 3)
    r = 1;
  else
    r = 0;

  return r;
}

// Corre uma venda, passa para a struct total e se for válida passa a struct valida
void saleS(Catalogo* tprod, Catalogo* tcli, THashFact* fact, GFiliais* gfil, char* buffer, int* val, int* lida) {
  char *aux = NULL, *prod = NULL, *cli = NULL, *type = NULL;
  int hashp, hashc, posp=0, posc=0;
  int uni, month, branch;
  float price;

  aux = strsep(&buffer, " ");
  prod = aux;

  aux = strsep(&buffer, " ");
  price = atof(aux);

  aux = strsep(&buffer, " ");
  uni = atoi(aux);

  aux = strsep(&buffer, " ");
  type = aux;

  aux = strsep(&buffer, " ");
  cli = aux;

  aux = strsep(&buffer, " ");
  month = atoi(aux);

  aux = strsep(&buffer, " ");
  branch = atoi(aux);

  hashc = hashCat(cli[0]);
  hashp = hashCat(prod[0]);

  posc = searchCat(cli, tcli);

  if(posc != (-1))
    posp = searchCat(prod, tprod);

  if(vendaVal(posp,posc,price,uni,type[0],month,branch)) {
    addFact(fact, hashp, posp, month, branch, type[0], price, uni);
    addGFilP(gfil, hashp, posp, cli, branch, type[0]);
    addGFilC(gfil, hashc, posc, prod, branch, month, price, uni);

    (*val)++;
  }

  (*lida)++;
}

// Abre o array das vendas e passa-as para uma struct
int loadFromSales(Catalogo* tprod, Catalogo* tcli, THashFact* fact, GFiliais* gfil, char* filePath, int* val, int* lida) {
  FILE *fsales;
  char* buffer= malloc(sizeof(char) * MAX);

  if((fsales = fopen(filePath, "r")) == NULL) {
    perror(filePath);
    return -1;
  }

  while(fgets(buffer,MAX,fsales)) {
    buffer = strsep(&buffer, "\r");
    saleS(tprod, tcli, fact, gfil, buffer, val, lida);
  }
  remRepC(gfil);

  fclose(fsales);

  free(buffer);

  return 0;
}
