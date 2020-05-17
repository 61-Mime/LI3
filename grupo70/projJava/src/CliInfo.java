import java.io.Serializable;
import java.util.*;

public class CliInfo extends ProdInfo implements Comparable<CliInfo>, Serializable {
    private int []numeroCompras;
    private double []gastoTotal;

    //--------------------------------------------------------------Construtores--------------------------------------------------------------------------\\

    public CliInfo(String code) {
        super(code);
        numeroCompras = new int[12];
        gastoTotal = new double[12];
    }

    //--------------------------------------------------------------Getters/Setters--------------------------------------------------------------------------\\

    public int getNumeroCompras(int month) {
        return numeroCompras[month];
    }

    public double getGastoTotal(int month) {
        return gastoTotal[month];
    }

    public double getGastoTotal(){
        return Arrays.stream(gastoTotal).sum();
    }

    public void addProd(String prodCode, int month, int uni, double price) {
        super.addCode(prodCode,month,price,uni);
        numeroCompras[month]++;
        gastoTotal[month] += uni * price;
    }

    //--------------------------------------------------------------compareTo--------------------------------------------------------------------------\\

    public int compareTo(CliInfo c) {
        return (int) (c.getGastoTotal() - this.getGastoTotal());
    }
}
