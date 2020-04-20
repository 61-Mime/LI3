package com.company;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.TreeSet;

public class Main {

    public static void main(String[] args) {
        Load sgv = new Load();
        sgv.loadCat("Files/Clientes.txt",0);
        sgv.loadCat("Files/Produtos.txt",1);
        sgv.getFact().loadFactfromCat(sgv.getCatP());
        sgv.loadSales("Files/Vendas_1M.txt");
        sgv.getFact().print();
	}
}

