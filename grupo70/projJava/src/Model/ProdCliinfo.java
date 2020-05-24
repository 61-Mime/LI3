package Model;

public class ProdCliinfo{
    private int month;
    private float fat;
    private int uni;

    //--------------------------------------------------------------Construtores--------------------------------------------------------------------------\\

    public ProdCliinfo(int month,float fat,int uni) {
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

    public int getMonth() {
        return month;
    }

    public float getFat() {
        return fat;
    }

    public int getUni() {
        return uni;
    }

    public void add(int uni,float price){
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
        final StringBuilder sb = new StringBuilder("Model.ProdCliinfo{");
        sb.append(", month=").append(month);
        sb.append(", price=").append(fat);
        sb.append(", uni=").append(uni);
        sb.append('}');
        return sb.toString();
    }

    public ProdCliinfo clone() {
        return new ProdCliinfo(this);
    }

    /*public int compareTo(Model.ProdCliinfo i) {
        return this.getCod().compareTo(i.getCod());
    }*/
}