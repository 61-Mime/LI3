import javax.xml.crypto.Data;
import java.io.*;
import java.util.TreeSet;

public class Main {

    public static void main(String[] args) throws IOException, ClassNotFoundException {
//        Crono.start();
        Load sgv = new Load();
        sgv.loadCat(sgv.getLoadInfo().getCliPath(),0);
        sgv.loadCat(sgv.getLoadInfo().getProdPath(),1);

        System.out.println("Tempo carregamento catalogos " + Crono.getTime());

        Crono.start();
        sgv.getFact().loadFactfromCat(sgv.getCatP());

        for(int i=0; i<3; i++)
            sgv.getFilial(i).loadFilfromCat(sgv.getCatP(), sgv.getCatC());

        System.out.println("Tempo carregamento catalogos para structs " +Crono.getTime());

        Crono.start();
        sgv.loadSales(sgv.getLoadInfo().getSalesPath());
        System.out.println("Tempo carregamento vendas " + Crono.getTime());
//
//        ConsultasEstatisticas ce = new ConsultasEstatisticas(sgv);
//        System.out.println(ce.toString());
//
////        System.out.println(sgv.getFilial(1).clientesOrdenados());
//
//
//        ConsultasInterativas ci = new ConsultasInterativas();
//
//        ci.setQuerie1(sgv);
//        System.out.println(ci.getQuerie1());
//
//        System.out.println("***********************************");
//
//        ci.setQuerie5(sgv, "Q4462");
//        System.out.println(ci.getQuerie5());
//
//        System.out.println("***********************************");
//
//        ci.setQuerie8(sgv, 10);
//        System.out.println(ci.getQuerie8());

//        ci.setQuerie5(sgv, );
//        System.out.println(ci.getQuerie5());

//        DataFile dataFile = new DataFile();
//        dataFile.guardaDados("data.dat", sgv);
//
//        System.out.println(sgv.getCatC().getTree(8));
//
//        sgv = dataFile.carregaDados("data.dat");
//
//        System.out.println(sgv.getCatC().getTree(8));

	}
}