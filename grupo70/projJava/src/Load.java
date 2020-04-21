import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Load {
    private Catalogo CatClientes;
    private Catalogo CatProdutos;
    private Facturacao Fact;
    private Map<Integer, Filial> GFil;

    public Load(){
        CatClientes = new Catalogo(0);
        CatProdutos = new Catalogo(1);
        Fact = new Facturacao();
        GFil = new HashMap<>();

        for(int i=0; i<3; i++)
            GFil.put(i, new Filial());
    }

    public Catalogo getCatC(){
        return CatClientes;
    }

    public Catalogo getCatP(){
        return CatProdutos;
    }

    public Facturacao getFact(){
        return Fact;
    }

    public Filial getFilial(int fil){
        return GFil.get(fil);
    }

    public void loadCat(String filename,int type){
        String line = "11111";
        BufferedReader br = null;

        try {
            br = new BufferedReader(new FileReader(filename));
        } catch (FileNotFoundException fnfex) {
            System.out.println(fnfex.getMessage() + "Ficheiro não encontrado");
            System.exit(0);
        }
        try {
            while ((line = br.readLine()) != null) {
                if(type == 0)
                    CatClientes.addCod(line);
                else
                    CatProdutos.addCod(line);
            }
        } catch (IOException ioex) {
            System.out.println(ioex.getMessage() + "Erro a ler ficheiro");
        }
    }

    public boolean valSale(int branch,int month,float price,int uni,char type){
        return (branch >= 1 && branch <= 3 && month >= 1 && month <= 12 &&
                price >= 0 && uni >= 0 && (type == 'N' || type == 'P'));
    }

    public void loadSales(String filename){
        String line = "11111";
        String[] venda;
        BufferedReader br = null;
        int branch,month,uni;
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
                   CatClientes.contem(venda[4]) && CatProdutos.contem(venda[0])) {
                    Fact.addSale(branch - 1, month, price, uni, type, venda[0]);
                    //GFil.get(branch - 1).addSale(month, price, uni, type, venda[0], venda[4]);
                }
            }
        } catch (IOException ioex) {
            System.out.println(ioex.getMessage() + "Erro a ler ficheiro");
        }
    }
}
