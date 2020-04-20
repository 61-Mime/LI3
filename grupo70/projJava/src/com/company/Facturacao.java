package com.company;

import java.util.*;
import java.util.stream.Collectors;
import java.util.Comparator;

public class Facturacao {
    private Map<Integer,List<FactMF>> listaProd;

    public Facturacao() {
        listaProd = new HashMap<>();
    }

    public void loadFactfromCat(Catalogo CatProd) {
        List<String> catlist;
        int i, i2,size;
        for(i = 0;i < 26;i++) {
            catlist = CatProd.getTree(i).stream().collect(Collectors.toList());
            size = catlist.size();
            System.out.println(size);
            listaProd.put(i,new ArrayList<>());
            for(i2 = 0;i2 < size;i2++){
                //System.out.println(catlist.get(i2));
                FactMF f = new FactMF(catlist.get(i2));
                listaProd.get(i).add(f);
                }
        }
    }

    public boolean valSale(int branch,int month,float price,int uni,char type){
        return (branch >= 1 && branch <= 3 && month >= 1 && month <= 12 &&
                price >= 0 && uni >= 0 && (type == 'N' || type == 'P'));
    }

    public int binarySearch(List <FactMF>lista,String codProd) {
        int startIndex = 0;
        int endIndex = lista.size();
        System.out.println(endIndex);
        int midIndex = (endIndex+startIndex) / 2;

        while(lista.get(midIndex).getCodProd().compareTo(codProd) !=  0) {
            if (lista.get(midIndex).getCodProd().compareTo(codProd) < 0) {
                startIndex = midIndex;
            } else {
                endIndex = midIndex;
            }
            midIndex = (endIndex+startIndex) / 2;
        }

        return midIndex;
    }

    public void addSale(int branch,int month,float price,int uni,char type,String prod){
        List<FactMF> l = listaProd.get(prod.charAt(0) - 'A');
        int i = binarySearch(l,prod);
        l.get(i).setFact(branch,month,type,price,uni);
    }

    public void print(){
        System.out.println(listaProd.get(0).size());
        System.out.print(listaProd.get(0).get(0).toSring());
    }
}
