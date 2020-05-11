public class ProdCliinfo implements Comparable<ProdCliinfo>{
    private String cod;
    private int month;
    private double price;
    private int uni;

    public ProdCliinfo(String cod, int month, double price, int uni) {
        this.cod = cod;
        this.month = month;
        this.price = price;
        this.uni = uni;
    }

    public String getCod() {
        return cod;
    }

    public void addUni(int uni){
        this.uni += uni;
    }

    public int compareTo(ProdCliinfo i) {
        return this.getCod().compareTo(i.getCod());
    }
}