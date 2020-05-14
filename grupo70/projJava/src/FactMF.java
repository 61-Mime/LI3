import java.util.Arrays;
import java.util.stream.Stream;

public class FactMF {
    private String codProd;
    private int occup;
    private int[] unidadesMes;
    private double[][] faturacaoMesFill;
    private double faturacaoTotal;

    public FactMF(String cod){
        this.codProd = cod;
        this.occup = 0;
        unidadesMes = new int[12];
        faturacaoMesFill = new double[12][3];
        faturacaoTotal = 0;
    }

    public String getCodProd(){
        return codProd;
    }

    public int getUnidadesMes(int month) {
        return unidadesMes[month];
    }

    public int getUniTotal() {
        return Arrays.stream(unidadesMes).sum();
    }

    public double getFaturacaoTotal() {
        return faturacaoTotal;
    }

    public double getFaturacaoMes(int month) {
        return faturacaoMesFill[month][0] + faturacaoMesFill[month][1] + faturacaoMesFill[month][2];
    }

    public double[][] getFaturacaoMesFill() {
        return Arrays.stream(faturacaoMesFill).toArray(double[][]::new);
    }

    public int getOccup() {
        return occup;
    }

    public void setFact(int branch, int month, float price, int uni) {
        if(occup == 0)
            occup = 1;
        unidadesMes[month] += uni;
        faturacaoTotal += price*uni;
        faturacaoMesFill[month][branch] = price*uni;
    }

    public String toSring() {
        return ("Produto: "+codProd+"\n"+"Faturação Total:"+faturacaoTotal);
    }
}
