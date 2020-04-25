import java.util.HashSet;
import java.util.Set;
import java.util.TreeSet;

public class ProdInfo extends Info{
//    private String prod;
    private Set<String> cliN;
    private Set<String> cliP;

    public ProdInfo(String code) {
        super(code);
        cliN = new TreeSet<>();
        cliP = new TreeSet<>();
    }

    public void addCli(String cliCode, char type) {
        if(type == 'N')
            cliN.add(cliCode);

        else
            cliP.add(cliCode);
    }

}
