import java.io.Serializable;

public class LoadInfo implements Serializable {
    private int vendasValidas;
    private int vendasInvalidas;
    private int CliValidos;
    private int CliLidos;
    private int cliComprador;
    private int ProdValidos;
    private int ProdLidos;
    private String CliPath;
    private String ProdPath;
    private String SalesPath;

    public LoadInfo() {
        vendasInvalidas = 0;
        vendasValidas = 0;
        ProdLidos = 0;
        CliLidos = 0;
        cliComprador = 0;
        CliPath = "Files/Clientes.txt";
        ProdPath = "Files/Produtos.txt";
        SalesPath = "Files/Vendas_1M.txt";
    }

    public int getVendasValidas(){
        return vendasValidas;
    }

    public int getVendasInvalidas(){
        return vendasInvalidas;
    }

    public String getCliPath() {
        return CliPath;
    }

    public String getProdPath() {
        return ProdPath;
    }

    public String getSalesPath() {
        return SalesPath;
    }

    public int getCliValidos() {
        return CliValidos;
    }

    public int getCliComprador() {
        return cliComprador;
    }

    public int getProdValidos() {
        return ProdValidos;
    }

    public void incValidas(){
        vendasValidas++;
    }

    public void incInvalidas(){
        vendasInvalidas++;
    }

    public void incProdLidos(){
        ProdLidos++;
    }

    public void incCliLidos(){
        CliLidos++;
    }

    public void incCliComprador() { cliComprador++; }

    public void setCliPath(String cliPath) {
        CliPath = cliPath;
    }

    public void setProdPath(String prodPath) {
        ProdPath = prodPath;
    }

    public void setSalesPath(String salesPath) {
        SalesPath = salesPath;
    }

    public void setCliValidos(int cliValidos) {
        CliValidos = cliValidos;
    }

    public void setProdValidos(int prodValidos) {
        ProdValidos = prodValidos;
    }
}