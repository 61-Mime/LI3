import java.util.*;

public class CliInfo {
    private String cli;
    private Set<ProdCli> prod;

    public CliInfo(String cliCode) {
        this.cli = cliCode;
        this.prod = new TreeSet<>();
    }

    public void addProd(String prodCode, int mes, int uni, double price) {

        if (!prod.add(new ProdCli(prodCode))) {
            prod.stream().filter(p -> p.getProd().equals(prodCode)).findAny().get().addInfo(mes, uni, price);
        }
    }

    public String getCli() {
        return this.cli;
    }
}
