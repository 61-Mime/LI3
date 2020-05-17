import java.io.Serializable;
import java.util.*;
import java.util.stream.Collectors;

public class Filial implements Serializable {
    private Map<String,ProdInfo> mapProd;
    private Map<String,CliInfo> mapCli;
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
    /*
        public int getIndex(String cod){
            return cod.charAt(0) - 'A';
        }

        public int getPosProd(String cod,int index){
            return binarySearchInfo(mapProd.get(index),cod);
        }

        public int getPosCli(String cod,int index){
            return binarySearchInfo(mapCli.get(index),cod);
        }
    */
    public ProdInfo getCliInfo(String cliCode){
        return mapCli.get(cliCode);
    }
/*
    public int getsize2(int i){
        return mapCli.get(i).size();
    }

    public ProdInfo getProdInfo(String prodCode){
        return mapProd.get(getIndex(prodCode)).get(prodCode);
    }
*/
    public int getClientesCompradores() {
        return clientesCompradores;
    }

    public int[] getCliCompradoresMes() {
        return cliCompradoresMes;
    }
/*
    public int getCliCompradoresMes(int month) {
        return cliCompradoresMes[month];
    }
*/
    public int getVendasMes(int month) {
        return vendasMes[month];
    }

    public int getVendasFil(){
        return Arrays.stream(vendasMes).sum();
    }
/*
    public int getSizeCli(String cliCod) {
        return mapCli.get(cliCod).getSize();
    }
*/
    public Set<String> getClientesMes(int month){
        Set<String> clientes = new TreeSet<>();
        for(int i = 0;i < 26;i++)
            for(ProdInfo p:mapProd.values())
                clientes.addAll(p.getCliMonth(month));
        return clientes;
    }

    public double getNumeroCompras(String cliCode,int month){
        return ((CliInfo)mapCli.get(cliCode)).getNumeroCompras(month);
    }

    public double getGastoTotal(String cliCode,int month){
        return ((CliInfo)mapCli.get(cliCode)).getGastoTotal(month);
    }

    public Set<String> getClientesDiferentes(int month,String code) {
        return mapProd.get(code).getCliMonth(month);
    }

    public Set<String> getProdutosDiferentes(int month,String code) {
        return mapCli.get(code).getCliMonth(month);
    }
/*
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
*/

    public int addSale(int month,double price,int uni,String prodCode,String cliCode){
        int res = -1;

        vendasMes[month]++;
        if(!mapCli.containsKey(cliCode)) {
            clientesCompradores++;
            cliCompradoresMes[month]++;
            res = 1;
            mapCli.put(cliCode,new CliInfo(cliCode));
        }
        if(!mapProd.containsKey(prodCode))
            mapProd.put(prodCode,new ProdInfo(prodCode));

        mapProd.get(prodCode).addCode(cliCode,month,price,uni);
        mapCli.get(cliCode).addProd(prodCode, month,uni,price);

        return res;
    }

    public List<String> getClientesMaisCompradores() {
        List<CliInfo> list = new ArrayList<>();

        mapCli.values().stream().sorted().limit(3).forEach(list::add);

       return list.stream().sorted().limit(3).map(CliInfo::getCode).collect(Collectors.toList());
    }

    public List<ProdCliinfo> getProdCliList(String code){
        return mapProd.get(code).getMapList();
    }

    public boolean conteinsCliCode(String code){
        return mapCli.containsKey(code);
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
