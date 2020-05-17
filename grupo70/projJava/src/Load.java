import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Load implements Serializable {
    private Catalogo catClientes;
    private Catalogo catProdutos;
    private Facturacao fact;
    private GestaoFiliais gFil;
    private LoadInfo loadInfo;

    public Load(){
        catClientes = new Catalogo(0);
        catProdutos = new Catalogo(1);
        fact = new Facturacao();
        gFil = new GestaoFiliais();
        loadInfo = new LoadInfo();
    }

    public Catalogo getCatC(){
        return catClientes;
    }

    public Catalogo getCatP(){
        return catProdutos;
    }

    public LoadInfo getLoadInfo(){
        return loadInfo;
    }

    public Facturacao getFact(){
        return fact;
    }

    public Filial getFilial(int branch){
        return gFil.getFil(branch);
    }

    public GestaoFiliais getgFil() {
        return gFil;
    }

    public List<String> lerFicheiro(String filename){
        List<String> lines = new ArrayList<>();
        try {
            lines = Files.readAllLines(Paths.get(filename));
        } catch (IOException ioex) {
            System.out.println(ioex.getMessage() + "Erro a ler ficheiro");
        }
        return lines;
    }

    public void load(){
        Crono.start();
        loadCat(getLoadInfo().getCliPath(),0);
        loadCat(getLoadInfo().getProdPath(),1);
        System.out.println("Tempo carregamento catalogos " + Crono.getTime());
/*
        Crono.start();
        fact.loadFactfromCat(getCatP());
        for(int i=0; i<3; i++)
            getFilial(i).loadFilfromCat(getCatP(), getCatC());
        System.out.println("Tempo carregamento catalogos para structs " +Crono.getTime());*/

        Crono.start();
        loadSales(getLoadInfo().getSalesPath());
        System.out.println("Tempo carregamento vendas " + Crono.getTime());

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
                    //System.out.println(".");
                    fact.addSale(branch - 1, month - 1, price, uni, type, venda[0]);
                    //System.out.println(".");
                    if (gFil.addSaleInfo(month - 1, price, uni, venda[0], venda[4], branch - 1))
                        loadInfo.incCliComprador();
                    else
                        loadInfo.incInvalidas();
                }
            }/*
        } catch (IOException ioex) {
            System.out.println(ioex.getMessage() + "Erro a ler ficheiro");
        }*/
    }

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
}
