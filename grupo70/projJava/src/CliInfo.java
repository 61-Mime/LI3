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
        boolean r = prod.add(aux);

        if(r == false) {
            Iterator<ProdCli> it = prod.iterator();
            r = true;
            while (it.hasNext() && r) {
                aux = it.next();
                if (aux.getProd().equals(prodCode))
                    r = false;
            }
        }

        aux.addInfo(mes, uni, price);
    }

    public String getCli() {
        return this.cli;
    }
}
