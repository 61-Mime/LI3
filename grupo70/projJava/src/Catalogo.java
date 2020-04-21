import java.util.*;

public class Catalogo {
    private int type;
    private Map<Integer,Set<String>> lista;

    public Catalogo(int t){
        int i;
        this.type = t;
        this.lista = new HashMap<>(26);
        for(i = 0;i < 26;i++) {
            this.lista.put(i,new TreeSet<>());
        }
    }

    public void addCod(String cod) {
        if((type == 0 && valCli(cod))||(type == 1 && valProd(cod))) {
            int i = cod.charAt(0) - 'A';
            lista.get(i).add(cod);
        }
    }

    public boolean valCli(String codCli) {
        return codCli.matches("[A-Z]([1-4]\\d{3}|50{3})");
    }

    public boolean valProd(String codProd) {
        return codProd.matches("[A-Z]{2}([1-9]\\d{3})");
    }

    public boolean contem(String cod) {
        return lista.get(cod.charAt(0) - 'A').contains(cod);
    }

    public Set<String> getTree(int i) {
        return lista.get(i);
    }

    public void printlista(int i) {
        Set <String> tree = lista.get(i);
        if(tree != null) {
            for (String elem : tree) {
                System.out.println(elem);
            }
        }
    }
}
