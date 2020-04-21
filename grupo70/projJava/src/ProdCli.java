public class ProdCli implements  Comparable {
    private String prod;
    private int[] uni;
    private double fat;

    public ProdCli(String prodCode){
        this.prod = prodCode;
        this.uni = new int[12];
        this.fat = 0;
    }

    public void addInfo(int mes, int uni, double price) {
        this.uni[mes] += uni;
        this.fat += price * uni;
    }

    @Override
    public int compareTo(Object o) {
        ProdCli aux = (ProdCli) o;
        return this.prod.compareTo(aux.prod);
    }

    public boolean equals(ProdCli p) {
        return prod.equals(p.getProd());
    }

    public String getProd(){
        return this.prod;
    }
}
