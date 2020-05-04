import java.util.List;
import java.util.ArrayList;

public class FactMF {
    private String codProd;
    private int occup;
    private List<FactbyFil> listMensal;

    public FactMF(String cod){
        this.codProd = cod;
        this.occup = 0;
        this.listMensal = new ArrayList<>();
        for(int i = 0;i < 12;i++)
            listMensal.add(i,new FactbyFil());
    }

    public String getCodProd(){
        return codProd;
    }

    public int getOccup() {
        return occup;
    }

    public void setFact(int fil, int mes, char type, float price, int uni) {
        if(occup == 0)
            occup = 1;
        this.listMensal.get(mes).setFactFil(fil,type,price,uni);
    }

    public String toSring() {
        return (codProd+" "+listMensal.get(1).toString());
    }
}
