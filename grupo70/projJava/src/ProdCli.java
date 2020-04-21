public class ProdCli {
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

    public int compareTo(ProdCli outro) {
        return this.prod.compareTo(outro.prod);
    }

    public String getProd(){
        return this.prod;
    }
}
