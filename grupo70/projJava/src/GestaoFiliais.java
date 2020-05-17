import java.io.Serializable;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class GestaoFiliais implements Serializable {
    private Map<Integer, Filial> gFil;

    public GestaoFiliais(){
        gFil = new HashMap<>();
        for(int i=0; i<3; i++)
            gFil.put(i, new Filial());
    }

    public Filial getFil(int fil) {
        return gFil.get(fil);
    }

    public boolean isComprador(int cliIndex,String cod,int branch){
        boolean res=false;
        if(cliIndex != -1) {
            res = true;
            for(int i=1; i<4 && res; i++)
                if(i!=branch + 1)
                    res = gFil.get(i-1).conteinsCliCode(cod);
        }
        return res;
    }

    public boolean addSaleInfo(int month,double price,int uni,String prodCod,String cliCod,int branch){
        int cliIndex = gFil.get(branch).addSale(month, price, uni, prodCod, cliCod);
        return isComprador(cliIndex,cliCod,branch);
    }

    public double clientesDiferentes(String prodCod,int month){
        Set<String> cli =gFil.get(0).getClientesDiferentes(month,prodCod);
        cli.addAll(gFil.get(1).getClientesDiferentes(month,prodCod));
        cli.addAll(gFil.get(2).getClientesDiferentes(month,prodCod));
        return cli.size();
    }

    public double produtosDiferentes(String cliCod,int month){
        Set<String> prod =gFil.get(0).getProdutosDiferentes(month,cliCod);
        prod.addAll(gFil.get(1).getProdutosDiferentes(month,cliCod));
        prod.addAll(gFil.get(2).getProdutosDiferentes(month,cliCod));
        return prod.size();
    }

    public int produtosDiferentesTotal(String cliCod){
        Set<String> prod = new HashSet<>();

        for(int i=0; i<12; i++) {
            prod.addAll(gFil.get(0).getProdutosDiferentes(i, cliCod));
            prod.addAll(gFil.get(1).getProdutosDiferentes(i, cliCod));
            prod.addAll(gFil.get(2).getProdutosDiferentes(i, cliCod));
        }

        return prod.size();
    }

    public int clientesDiferentesTotal(String prodCod){
        Set<String> cli = new HashSet<>();

        for(int i=0; i<12; i++) {
            cli.addAll(gFil.get(0).getClientesDiferentes(i, prodCod));
            cli.addAll(gFil.get(1).getClientesDiferentes(i, prodCod));
            cli.addAll(gFil.get(2).getClientesDiferentes(i, prodCod));
        }

        return cli.size();
    }

    public double gastoTotalMes(String code,int month){
        return gFil.get(0).getGastoTotal(code,month) + gFil.get(1).getGastoTotal(code,month)
                + gFil.get(2).getGastoTotal(code,month);
    }

    public double numeroComprasMes(String code,int month){
        return gFil.get(0).getNumeroCompras(code,month) + gFil.get(1).getNumeroCompras(code,month)
               + gFil.get(2).getNumeroCompras(code,month);
    }

    public int clientesDiferentesMes(int month) {
        Set<String> cli =gFil.get(0).getClientesMes(month);
        cli.addAll(gFil.get(1).getClientesMes(month));
        cli.addAll(gFil.get(2).getClientesMes(month));
        return cli.size();
    }

    public int getVendasMes(int month){
        return gFil.get(0).getVendasMes(month)+gFil.get(1).getVendasMes(month)+gFil.get(2).getVendasMes(month);
    }
}
