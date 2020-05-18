import java.io.Serializable;
import java.util.*;

public class Facturacao implements Serializable {
    private Map<String,FactMF> listaProd;
    private int comprados;
    private int compras0;
    private double faturacaoTotal;
    private double [][] faturacaoMesFil;
    private int [] comprasMes;

    //--------------------------------------------------------------Construtores--------------------------------------------------------------------------\\

    public Facturacao() {
        listaProd = new HashMap<>();
        comprados = 0;
        compras0 = 0;
        faturacaoTotal = 0;
        comprasMes = new int[12];
        faturacaoMesFil = new double[12][3];
    }

    //--------------------------------------------------------------Getters/Setters--------------------------------------------------------------------------\\

    public int getComprados() {
        return comprados;
    }

    public int getCompras0() {
        return compras0;
    }

    public double getFaturacaoTotal() {
        return faturacaoTotal;
    }

    public int[] getComprasMes() {
        return comprasMes.clone();
    }

    public double[][] getFaturacaoMesFil() {
        return faturacaoMesFil.clone();
    }

    public Set<String> getKeys() {
        return new TreeSet<>(listaProd.keySet());
    }

    public int getUni(String code) {
        return listaProd.get(code).getUniTotal();
    }

    public double getFatTotalMes(String code,int month){
        return listaProd.get(code).getFaturacaoMes(month);
    }

    public double[][] getFatMesFilProd(String code){
        return listaProd.get(code).getFaturacaoMesFill();
    }

    public double getUniMes(String code,int month){
        return listaProd.get(code).getUnidadesMes(month);
    }

    //--------------------------------------------------------------Outros métodos--------------------------------------------------------------------------\\

    public boolean containsProd(String prodCode){
        return listaProd.containsKey(prodCode);
    }

    public void addSale(int branch,int month,float price,int uni,String prod){

        if(!listaProd.containsKey(prod)) {
            comprados++;
            listaProd.put(prod,new FactMF());
        }
        if(price * uni == 0.0)
            compras0++;

        double f = price * uni;
        faturacaoTotal += f;
        comprasMes[month]++;
        faturacaoMesFil [month][branch]+= f;
        listaProd.get(prod).setFact(branch,month,price,uni);
    }
}
