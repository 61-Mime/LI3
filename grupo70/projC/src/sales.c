#include "sales.h"

#define SMAX 10
#define MAX 64
#define SIZE 26

THashSales* initSales() {
  THashSales* sales = malloc(sizeof(THashSales));
  int i;

  sales->nValidas = 0;
  sales->nLidas = 0;

  for(i=0; i<SIZE * 3; i++) {
    sales->tblp[i].size2 = 0;
    sales->tblp[i].list = NULL;

    sales->tblc[i].size2 = 0;
    sales->tblc[i].list = NULL;
  }

  return sales;
}

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
void saleS(THashSales* sales, char* buffer, Catalogo* tprod, Catalogo* tcli) {
  char *aux = NULL, *prod = NULL, *cli = NULL, *type = NULL;
  int hashp, hashc, posp=0, posc=0, size;
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
    size = sales->tblp[hashp].list[posp].size3;

    sales->tblp[hashp].list[posp].venda = realloc(sales->tblp[hashp].list[posp].venda, sizeof(Sale) * (size + 1));
    sales->tblp[hashp].list[posp].venda[size].p = sales->tblp[hashp].list[posp].key;
    sales->tblp[hashp].list[posp].venda[size].price = price;
    sales->tblp[hashp].list[posp].venda[size].uni = uni;
    sales->tblp[hashp].list[posp].venda[size].type = malloc(sizeof(char) * 3);
    strcpy(sales->tblp[hashp].list[posp].venda[size].type,type);
    sales->tblp[hashp].list[posp].venda[size].c = malloc(sizeof(char) * SMAX);
    strcpy(sales->tblp[hashp].list[posp].venda[size].c,cli);
    sales->tblp[hashp].list[posp].venda[size].month = month;
    sales->tblp[hashp].list[posp].venda[size].branch = branch;
    sales->tblp[hashp].list[posp].size3++;

    size = sales->tblc[hashc].list[posc].size3;

    sales->tblc[hashc].list[posc].venda = realloc(sales->tblc[hashc].list[posc].venda ,sizeof(Sale) * (size + 1));
    sales->tblc[hashc].list[posc].venda[size].p = malloc(sizeof(char) * SMAX);
    strcpy(sales->tblc[hashc].list[posc].venda[size].p,prod);
    sales->tblc[hashc].list[posc].venda[size].price = price;
    sales->tblc[hashc].list[posc].venda[size].uni = uni;
    sales->tblc[hashc].list[posc].venda[size].type = malloc(sizeof(char) * 3);
    strcpy(sales->tblc[hashc].list[posc].venda[size].type,type);
    sales->tblc[hashc].list[posc].venda[size].c = sales->tblc[hashc].list[posc].key;
    sales->tblc[hashc].list[posc].venda[size].month = month;
    sales->tblc[hashc].list[posc].venda[size].branch = branch;
    sales->tblc[hashc].list[posc].size3++;

    sales->nValidas++;
  }

  sales->nLidas++;
}

void copyTbl(THashSales* sales, Catalogo* tprod, Catalogo* tcli) {
  int i, j;
  int sizeP, sizeC;

  for(i=0; i<SIZE; i++) {
    sizeP = getCatListSize(tprod, i);
    sales->tblp[i].list = malloc(sizeof(List) * sizeP);
    sales->tblp[i].size2 = sizeP;

    sizeC = getCatListSize(tcli, i);
    sales->tblc[i].list = malloc(sizeof(List) * sizeC);
    sales->tblc[i].size2 = sizeC;

    for(j=0; j<sizeP; j++) {

      sales->tblp[i].list[j].key = malloc(sizeof(char) * SMAX);
      strcpy(sales->tblp[i].list[j].key, getCatKey(tprod, i, j));

      sales->tblp[i].list[j].size3 = 0;
      sales->tblp[i].list[j].venda = NULL;
    }

    for(j=0; j<sizeC; j++) {
      sales->tblc[i].list[j].key = malloc(sizeof(char) * SMAX);
      strcpy(sales->tblc[i].list[j].key, getCatKey(tcli, i, j));

      sales->tblc[i].list[j].size3 = 0;
      sales->tblc[i].list[j].venda = NULL;
    }
  }
}

// Abre o array das vendas e passa-as para uma struct
int tblSales(THashSales * sales, Catalogo* tprod, Catalogo* tcli, char* filePath) {
  FILE *fsales;
  char* buffer= malloc(sizeof(char) * MAX);

  if((fsales = fopen(filePath, "r")) == NULL) {
    perror(filePath);
    return -1;
  }

  copyTbl(sales, tprod, tcli);

  while(fgets(buffer,MAX,fsales)) {
    buffer = strsep(&buffer, "\r");
    saleS(sales, buffer, tprod, tcli);
  }  

  fclose(fsales);

  return 0;
}

void freeSales(THashSales* sales) {
  int i, j;

  for(i=0; i<SIZE; i++) {
    for(j=0 ;j<sales->tblc[i].size2; j++) {
      free(sales->tblc[i].list[j].venda);
      free(sales->tblc[i].list[j].key);
    }
    free(sales->tblc[i].list);
  }

  for(i=0; i<SIZE; i++) {
    for(j=0 ;j<sales->tblp[i].size2; j++) {
      free(sales->tblp[i].list[j].venda);
      free(sales->tblp[i].list[j].key);
    }
    free(sales->tblp[i].list);
  }

  free(sales);
}
