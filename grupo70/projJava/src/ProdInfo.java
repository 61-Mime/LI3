import java.util.*;

public class ProdInfo {
    private String code;
    private Map<Integer,Set<ProdCliinfo>> mapMes;

    public ProdInfo(String code) {
        this.code = code;
        mapMes = new HashMap<>();
    }

//    public ProdInfo(ProdInfo p) {
//        this.code = p.getCode();
//        this.mapMes = p.get
//    }

    public int getSizeMonth(int month) {
        if(mapMes.containsKey(month))
            return mapMes.get(month).size();
        else return 0;
    }

    public Set<ProdCliinfo> getSetMes(int month) {
        Set<ProdCliinfo> novo  = new TreeSet<>();
        if(mapMes.get(month) == null)
            return null;

        mapMes.get(month).forEach(c -> novo.add(c.clone()));

        return novo;
    }

    public String getCode() {
        return code;
    }

    public void setCode(String code) {
        this.code = code;
    }

    public Map<Integer, Set<ProdCliinfo>> getMapMes() {
        return mapMes;
    }

    public void setMapMes(Map<Integer, Set<ProdCliinfo>> mapMes) {
        this.mapMes = mapMes;
    }

    public int getSize(){
        return mapMes.size();
    }

    public Set<String> getCliMonth(int month){
        Set<String> clientes = new TreeSet<>();
        if(mapMes.containsKey(month)){
            for(ProdCliinfo c:mapMes.get(month))
                clientes.add(c.getCod());
        }
        return clientes;
    }

    public void addCode(String cliCode, int month, double price, int uni) {
        ProdCliinfo c = new ProdCliinfo(cliCode,month,price,uni);
        mapMes.putIfAbsent(month,new TreeSet<>());
        if(!mapMes.get(month).add(c)){
            Iterator<ProdCliinfo> it = mapMes.get(month).iterator();
            boolean b = true;
            ProdCliinfo pc;
            while (it.hasNext() && b){
                pc = it.next();
                if(pc.getCod().equals(cliCode)) {
                    pc.addUni(uni);
                    b = false;
                }
            }
        }
    }

    public void addProd(String prodCode, int month, int uni, double price) {
    }

//    public int compareTo(ProdInfo i) {
//        return this.getCode().compareTo(i.getCode());
//    }
}
