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

    public ProdInfo getCliInfo(String cliCode){
        return mapCli.get(cliCode);
    }

    public int getClientesCompradores() {
        return clientesCompradores;
    }

    public int[] getCliCompradoresMes() {
        return cliCompradoresMes;
    }

    public int getVendasMes(int month) {
        return vendasMes[month];
    }

    public int getVendasFil(){
        return Arrays.stream(vendasMes).sum();
    }

    public Set<String> getClientesMes(int month){
        Set<String> clientes = new TreeSet<>();
        for(int i = 0;i < 26;i++)
            for(ProdInfo p:mapProd.values())
                clientes.addAll(p.getCliMonth(month));
        return clientes;
    }

    public double getNumeroCompras(String cliCode,int month){
        return (mapCli.get(cliCode)).getNumeroCompras(month);
    }

    public double getGastoTotal(String cliCode,int month){
        return (mapCli.get(cliCode)).getGastoTotal(month);
    }

    public Set<String> getClientesDiferentes(int month,String code) {
        return mapProd.get(code).getCliMonth(month);
    }

    public Set<String> getProdutosDiferentes(int month,String code) {
        return mapCli.get(code).getCliMonth(month);
    }

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

    public boolean containsCliCode(String code){
        return mapCli.containsKey(code);
    }
}
