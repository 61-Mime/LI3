import java.io.Serializable;
import java.util.Arrays;
import java.util.stream.Stream;

public class FactMF implements Serializable {
    private int[] unidadesMes;
    private float[][] faturacaoMesFill;
    private float faturacaoTotal; // Rever se é preciso

    //--------------------------------------------------------------Construtores--------------------------------------------------------------------------\\

    public FactMF(){
        unidadesMes = new int[12];
        faturacaoMesFill = new float[12][3];
        faturacaoTotal = 0;
    }

    //--------------------------------------------------------------Getters/Setters--------------------------------------------------------------------------\\

    public int getUnidadesMes(int month) {
        return unidadesMes[month];
    }

    public int getUniTotal() {
        return Arrays.stream(unidadesMes).sum();
    }

    public float getFaturacaoTotal() {
        return faturacaoTotal;
    }

    public float getFaturacaoMes(int month) {
        return faturacaoMesFill[month][0] + faturacaoMesFill[month][1] + faturacaoMesFill[month][2];
    }

    public float[][] getFaturacaoMesFill() {
        return Arrays.stream(faturacaoMesFill).toArray(float[][]::new);
    }

    public void setFact(int branch, int month, float
            price,int uni) {
        unidadesMes[month] += uni;
        faturacaoTotal += price*uni;
        faturacaoMesFill[month][branch] += price*uni;
    }
}
