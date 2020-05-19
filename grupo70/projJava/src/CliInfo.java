import java.io.Serializable;
import java.util.*;

public class CliInfo extends ProdInfo implements Comparable<CliInfo>, Serializable {
    private int []numeroCompras;
    private float []gastoTotal;

    //--------------------------------------------------------------Construtores--------------------------------------------------------------------------\\

    public CliInfo(String code) {
        super(code);
        numeroCompras = new int[12];
        gastoTotal = new float[12];
    }

    //--------------------------------------------------------------Getters/Setters--------------------------------------------------------------------------\\

    public int getNumeroCompras(int month) {
        return numeroCompras[month];
    }

    public float getGastoTotal(int month) {
        return gastoTotal[month];
    }

    public float getGastoTotal(){
        float gasto = 0;
        for (int i = 0;i< 12;i++)
            gasto+=gastoTotal[i];
        return gasto;
    }

    public void addProd(String prodCode, int month, int uni, float price) {
        super.addCode(prodCode,month,price,uni);
        numeroCompras[month]++;
        gastoTotal[month] += uni * price;
    }

    //--------------------------------------------------------------compareTo--------------------------------------------------------------------------\\

    public int compareTo(CliInfo c) {
        return (int) (c.getGastoTotal() - this.getGastoTotal());
    }
}
