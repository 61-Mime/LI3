import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;

public class Interpretador {
    public void menu(){
        System.out.print("INÍCIO\n" +
                "1 | Consultas estatisticas\n" +
                "2 | Consultas iterativas\n" +
                "3 | Gravar estado\n" +
                "4 | Carregar estado a partir de um ficheiro\n" +
                "5 | Carregar dados a partir do ficheiro vendas_1M.txt\n" +
                "0 | Sair\n");
    }

    public void menuConsultasInterativas(){
        System.out.print("CONSULTAS INTERATIVAS\n" +
                "1 | Códigos Produtos nunca comprados e total\n" +
                "2 | Total vendas e clientes distintos para cada filial e para um dado mês\n" +
                "3 | Número compras, produtos distintos e gasto total de um dado cliente para cada mês\n" +
                "4 | Número compras, clientes distintos e faturação total de um dado produto para cada mês\n"+
                "5 | Lista produtos que um cliente mais comprou(quantidade)\n"+
                "6 | X produtos mais vendidos em todo o ano(unidades) e clientes distintos que os compraram\n" +
                "7 | 3 maiores compradores em termos de faturação por filial\n" +
                "8 | X clientes que compraram mais produtos diferentes\n" +
                "9 | X clientes que mais compraram um produto e valor gasto para cada um\n" +
                "10| Faturação total de cada produto mês a mês e filial a filial\n" +
                "0 | Sair\n");
    }

    public void menuConsultasEstatisticas(){
        System.out.print("CONSULTAS ESTATÍSTICAS\n" +
                "1 | Dados relativos ao último ficheiro de vendas lido\n" +
                "2 | Total compras por mês\n" +
                "3 | Facturação total e por (Filial/Mês)\n" +
                "4 | Clientes compradores distintos por (Filial/Mês)\n" +
                "0 | Sair\n");
    }

    public int lerInt(String message,int min,int max){
        Scanner s = new Scanner(System.in);
        int n = 0;

        do{
            System.out.println(message);
            try {
                String line = s.nextLine();
                n = Integer.parseInt(line);
            } catch (NumberFormatException nfe) {
                System.out.println(nfe.getMessage()+"erro a ler int");
                n = -1;
            }
        } while (n < min);

        return n;
    }

    public String lerString(String message,int type,Load sgv){
        Scanner s = new Scanner(System.in);
        String line;

        do{
            System.out.println(message);
            line = s.nextLine();
        } while ((type == 0 && !sgv.getCatCcontains(line)) || (type == 1 && !sgv.getCatPcontains(line)));

        return line;
    }

    public void consultasIterativas(Load sgv){
        boolean val = true;
        Scanner scanner = new Scanner(System.in);
        String line,time;
        int comand,num;
        ConsultasInterativas ci = new ConsultasInterativas();

        while (val){
            menuConsultasInterativas();
            comand = (int)lerInt("Introduza um número:",0,10);
            switch (comand){
                case 0:
                    val = false;
                    break;
                case 1:
                    Crono.start();
                    ci.setQuerie1(sgv);
                    time = Crono.getTime();
                    System.out.println(ci.toStringQ1()+"\nTempo querie 1:" + time);
                    break;
                case 2:
                    System.out.println("Introduza um mês");
                    num = (int)lerInt("Introduza um mês",1,12);
                    Crono.start();
                    ci.setQuerie2(sgv,num - 1);
                    time = Crono.getTime();
                    System.out.println(ci.toStringQ2(num)+"\nTempo querie 2:" + time);
                    break;
                case 3:
                    line = lerString("Introduza um cliente",0,sgv);
                    Crono.start();
                    ci.setQuerie3(sgv, line);
                    time = Crono.getTime();
                    System.out.println(ci.toStringQ3() + "\nTempo querie 3:" + time);
                    break;
                case 4:
                    line = lerString("Introduza um produto",1,sgv);
                    Crono.start();
                    ci.setQuerie4(sgv, line);
                    time = Crono.getTime();
                    System.out.println(ci.toStringQ4() + "Tempo querie 4:" + time);
                    break;
                case 5:
                    line = lerString("Introduza um cliente",0,sgv);
                    Crono.start();
                    ci.setQuerie5(sgv, line);
                    time = Crono.getTime();
                    System.out.println(ci.toStringQ5() + "Tempo querie 5:" + time);
                    break;
                case 6:
                    num = lerInt("Introduza o limite",0,1000000);
                    Crono.start();
                    ci.setQuerie6(sgv, num);
                    time = Crono.getTime();
                    System.out.println(ci.toStringQ6(num) + "\nTempo querie 6:" + time);
                    break;
                case 7:
                    Crono.start();
                    ci.setQuerie7(sgv);
                    time = Crono.getTime();
                    System.out.println(ci.toStringQ7() + "Tempo querie 7:" + time);
                    break;
                case 8:
                    num = lerInt("Introduza o limite",0,1000000);
                    Crono.start();
                    ci.setQuerie8(sgv, num);
                    time = Crono.getTime();
                    System.out.println(ci.toStringQ8(num) + "\nTempo querie 8:" + time);
                    break;
                case 9:
                    num = lerInt("Introduza o limite",0,1000000);
                    line = lerString("Introduza um produto",1,sgv);
                    Crono.start();
                    ci.setQuerie9(sgv, line,num);
                    time = Crono.getTime();
                    System.out.println(ci.toStringQ9(num,line) + "\nTempo querie 9:" + time);
                    break;
                case 10:
                    Crono.start();
                    ci.setQuerie10(sgv);
                    time = Crono.getTime();
                    System.out.println(ci.toStringQ10() + "\nTempo querie 10:" + time);
                    break;
            }
        }
    }
//ver tempo
    public void consultasEstatisticas(Load sgv){
        boolean val = true;
        int comand;
        ConsultasEstatisticas ce = new ConsultasEstatisticas(sgv);

        while (val){
            menuConsultasEstatisticas();
            comand = lerInt("Introduza um número:",0,4);
            switch (comand){
                case 0:
                    val = false;
                    break;
                case 1:
                    System.out.println(ce.toString());
                    break;
                case 2:
                    System.out.println(ce.toString2());
                    break;
                case 3:
                    System.out.println(ce.toString3());
                    break;
                case 4:
                    System.out.println(ce.toString4());
                    break;
            }
        }
    }

    public void interpretador() throws IOException, ClassNotFoundException {
        boolean val = true,load = false;
        Scanner scanner = new Scanner(System.in);
        int comand;
        Load sgv = new Load();
        DataFile data = new DataFile();

        while (val){
            menu();
            comand = lerInt("Introduza um número:",0,5);
            switch (comand){
                case 0:
                    val = false;
                    break;
                case 1:
                    if(load)
                        consultasEstatisticas(sgv);
                    else
                        System.out.println("Carregue as estruturas primeiro");
                    break;
                case 2:
                    if(load)
                        consultasIterativas(sgv);
                    else
                        System.out.println("Carregue as estruturas primeiro");
                    break;
                case 3:
                    if(!load) {
                        System.out.println("Carregue as estruturas primeiro");
                        break;
                    }
                    System.out.println("Pretende guardar no ficheiro default? (S/N)");
                    String str = scanner.nextLine();
                    if (str.equals("S"))
                        data.guardaDados("gestVendas.dat", sgv);
                    else {
                        System.out.println("Introduza o nome do ficheiro para o qual pretende guardar os dados: ");
                        str = scanner.nextLine();
                        data.guardaDados(str, sgv);
                    }
                    break;
                case 4:
                    System.out.println("Introduza o nome do ficheiro do qual os dados serão carregados: ");
                    String string = scanner.nextLine();
                    sgv = data.carregaDados(string);
                    load = true;
                    break;
                case 5:
                    sgv.load();
                    load = true;
                    break;
            }
        }
    }
}
