import java.io.Serializable;
import java.util.Arrays;
import java.util.stream.Stream;

public class FactMF implements Serializable {
    private int[] unidadesMes;
    private double[][] faturacaoMesFill;
    private double faturacaoTotal; // Rever se é preciso

    //--------------------------------------------------------------Construtores--------------------------------------------------------------------------\\

    public FactMF(){
        unidadesMes = new int[12];
        faturacaoMesFill = new double[12][3];
        faturacaoTotal = 0;
    }

    //--------------------------------------------------------------Getters/Setters--------------------------------------------------------------------------\\

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

    public void setFact(int branch, int month, float price, int uni) {
        unidadesMes[month] += uni;
        faturacaoTotal += price*uni;
        faturacaoMesFill[month][branch] = price*uni;
    }
}
