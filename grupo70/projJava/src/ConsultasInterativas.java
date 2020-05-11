import java.lang.reflect.Array;
import java.util.*;
import java.util.stream.Collectors;

public class ConsultasInterativas {
    private List<String> querie1;
    private int[] querie2;
    private Map<Integer,double[]> querie3;
    private Map<Integer,double[]> querie4;
    private Map<Integer, List<String>> querie7;
    private List<Querie8> querie8;

    public ConsultasInterativas(){
        querie1 = new ArrayList<>();
        querie2 = new int[8];
        querie3 = new HashMap<>();
        querie4 = new HashMap<>();
        querie7 = new HashMap<>();
        querie8 = new ArrayList<>();
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
        double res[];
        int index,pos;
        for(int month = 1;month < 13;month++){
            res = new double[3];
            index = sgv.getFilial(0).getIndex(cod);
            pos = sgv.getFilial(0).getPosCli(cod,index);
            res[0] = sgv.getgFil().numeroComprasMes(index,pos,month);
            res[1] = sgv.getgFil().produtosDiferentes(cod,month);
            res[2] = sgv.getgFil().gastoTotalMes(index,pos,month);
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

    public void setQuerie7(Load sgv) {

        for(int i = 0; i<3; i++)
            querie7.put(i, sgv.getFilial(i).getClientesMaisCompradores());
    }

    public Map<Integer, List<String>> getQuerie7() {
        return querie7;
    }

    public void setQuerie8(Load sgv, int limit) {
        for(int i=0; i<26; i++) {
            sgv.getCatC().getTree(i).forEach(a -> querie8.add(new Querie8(a, sgv.getgFil().produtosDiferentesTotal(a))));
        }

        querie8 = querie8.stream().sorted().limit(limit).collect(Collectors.toList());
    }

    public List<Querie8> getQuerie8() {
        return querie8;
    }
}


