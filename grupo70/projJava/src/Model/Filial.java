/**
 * Classe com informação sobre uma Filial
 */

package Model;

import java.io.Serializable;
import java.util.*;
import java.util.stream.Collectors;

public class Filial implements Serializable {
    private Map<String,ProdInfo> mapProd;
    private Map<String,CliInfo> mapCli;
    private int clientesCompradores;
    private int[] cliCompradoresMes;
    private int[] vendasMes;

    //--------------------------------------------------------------Construtores--------------------------------------------------------------------------\\

    /**
     * Contrutos da classe Filial
     */
    public Filial() {
        mapProd = new HashMap<>();
        mapCli = new HashMap<>();
        clientesCompradores = 0;
        cliCompradoresMes = new int[12];
        vendasMes = new int[12];
    }

    //--------------------------------------------------------------Getters/Setters--------------------------------------------------------------------------\\

    /*public Model.ProdInfo getCliInfo(String cliCode){
        return mapCli.get(cliCode);
    }*/

    /**
     * Método que devolve o número de Clientes compradores da Filial
     *
     * @return  Inteiro que representa o número de Clientes compradores
     */
    public int getClientesCompradores() {
        return clientesCompradores;
    }

    /**
     * Método que devolve o número de Clientes compradores da Filial por mês
     *
     * @return      Array de Float(de tamanho 12) que representa o número de Clientes compradores associados ao mês
     */
    public int[] getCliCompradoresMes() {
        return cliCompradoresMes.clone();
    }

    /**
     * Método que devolve o número de Vendas de uma Filial num determinado mês
     *
     * @param month
     * @return
     */
    public int getVendasMes(int month) {
        return vendasMes[month];
    }

    public int getVendasFil(){
        return Arrays.stream(vendasMes).sum();
    }

    public Set<String> getClientesMes(int month){
        Set<String> clientes = new TreeSet<>();

        for(ProdInfo p:mapProd.values())
            clientes.addAll(p.getCodeMonth(month));

        return clientes;
    }

    public float getNumeroCompras(String cliCode,int month){
        return (mapCli.get(cliCode)).getNumeroCompras(month);
    }

    public float getGastoTotal(String cliCode,int month){
        return (mapCli.get(cliCode)).getGastoTotal(month);
    }

    public Set<String> getClientesDiferentes(int month,String code) {
        if (!mapProd.containsKey(code))
            return new TreeSet<>();
        return mapProd.get(code).getCodeMonth(month);
    }

    public Set<String> getProdutosDiferentes(int month,String code) {
        return mapCli.get(code).getCodeMonth(month);
    }

    public List<String> getClientesMaisCompradores() {
        return mapCli.values().stream().sorted().limit(3).map(CliInfo::getCode).collect(Collectors.toList());
    }

    /*public List<Model.ProdCliinfo> getProdCliList(String code){
        return mapProd.get(code).getMapList();
    }*/

    public boolean containsCliCode(String code){
        return mapCli.containsKey(code);
    }

    public Set<ParStringFloat> getCliSetCodUni(String code){
        return mapCli.get(code).getSetCodUni();
    }

    public Set<ParStringFloat> getProdSetCodUni(String code){
        return mapProd.get(code).getSetCodUni();
    }

    public int getClientesCompradoresMes(int month) {
        return cliCompradoresMes[month];
    }

    //--------------------------------------------------------------Outros métodos--------------------------------------------------------------------------\\

    public int addSale(int month,float price,int uni,String prodCode,String cliCode){
        int res = -1;

        vendasMes[month]++;
        if(!mapCli.containsKey(cliCode)) {
            clientesCompradores++;
            cliCompradoresMes[month]++;
            res = 1;
            mapCli.put(cliCode,new CliInfo(cliCode));
        }
        else {
            if(!mapCli.get(cliCode).containsMes(month))
                cliCompradoresMes[month]++;
        }
        if(!mapProd.containsKey(prodCode))
            mapProd.put(prodCode,new ProdInfo(prodCode));

        mapProd.get(prodCode).addCode(cliCode,month,price,uni);
        mapCli.get(cliCode).addProd(prodCode, month,uni,price);

        return res;
    }
}
