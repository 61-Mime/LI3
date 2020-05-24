package Model;

import Controller.Crono;

import java.util.*;
import java.util.stream.Collectors;

public class ConsultasInterativas implements IConsultasInterarivas {
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

    //--------------------------------------------------------------Getters--------------------------------------------------------------------------\\

    public List<String> getQ1(){
        return new ArrayList<>(querie1);
    }

    public int[] getQ2(){
        int[] copy;
        copy = Arrays.copyOf(querie2,8);
        return copy;
    }

    public Map<Integer,float[]> getQ3(){
        Map<Integer,float[]> q3copy = new HashMap<>();
        for(int i = 0;i < 12;i++) {
            q3copy.put(i,querie3.get(i).clone());
        }
        return q3copy;
    }

    public Map<Integer,float[]> getQ4(){
        Map<Integer,float[]> q4copy = new HashMap<>();
        for(int i = 0;i < 12;i++) {
            q4copy.put(i,querie4.get(i).clone());
        }
        return q4copy;
    }

    public List<String> getQ5(){
        List<String> q5copy = new ArrayList<>();
        querie5.forEach(p -> q5copy.add(p.toString()));

        return q5copy;
    }

    public List<String> getQ6(){
        List<String> q6copy = new ArrayList<>();
        querie6.forEach(p -> q6copy.add(p.toString()));

        return q6copy;
    }

    public Map<Integer,List<String>> getQ7(){
        Map<Integer,List<String>> q7copy = new HashMap<>();
        for(int i = 0;i < 3;i++)
            q7copy.put(i, new ArrayList<>(querie7.get(i)));

        return q7copy;
    }

    public List<String> getQ8(){
        List<String> q8copy = new ArrayList<>();
        querie8.forEach(p -> q8copy.add(p.toString()));

        return q8copy;
    }

    public List<String> getQ9(){
        List<String> q9copy = new ArrayList<>();
        querie9.forEach(p -> q9copy.add(p.toString()));

        return q9copy;
    }

    public Map<String,float[][]> getQ10(){
        return new HashMap<>(querie10);
    }

    //--------------------------------------------------------------Setters--------------------------------------------------------------------------\\


    public String setQuerie1(GestVendas sgv){
        Crono.start();
        querie1 = new ArrayList<>();

        sgv.getCatPtree().stream().filter(cod -> !(sgv.getFactContainsProd(cod))).forEach(s -> querie1.add(s));
        return Crono.getTime();
    }

    public String setQuerie2(GestVendas sgv,int month){
        Crono.start();
        querie2 = new int[8];
        int i = 0;
        querie2[i++] = sgv.getGFilVendasMes(month);
        querie2[i++] = sgv.getGFilClientesDiferentesMes(month);
        for(int f = 0;f < 3;f++) {
            querie2[i++] = sgv.getFilialVendas(f);
            querie2[i++] = sgv.getFilialClientesCompradores(f);
        }
        return Crono.getTime();
    }

    public String setQuerie3(GestVendas sgv,String cod){
        Crono.start();
        querie3 = new HashMap<>();
        float[] res;
        for(int month = 0;month < 12;month++){
            res = new float[3];
            res[0] = sgv.getGFilNumeroComprasMes(cod, month);
            res[1] = sgv.getGFilProdutosDiferentes(cod, month);
            res[2] = sgv.getGFilGastoTotalMes(cod, month);
            querie3.put(month,res);
        }
        return Crono.getTime();
    }

    public String setQuerie4(GestVendas sgv,String cod){
        Crono.start();
        querie4 = new HashMap<>();
        float[] res;
        for(int month = 0;month < 12;month++){
            res = new float[3];
            res[0] = sgv.getFactUniMes(cod,month);
            res[1] = sgv.getGFilClientesDiferentes(cod, month);
            res[2] = sgv.getFactTotalMes(cod,month);
            querie4.put(month,res);
        }
        return Crono.getTime();
    }

    public String setQuerie5(GestVendas sgv, String cod) {
        Crono.start();
        querie5 = new ArrayList<>();
        int i;

        for(i=0; i<3; i++)
            querie5.addAll(sgv.getGFilCliSet(i, cod));

        querie5 = querie5.stream().sorted(new sortParbyValue()).collect(Collectors.toList());
        return Crono.getTime();
    }

    public String setQuerie6(GestVendas sgv, int limit) {
        Crono.start();
        querie6 = new ArrayList<>();

        for(String cod:sgv.getFactKeys())
            querie6.add(new ParStringFloat(cod, sgv.getFactUni(cod),0));

        querie6 = querie6.stream().sorted(new sortParbyValue()).limit(limit).collect(Collectors.toList());

        querie6.forEach(q -> q.setValue2(sgv.getGFilClientesDiferentesTotal(q.getCode())));
        return Crono.getTime();
    }

    public String setQuerie7(GestVendas sgv) {
        Crono.start();
        querie7 = new HashMap<>();

        for(int i = 0; i<3; i++)
            querie7.put(i, sgv.getFilialClientesMaisCompradores(i));
        return Crono.getTime();
    }

    public String setQuerie8(GestVendas sgv, int limit) {
        Crono.start();
        querie8 = new ArrayList<>();

        sgv.getCatCtree().forEach(a -> querie8.add(new ParStringFloat(a, sgv.getGFilProdutosDiferentesTotal(a))));

        querie8 = querie8.stream().sorted(new sortParbyValue()).limit(limit).collect(Collectors.toList());
        return Crono.getTime();
    }

    public String setQuerie9(GestVendas sgv, String codProd,int limit) {
        Crono.start();
        querie9 = new ArrayList<>();

        for(int i=0; i<3; i++)
            querie9.addAll(sgv.getGFilProdSet(i, codProd));

        querie9 = querie9.stream().sorted(new sortParbyValue()).limit(limit).collect(Collectors.toList());
        return Crono.getTime();
    }

    public String setQuerie10(GestVendas sgv) {
        Crono.start();
        querie10 = new HashMap<>();

        for(String cod: sgv.getCatPtree()){
            if(sgv.getFactContainsProd(cod))
                querie10.put(cod, sgv.getFactMesFilProd(cod));

            else
                querie10.put(cod, null);
        }
        return Crono.getTime();
    }
}


