import java.io.Serializable;
import java.util.*;
import java.util.stream.Collectors;
import java.util.Comparator;

public class Facturacao implements Serializable {
    private Map<Integer,Map<String,FactMF>> listaProd;
    private int comprados;
    private int compras0;
    private float faturacaoTotal;
    private float [] faturacaoMesFil;
    private int [] comprasMes;

    public Facturacao() {
        listaProd = new HashMap<>();
        for(int i = 0;i < 26;i ++)
            listaProd.put(i,new HashMap<>());
        comprados = 0;
        compras0 = 0;
        faturacaoTotal = 0;
        comprasMes = new int[12];
        faturacaoMesFil = new float[36];
    }

    /*public Map<Integer, Map<String,FactMF>> getListaProd() {
        return listaProd;
    }*/

    public int getComprados() {
        return comprados;
    }

    public int getCompras0() {
        return compras0;
    }

    public float getFaturacaoTotal() {
        return faturacaoTotal;
    }

    public int[] getComprasMes() {
        return comprasMes;
    }

    public float[] getFaturacaoMesFil() {
        return faturacaoMesFil;
    }

    public int getIndex(String cod){
        return cod.charAt(0) - 'A';
    }
/*
    public int getPos(String cod,int index){
        return binarySearch(listaProd.get(index),cod);
    }
*/

    public Set<String> getKeys(int index) {
        return listaProd.get(index).keySet();
    }

    public String getProd(int i, String code) {
        return listaProd.get(i).get(code).getCodProd();
    }

    public int getUni(int i, String code) {
        return listaProd.get(i).get(code).getUniTotal();
    }

    public int getSize(int i) {
        return listaProd.get(i).size();
    }

    public double getFatTotalMes(int index,String code,int month){
        return listaProd.get(index).get(code).getFaturacaoMes(month);
    }

    public double[][] getFatMesFilProd(int index,String code){
        return listaProd.get(index).get(code).getFaturacaoMesFill();
    }

    public double getUniMes(int index,String code,int month){
        return listaProd.get(index).get(code).getUnidadesMes(month);
    }

    public List<FactMF> getList(int index){
        return listaProd.get(index).values().stream().collect(Collectors.toList());
    }

    public boolean containsProd(int i,String prodCode){
        return listaProd.get(i).containsKey(prodCode);
    }
/*
    public List<String> getXmaisVendidos(int x){

    }

    public void loadFactfromCat(Catalogo catProd) {
        List<String> catlist;
        int i, i2,size;
        for(i = 0;i < 26;i++) {
            catlist = new ArrayList<>(catProd.getTree(i));
            listaProd.put(i,new ArrayList<>());
            for(i2 = 0; i2 < catlist.size(); i2++){
                FactMF f = new FactMF(catlist.get(i2));
                listaProd.get(i).add(f);
            }
        }
    }

    public int binarySearch(List <FactMF>lista, String codProd) {
        int startIndex = 0;
        int endIndex = lista.size();
        int midIndex = (endIndex+startIndex) / 2;

        while(lista.get(midIndex).getCodProd().compareTo(codProd) !=  0) {
            if (lista.get(midIndex).getCodProd().compareTo(codProd) < 0) {
                startIndex = midIndex;
            } else {
                endIndex = midIndex;
            }
            midIndex = (endIndex+startIndex) / 2;
        }

        return midIndex;
    }
*/
    public void addSale(int branch,int month,float price,int uni,char type,String prod){
        int i = getIndex(prod);

        if(!listaProd.get(i).containsKey(prod)) {
            comprados++;
            listaProd.get(i).put(prod,new FactMF(prod));
        }
        if(price * uni == 0.0)
            compras0++;

        float f = price * uni;
        faturacaoTotal += f;
        comprasMes[month]++;
        faturacaoMesFil [12*branch + month]+= f;
        listaProd.get(i).get(prod).setFact(branch,month,price,uni);
    }

    public void print(){
        System.out.println(listaProd.get(0).size());
        for(int i = 0;i < 20;i++)
        System.out.print(listaProd.get(1).get(i).toSring());
    }


}
