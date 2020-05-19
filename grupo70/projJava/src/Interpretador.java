import java.io.IOException;
import java.util.Scanner;

public class Interpretador {
    Apresentacao a = new Apresentacao();

    public int lerInt(String message,int min,int max){
        Scanner s = new Scanner(System.in);
        int n = -1;

        do{
            a.printMessage(message);
            try {
                String line = s.nextLine();
                n = Integer.parseInt(line);
            } catch (NumberFormatException nfe) {
                a.printErroLerInt();
            }
        } while (n < min || n > max);

        return n;
    }

    public String lerString(String message, int type, GestVendas sgv){
        Scanner s = new Scanner(System.in);
        String line;

        do{
            a.printMessage(message);
            line = s.nextLine();
        } while ((type == 0 && (!sgv.cliVal(line) || !sgv.getCatCcontains(line))) ||
                 (type == 1 && (!sgv.prodVal(line) || !sgv.getCatPcontains(line))));

        return line;
    }

    public void consultasIterativas(GestVendas sgv){
        boolean val = true;
        String line,time;
        int comand,num;
        ConsultasInterativas ci = new ConsultasInterativas();

        while (val){
            a.menuConsultasInterativas();
            comand = lerInt(a.pedirNumero(),0,10);
            switch (comand){
                case 0:
                    val = false;
                    break;
                case 1:
                    Crono.start();
                    ci.setQuerie1(sgv);
                    time = Crono.getTime();
                    a.printQ1(ci, time);
                    break;
                case 2:
                    num = lerInt(a.pedirMes(),1,12);
                    Crono.start();
                    ci.setQuerie2(sgv,num - 1);
                    time = Crono.getTime();
                    a.printQ2(ci, time, num);
                    break;
                case 3:
                    line = lerString(a.pedirCliente(),0,sgv);
                    Crono.start();
                    ci.setQuerie3(sgv, line);
                    time = Crono.getTime();
                    a.printQ3(ci, time);
                    break;
                case 4:
                    line = lerString(a.pedirProduto(),1,sgv);
                    Crono.start();
                    ci.setQuerie4(sgv, line);
                    time = Crono.getTime();
                    a.printQ4(ci, time);
                    break;
                case 5:
                    line = lerString(a.pedirCliente(),0,sgv);
                    Crono.start();
                    ci.setQuerie5(sgv, line);
                    time = Crono.getTime();
                    a.printQ5(ci, time);
                    break;
                case 6:
                    num = lerInt(a.pedirLimite(),0,1000000);
                    Crono.start();
                    ci.setQuerie6(sgv, num);
                    time = Crono.getTime();
                    a.printQ6(ci, time, num);
                    break;
                case 7:
                    Crono.start();
                    ci.setQuerie7(sgv);
                    time = Crono.getTime();
                    a.printQ7(ci, time);
                    break;
                case 8:
                    num = lerInt(a.pedirLimite(),0,1000000);
                    Crono.start();
                    ci.setQuerie8(sgv, num);
                    time = Crono.getTime();
                    a.printQ8(ci, time, num);
                    break;
                case 9:
                    num = lerInt(a.pedirLimite(),0,1000000);
                    line = lerString(a.pedirProduto(),1,sgv);
                    Crono.start();
                    ci.setQuerie9(sgv, line,num);
                    time = Crono.getTime();
                    a.printQ9(ci, time, num, line);
                    break;
                case 10:
                    Crono.start();
                    ci.setQuerie10(sgv);
                    time = Crono.getTime();
                    a.printQ10(ci, time);
                    break;
            }
        }
    }
//ver tempo
    public void consultasEstatisticas(GestVendas sgv){
        boolean val = true;
        int comand;
        ConsultasEstatisticas ce = new ConsultasEstatisticas(sgv);

        while (val){
            a.menuConsultasEstatisticas();
            comand = lerInt(a.pedirNumero(),0,4);
            switch (comand){
                case 0:
                    val = false;
                    break;
                case 1:
                    a.printConsultaEstatisticas(ce, 1);
                    break;
                case 2:
                    a.printConsultaEstatisticas(ce, 2);
                    break;
                case 3:
                    a.printConsultaEstatisticas(ce, 3);
                    break;
                case 4:
                    a.printConsultaEstatisticas(ce, 4);
                    break;
            }
        }
    }

    public void interpretador() throws IOException, ClassNotFoundException {
        boolean val = true,load = false;
        Scanner scanner = new Scanner(System.in);
        int comand, n;
        String time;
        GestVendas sgv = new GestVendas();
        DataFile data = new DataFile();

        a.welcome();
        scanner.nextLine();
        a.clearScreen();

        while (val){
            a.menu();
            comand = lerInt(a.pedirNumero(),0,5);
            switch (comand){
                case 0:
                    val = false;
                    break;
                case 1:
                    if(load)
                        consultasEstatisticas(sgv);
                    else
                        a.printErroCarregar();
                    break;
                case 2:
                    if(load)
                        consultasIterativas(sgv);
                    else
                        a.printErroCarregar();
                    break;
                case 3:
                    if(!load) {
                        a.printErroCarregar();
                        break;
                    }
                    a.printMessage("Pretende guardar no ficheiro default? (S/N)");
                    String str = scanner.nextLine();
                    if (str.equals("S"))
                        data.guardaDados("gestVendas.dat", sgv);
                    else {
                        a.printMessage("Introduza o nome do ficheiro para o qual pretende guardar os dados: ");
                        str = scanner.nextLine();
                        data.guardaDados(str, sgv);
                    }
                    break;
                case 4:
                    a.printMessage("Introduza o nome do ficheiro do qual os dados serão carregados: ");
                    String string = scanner.nextLine();
                    sgv = data.carregaDados(string);
                    load = true;
                    break;
                case 5:
                    if(load)
                        sgv = new GestVendas();
                    Crono.start();
                    if((n = sgv.loadCat("Files/Clientes.txt",0)) != 0)
                        a.printErroLerFicheiro(n);
                    if((n = sgv.loadCat("Files/Produtos.txt",1)) != 0)
                        a.printErroLerFicheiro(n);
                    a.printTime(Crono.getTime(),"Catalogos");

                    Crono.start();
                    if((n = sgv.loadSales(sgv.getLoadInfoSalesPath())) != 0)
                        a.printErroLerFicheiro(n);
                    a.printTime(Crono.getTime(),"Vendas");
                    load = true;
                    break;
            }
        }
    }
}
