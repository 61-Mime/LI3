package Model;

import java.io.Serializable;
import java.util.*;

public class ProdInfo implements Serializable {
    private String code;
    private Map<Integer,Map<String,ProdCliinfo>> mapMes;

    //--------------------------------------------------------------Construtores--------------------------------------------------------------------------\\

    public ProdInfo(String code) {
        this.code = code;
        mapMes = new HashMap<>();
    }

    //--------------------------------------------------------------Getters/Setters--------------------------------------------------------------------------\\

    public String getCode() {
        return code;
    }
/*
    public Set<Model.ProdCliinfo> getSetMes(int month) {
        Set<Model.ProdCliinfo> novo  = new TreeSet<>();
        if(mapMes.get(month) == null)
            return null;

        mapMes.get(month).values().forEach(c -> novo.add(c.clone()));

        return novo;
    }
*/
    public Set<ParStringFloat> getSetCodUni(){
        TreeSet<ParStringFloat> tree = new TreeSet<>();
        for(Map<String,ProdCliinfo> map: mapMes.values())
            for(Map.Entry<String,ProdCliinfo> entryProd: map.entrySet()) {
                ParStringFloat c = new ParStringFloat(entryProd.getKey(),entryProd.getValue().getUni(),entryProd.getValue().getFat());
                if (tree.contains(c)) {
                    Iterator<ParStringFloat> it = tree.iterator();
                    boolean b = true;
                    ParStringFloat q;
                    while (it.hasNext() && b) {
                        q = it.next();
                        if (q.getCode().equals(c.getCode())) {
                            q.addUni(c.getValue(),c.getValue2());
                            b = false;
                        }
                    }
                } else
                    tree.add(c);
            }
        return tree;
    }
    public Set<String> getCodeMonth(int month){
        Set<String> clientes = new TreeSet<>();
        /*if(mapMes.containsKey(month)){
            for(Model.ProdCliinfo c:mapMes.get(month).keySet())
                clientes.add(c.getCod());
        }*/
        if(mapMes.containsKey((int) month))
            clientes.addAll(mapMes.get((int)month).keySet());
        //System.out.println(clientes);
        return clientes;
    }
/*
    public List<Model.ProdCliinfo> getMapList(){
        List<Model.ProdCliinfo> list = new ArrayList<>();

        for(int i = 0;i < 12;i++)
            if(mapMes.containsKey(i))
                mapMes.get(i).stream().forEach(pcli -> list.add(pcli.clone()));

        return list;
    }*/

    //--------------------------------------------------------------Outros métodos--------------------------------------------------------------------------\\

    public void addCode(String cliCode,int month,float price,int uni) {
        //Model.ProdCliinfo c = new Model.ProdCliinfo(cliCode,month,price,uni);
        mapMes.putIfAbsent(month,new HashMap<>());
        if(mapMes.get(month).containsKey(cliCode))
            mapMes.get(month).get(cliCode).add(uni,price);
        else
            mapMes.get(month).put(cliCode,new ProdCliinfo(month,price * uni,uni));
    }
}
