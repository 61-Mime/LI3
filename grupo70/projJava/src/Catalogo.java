import java.io.Serializable;
import java.util.*;

public class Catalogo implements Serializable {
    private int type;
    private int total;
    private Set<String> list;

    //--------------------------------------------------------------Construtores--------------------------------------------------------------------------\\

    public Catalogo(int t){
        int i;
        this.type = t;
        this.total = 0;
        this.list = new TreeSet<>();
    }

    //--------------------------------------------------------------Getters/Setters--------------------------------------------------------------------------\\

    public int getTotal() {
        return this.total;
    }

    public Set<String> getTree() {
        Set<String> set = new TreeSet<>();
        set.addAll(list);
        return set;
    }

    //--------------------------------------------------------------toString--------------------------------------------------------------------------\\

    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder("Catalogo{");
        sb.append("type=").append(type);
        sb.append(", total=").append(total);
        sb.append(", list=").append(list);
        sb.append('}');
        return sb.toString();
    }

    //--------------------------------------------------------------Outros métodos--------------------------------------------------------------------------\\

    public void addCod(String cod) {
        if((type == 0 && valCli(cod))||(type == 1 && valProd(cod))) {
            total++;
            list.add(cod);
        }
    }

    public boolean valCli(String codCli) {
        return codCli.matches("[A-Z]([1-4]\\d{3}|50{3})");
    }

    public boolean valProd(String codProd) {
        return codProd.matches("[A-Z]{2}([1-9]\\d{3})");
    }

    public boolean contem(String cod) {
        return list.contains(cod);
    }
}
