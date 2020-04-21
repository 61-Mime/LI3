import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class Filial {
    private Map<Integer, List<ProdInfo>> mapProd;
    private Map<Integer,List<CliInfo>> mapCli;

    public Filial() {
        mapProd = new HashMap<>();
        mapCli = new HashMap<>();
    }

    public void loadFilfromCat(Catalogo catProd, Catalogo catCli) {
        List<String> catlist;

        int i, i2,size;

        for(i = 0;i < 26;i++) {
            catlist = catProd.getTree(i).stream().collect(Collectors.toList());
            size = catlist.size();
            mapProd.put(i,new ArrayList<>());
            for(i2 = 0;i2 < size;i2++){
                ProdInfo f = new ProdInfo(catlist.get(i2));
                mapProd.get(i).add(f);
            }

            catlist = catCli.getTree(i).stream().collect(Collectors.toList());
            size = catlist.size();
            mapCli.put(i,new ArrayList<>());
            for(i2 = 0;i2 < size;i2++){
                CliInfo f = new CliInfo(catlist.get(i2));
                mapCli.get(i).add(f);
            }
        }
    }

    public int binarySearchProd(List <ProdInfo> lista, String codProd) {
        int startIndex = 0;
        int endIndex = lista.size();
        int midIndex = (endIndex+startIndex) / 2;

        while(lista.get(midIndex).getProd().compareTo(codProd) !=  0) {
            if (lista.get(midIndex).getProd().compareTo(codProd) < 0) {
                startIndex = midIndex;
            } else {
                endIndex = midIndex;
            }
            midIndex = (endIndex+startIndex) / 2;
        }

        return midIndex;
    }

    public int binarySearchCli(List <CliInfo> lista, String codCli) {
        int startIndex = 0;
        int endIndex = lista.size();
        int midIndex = (endIndex+startIndex) / 2;

        while(lista.get(midIndex).getCli().compareTo(codCli) !=  0) {
            if (lista.get(midIndex).getCli().compareTo(codCli) < 0) {
                startIndex = midIndex;
            } else {
                endIndex = midIndex;
            }
            midIndex = (endIndex+startIndex) / 2;
        }

        return midIndex;
    }

    public void addSale(int month,float price,int uni,char type,String prod,String cli){
        List<ProdInfo> lprod = mapProd.get(prod.charAt(0) - 'A');
        List<CliInfo> lcli = mapCli.get(prod.charAt(0) - 'A');

        int i = binarySearchProd(lprod, prod);
        int j = binarySearchCli(lcli, cli);

        lprod.get(j).addCli(cli, type);
        lcli.get(i).addProd(prod, month, uni, price);
    }
}
