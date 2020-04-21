package com.company;

import java.util.List;
import java.util.ArrayList;

public class FactbyFil{
    private int vendasP[] = new int[3];
    private int vendasN[] = new int[3];
    private int facturacaoP[] = new int[3];
    private int facturacaoN[] = new int[3];
    private int unidades[] = new int[3];

    public FactbyFil() {
    }

    public void setFactFil(int fil,char type,float price, int uni) {
        if(type == 'N') {
            vendasN[fil]++;
            facturacaoN[fil] += price * uni;
        }
        else {
            vendasP[fil]++;
            facturacaoP[fil] += price * uni;
        }
        unidades[fil] += uni;
    }

    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(vendasN[0]+" "+vendasN[1]+" "+vendasN[2]+"\n");
        return sb.toString();
    }
}
