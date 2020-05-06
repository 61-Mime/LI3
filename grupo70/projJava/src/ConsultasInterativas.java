import java.lang.reflect.Array;
import java.util.*;

public class ConsultasInterativas {
    private List<String> querie1;
    private int[] querie2;
    private Map<Integer,double[]> querie3;
    private Map<Integer,double[]> querie4;

    public ConsultasInterativas(){
        querie1 = new ArrayList<>();
        querie2 = new int[8];
        querie3 = new HashMap<>();
    }

    public void setQuerie1(Load sgv){
        for(int i = 0;i < 26;i++){
            sgv.getFact().getList(i).stream().filter(p -> p.getOccup() == 0).forEach(p -> querie1.add(p.getCodProd()));
        }
    }

    public int getQ1size(){
        return querie1.size();
    }

    public void setQuerie2(Load sgv,int month){
        querie2[0] = sgv.getgFil().getVendasMes(month);
        querie2[1] = sgv.getgFil().clientesDiferentesMes(month);
        for(int i = 0;i < 3;i++) {
            querie2[2 + 2*i] = sgv.getFilial(i).getVendasFil();
            querie2[2 + 2*i+1] = sgv.getFilial(i).getClientesCompradores();
        }
    }

    public void setQuerie3(Load sgv,String cod){
        double res[],res2[],res3[];
        for(int month = 1;month < 13;month++){
            res = sgv.getFilial(0).getCliInfo(cod,month);
            res2 = sgv.getFilial(1).getCliInfo(cod,month);
            res3 = sgv.getFilial(2).getCliInfo(cod,month);
            res[0] += res2[0] + res3[0];
            res[1] += res2[1] + res3[1];
            res[2] += res2[2] + res3[2];
            querie3.put(month,res);
        }
    }

    public void setQuerie4(Load sgv,String cod){
        int index,pos;
        double res[];
        for(int month = 1;month < 13;month++){
            res = new double[3];
            index = sgv.getFact().getIndex(cod);
            pos = sgv.getFact().getPos(cod,index);
            res[0] = sgv.getFact().getUniMes(index,pos,month);
            res[1] = sgv.getgFil().clientesDiferentes(cod,month);
            res[2] = sgv.getFact().getFatTotalMes(index,pos,month);
            querie3.put(month,res);
        }
    }
}


