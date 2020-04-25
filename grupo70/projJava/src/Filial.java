import javax.swing.plaf.basic.BasicComboPopup;
import java.util.*;
import java.util.stream.Collectors;

public class Filial {
    private Map<Integer, List<Info>> mapProd;
    private Map<Integer,List<Info>> mapCli;

    public Filial() {
        mapProd = new HashMap<>();
        mapCli = new HashMap<>();
    }

    public void loadFilfromCat(Catalogo catProd, Catalogo catCli) {
        List<String> catlist;

        int i, i2,size;

        for(i = 0;i < 26;i++) {
            catlist = new ArrayList<>(catProd.getTree(i));
            mapProd.put(i,new ArrayList<>());
            for(i2 = 0; i2 < catlist.size(); i2++){
                ProdInfo f = new ProdInfo(catlist.get(i2));
                mapProd.get(i).add(f);
            }

            catlist = new ArrayList<>(catCli.getTree(i));
            mapCli.put(i,new ArrayList<>());
            for(i2 = 0; i2 < catlist.size(); i2++){
                CliInfo f = new CliInfo(catlist.get(i2));
                mapCli.get(i).add(f);
            }
        }
    }

    public int binarySearchInfo(List <Info> lista, String codProd) {
        int startIndex = 0;
        int endIndex = lista.size();
        int midIndex = (endIndex+startIndex) / 2;

        while(lista.get(midIndex).getCode().compareTo(codProd) !=  0) {
            if (lista.get(midIndex).getCode().compareTo(codProd) < 0) {
                startIndex = midIndex;
            } else {
                endIndex = midIndex;
            }
            midIndex = (endIndex+startIndex) / 2;
        }

        return midIndex;
    }


    public void addSale(int month,float price,int uni,char type,String prod,String cli){
        List<Info> lprod = mapProd.get(prod.charAt(0) - 'A');
        List<Info> lcli = mapCli.get(cli.charAt(0) - 'A');

        int i = binarySearchInfo(lprod, prod);
        int j = binarySearchInfo(lcli, cli);

        lprod.get(i).addCli(cli, type);
        lcli.get(j).addProd(prod, month, uni, price);

    }
}
