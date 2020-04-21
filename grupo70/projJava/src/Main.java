import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.TreeSet;

public class Main {

    public static void main(String[] args) {
        Load sgv = new Load();
        sgv.loadCat("files/Clientes.txt",0);
        sgv.loadCat("files/Produtos.txt",1);
        sgv.getFact().loadFactfromCat(sgv.getCatP());

        for(int i=0; i<3; i++){
            sgv.getFilial(i).loadFilfromCat(sgv.getCatP(), sgv.getCatC());
        }
        sgv.loadSales("files/Vendas_1M.txt");
        //sgv.getFact().print();
	}
}

