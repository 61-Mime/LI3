package Model;

import Controller.Crono;

import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;
import java.util.stream.Collectors;

public class GestVendas implements Serializable, IGestVendas {
    private Catalogo catClientes;
    private Catalogo catProdutos;
    private Faturacao fact;
    private GestaoFiliais gFil;
    private LoadInfo loadInfo;

    //--------------------------------------------------------------Construtores--------------------------------------------------------------------------\\

    public GestVendas(){
        catClientes = new Catalogo(0);
        catProdutos = new Catalogo(1);
        fact = new Faturacao();
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

    public Set<ParStringFloat> getGFilCliSet(int branch, String cod){
        return gFil.getCliSetCodUni(branch, cod);
    }

    public Set<ParStringFloat> getGFilProdSet(int branch, String cod){
        return gFil.getProdSetCodUni(branch, cod);
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

    public float getGFilNumeroComprasMes(String cod, int month) {
        return gFil.numeroComprasMes(cod, month);
    }

    public float getGFilProdutosDiferentes(String cod, int month) {
        return gFil.produtosDiferentes(cod, month);
    }

    public float getGFilGastoTotalMes(String cod, int month) {
        return gFil.gastoTotalMes(cod, month);
    }

    public float getGFilClientesDiferentes(String cod, int month) {
        return gFil.clientesDiferentes(cod, month);
    }

    public int getGFilClientesDiferentesTotal(String cod) {
        return gFil.clientesDiferentesTotal(cod);
    }

    public int getGFilProdutosDiferentesTotal(String cod) {
        return gFil.produtosDiferentesTotal(cod);
    }

    public float[] getgFilCliCompradoresMes(int branch){
        return gFil.getFilCliCompradoresMes(branch);
    }

    public float getFactUniMes(String cod,int month){
        return fact.getUniMes(cod,month);
    }

    public float getFactTotalMes(String cod,int month){
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

    public float[][] getFactMesFilProd(String cod){
        return fact.getFatMesFilProd(cod);
    }

    public int getFactComprados(){
        return fact.getComprados();
    }

    public int getFactCompras0(){
        return fact.getCompras0();
    }

    public float getFactFaturacaoTotal(){
        return fact.getFaturacaoTotal();
    }

    public int[] getFactComprasMes(){
        return fact.getComprasMes();
    }

    public float[][] getFactFaturacaoMesFil(){
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


    //--------------------------------------------------------------Outros métodos--------------------------------------------------------------------------\\
//    public List<String> lerFicheiro(String filename){
//        Crono crono = new Crono();
//        crono.start();
//        List<String> lines = new ArrayList<>();
//        try {
//            lines = Files.readAllLines(Paths.get(filename));
//        } catch (IOException ioex) {
//            System.out.println(ioex.getMessage() + "Erro a ler ficheiro");
//        }
//        crono.getTImeString();
//        return lines;
//    }

    private boolean valSale(int branch,int month,float price,int uni,char type){
        return (branch >= 1 && branch <= 3 && month >= 1 && month <= 12 &&
                price >= 0 && uni >= 0 && (type == 'N' || type == 'P'));
    }

    public int loadCat(String filename, int type){
        String line;
        BufferedReader br = null;
        try {
            br = new BufferedReader(new FileReader(filename));
        } catch (FileNotFoundException fnfex) {
            System.exit(1);
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
            System.exit(1);
        }
        if(type == 0)
            loadInfo.setCliValidos(catClientes.getTotal());
        else
            loadInfo.setProdValidos(catProdutos.getTotal());

        return 0;
    }

    public int loadSales(String filename){
        String[] venda;
        int branch,month;
        int uni;
        float price;
        char type;
        BufferedReader br = null;
        String line;

        try {
            br = new BufferedReader(new FileReader(filename));
        } catch (FileNotFoundException fnfex) {
            System.exit(1);
        }
        try {
            while ((line = br.readLine()) != null) {
//            List<String> linhas = lerFicheiro(filename);
//            for(String line: linhas) {
            venda = line.split(" ");
            branch = Integer.parseInt(venda[6]);
            month = Integer.parseInt(venda[5]);
            price = Float.parseFloat(venda[1]);
            uni = Integer.parseInt(venda[2]);
            type = venda[3].charAt(0);
            if(valSale(branch,month,price,uni,type) &&
                    catClientes.contem(venda[4]) && catProdutos.contem(venda[0])) {
                loadInfo.incValidas();
                fact.addSale((branch - 1), (month - 1), price, uni, venda[0]);
                if (gFil.addSaleInfo((month - 1), price, uni, venda[0], venda[4], (branch - 1)))
                    loadInfo.incCliComprador();
            }
            else
                loadInfo.incInvalidas();
            }
        } catch (IOException ioex) {
            System.exit(2);
        }
        return 0;
    }

    public float[][] getCompradoresMesFil() {
        float[][] compradoresMesFil = new float[12][3];
        float [] array = getgFilCliCompradoresMes(0);
        float [] array2 = getgFilCliCompradoresMes(1);
        float [] array3 = getgFilCliCompradoresMes(2);
        for(int i = 0;i < 12; i++) {
            compradoresMesFil[i][0] = array[i];
            compradoresMesFil[i][1] = array2[i];
            compradoresMesFil[i][2] = array3[i];
        }

        return compradoresMesFil;
    }

    //--------------------------------------------------------------Consultas Interativas-------------------------------------------------------------\\

    public List<String> listParStringFloatToListString(List<ParStringFloat> list){
        List<String> stringList = new ArrayList<>();
        list.forEach(p -> stringList.add(p.toString()));

        return stringList;
    }

    public List<String> getQ1(){
        List<String> querie1 = new ArrayList<>();

        getCatPtree().stream().filter(cod -> !(getFactContainsProd(cod))).forEach(querie1::add);
        return querie1;
    }

    public int[] getQ2(int month){

         int[] querie2 = new int[8];
        int i = 0;
        querie2[i++] = getGFilVendasMes(month);
        querie2[i++] = getGFilClientesDiferentesMes(month);
        for(int f = 0;f < 3;f++) {
            querie2[i++] = getFilialVendas(f);
            querie2[i++] = getFilialClientesCompradores(f);
        }

        return querie2;
    }

    public Map<Integer, float[]> getQ3(String cod){
        Map<Integer, float[]> querie3 = new HashMap<>();
        float[] res;
        for(int month = 0;month < 12;month++){
            res = new float[3];
            res[0] = getGFilNumeroComprasMes(cod, month);
            res[1] = getGFilProdutosDiferentes(cod, month);
            res[2] = getGFilGastoTotalMes(cod, month);
            querie3.put(month,res);
        }
        return querie3;
    }

    public Map<Integer, float[]> getQ4(String cod){
        Map<Integer, float[]> querie4 = new HashMap<>();
        float[] res;
        for(int month = 0;month < 12;month++){
            res = new float[3];
            res[0] = getFactUniMes(cod,month);
            res[1] = getGFilClientesDiferentes(cod, month);
            res[2] = getFactTotalMes(cod,month);
            querie4.put(month,res);
        }
        return querie4;
    }

    public List<ParStringFloat> getQ5(String cod) {
        List<ParStringFloat> querie5 = new ArrayList<>();
        int i;

        for(i=0; i<3; i++)
            querie5.addAll(getGFilCliSet(i, cod));

        querie5 = querie5.stream().sorted(new sortParbyValue()).collect(Collectors.toList());
        return querie5;
    }

    public List<ParStringFloat> getQ6(int limit) {
        List<ParStringFloat> querie6 = new ArrayList<>();

        for(String cod: getFactKeys())
            querie6.add(new ParStringFloat(cod, getFactUni(cod),0));

        querie6 = querie6.stream().sorted(new sortParbyValue()).limit(limit).collect(Collectors.toList());

        querie6.forEach(q -> q.setValue2(getGFilClientesDiferentesTotal(q.getCode())));
        return querie6;
    }

    public Map<Integer, List<String>> getQ7() {
        Map<Integer, List<String>> querie7 = new HashMap<>();

        for(int i = 0; i<3; i++)
            querie7.put(i, getFilialClientesMaisCompradores(i));
        return querie7;
    }

    public List<ParStringFloat> getQ8(int limit) {
        List<ParStringFloat> querie8 = new ArrayList<>();

        for (String s: getCatCtree())
            querie8.add(new ParStringFloat(s, getGFilProdutosDiferentesTotal(s)));

        querie8 = querie8.stream().sorted(new sortParbyValue()).limit(limit).collect(Collectors.toList());
        return querie8;
    }

    public List<ParStringFloat> getQ9(String codProd,int limit) {
        List<ParStringFloat> querie9 = new ArrayList<>();

        for(int i=0; i<3; i++)
            querie9.addAll(getGFilProdSet(i, codProd));

        querie9 = querie9.stream().sorted(new sortParbyValue()).limit(limit).collect(Collectors.toList());
        return querie9;
    }

    public Map<String, float[][]> getQ10() {
        Map<String, float[][]> querie10 = new HashMap<>();

        for(String cod: getCatPtree()){
            if(getFactContainsProd(cod))
                querie10.put(cod, getFactMesFilProd(cod));

            else
                querie10.put(cod, null);
        }
        return querie10;
    }
}
