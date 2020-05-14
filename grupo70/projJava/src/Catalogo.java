import java.util.*;

public class Catalogo {
    private int type;
    private int total;
    private Map<Integer,Set<String>> list;

    public Catalogo(int t){
        int i;
        this.type = t;
        this.total = 0;
        this.list = new HashMap<>(26);
        for(i = 0;i < 26;i++) {
            this.list.put(i,new TreeSet<>());
        }
    }

    public int getTotal() {
        return this.total;
    }

    public void addCod(String cod) {
        if((type == 0 && valCli(cod))||(type == 1 && valProd(cod))) {
            total++;
            int i = cod.charAt(0) - 'A';
            list.get(i).add(cod);
        }
    }
    /*
    public void ordena(){
        for(int i = 0;i < 12;i++)
            list.get(i).sort(null);
    }*/

    public boolean valCli(String codCli) {
        return codCli.matches("[A-Z]([1-4]\\d{3}|50{3})");
    }

    public boolean valProd(String codProd) {
        return codProd.matches("[A-Z]{2}([1-9]\\d{3})");
    }

    public boolean contem(String cod) {
        return list.get(cod.charAt(0) - 'A').contains(cod);
    }

    public Set<String> getTree(int i) {
        return list.get(i);
    }

    public String[] getArraycat(){
        String[] array = new String[total];
        int curr = 0,i;
        for(i = 0;i < 12;i++)
            for (String st:list.get(i))
                array[curr++] = st;

        return array;
    }

    /*public void printlista(int i) {
        Set <String> tree = list.get(i);
        if(tree != null) {
            tree.forEach(System.out::println);
        }
    }*/
}
