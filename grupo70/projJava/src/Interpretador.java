import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;

public class Interpretador {
    Apresentacao a = new Apresentacao();

    public int lerInt(String message,int min,int max){
        Scanner s = new Scanner(System.in);
        int n = 0;

        do{
            a.printMessage(message);
            try {
                String line = s.nextLine();
                n = Integer.parseInt(line);
            } catch (NumberFormatException nfe) {
                a.printMessage(nfe.getMessage()+"erro a ler int");
                n = -1;
            }
        } while (n < min);

        return n;
    }

    public String lerString(String message,int type,Load sgv){
        Scanner s = new Scanner(System.in);
        String line;

        do{
            a.printMessage(message);
            line = s.nextLine();
        } while ((type == 0 && (!sgv.cliVal(line) || !sgv.getCatCcontains(line))) || (type == 1 && (!sgv.prodVal(line) || !sgv.getCatPcontains(line))));

        return line;
    }

    public void consultasIterativas(Load sgv){
        boolean val = true;
        Scanner scanner = new Scanner(System.in);
        String line,time;
        int comand,num;
        ConsultasInterativas ci = new ConsultasInterativas();

        while (val){
            a.menuConsultasInterativas();
            comand = (int)lerInt("Introduza um número:",0,10);
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
                    num = (int)lerInt("Introduza um mês",1,12);
                    Crono.start();
                    ci.setQuerie2(sgv,num - 1);
                    time = Crono.getTime();
                    a.printQ2(ci, time, num);
                    break;
                case 3:
                    line = lerString("Introduza um cliente",0,sgv);
                    Crono.start();
                    ci.setQuerie3(sgv, line);
                    time = Crono.getTime();
                    a.printQ3(ci, time);
                    break;
                case 4:
                    line = lerString("Introduza um produto",1,sgv);
                    Crono.start();
                    ci.setQuerie4(sgv, line);
                    time = Crono.getTime();
                    a.printQ4(ci, time);
                    break;
                case 5:
                    line = lerString("Introduza um cliente",0,sgv);
                    Crono.start();
                    ci.setQuerie5(sgv, line);
                    time = Crono.getTime();
                    a.printQ5(ci, time);
                    break;
                case 6:
                    num = lerInt("Introduza o limite",0,1000000);
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
                    num = lerInt("Introduza o limite",0,1000000);
                    Crono.start();
                    ci.setQuerie8(sgv, num);
                    time = Crono.getTime();
                    a.printQ8(ci, time, num);
                    break;
                case 9:
                    num = lerInt("Introduza o limite",0,1000000);
                    line = lerString("Introduza um produto",1,sgv);
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
    public void consultasEstatisticas(Load sgv){
        boolean val = true;
        int comand;
        ConsultasEstatisticas ce = new ConsultasEstatisticas(sgv);

        while (val){
            a.menuConsultasEstatisticas();
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

        a.welcome();
        scanner.nextLine();
        a.clearScreen();

        while (val){
            a.menu();
            comand = lerInt("Introduza um número: ",0,5);
            switch (comand){
                case 0:
                    val = false;
                    break;
                case 1:
                    if(load)
                        consultasEstatisticas(sgv);
                    else
                        a.printMessage("Carregue as estruturas primeiro");
                    break;
                case 2:
                    if(load)
                        consultasIterativas(sgv);
                    else
                        a.printMessage("Carregue as estruturas primeiro");
                    break;
                case 3:
                    if(!load) {
                        a.printMessage("Carregue as estruturas primeiro");
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
                    sgv.load();
                    load = true;
                    break;
            }
        }
    }
}
