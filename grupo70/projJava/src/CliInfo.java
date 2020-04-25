import java.util.*;

public class CliInfo extends Info{
//    private String cli;
    private Set<ProdCli> prod;

    public CliInfo(String code) {
        super(code);
        this.prod = new TreeSet<>();
    }

    public void addProd(String prodCode, int mes, int uni, double price) {

        if (!prod.add(new ProdCli(prodCode))) {
            prod.stream().filter(p -> p.getProd().equals(prodCode)).findFirst().orElse(null).addInfo(mes, uni, price);
        }
    }
}
