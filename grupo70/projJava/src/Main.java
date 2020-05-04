import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.TreeSet;

public class Main {

    public static void main(String[] args) {
        Crono.start();
        Load sgv = new Load();
        sgv.loadCat("Files/Clientes.txt",0);
        sgv.loadCat("Files/Produtos.txt",1);
        System.out.println("Tempo carregamento catalogos " + Crono.getTime());
        Crono.start();
        sgv.getFact().loadFactfromCat(sgv.getCatP());

        for(int i=0; i<3; i++){
            sgv.getFilial(i).loadFilfromCat(sgv.getCatP(), sgv.getCatC());
        }
        System.out.println("Tempo carregamento catalogos para structs " +Crono.getTime());
        Crono.start();
        sgv.loadSales("Files/Vendas_1M.txt");
        System.out.println("Tempo carregamento vendas " + Crono.getTime());
        System.out.println("nºprodutos " + sgv.getCatP().getTotal());
        System.out.println("nºclientes " + sgv.getCatC().getTotal());
        System.out.println("nºvendas válidas " + sgv.getLoadInfo().getVendasValidas());
        System.out.println("nºvendas inválidas " + sgv.getLoadInfo().getVendasInvalidas());
        System.out.println("produtos comprados  " + sgv.getFact().getComprados());
        System.out.println("compras valor 0 " + sgv.getFact().getCompras0());
        System.out.println("faturação total " + sgv.getFact().getFaturacaoTotal());
        System.out.println("Clientes compradores " + (sgv.getFilial(0).getClientesCompradores()+
                                                      sgv.getFilial(1).getClientesCompradores())+
                                                      sgv.getFilial(2).getClientesCompradores());
	}
}