package Model;

import Model.GestVendas;

import java.util.List;
import java.util.Map;

public interface IConsultasInterarivas {
    List<String> getQ1();
    int[] getQ2();
    Map<Integer,float[]> getQ3();
    Map<Integer,float[]> getQ4();
    List<String> getQ5();
    List<String> getQ6();
    Map<Integer,List<String>> getQ7();
    List<String> getQ8();
    List<String> getQ9();
    Map<String,float[][]> getQ10();
    String setQuerie1(GestVendas sgv);
    String setQuerie2(GestVendas sgv,int month);
    String setQuerie3(GestVendas sgv,String code);
    String setQuerie4(GestVendas sgv,String code);
    String setQuerie5(GestVendas sgv, String code);
    String setQuerie6(GestVendas sgv,int limit);
    String setQuerie7(GestVendas sgv);
    String setQuerie8(GestVendas sgv,int limit);
    String setQuerie9(GestVendas sgv,String code,int limit);
    String setQuerie10(GestVendas sgv);
}
