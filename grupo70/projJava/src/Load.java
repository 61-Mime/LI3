import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

public class Load {
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

    public void loadCat(String filename, int type){
        String line;
        BufferedReader br = null;

        try {
            br = new BufferedReader(new FileReader(filename));
        } catch (FileNotFoundException fnfex) {
            System.out.println(fnfex.getMessage() + "Ficheiro não encontrado");
            System.exit(0);
        }
        try {
            while ((line = br.readLine()) != null) {
                if(type == 0) {
                    loadInfo.incCliLidos();
                    catClientes.addCod(line);
                }
                else {
                    loadInfo.incProdLidos();
                    catProdutos.addCod(line);
                }
            }
        } catch (IOException ioex) {
            System.out.println(ioex.getMessage() + "Erro a ler ficheiro");
        }
        loadInfo.setCliValidos(catClientes.getTotal());
        loadInfo.setProdValidos(catProdutos.getTotal());
    }

    public boolean valSale(int branch,int month,float price,int uni,char type){
        return (branch >= 1 && branch <= 3 && month >= 1 && month <= 12 &&
                price >= 0 && uni >= 0 && (type == 'N' || type == 'P'));
    }

    public void loadSales(String filename){
        String line;
        String[] venda;
        BufferedReader br = null;
        int branch,month,uni,cliIndex,res;
        float price;
        char type;

        try {
            br = new BufferedReader(new FileReader(filename));
        } catch (FileNotFoundException fnfex) {
            System.out.println(fnfex.getMessage() + "Ficheiro não encontrado");
            System.exit(0);
        }
        try {
            while ((line = br.readLine()) != null) {
                venda = line.split(" ");
                branch = Integer.parseInt(venda[6]);
                month = Integer.parseInt(venda[5]);
                price = Float.parseFloat(venda[1]);
                uni = Integer.parseInt(venda[2]);
                type = venda[3].charAt(0);
                if(valSale(branch,month,price,uni,type) &&
                   catClientes.contem(venda[4]) && catProdutos.contem(venda[0])) {
                    loadInfo.incValidas();
                    fact.addSale(branch - 1, month-1, price, uni, type, venda[0]);

                    if (gFil.addSaleInfo(month-1, price, uni, venda[0], venda[4],branch - 1))
                        loadInfo.incCliComprador();
                }
                else
                    loadInfo.incInvalidas();
            }
        } catch (IOException ioex) {
            System.out.println(ioex.getMessage() + "Erro a ler ficheiro");
        }
    }
}
