package com.company;

import java.util.List;
import java.util.ArrayList;

public class FactbyFil{
    private List<Integer> vendasP;
    private List<Integer> vendasN;
    private List<Float> facturacaoP;
    private List<Float> facturacaoN;
    private List<Integer> unidades;

    public FactbyFil() {
        this.vendasN = new ArrayList<>(3);
        this.vendasP = new ArrayList<>(3);
        this.facturacaoN = new ArrayList<>(3);
        this.facturacaoP = new ArrayList<>(3);
        this.unidades = new ArrayList<>(3);
    }

    public void setFactFil(int fil,char type,float price, int uni) {
        if(type == 'N') {
            vendasN.set(fil, vendasN.get(fil) + 1);
            facturacaoN.set(fil, price * uni + facturacaoN.get(fil));
        }
        else {
            vendasP.set(fil, vendasP.get(fil) + 1);
            facturacaoP.set(fil, price * uni + facturacaoP.get(fil));
        }
        unidades.set(fil,uni + unidades.get(fil));
    }

    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(vendasN.get(0)+" "+vendasN.get(1)+" "+vendasN.get(2)+"\n");
        return sb.toString();
    }
}
