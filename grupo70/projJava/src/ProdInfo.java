import java.util.HashSet;
import java.util.Set;
import java.util.TreeSet;

public class ProdInfo {
    private String prod;
    private Set<String> cliN;
    private Set<String> cliP;

    public ProdInfo(String prodCode) {
        prod = prodCode;
        cliN = new TreeSet<>();
        cliP = new TreeSet<>();
    }

    public void addCli(String cliCode, char type) {
        if(type == 'N')
            cliN.add(cliCode);

        else
            cliP.add(cliCode);
    }

    public String getProd() {
        return this.prod;
    }
}
