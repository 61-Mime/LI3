/**
 * Classe com a informação das três Filiais
 */

package Model;

import java.io.Serializable;
import java.util.*;

public class GestaoFiliais implements Serializable, IGestaoFiliais {
    private Map<Integer, Filial> gFil;

    /**
     * Construtor da Classe GestaoFiliais
     */
    public GestaoFiliais(){
        gFil = new HashMap<>();
        for(int i=0; i<3; i++)
            gFil.put(i, new Filial());
    }

    /**
     * Método que devolve uma Filial
     *
     * @param fil Interiro com o número da Filial que se pretende obter
     * @return Filial que obtida
     */
    private Filial getFil(int fil) {
        return gFil.get(fil);
    }

    /**
     * Método que devolve as Vendas de uma Filial
     *
     * @param branch Interiro com o número da Filial
     * @return  Inteiro que representa o número de Vendas da Filial
     */
    public int getVendasFilial(int branch) {
        return getFil(branch).getVendasFil();
    }

    /**
     * Método que devolve os Clientes compradores de uma Filial
     *
     * @param branch Interiro com o número da Filial
     * @return  Inteiro que representa o número de Clientes compradores  da Filial
     */
    public int getClientesCompradoresFilial(int branch){
        return getFil(branch).getClientesCompradores();
    }

    /**
     * -----------------------------------------------------------------------------------------------------
     *
     * @param branch
     * @param code
     * @return
     */
    public Set<ParStringFloat> getCliSetCodUni(int branch,String code){
        return gFil.get(branch).getCliSetCodUni(code);
    }

    /**
     * -----------------------------------------------------------------------------------------------------
     *
     * @param branch
     * @param code
     * @return
     */
    public Set<ParStringFloat> getProdSetCodUni(int branch,String code){
        return gFil.get(branch).getProdSetCodUni(code);
    }

    /**
     * Método que devolve os Clientes que mais compraram numa Filial
     *
     * @param branch  Interiro com o número da Filial
     * @return        Lista com os Clientes mais compradores de uma Filial
     */
    public List<String> getClientesMaisCompradoresFilial(int branch){
        return getFil(branch).getClientesMaisCompradores();
    }

    /**
     * Método que devolve o número de clientes que fizeram compras por mês numa Filial
     *
     * @param branch    Inteiro com o número da Filial
     * @return          Array de float(de tamanho 12) cujos valores representam o número de clientes compradores da Filial nos respetivos meses
     */
    public float[] getFilCliCompradoresMes(int branch){
        return getFil(branch).getCliCompradoresMes();
    }

    /**
     * Método que verifica se um Cliente é comprador em todas as Filiais
     *
     * @param cliIndex  Inteiro que representa o Cliente
     * @param cod       String que representa o código de Cliente
     * @param branch    Inteiro com o número da Filial
     * @return          Resultado Booleano
     */
    private boolean isComprador(int cliIndex,String cod,int branch){
        boolean res=false;
        if(cliIndex != -1) {
            res = true;
            for(int i=1; i<4 && res; i++)
                if(i!=branch + 1)
                    res = gFil.get(i-1).containsCliCode(cod);
        }
        return res;
    }

    /**
     * Método que adiciona os dados de uma Venda a uma  --------------------------------------------------------------
     *
     * @param month
     * @param price
     * @param uni
     * @param prodCod
     * @param cliCod
     * @param branch
     * @return
     */
    public boolean addSaleInfo(int month,float price,int uni,String prodCod,String cliCod,int branch){
        int cliIndex = gFil.get(branch).addSale(month, price, uni, prodCod, cliCod);
        return isComprador(cliIndex,cliCod,branch);
    }

    /**
     * Método que devolve o número de Clientes diferentes que efetuaram compra de um produto num determinado mês
     *
     * @param prodCod   String que representa o código do produto
     * @param month     Inteiro que respresenta o mês
     * @return          Inteiro com o número de Clientes diferentes
     */
    public int clientesDiferentes(String prodCod,int month){
        Set<String> cli =gFil.get(0).getClientesDiferentes(month,prodCod);
        cli.addAll(gFil.get(1).getClientesDiferentes(month,prodCod));
        cli.addAll(gFil.get(2).getClientesDiferentes(month,prodCod));
        return cli.size();
    }

    /**
     * Método que devolve o número de Produtos diferentes que foram comprados por um Cliente num determinado mês
     *
     * @param cliCod    String que representa o código do cliente
     * @param month     Inteiro que representa o mês
     * @return          Inteiro com o número de Produtos diferentes
     */
    public int produtosDiferentes(String cliCod,int month){
        Set<String> prod =gFil.get(0).getProdutosDiferentes(month,cliCod);
        prod.addAll(gFil.get(1).getProdutosDiferentes(month,cliCod));
        prod.addAll(gFil.get(2).getProdutosDiferentes(month,cliCod));
        return prod.size();
    }

    /**
     * Método que devolve o número de Produtos diferentes que foram comprados por um Cliente
     *
     * @param cliCod    String que representa o código do Cliente
     * @return          Inteiro com o número de Produtos diferentes
     */
    public int produtosDiferentesTotal(String cliCod){
        Set<String> prod = new HashSet<>();

        for(int i=0; i<12; i++) {
            prod.addAll(gFil.get(0).getProdutosDiferentes(i, cliCod));
            prod.addAll(gFil.get(1).getProdutosDiferentes(i, cliCod));
            prod.addAll(gFil.get(2).getProdutosDiferentes(i, cliCod));
        }

        return prod.size();
    }

    /**
     * Método que devolve o número de Clientes diferentes que compraram um Produto
     *
     * @param prodCod   String que representa o código do Produto
     * @return          Inteiro com o número de Clientes diferentes
     */
    public int clientesDiferentesTotal(String prodCod){
        Set<String> cli = new HashSet<>();

        for(int i=0; i<12; i++) {
            cli.addAll(gFil.get(0).getClientesDiferentes(i, prodCod));
            cli.addAll(gFil.get(1).getClientesDiferentes(i, prodCod));
            cli.addAll(gFil.get(2).getClientesDiferentes(i, prodCod));
        }

        return cli.size();
    }

    /**
     * Método que devolve o gasto de um Cliente num determinado mês
     *
     * @param code      String que representa o código do Cliente
     * @param month     Inteiro que representa o mês pretendido
     * @return          Float com o gsto total do Cliente
     */
    public float gastoTotalMes(String code,int month){
        return gFil.get(0).getGastoTotal(code,month) + gFil.get(1).getGastoTotal(code,month)
                + gFil.get(2).getGastoTotal(code,month);
    }

    /**
     * Método que devolve o número de compras que um Cliente fez num determinado mês
     *
     * @param code      String que representa o código do Cliente
     * @param month     Inteiro que representa o mês pretendido
     * @return          Float com o número de compras do Cliente
     */
    public float numeroComprasMes(String code,int month){
        return gFil.get(0).getNumeroCompras(code,month) + gFil.get(1).getNumeroCompras(code,month)
               + gFil.get(2).getNumeroCompras(code,month);
    }

    /**
     * Método que devolve o número de Clientes diferentes que fizeram compras num determinadp mês
     *
     * @param month     Inteiro que representa o mês pretendido
     * @return          Inteiro que representa o número de Clientes diferentes
     */
    public int clientesDiferentesMes(int month) {
        Set<String> cli =gFil.get(0).getClientesMes(month);
        cli.addAll(gFil.get(1).getClientesMes(month));
        cli.addAll(gFil.get(2).getClientesMes(month));
        return cli.size();
    }

    /**
     * Método que devolve o número de Vendas efetuadas num determinado mês
     *
     * @param month     Inteiro que representa o mês pretendido
     * @return          Inteiro que representa o número de Vendas
     */
    public int getVendasMes(int month){
        return gFil.get(0).getVendasMes(month)+gFil.get(1).getVendasMes(month)+gFil.get(2).getVendasMes(month);
    }

    /*public List<Model.ProdCliinfo> getFilialProdCliList(String cod, int branch) {
        return getFil(branch).getProdCliList(cod);
    }*/
}
