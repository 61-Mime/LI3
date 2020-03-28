#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sales.h"

#define SMAX 10
#define MAX 64
#define SIZEP 26
#define SIZEC 26

THashSales* initSales() {
  THashSales* sales = malloc(sizeof(THashSales));
  int i;

  sales->size1 = 0;

  for(i=0; i<SIZEP; i++) {
    sales->tblp[i].size2 = 0;
    sales->tblp[i].list = NULL;
  }

  for(i=0; i<SIZEC; i++) {
    sales->tblc[i].size2 = 0;
    sales->tblc[i].list = NULL;
  }

  return sales;
}

THashFact* initFact() {
  THashFact *fact = malloc(sizeof(THashFact));

  fact -> size1 = 0;

  for(int i=0; i<SIZEP; i++) {
    fact->tbl[i].size2 = 0;
    fact->tbl[i].list = NULL;
  }

  return fact;
}

void tblFact(THashSales *sales,THashFact *fact) {
  int i,i2,i3,f;

  for(i = 0;i < SIZEP;i++) {
    fact -> tbl[i].size2 = sales -> tblp[i].size2;
    fact -> size1 += fact -> tbl[i].size2;
    fact -> tbl[i].list = malloc(sizeof(Facturacao) * fact -> tbl[i].size2);

    for(i2 = 0;i2 < fact->tbl[i].size2;i2++) {
      fact -> tbl[i].list[i2].prod = sales -> tblp[i].list[i2].key;
      fact -> tbl[i].list[i2].numeroN = 0;
      fact -> tbl[i].list[i2].numeroP = 0;
      fact -> tbl[i].list[i2].facturacaoN = 0;
      fact -> tbl[i].list[i2].facturacaoP = 0;

      for(i3 = 0;i3 < sales -> tblp[i].list[i2].size3;i3++) {
        f = sales->tblp[i].list[i2].venda[i3].price * sales->tblp[i].list[i2].venda[i3].uni;
        if(sales -> tblp[i].list[i2].venda[i3].type[0] == 'N') {
          fact -> tbl[i].list[i2].numeroN++;
          fact -> tbl[i].list[i2].facturacaoN += f;
        }
        else {
          fact -> tbl[i].list[i2].numeroP++;
          fact -> tbl[i].list[i2].facturacaoP += f;
        }
      }
    }
  }
}

int vendaVal(float preco,int uni,char type,int mes,int branch) {
  int r;
  if(preco >= 0.0 && preco < 1000.0 && uni > 0 && uni <= 200 &&
    (type == 'N' || type == 'P') && mes > 0 && mes <= 12 &&
    branch > 0 && branch <= 3)
    r = 1;
  else
    r = 0;

  return r;
}

// Corre uma venda, passa para a struct total e se for válida passa a struct valida
void saleS(THashSales* sales, char* buffer, THashP* tprod, THashC* tcli) {
  char *aux = NULL, *prod = NULL, *cli = NULL, *type = NULL;
  int hashp, hashc, posp, posc, size;
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

  hashc = hashC(cli[0]);
  hashp = hashP(prod[0]);

  posp = searchProd(prod, tprod);
  posc = searchCli(cli, tcli);

//printf("%s %d %d\n", prod,hashp,posp);
  if(posp!=(-1) && posc!=(-1) && vendaVal(price,uni,type[0],month,branch))
  {

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

    sales->size1++;
  }
}

void copyTbl(THashSales* sales, THashP* tprod, THashC* tcli)
{
  int i, j;

  for(i=0; i<SIZEP; i++) {
    sales->tblp[i].list = malloc(sizeof(List) * tprod->tbl[i].size);
    sales->tblp[i].size2 = tprod->tbl[i].size;

    for(j=0; j<tprod->tbl[i].size; j++) {
      sales->tblp[i].list[j].key = malloc(sizeof(char) * SMAX);
      strcpy(sales->tblp[i].list[j].key, tprod->tbl[i].list[j]);

      sales->tblp[i].list[j].size3 = 0;
      sales->tblp[i].list[j].venda = NULL;
    }
  }

  for(i=0; i<SIZEC; i++) {
    sales->tblc[i].list = malloc(sizeof(List) * tcli->tbl[i].size);
    sales->tblc[i].size2 = tcli->tbl[i].size;

    for(j=0; j<tcli->tbl[i].size; j++) {
      sales->tblc[i].list[j].key = malloc(sizeof(char) * SMAX);
      strcpy(sales->tblc[i].list[j].key, tcli->tbl[i].list[j]);

      sales->tblc[i].list[j].size3 = 0;
      sales->tblc[i].list[j].venda = NULL;
    }
  }
}

// Abre o array das vendas e passa-as para uma struct
int tblSales(THashSales * sales, THashP* tprod, THashC* tcli) {
  FILE *fsales;
  char* buffer= malloc(sizeof(char) * MAX);

  if((fsales = fopen("../files/Vendas_1M.txt", "r")) == NULL)
    return -1;

  copyTbl(sales, tprod, tcli);

  while(fgets(buffer,MAX,fsales)) {
    buffer = strsep(&buffer, "\r");
    saleS(sales, buffer, tprod, tcli);
  }

  fclose(fsales);

   return 0;
}

void printSales(THashSales* sales) {
  int i,j,c;

  for(i=0; i<SIZEC; i++){
    for(j=0 ;j<sales->tblc[i].size2; j++) {
      printf("\n" );
      for(c=0 ;c<sales->tblc[i].list[j].size3; c++)
        printf("%s %f %d %s %s %d %d\r\n",
                sales->tblc[i].list[j].venda[c].p,
                sales->tblc[i].list[j].venda[c].price,
                sales->tblc[i].list[j].venda[c].uni,
                sales->tblc[i].list[j].venda[c].type,
                sales->tblc[i].list[j].venda[c].c,
                sales->tblc[i].list[j].venda[c].month,
                sales->tblc[i].list[j].venda[c].branch);
    }
  }

  printf("Vendas Válidas: %d\n", sales->size1);
}

void printFact(THashFact* fact) {
  int i,j;

  for(i=0; i<SIZEC; i++){
    for(j=0 ;j<fact->tbl[i].size2; j++) {
        printf("%s %d %d %d %d\r\n",
                fact->tbl[i].list[j].prod,
                fact->tbl[i].list[j].numeroN,
                fact->tbl[i].list[j].numeroP,
                fact->tbl[i].list[j].facturacaoN,
                fact->tbl[i].list[j].facturacaoP);

    }
  }
}

void freeSales(THashSales* sales) {
  int i, j, c;

  for(i=0; i<SIZEC; i++){
    for(j=0 ;j<sales->tblc[i].size2; j++) {
      for(c=0 ;c<sales->tblc[i].list[j].size3; c++) {
        free(sales->tblc[i].list[j].venda[c].c);
        free(sales->tblc[i].list[j].venda[c].p);
        free(sales->tblc[i].list[j].venda[c].type);
      }
      free(sales->tblc[i].list[j].venda);
      free(sales->tblc[i].list[j].key);
    }
    free(sales->tblc[i].list);
  }

  for(i=0; i<SIZEP; i++){
    for(j=0 ;j<sales->tblp[i].size2; j++) {
      for(c=0 ;c<sales->tblp[i].list[j].size3; c++) {
        free(sales->tblp[i].list[j].venda[c].c);
        free(sales->tblp[i].list[j].venda[c].p);
        free(sales->tblp[i].list[j].venda[c].type);
      }
      free(sales->tblp[i].list[j].venda);
      free(sales->tblp[i].list[j].key);
    }
    free(sales->tblp[i].list);
  }

  free(sales->tblc);
  free(sales->tblp);
  free(sales);
}
