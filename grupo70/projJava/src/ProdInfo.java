import java.util.*;

public class ProdInfo{
    private String code;
    private Map<Integer,Set<ProdCliinfo>> mapMes;

    public ProdInfo(String code) {
        this.code = code;
        mapMes = new HashMap<>();
    }

    public int getSizeMonth(int month) {
        if(mapMes.containsKey(month))
            return mapMes.get(month).size();
        else return 0;
    }

    public String getCode() {
        return code;
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

    //public int compareTo(ProdInfo i) {
      //  return this.getCode().compareTo(i.getCode());
    //}
}
