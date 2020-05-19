import java.io.Serializable;
import java.util.Objects;

public class ProdCliinfo{
    private short month;
    private float fat;
    private short uni;

    //--------------------------------------------------------------Construtores--------------------------------------------------------------------------\\

    public ProdCliinfo(short month,float fat,short uni) {
        this.month = month;
        this.fat = fat;
        this.uni = uni;
    }

    public ProdCliinfo(ProdCliinfo p) {
        this.month = p.getMonth();
        this.fat = p.getFat();
        this.uni = p.getUni();
    }

    //--------------------------------------------------------------Getters/Setters--------------------------------------------------------------------------\\

    public short getMonth() {
        return month;
    }

    public float getFat() {
        return fat;
    }

    public short getUni() {
        return uni;
    }

    public void add(short uni,float price){
        this.uni += uni;
        this.fat += uni * price;
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
                Double.compare(that.fat, fat) == 0 &&
                uni == that.uni;
    }

    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder("ProdCliinfo{");
        sb.append(", month=").append(month);
        sb.append(", price=").append(fat);
        sb.append(", uni=").append(uni);
        sb.append('}');
        return sb.toString();
    }

    public ProdCliinfo clone() {
        return new ProdCliinfo(this);
    }

    /*public int compareTo(ProdCliinfo i) {
        return this.getCod().compareTo(i.getCod());
    }*/
}