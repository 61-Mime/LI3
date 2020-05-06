import javax.swing.plaf.basic.BasicComboPopup;
import java.util.*;
import java.util.stream.Collectors;

public class Filial {
    private Map<Integer, List<ProdInfo>> mapProd;
    private Map<Integer,List<ProdInfo>> mapCli;
    private int clientesCompradores;
    private int[] cliCompradoresMes;
    private int[] vendasMes;

    public Filial() {
        mapProd = new HashMap<>();
        mapCli = new HashMap<>();
        clientesCompradores = 0;
        cliCompradoresMes = new int[12];
        vendasMes = new int[12];
    }

    public int getClientesCompradores() {
        return clientesCompradores;
    }

    public int[] getCliCompradoresMes() {
        return cliCompradoresMes;
    }

    public int getCliCompradoresMes(int month) {
        return cliCompradoresMes[month];
    }

    public int getVendasMes(int month) {
        return vendasMes[month];
    }

    public int getVendasFil(){
        return Arrays.stream(vendasMes).sum();
    }

    public int getSizeCli(String cliCod, int pos) {
        return mapCli.get(cliCod.charAt(0) - 'A').get(pos).getSize();
    }

    public Set<String> getClientesMes(int month){
        Set<String> clientes = new TreeSet<>();
        for(int i = 0;i < 26;i++)
            for(ProdInfo p:mapProd.get(i))
                clientes.addAll(p.getCliMonth(month));

        return clientes;
    }

    public double[] getCliInfo(String cod,int month){
        int index = cod.charAt(0)-'A';
        int pos = binarySearchInfo(mapCli.get(index),cod);
        double []res = new double[3];
        CliInfo cli = (CliInfo) mapCli.get(index).get(pos);
        res[0] = cli.getNumeroCompras(month);
        res[1] = cli.getSizeMonth(month);
        res[2] = cli.getGastoTotal(month);
        return res;
    }

    public Set<String> getClientesDiferentes(int month,String cod) {
        int index = cod.charAt(0)-'A';
        int pos = binarySearchInfo(mapProd.get(index),cod);
        return mapProd.get(index).get(pos).getCliMonth(month);
    }

    public Set<String> getProdutosDiferentes(int month,String cod) {
        int index = cod.charAt(0)-'A';
        int pos = binarySearchInfo(mapCli.get(index),cod);
        return mapCli.get(index).get(pos).getCliMonth(month);
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
                ProdInfo f = new CliInfo(catlist.get(i2));
                mapCli.get(i).add(f);
            }
        }
    }

    public int binarySearchInfo(List <ProdInfo> lista, String codProd) {
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


    public int addSale(int month,double price,int uni,String prod,String cli){
        List<ProdInfo> lprod = mapProd.get(prod.charAt(0) - 'A');
        List<ProdInfo> lcli = mapCli.get(cli.charAt(0) - 'A');

        int prodIndex = binarySearchInfo(lprod, prod);
        int cliIndex = binarySearchInfo(lcli, cli);
        int res = -1;

        vendasMes[month]++;
        if(lcli.get(cliIndex).getSize() == 0) {
            clientesCompradores++;
            cliCompradoresMes[month]++;
            res = cliIndex;
        }

        lprod.get(prodIndex).addCode(prod,month,price,uni);
        lcli.get(cliIndex).addProd(prod, month,uni,price);

        return res;
    }


}
