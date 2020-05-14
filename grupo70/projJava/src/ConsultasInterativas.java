import java.util.*;
import java.util.stream.Collectors;

public class ConsultasInterativas {
    private List<String> querie1;
    private int[] querie2;
    private Map<Integer,double[]> querie3;
    private Map<Integer,double[]> querie4;
    private List<ParStringInt> querie5;
    private List<ParStringInt> querie6;
    private Map<Integer, List<String>> querie7;
    private List<ParStringInt> querie8;
    private List<ParStringInt> querie9;
    private List<double[][]> querie10;
    private String[]querie10prods;

    public ConsultasInterativas(){
        querie1 = new ArrayList<>();
        querie2 = new int[8];
        querie3 = new HashMap<>();
        querie4 = new HashMap<>();
        querie5 = new ArrayList<>();
        querie6 = new ArrayList<>();
        querie7 = new HashMap<>();
        querie8 = new ArrayList<>();
        querie9 = new ArrayList<>();
        querie10 = new ArrayList<>();
        querie10prods = new String[0];
    }

    public void setQuerie1(Load sgv){
        for(int i = 0;i < 26;i++){
            sgv.getFact().getList(i).stream().filter(p -> p.getOccup() == 0).forEach(p -> querie1.add(p.getCodProd()));
        }
    }

    public int getQuerie1(){
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

    public int[] getQuerie2() {
        return querie2;
    }

    public void setQuerie3(Load sgv,String cod){
        double[] res;
        int index,pos;
        index = sgv.getFilial(0).getIndex(cod);
        pos = sgv.getFilial(0).getPosCli(cod,index);
        for(int month = 0;month < 12;month++){
            res = new double[3];
            res[0] = sgv.getgFil().numeroComprasMes(index,pos,month);
            res[1] = sgv.getgFil().produtosDiferentes(cod,month);
            res[2] = sgv.getgFil().gastoTotalMes(index,pos,month);
            querie3.put(month,res);
        }
    }

    public Map<Integer,double[]> getQuerie3() {
        return querie3;
    }

    public void setQuerie4(Load sgv,String cod){
        int index,pos;
        double res[];
        for(int month = 0;month < 12;month++){
            res = new double[3];
            index = sgv.getFact().getIndex(cod);
            pos = sgv.getFact().getPos(cod,index);
            res[0] = sgv.getFact().getUniMes(index,pos,month);
            res[1] = sgv.getgFil().clientesDiferentes(cod,month);
            res[2] = sgv.getFact().getFatTotalMes(index,pos,month);
            querie3.put(month,res);
        }
    }

    public Map<Integer,double[]> getQuerie4() {
        return querie4;
    }

    public void addQuerie5(String cod, int uni) {
        ParStringInt c = new ParStringInt(cod, uni);

        if(querie5.contains(c)){
            Iterator<ParStringInt> it = querie5.iterator();
            boolean b = true;
            ParStringInt q;
            while (it.hasNext() && b){
                q = it.next();
                if(q.getCode().equals(cod)) {
                    q.addUni(uni);
                    b = false;
                }
            }
        }
        else
            querie5.add(c);
    }

    public void setQuerie5(Load sgv, String cod) {
        int index,pos, i, j;
        index = sgv.getgFil().getFil(0).getIndex(cod);
        pos = sgv.getgFil().getFil(0).getPosCli(cod,index);

        for(i=0; i<3; i++)
            for(j=0; j<12; j++){
                Set<ProdCliinfo> tree = sgv.getFilial(i).getCliInfo(index, pos).getSetMes(j);
                if(tree != null)
                    tree.forEach(c -> addQuerie5(c.getCod(),c.getUni()));}

        querie5 = querie5.stream().sorted(new sortParbyValue()).collect(Collectors.toList());

    }

    public List<ParStringInt> getQuerie5() {
        return querie5;
    }

    public void setQuerie6(Load sgv, int limit) {
            int size = 0;
//        for (List<FactMF> list: sgv.getFact().getListaProd().values()) {
//            for (FactMF f: list)
//                querie6.add(new Querie8(f.getCodProd(), f.getUniTotal()));
//        }

        for(int i = 0; i<26; i++) {
            size = sgv.getFact().getSize(i);

//            sgv.getFact().getList(i).forEach(a -> querie6.add(new Querie8(a.getCodProd(), )));

            for (int j = 0; j<size; j++) {
                querie6.add(new ParStringInt(sgv.getFact().getProd(i, j), sgv.getFact().getUni(i, j)));
            }
        }

        querie6 = querie6.stream().sorted(new sortParbyValue()).limit(limit).collect(Collectors.toList());

        querie6.forEach(q -> q.setValue(sgv.getgFil().clientesDiferentesTotal(q.getCode())));
    }

    public List<ParStringInt> getQuerie6() {
        return querie6.stream().map(ParStringInt::clone).collect(Collectors.toList());
    }

    public void setQuerie7(Load sgv) {

        for(int i = 0; i<3; i++)
            querie7.put(i, sgv.getFilial(i).getClientesMaisCompradores());
    }

    public Map<Integer, List<String>> getQuerie7() {
        return querie7;
    }

    public void setQuerie8(Load sgv, int limit) {
        for(int i=0; i<26; i++)
            sgv.getCatC().getTree(i).forEach(a -> querie8.add(new ParStringInt(a, sgv.getgFil().produtosDiferentesTotal(a))));

        querie8 = querie8.stream().sorted(new sortParbyValue()).limit(limit).collect(Collectors.toList());
    }

    public List<ParStringInt> getQuerie8() {
        return querie8;
    }

    public void setQuerie9(Load sgv, String codProd,int limit) {
        List<ProdCliinfo> list;
        int index = sgv.getgFil().getFil(0).getIndex(codProd);
        int pos = sgv.getgFil().getFil(0).getPosProd(codProd,index);

        for(int i=0; i<3; i++) {
            list = sgv.getgFil().getFil(i).getProdCliList(index, pos);
            for (ProdCliinfo pcli : list){
                ParStringInt q9 = new ParStringInt(pcli.getCod(),pcli.getUni());
                if(querie9.contains(q9)){
                    Iterator<ParStringInt> it = querie9.iterator();
                    boolean b = true;
                    ParStringInt q;
                    while (it.hasNext() && b){
                        q = it.next();
                        if(q.getCode().equals(q9.getCode())) {
                            q.addUni(q9.getValue());
                            b = false;
                        }
                    }
                }
                else
                    querie9.add(q9);
            }
        }

        querie9 = querie9.stream().sorted(new sortParbyValue()).limit(limit).collect(Collectors.toList());
    }

    public List<ParStringInt> getQuerie9() {
        return querie9.stream().map(ParStringInt::clone).collect(Collectors.toList());
    }

    public void setQuerie10(Load sgv) {
        int size = 0, i,c = 0;
        querie10prods = new String[sgv.getCatP().getTotal()];

        for (i = 0; i < 26; i++) {
            size = sgv.getFact().getSize(i);
            for (int j = 0; j < size; j++) {
                querie10.add(sgv.getFact().getFatMesFilProd(i, j));
                querie10prods[c++] = sgv.getFact().getProd(i, j);
            }
        }
    }

    public String toStringTabela(double[][] values){
        StringBuilder sb = new StringBuilder();
        for(int fil = 0;fil < 3;fil++) {
            for (int i = 0; i < 12; i++)
                sb.append(values[i][fil]).append(" ");
            sb.append("\n");
        }

        return sb.toString();
    }

    public String toStringQ10(){
        int size = querie10.size();
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i<size;i++)
            sb.append("Faturação ").append(querie10prods[i]).append("\n").append(toStringTabela(querie10.get(i)));

        return sb.toString();
    }
}


