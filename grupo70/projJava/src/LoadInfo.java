public class LoadInfo {
    private int vendasValidas;
    private int vendasInvalidas;

    public LoadInfo() {
        vendasInvalidas = 0;
        vendasValidas = 0;
    }

    public void incValidas(){
        vendasValidas++;
    }

    public void incInvalidas(){
        vendasInvalidas++;
    }

    public int getVendasValidas(){
        return vendasValidas;
    }

    public int getVendasInvalidas(){
        return vendasInvalidas;
    }
}
