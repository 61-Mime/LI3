import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;

public class Load implements Serializable {
    private Catalogo catClientes;
    private Catalogo catProdutos;
    private Facturacao fact;
    private GestaoFiliais gFil;
    private LoadInfo loadInfo;

    //--------------------------------------------------------------Construtores--------------------------------------------------------------------------\\

    public Load(){
        catClientes = new Catalogo(0);
        catProdutos = new Catalogo(1);
        fact = new Facturacao();
        gFil = new GestaoFiliais();
        loadInfo = new LoadInfo();
    }

    //--------------------------------------------------------------Getters/Setters--------------------------------------------------------------------------\\
    public boolean getCatCcontains(String cliCode){
        return catClientes.contem(cliCode);
    }

    public boolean getCatPcontains(String prodCode){
        return catProdutos.contem(prodCode);
    }

    public Set<String> getCatPtree(){
        return catProdutos.getTree();
    }

    public Set<String> getCatCtree(){
        return catClientes.getTree();
    }

    public boolean cliVal(String code) {
        return catClientes.valCli(code);
    }

    public boolean prodVal(String code) {
        return catProdutos.valProd(code);
    }

    public int getFilialVendas(int branch){
        return gFil.getVendasFilial(branch);
    }

    public int getFilialClientesCompradores(int branch){
        return gFil.getClientesCompradoresFilial(branch);
    }

    public Set<ProdCliinfo> getFilialProdCliMes(int branch, String cod, int month){
        return gFil.getProdCliMesFilial(branch, cod, month);
    }

    public List<String> getFilialClientesMaisCompradores(int branch){
        return gFil.getClientesMaisCompradoresFilial(branch);
    }

    public int getGFilVendasMes(int month){
        return gFil.getVendasMes(month);
    }

    public int getGFilClientesDiferentesMes(int month) {
        return gFil.clientesDiferentesMes(month);
    }

    public double getGFilNumeroComprasMes(String cod, int month) {
        return gFil.numeroComprasMes(cod, month);
    }

    public double getGFilProdutosDiferentes(String cod, int month) {
        return gFil.produtosDiferentes(cod, month);
    }

    public double getGFilGastoTotalMes(String cod, int month) {
        return gFil.gastoTotalMes(cod, month);
    }

    public double getGFilClientesDiferentes(String cod, int month) {
        return gFil.clientesDiferentes(cod, month);
    }

    public int getGFilClientesDiferentesTotal(String cod) {
        return gFil.clientesDiferentesTotal(cod);
    }

    public int getGFilProdutosDiferentesTotal(String cod) {
        return gFil.produtosDiferentesTotal(cod);
    }

    public List<ProdCliinfo> getGFilProdCliList(int branch, String cod) {
        return gFil.getFilialProdCliList(cod, branch);
    }

    public int[] getgFilCliCompradoresMes(int branch){
        return gFil.getFilCliCompradoresMes(branch);
    }

    public double getFactUniMes(String cod,int month){
        return fact.getUniMes(cod,month);
    }

    public double getFactTotalMes(String cod,int month){
        return fact.getFatTotalMes(cod,month);
    }

    public Set<String> getFactKeys(){
        return fact.getKeys();
    }

    public int getFactUni(String cod){
        return fact.getUni(cod);
    }

    public boolean getFactContainsProd(String cod){
        return fact.containsProd(cod);
    }

    public double[][] getFactMesFilProd(String cod){
        return fact.getFatMesFilProd(cod);
    }

    public int getFactComprados(){
        return fact.getComprados();
    }

    public int getFactCompras0(){
        return fact.getCompras0();
    }

    public double getFactFaturacaoTotal(){
        return fact.getFaturacaoTotal();
    }

    public int[] getFactComprasMes(){
        return fact.getComprasMes();
    }

    public double[][] getFactFaturacaoMesFil(){
        return fact.getFaturacaoMesFil();
    }

    public String getLoadInfoSalesPath(){
        return loadInfo.getSalesPath();
    }

    public int getLoadInfoVendasInvalidas(){
        return loadInfo.getVendasInvalidas();
    }

    public int getLoadInfoProdValidos(){
        return loadInfo.getProdValidos();
    }

    public int getLoadInfoCliValidos(){
        return loadInfo.getCliValidos();
    }

    public int getLoadInfoCliComprador(){
        return loadInfo.getCliComprador();
    }

    //--------------------------------------------------------------toString--------------------------------------------------------------------------\\

    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder("Load{");
        sb.append("catClientes=").append(catClientes);
        sb.append(", catProdutos=").append(catProdutos);
        sb.append(", fact=").append(fact);
        sb.append(", gFil=").append(gFil);
        sb.append(", loadInfo=").append(loadInfo);
        sb.append('}');
        return sb.toString();
    }

    //--------------------------------------------------------------Outros métodos--------------------------------------------------------------------------\\

    public List<String> lerFicheiro(String filename){
        Crono crono = new Crono();
        crono.start();
        List<String> lines = new ArrayList<>();
        try {
            lines = Files.readAllLines(Paths.get(filename));
        } catch (IOException ioex) {
            System.out.println(ioex.getMessage() + "Erro a ler ficheiro");
        }
        System.out.println(crono.getTImeString());
        return lines;
    }

    public void load(){
        Crono.start();
        loadCat(loadInfo.getCliPath(),0);
        loadCat(loadInfo.getProdPath(),1);
        System.out.println("Tempo carregamento catalogos " + Crono.getTime() + "\n");

        Crono.start();
        loadSales(loadInfo.getSalesPath());
        System.out.println("Tempo carregamento vendas " + Crono.getTime() + "\n");

    }

    public void loadCat(String filename, int type){
        /*String line;
        BufferedReader br = null;
        try {
            br = new BufferedReader(new FileReader(filename));
        } catch (FileNotFoundException fnfex) {
            System.out.println(fnfex.getMessage() + "Ficheiro não encontrado");
            System.exit(0);
        }
        try {
            while ((line = br.readLine()) != null) {*/
        List<String> linhas = lerFicheiro(filename);
        for(String line: linhas) {
            if(type == 0) {
                loadInfo.incCliLidos();
                catClientes.addCod(line);
            }
            else {
                loadInfo.incProdLidos();
                catProdutos.addCod(line);
            }
        }/*
        } catch (IOException ioex) {
            System.out.println(ioex.getMessage() + "Erro a ler ficheiro");
        }*/
        if(type == 0)
            loadInfo.setCliValidos(catClientes.getTotal());
        else
            loadInfo.setProdValidos(catProdutos.getTotal());
    }

    public boolean valSale(int branch,int month,float price,int uni,char type){
        return (branch >= 1 && branch <= 3 && month >= 1 && month <= 12 &&
                price >= 0 && uni >= 0 && (type == 'N' || type == 'P'));
    }

    public void loadSales(String filename){
        String[] venda;
        int branch,month,uni,cliIndex,res;
        float price;
        char type;
        /*BufferedReader br = null;
        String line;

        try {
            br = new BufferedReader(new FileReader(filename));
        } catch (FileNotFoundException fnfex) {
            System.out.println(fnfex.getMessage() + "Ficheiro não encontrado");
            System.exit(0);
        }
        try {
            while ((line = br.readLine()) != null) {*/
        List<String> linhas = lerFicheiro(filename);
        for(String line: linhas) {
            venda = line.split(" ");
            branch = Integer.parseInt(venda[6]);
            month = Integer.parseInt(venda[5]);
            price = Float.parseFloat(venda[1]);
            uni = Integer.parseInt(venda[2]);
            type = venda[3].charAt(0);
            if(valSale(branch,month,price,uni,type) &&
                    catClientes.contem(venda[4]) && catProdutos.contem(venda[0])) {
                loadInfo.incValidas();
                fact.addSale(branch - 1, month - 1, price, uni, venda[0]);
                if (gFil.addSaleInfo(month - 1, price, uni, venda[0], venda[4], branch - 1))
                    loadInfo.incCliComprador();
            }
            else
                loadInfo.incInvalidas();
        }/*
        } catch (IOException ioex) {
            System.out.println(ioex.getMessage() + "Erro a ler ficheiro");
        }*/
    }
}
