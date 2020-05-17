import java.io.Serializable;
import java.util.Objects;

public class ProdCliinfo implements Comparable<ProdCliinfo>, Serializable {
    private String cod;
    private int month;
    private double price;
    private int uni;

    //--------------------------------------------------------------Construtores--------------------------------------------------------------------------\\

    public ProdCliinfo(String cod, int month, double price, int uni) {
        this.cod = cod;
        this.month = month;
        this.price = price;
        this.uni = uni;
    }

    public ProdCliinfo(ProdCliinfo p) {
        this.cod = p.getCod();
        this.month = p.getMonth();
        this.price = p.getPrice();
        this.uni = p.getUni();
    }

    //--------------------------------------------------------------Getters/Setters--------------------------------------------------------------------------\\

    public String getCod() {
        return cod;
    }

    public int getMonth() {
        return month;
    }

    public double getPrice() {
        return price;
    }

    public int getUni() {
        return uni;
    }

    public void addUni(int uni){
        this.uni += uni;
    }

    //--------------------------------------------------------------toString, equals e clone--------------------------------------------------------------------------\\

    @Override
    public boolean equals(Object o) {
        if (this == o)
            return true;
        if (o == null || getClass() != o.getClass())
            return false;
        ProdCliinfo that = (ProdCliinfo) o;
        return month == that.month &&
                Double.compare(that.price, price) == 0 &&
                uni == that.uni &&
                Objects.equals(cod, that.cod);
    }

    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder("ProdCliinfo{");
        sb.append("cod='").append(cod).append('\'');
        sb.append(", month=").append(month);
        sb.append(", price=").append(price);
        sb.append(", uni=").append(uni);
        sb.append('}');
        return sb.toString();
    }

    public ProdCliinfo clone() {
        return new ProdCliinfo(this);
    }

    public int compareTo(ProdCliinfo i) {
        return this.getCod().compareTo(i.getCod());
    }
}