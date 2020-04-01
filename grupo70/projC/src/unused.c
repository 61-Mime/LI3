/* Versao para 3 filiais

*/

/*
void ProdCliComp(THashSales* sales,int hash,int pos,int tabela) {
  int p1,p2;
  if(hash < 26) {
    p1 = hash + 26; p2 = hash + 52;
  }
  else if(hash > 51) {
    p1 = hash - 26; p2 = hash - 52;
  }
  else {
    p1 = hash - 26; p2 = hash + 26;
  }

  if(!tabela && sales->tblp[p1].list[pos].venda == NULL &&
     sales->tblp[p2].list[pos].venda == NULL)
     sales -> comprados++;
  else if(tabela && sales->tblc[p1].list[pos].venda == NULL &&
          sales->tblc[p2].list[pos].venda == NULL)
          sales -> compradores++;
}



void quickSortS(Sale *sales, int low, int high)
{
    if (low < high)
    {
      int pivot = sales[high].month;
      int i = (low - 1);

      for (int j=low; j<=high-1; j++)
      {
          if (sales[j].month < pivot)
          {
              i++;
              swapS(&sales[i], &sales[j]);
          }
      }
      swapS(&sales[i + 1], &sales[high]);

      int pi = i + 1;

      quickSortS(sales, low, pi - 1);
      quickSortS(sales, pi + 1, high);
    }
}

void tblFil(THashSales *sales,TblFil *fil, int filial) {
  int i,j,k;

  for(i = 0;i < SIZE;i++) {
    fil->tblp[i].list = malloc(sizeof(Lista) * sales->tblp[i].size2);
    fil->tblp[i].size2 = sales->tblp[i].size2;
//printf(".\n");
    for(j = 0;j < sales->tblp[i].size2;j++) {
      fil->tblp[i].list[j].key = malloc(sizeof(char)*SMAX);
      strcpy(fil->tblp[i].list[j].key, sales->tblp[i].list[j].key);
      fil->tblp[i].list[j].size3 = 0;

      for(k = 0;k < sales->tblp[i].list[j].size3;k++) {
        if(sales->tblp[i].list[j].venda[k].branch == filial) {
          fil->tblp[i].list[j].venda = realloc(fil->tblp[i].list[j].venda,sizeof(Venda) * (fil->tblp[i].list[j].size3 + 1));
          fil->tblp[i].list[j].size3++;
          fil->tblp[i].list[j].venda[k].month = sales->tblp[i].list[j].venda[k].month;
          fil->tblp[i].list[j].venda[k].branch = sales->tblp[i].list[j].venda[k].branch;
          fil->tblp[i].list[j].venda[k].uni = sales->tblp[i].list[j].venda[k].uni;
          fil->tblp[i].list[j].venda[k].price = sales->tblp[i].list[j].venda[k].price;
          fil->tblp[i].list[j].venda[k].month = sales->tblp[i].list[j].venda[k].month;
          printf(".\n" );
          strcpy(fil->tblp[i].list[j].venda[k].c,sales->tblp[i].list[j].venda[k].c);
          strcpy(fil->tblp[i].list[j].venda[k].p,sales->tblp[i].list[j].venda[k].p);
          printf(".\n" );
          strcpy(fil->tblp[i].list[j].venda[k].type,sales->tblp[i].list[j].venda[k].type);
          printf("%s %d\n", fil->tblp[i].list[j].venda[k].c,fil->tblp[i].list[j].venda[k].month);
        }
      }
    }

    fil->tblc[i].list = malloc(sizeof(Lista) * sales->tblc[i].size2);
    fil ->tblc[i].size2 = sales->tblc[i].size2;

    for(j = 0;j < sales->tblc[i].size2;j++) {
      fil->tblc[i].list[j].key = malloc(sizeof(char)*SMAX);
      strcpy(fil->tblc[i].list[j].key,sales->tblc[i].list[j].key);
      fil->tblc[i].list[j].size3 = 0;

      for(k = 0;k < sales->tblc[i].list[j].size3;k++) {
        if(sales->tblc[i].list[j].venda[k].branch == filial) {
          fil->tblc[i].list[j].venda = realloc(fil->tblc[i].list[j].venda,sizeof(Venda) * (fil->tblc[i].list[j].size3 + 1));
          fil->tblc[i].list[j].size3++;
          fil->tblc[i].list[j].venda[k].month = sales->tblc[i].list[j].venda[k].month;
          fil->tblc[i].list[j].venda[k].branch = sales->tblc[i].list[j].venda[k].branch;
          fil->tblc[i].list[j].venda[k].uni = sales->tblc[i].list[j].venda[k].uni;
          fil->tblc[i].list[j].venda[k].price = sales->tblc[i].list[j].venda[k].price;
          fil->tblc[i].list[j].venda[k].month = sales->tblc[i].list[j].venda[k].month;
          strcpy(fil->tblc[i].list[j].venda[k].c,sales->tblc[i].list[j].venda[k].c);
          strcpy(fil->tblc[i].list[j].venda[k].p,sales->tblc[i].list[j].venda[k].p);
          strcpy(fil->tblc[i].list[j].venda[k].type,sales->tblc[i].list[j].venda[k].type);
        }
      }
    }
  }
}
*/
