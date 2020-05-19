import java.util.*;
import java.util.stream.Collectors;

public class ConsultasInterativas {
    private List<String> querie1;
    private int[] querie2;
    private Map<Integer,float[]> querie3;
    private Map<Integer,float[]> querie4;
    private List<ParStringFloat> querie5;
    private List<ParStringFloat> querie6;
    private Map<Integer, List<String>> querie7;
    private List<ParStringFloat> querie8;
    private List<ParStringFloat> querie9;
    private Map<String, float[][]> querie10;

    public void setQuerie1(GestVendas sgv){
        querie1 = new ArrayList<>();

        sgv.getCatPtree().stream().filter(cod -> !(sgv.getFactContainsProd(cod))).forEach(s -> querie1.add(s));
    }

    public void setQuerie1teste(GestVendas sgv){
        querie1 = new ArrayList<>();

        sgv.getCatPtree().stream().filter(cod -> !(sgv.getFactContainsProd(cod))).forEach(s -> querie1.add(s));
    }

    public String toStringQ1(){
        return querie1.toString() + "\nTotal produtos nunca comprados:" + querie1.size();
    }

    public void setQuerie2(GestVendas sgv, int month){
        querie2 = new int[8];
        int i = 0;
        querie2[i++] = sgv.getGFilVendasMes(month);
        querie2[i++] = sgv.getGFilClientesDiferentesMes(month);
        for(int f = 0;f < 3;f++) {
            querie2[i++] = sgv.getFilialVendas(f);
            querie2[i++] = sgv.getFilialClientesCompradores(f);
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

    public void setQuerie3(GestVendas sgv, String cod){
        querie3 = new HashMap<>();
        float[] res;
        for(int month = 0;month < 12;month++){
            res = new float[3];
            res[0] = sgv.getGFilNumeroComprasMes(cod, month);
            res[1] = sgv.getGFilProdutosDiferentes(cod, month);
            res[2] = sgv.getGFilGastoTotalMes(cod, month);
            querie3.put(month,res);
        }
    }

    public String toStringQ3(){
        float [] res;
        StringBuilder sb = new StringBuilder();
        sb.append("Mês (Compras) (Produtos Diferentes) (Gasto total)\n");
        for(int mes = 0;mes < 12;mes++) {
            res = querie3.get(mes);
            sb.append(mes+1).append("    ").append(res[0]).append("           ").append(res[1]).append("             ").append(res[2]).append("\n");
        }

        return sb.toString();
    }

    public void setQuerie4(GestVendas sgv, String cod){
        querie4 = new HashMap<>();
        float res[];
        for(int month = 0;month < 12;month++){
            res = new float[3];
            res[0] = sgv.getFactUniMes(cod,month);
            res[1] = sgv.getGFilClientesDiferentes(cod, month);
            res[2] = sgv.getFactTotalMes(cod,month);
            querie4.put(month,res);
        }
    }

    public String toStringQ4(){
        float [] res;
        StringBuilder sb = new StringBuilder();
        sb.append("Mês (Vendas uni) (Clientes Diferentes) (Faturação)\n");
        for(int mes = 0;mes < 12;mes++) {
            res = querie4.get(mes);
            sb.append(mes+1).append("      ").append(res[0]).append("           ").append(res[1]).append("            ").append(res[2]).append("\n");
        }

        return sb.toString();
    }
/*
    public void addQuerie5(String cod, int uni) {
        ParStringFloat c = new ParStringFloat(cod, uni);

        if(querie5.contains(c)){
            Iterator<ParStringFloat> it = querie5.iterator();
            boolean b = true;
            ParStringFloat q;
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
*/
    public void setQuerie5(GestVendas sgv, String cod) {
        querie5 = new ArrayList<>();
        int i;

        for(i=0; i<3; i++)
            querie5.addAll(sgv.getGFilCliSet(i, cod));

        querie5 = querie5.stream().sorted(new sortParbyValue()).collect(Collectors.toList());
    }

    public String toStringQ5(){
        return "Produtos que o cliente mais comprou:\n" + querie5.toString();
    }

    public void setQuerie6(GestVendas sgv, int limit) {
        querie6 = new ArrayList<>();

        for(String cod:sgv.getFactKeys())
            querie6.add(new ParStringFloat(cod, sgv.getFactUni(cod), 0));

        querie6 = querie6.stream().sorted(new sortParbyValue()).limit(limit).collect(Collectors.toList());

        querie6.forEach(q -> q.setValue2(sgv.getGFilClientesDiferentesTotal(q.getCode())));
    }

    public String toStringQ6(int limit){
        return limit + " produtos mais vendidos em todo o ano:\n" + querie6.toString();
    }

    public void setQuerie7(GestVendas sgv) {
        querie7 = new HashMap<>();

        for(int i = 0; i<3; i++)
            querie7.put(i, sgv.getFilialClientesMaisCompradores(i));
    }

    public String toStringQ7(){
        return "3 Clientes mais compradores por filial:\n" + querie7.toString();
    }

    public void setQuerie8(GestVendas sgv, int limit) {
        querie8 = new ArrayList<>();

        sgv.getCatCtree().forEach(a -> querie8.add(new ParStringFloat(a, sgv.getGFilProdutosDiferentesTotal(a))));

        querie8 = querie8.stream().sorted(new sortParbyValue()).limit(limit).collect(Collectors.toList());
    }

    public String toStringQ8(int limit){
        return limit + " Clientes que compraram mais produtos diferentes:\n" + querie8.toString();
    }

    public void setQuerie9(GestVendas sgv, String codProd, int limit) {
        querie9 = new ArrayList<>();
  /*      List<ProdCliinfo> list;

        for(int i=0; i<3; i++) {
            list = sgv.getGFilProdCliList(i, codProd);
            for (ProdCliinfo pcli : list){
                ParStringFloat q9 = new ParStringFloat(pcli.getCod(),pcli.getUni(),pcli.getPrice()*pcli.getUni());
                if(querie9.contains(q9)){
                    Iterator<ParStringFloat> it = querie9.iterator();
                    boolean b = true;
                    ParStringFloat q;
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
        }*/
        for(int i=0; i<3; i++)
            querie9.addAll(sgv.getGFilProdSet(i, codProd));

        querie9 = querie9.stream().sorted(new sortParbyValue()).limit(limit).collect(Collectors.toList());
    }

    public String toStringQ9(int limit,String code){
        StringBuilder sb = new StringBuilder();
        sb.append(limit).append(" Clientes que mais compraram o produto com o código ").append(code).append("\n");
        querie9.forEach(par -> sb.append(par.toString2()));

        return sb.toString();
    }

    public void setQuerie10(GestVendas sgv) {
        querie10 = new HashMap<>();

        for(String cod: sgv.getCatPtree()){
            if(sgv.getFactContainsProd(cod))
                querie10.put(cod, sgv.getFactMesFilProd(cod));

            else
                querie10.put(cod, null);
        }
    }

    public String toStringTabela(float[][] values){
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
        for(Map.Entry<String, float[][]> cod:querie10.entrySet()) {
            sb.append("Faturação ").append(cod.getKey()).append("\n");

            if (cod.getValue() != null)
                sb.append(toStringTabela(cod.getValue()));

            else
                sb.append("Produto não vendido\n");
        }

        return sb.toString();
    }
}


