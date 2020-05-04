import java.util.*;

public class CliInfo extends Info{
//    private String cli;
    private Set<ProdCli> prod;

    public CliInfo(String code) {
        super(code);
        this.prod = new TreeSet<>();
    }

    public int getSize() {
        return prod.size();
    }

    public void addProd(String prodCode, int mes, int uni, double price) {

        if (!prod.add(new ProdCli(prodCode,mes, uni, price))) {
            Iterator<ProdCli> it = prod.iterator();
            boolean b = true;
            ProdCli pc;
            while (it.hasNext() && b){
                pc = it.next();
                if(pc.getProd().equals(prodCode)) {
                    pc.addInfo(mes, uni, price);
                    b = false;
                }
            }
        }
        //prod.stream().filter(p -> p.getProd().equals(prodCode)).findFirst().orElse(null).addInfo(mes, uni, price);
    }
}
