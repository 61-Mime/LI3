import java.util.*;
import java.util.stream.Collectors;
import java.util.Comparator;

public class Facturacao {
    private Map<Integer,List<FactMF>> listaProd;
    private int comprados;
    private int compras0;
    private float faturacaoTotal;
    private float [] faturacaoMesFil;
    private int [] comprasMes;

    public Facturacao() {
        listaProd = new HashMap<>();
        comprados = 0;
        compras0 = 0;
        faturacaoTotal = 0;
        comprasMes = new int[12];
        faturacaoMesFil = new float[36];
    }

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

    public void addSale(int branch,int month,float price,int uni,char type,String prod){
        List<FactMF> l = listaProd.get(prod.charAt(0) - 'A');
        int i = binarySearch(l,prod);

        if(l.get(i).getOccup() == 0)
            comprados++;
        if(price * uni == 0.0)
            compras0++;

        float f = price * uni;
        faturacaoTotal += f;
        comprasMes[month]++;
        faturacaoMesFil [12*branch + month]+= f;
        l.get(i).setFact(branch,month,type,price,uni);
    }

    public void print(){
        System.out.println(listaProd.get(0).size());
        for(int i = 0;i < 20;i++)
        System.out.print(listaProd.get(1).get(i).toSring());
    }
}
