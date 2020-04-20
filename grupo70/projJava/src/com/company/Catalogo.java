package com.company;
import java.util.*;

public class Catalogo {
    private int type;
    private Map<Integer,Set<String>> lista;

    public Catalogo(int t){
        int i;
        this.type = t;
        this.lista = new HashMap<>(26);
        for(i = 0;i < 26;i++) {
            this.lista.put(i,new TreeSet<>());
        }

    }

    public void addCod(String cod) {
        if((type == 0 && valCli(cod))||(type == 1 && valProd(cod))) {
            int i = cod.charAt(0) - 'A';
            lista.get(i).add(cod);
        }
    }

    public boolean valCli(String codCli) {
        boolean r = true;
        if(codCli.length() != 5) r = false;
        else {
            if(codCli.charAt(0) < 'A' || codCli.charAt(0) > 'Z' ||
              codCli.charAt(1) < '1' || codCli.charAt(1) > '5')
                r = false;
            else {
                int i;
                for(i = 2;i < 5 && (codCli.charAt(i) >= '0' && codCli.charAt(i) <= '9');i ++);
                if(i != 5) r = false;
            }
        }
        return r;
    }

    public boolean valProd(String codProd) {
        boolean r = true;
        if(codProd.length() != 6) r = false;
        else {
            if(codProd.charAt(0) < 'A' || codProd.charAt(0) > 'Z' ||
               codProd.charAt(1) < 'A' || codProd.charAt(1) > 'Z' ||
               codProd.charAt(2) < '1' || codProd.charAt(2) > '9')
                r = false;
            else {
                int i;
                for(i = 3;i < 6 && (codProd.charAt(i) >= '0' && codProd.charAt(i) <= '9');i ++);
                if(i != 6) r = false;
            }
        }
        return r;
    }

    public boolean contem(String cod) {
        return lista.get(cod.charAt(0) - 'A').contains(cod);
    }

    public Set<String> getTree(int i) {
        return lista.get(i);
    }

    public void printlista(int i) {
        Set <String> tree = lista.get(i);
        if(tree != null) {
            for (String elem : tree) {
                System.out.println(elem);
            }
        }
    }
}
