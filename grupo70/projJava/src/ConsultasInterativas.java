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

    public void setQuerie1(Load sgv){
        querie1 = new ArrayList<>();
        int i;
        for(i = 0;i < 26;i++){
            int finalI = i;
            sgv.getCatP().getTree(i).stream().filter(cod -> sgv.getFact().containsProd(finalI,cod)).forEach(s -> querie1.add(s));
            //sgv.getFact().getList(i).stream().filter(p -> p.getOccup() == 0).forEach(p -> querie1.add(p.getCodProd()));
        }
    }

    public String toStringQ1(){
        return querie1.toString() + "\nTotal produtos nunca comprados:" + querie1.size();
    }

    public void setQuerie2(Load sgv,int month){
        querie2 = new int[8];
        int i = 0;
        querie2[i++] = sgv.getgFil().getVendasMes(month);
        querie2[i++] = sgv.getgFil().clientesDiferentesMes(month);
        for(int f = 0;f < 3;f++) {
            querie2[i++] = sgv.getFilial(f).getVendasFil();
            querie2[i++] = sgv.getFilial(f).getClientesCompradores();
        }
    }

    public String toStringQ2(int month){
        int i = 0;
        StringBuilder sb = new StringBuilder();
        sb.append("Total do vendas no mês ").append(month).append(":").append(querie2[i++]).
                append("\nTotal de compras de clientes diferentes no mês ").append(month).append(":").append(querie2[i++]);
        for(int fil = 1;fil < 4;fil++)
            sb.append("\nTotal de vendas na filial ").append(fil).append(":").append(querie2[i++])
              .append("\nTotal de compras de clientes diferentes na filial ").append(fil).append(":").append(querie2[i++]);

        return sb.toString();
    }

    public void setQuerie3(Load sgv,String cod){
        querie3 = new HashMap<>();
        double[] res;
        int index,pos;
        //index = sgv.getFilial(0).getIndex(cod);
        //pos = sgv.getFilial(0).getPosCli(cod,index);
        for(int month = 0;month < 12;month++){
            res = new double[3];
            res[0] = sgv.getgFil().numeroComprasMes(cod,month);
            res[1] = sgv.getgFil().produtosDiferentes(cod,month);
            res[2] = sgv.getgFil().gastoTotalMes(cod,month);
            querie3.put(month,res);
        }
    }

    public String toStringQ3(){
        double [] res;
        StringBuilder sb = new StringBuilder();
        sb.append("Mês (Compras) (Produtos Diferentes) (Gasto total)\n");
        for(int mes = 0;mes < 12;mes++) {
            res = querie3.get(mes);
            sb.append(mes).append("    ").append(res[0]).append("           ").append(res[1]).append("             ").append(res[2]).append("\n");
        }

        return sb.toString();
    }

    public void setQuerie4(Load sgv,String cod){
        querie4 = new HashMap<>();
        int index;
        double res[];
        for(int month = 0;month < 12;month++){
            res = new double[3];
            index = sgv.getFact().getIndex(cod);
            //pos = sgv.getFact().getPos(cod,index);
            res[0] = sgv.getFact().getUniMes(index,cod,month);
            res[1] = sgv.getgFil().clientesDiferentes(cod,month);
            res[2] = sgv.getFact().getFatTotalMes(index,cod,month);
            querie3.put(month,res);
        }
    }

    public String toStringQ4(){
        double [] res;
        StringBuilder sb = new StringBuilder();
        sb.append("Mês (Vendas uni) (Clientes Diferentes) (Faturação)\n");
        for(int mes = 0;mes < 12;mes++) {
            res = querie3.get(mes);
            sb.append(mes).append("      ").append(res[0]).append("           ").append(res[1]).append("            ").append(res[2]).append("\n");
        }

        return sb.toString();
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
        querie5 = new ArrayList<>();
        int i, j;

        for(i=0; i<3; i++)
            for(j=0; j<12; j++){
                Set<ProdCliinfo> tree = sgv.getFilial(i).getCliInfo(cod).getSetMes(j);
                if(tree != null)
                    tree.forEach(c -> addQuerie5(c.getCod(),c.getUni()));}

        querie5 = querie5.stream().sorted(new sortParbyValue()).collect(Collectors.toList());
    }

    public String toStringQ5(){
        return "Produtos que o cliente mais comprou:\n" + querie5.toString();
    }

    public void setQuerie6(Load sgv, int limit) {
        querie6 = new ArrayList<>();
        int size = 0;
//        for (List<FactMF> list: sgv.getFact().getListaProd().values()) {
//            for (FactMF f: list)
//                querie6.add(new Querie8(f.getCodProd(), f.getUniTotal()));
//        }

        for(int i = 0; i<26; i++) {
            //size = sgv.getFact().getSize(i);
            for(String s:sgv.getFact().getKeys(i))
                querie6.add(new ParStringInt(s, sgv.getFact().getUni(i, s)));
//            sgv.getFact().getList(i).forEach(a -> querie6.add(new Querie8(a.getCodProd(), )));
/*
            for (int j = 0; j<size; j++) {
                querie6.add(new ParStringInt(sgv.getFact().getProd(i, j), sgv.getFact().getUni(i, j)));
            }*/
        }

        querie6 = querie6.stream().sorted(new sortParbyValue()).limit(limit).collect(Collectors.toList());

        querie6.forEach(q -> q.setValue(sgv.getgFil().clientesDiferentesTotal(q.getCode())));
    }

    public String toStringQ6(int limit){
        return limit + " produtos mais vendidos em todo o ano:\n" + querie6.toString();
    }

    public void setQuerie7(Load sgv) {
        querie7 = new HashMap<>();

        for(int i = 0; i<3; i++)
            querie7.put(i, sgv.getFilial(i).getClientesMaisCompradores());
    }

    public String toStringQ7(){
        return "3 Clientes mais compradores por filial:\n" + querie7.toString();
    }

    public void setQuerie8(Load sgv, int limit) {
        querie8 = new ArrayList<>();
        for(int i=0; i<26; i++)
            sgv.getCatC().getTree(i).forEach(a -> querie8.add(new ParStringInt(a, sgv.getgFil().produtosDiferentesTotal(a))));

        querie8 = querie8.stream().sorted(new sortParbyValue()).limit(limit).collect(Collectors.toList());
    }

    public String toStringQ8(int limit){
        return limit + " Clientes que compraram mais produtos diferentes:\n" + querie8.toString();
    }

    public void setQuerie9(Load sgv, String codProd,int limit) {
        querie9 = new ArrayList<>();
        List<ProdCliinfo> list;

        for(int i=0; i<3; i++) {
            list = sgv.getgFil().getFil(i).getProdCliList(codProd);
            for (ProdCliinfo pcli : list){
                ParStringInt q9 = new ParStringInt(pcli.getCod(),pcli.getUni(),pcli.getPrice()*pcli.getUni());
                if(querie9.contains(q9)){
                    Iterator<ParStringInt> it = querie9.iterator();
                    boolean b = true;
                    ParStringInt q;
                    while (it.hasNext() && b){
                        q = it.next();
                        if(q.getCode().equals(q9.getCode())) {
                            q.addUni(q9.getValue(),q9.getValue2());
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

    public String toStringQ9(int limit,String code){
        StringBuilder sb = new StringBuilder();
        sb.append(limit).append(" Clientes que mais compraram o produto com o código ").append(code).append("\n");
        querie9.forEach(par -> sb.append(par.toString2()));

        return sb.toString();
    }

    public void setQuerie10(Load sgv) {
        querie10 = new ArrayList<>();
        querie10prods = new String[0];
        int i,c = 0;
        querie10prods = new String[sgv.getCatP().getTotal()];

        for (i = 0; i < 26; i++) {
            for(String s:sgv.getFact().getKeys(i)){
                querie10.add(sgv.getFact().getFatMesFilProd(i, s));
                querie10prods[c++] = sgv.getFact().getProd(i, s);
            }
            /*size = sgv.getFact().getSize(i);
            for (int j = 0; j < size; j++) {
                querie10.add(sgv.getFact().getFatMesFilProd(i, j));
                querie10prods[c++] = sgv.getFact().getProd(i, j);
            }*/
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


