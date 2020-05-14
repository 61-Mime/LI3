import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.TreeSet;

public class Main {

    public static void main(String[] args) {
        Crono.start();
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

        ConsultasEstatisticas ce = new ConsultasEstatisticas(sgv);
        System.out.println(ce.toString());

//        System.out.println(sgv.getFilial(1).clientesOrdenados());


        ConsultasInterativas ci = new ConsultasInterativas();

        ci.setQuerie1(sgv);
        System.out.println("Querie 1\n"+ci.getQuerie1());

        System.out.println("***********************************");

        ci.setQuerie2(sgv, 1);
        System.out.println(ci.getQuerie2().toString());

        System.out.println("***********************************");

        ci.setQuerie5(sgv, "Q4462");
        System.out.println("Querie 5\n"+ci.getQuerie5());

        System.out.println("***********************************");

        ci.setQuerie6(sgv, 100);
        System.out.println("Querie 6\n"+ci.getQuerie6());

        System.out.println("***********************************");

        ci.setQuerie8(sgv, 10);
        System.out.println("Querie 8\n"+ci.getQuerie8());

        System.out.println("***********************************");

        ci.setQuerie9(sgv, "AF1184",6);
        System.out.println("Querie 9\n"+ci.getQuerie9());

//        ci.setQuerie5(sgv, );
//        System.out.println(ci.getQuerie5());
	}
}