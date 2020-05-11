import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class GestaoFiliais {
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
        if(cliIndex != -1) {
            int res=0;
            for(int i=1; i<4 && res==0; i++)
                if(i!=branch)
                    res += gFil.get(i-1).getSizeCli(cod, cliIndex);

            if(res == 0)
                return true;
        }
        return false;
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

    public double gastoTotalMes(int pos,int index,int month){
        return gFil.get(0).getGastoTotal(index,pos,month) + gFil.get(1).getGastoTotal(index,pos,month)
                + gFil.get(2).getGastoTotal(index,pos,month);
    }

    public double numeroComprasMes(int pos,int index,int month){
        return gFil.get(0).getNumeroCompras(index,pos,month) + gFil.get(1).getNumeroCompras(index,pos,month)
               + gFil.get(2).getNumeroCompras(index,pos,month);
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
