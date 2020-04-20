package com.company;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class Load {
    private Catalogo CatClientes;
    private Catalogo CatProdutos;
    private Facturacao Fact;

    public Load(){
        CatClientes = new Catalogo(0);
        CatProdutos = new Catalogo(1);
        Fact = new Facturacao();
    }

    public Catalogo getCatC(){
        return CatClientes;
    }

    public Catalogo getCatP(){
        return CatProdutos;
    }

    public Facturacao getFact(){
        return Fact;
    }

    public void loadCat(String filename,int type){
        String line = "11111";
        BufferedReader br = null;

        try {
            br = new BufferedReader(new FileReader(filename));
        } catch (FileNotFoundException fnfex) {
            System.out.println(fnfex.getMessage() + "Ficheiro não encontrado");
            System.exit(0);
        }
        try {
            while ((line = br.readLine()) != null) {
                if(type == 0)
                    CatClientes.addCod(line);
                else
                    CatProdutos.addCod(line);
            }
        } catch (IOException ioex) {
            System.out.println(ioex.getMessage() + "Erro a ler ficheiro");
        }
    }

    public void loadSales(String filename){
        String line = "11111";
        String[] venda;
        BufferedReader br = null;
        int branch,month,uni;
        float price;
        char type;

        try {
            br = new BufferedReader(new FileReader(filename));
        } catch (FileNotFoundException fnfex) {
            System.out.println(fnfex.getMessage() + "Ficheiro não encontrado");
            System.exit(0);
        }
        try {
            while ((line = br.readLine()) != null) {
                venda = line.split(" ");
                branch = Integer.parseInt(venda[6]);
                month = Integer.parseInt(venda[5]);
                price = Float.parseFloat(venda[1]);
                uni = Integer.parseInt(venda[2]);
                type = venda[3].charAt(0);
                if(Fact.valSale(branch,month,price,uni,type) &&
                   CatClientes.contem(venda[4]) && CatProdutos.contem(venda[0]))
                    Fact.addSale(branch-1,month,price,uni,type,venda[0]);

            }
        } catch (IOException ioex) {
            System.out.println(ioex.getMessage() + "Erro a ler ficheiro");
        }
    }
}
