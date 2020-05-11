import java.util.*;
import java.util.stream.Collectors;

public class Filial {
    private Map<Integer, List<ProdInfo>> mapProd;
    private Map<Integer,List<CliInfo>> mapCli;
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
    public int getIndex(String cod){
        return cod.charAt(0) - 'A';
    }

    public int getPosProd(String cod,int index){
        return binarySearchInfo(mapProd.get(index),cod);
    }

    public int getPosCli(String cod,int index){
        return binarySearchInfo(mapCli.get(index),cod);
    }

    public ProdInfo getCliInfo(int index,int pos){
        return mapCli.get(index).get(pos);
    }

    public ProdInfo getProdInfo(int index,int pos){
        return mapProd.get(index).get(pos);
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

    public double getNumeroCompras(int index,int pos,int month){
        return ((CliInfo)mapCli.get(index).get(pos)).getNumeroCompras(month);
    }

    public double getGastoTotal(int index,int pos,int month){
        return ((CliInfo)mapCli.get(index).get(pos)).getGastoTotal(month);
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
                CliInfo f = new CliInfo(catlist.get(i2));
                mapCli.get(i).add(f);
            }
        }
    }

    public int binarySearchInfo(List <? extends ProdInfo> lista, String codProd) {
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
        List<CliInfo> lcli = mapCli.get(cli.charAt(0) - 'A');

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

    public List<String> getClientesMaisCompradores() {
        List<CliInfo> list = new ArrayList<>();

       for(List<CliInfo> l: mapCli.values()) {
           l.stream().sorted().limit(3).forEach(list::add);
       }

       return list.stream().sorted().limit(3).map(CliInfo::getCode).collect(Collectors.toList());

    }

//    public List<String> clientesOrdenados() {
//
//        List<String> list = new ArrayList<>();
//
//       for(List<CliInfo> l: mapCli.values()) {
//           l.stream().sorted().forEach(c -> list.add(c.getCode()));
//       }
//
//       return list;
//    }
}
