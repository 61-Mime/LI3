import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;
import java.util.TreeSet;

public class CliInfo {
    private String cli;
    private Set<ProdCli> prod;

    public CliInfo(String cliCode) {
        this.cli = cliCode;
        this.prod = new TreeSet<>();
    }

    public void addProd(String prodCode, int mes, int uni, double price) {
        ProdCli aux = new ProdCli(prodCode);

        if(!prod.add(aux)) {
            Iterator<ProdCli> it = prod.iterator();
            boolean r = true;

            while (it.hasNext() && r) {
                if (it.next().getProd().equals(prodCode)) {
                    r = false;
                    aux = it.next();
                }
            }
        }

        aux.addInfo(mes, uni, price);
    }

    public String getCli() {
        return this.cli;
    }
}
