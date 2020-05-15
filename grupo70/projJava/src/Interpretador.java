import java.util.Scanner;

public class Interpretador {
    public void menu(){
        System.out.print("0.Sair\n" +
                "1.Códigos Produtos nunca comprados e total\n" +
                "2.Total vendas e clientes distintos para cada filial e para um dado mês\n" +
                "3.Número compras, produtos distintos e gasto total de um dado cliente para cada mês\n" +
                "4.Número compras, clientes distintos e faturação total de um dado produto para cada mês\n"+
                "5.Lista produtos que um cliente mais comprou(quantidade)\n"+
                "6.X produtos mais vendidos em todo o ano(unidades) e clientes distintos que os compraram\n" +
                "7.3 maiores compradores em termos de faturação por filial\n" +
                "8.X clientes que compraram mais produtos diferentes\n" +
                "9.X clientes que mais compraram um produto e valor gasto para cada um\n" +
                "10.Faturação total de cada produto mês a mês e filial a filial\n" +
                "11.Consultas estatisticas\n" +
                "12.Menu\n");
    }

    public void interpretador(){
        boolean val = true;
        Scanner scanner = new Scanner(System.in);
        String line;
        int comand,num;
        Load sgv = new Load();
        sgv.load();
        ConsultasInterativas ci = new ConsultasInterativas();

        while (val){
            menu();
            System.out.println("Introduza número:");
            comand = scanner.nextInt();
            scanner.nextLine();
            switch (comand){
                case 0:
                    val = false;
                case 1:
                    Crono.start();
                    ci.setQuerie1(sgv);
                    System.out.println(ci.toStringQ1());
                    System.out.println("Tempo querie 1:" + Crono.getTime());
                    break;
                case 2:
                    System.out.println("Introduza um mês");
                    num = scanner.nextInt();
                    scanner.nextLine();
                    if(num > 0 && num < 13) {
                        Crono.start();
                        ci.setQuerie2(sgv,num - 1);
                        System.out.println(ci.toStringQ2(num));
                        System.out.println("Tempo querie 2:" + Crono.getTime());
                    } else
                        System.out.println("Mês inválido");
                    break;
                case 3:
                    System.out.println("Introduza um cliente");
                    line = scanner.nextLine();
                    if(sgv.getCatC().contem(line)) {
                        Crono.start();
                        ci.setQuerie3(sgv, line);
                        System.out.println(ci.toStringQ3());
                        System.out.println("Tempo querie 3:" + Crono.getTime());
                    } else
                        System.out.println("Cliente inválido");
                    break;
                case 4:
                    System.out.println("Introduza um produto");
                    line = scanner.nextLine();
                    if(sgv.getCatP().contem(line)) {
                        Crono.start();
                        ci.setQuerie4(sgv, line);
                        System.out.println(ci.toStringQ4());
                        System.out.println("Tempo querie 4:" + Crono.getTime());
                    } else
                        System.out.println("Produto inválido");
                    break;
                case 5:
                    System.out.println("Introduza um cliente");
                    line = scanner.nextLine();
                    if(sgv.getCatC().contem(line)) {
                        Crono.start();
                        ci.setQuerie5(sgv, line);
                        System.out.println(ci.toStringQ5());
                        System.out.println("Tempo querie 5:" + Crono.getTime());
                    } else
                        System.out.println("Cliente inválido");
                    break;
                case 6:
                    System.out.println("Introduza o limite");
                    num = scanner.nextInt();
                    scanner.nextLine();
                    if(num >= 0) {
                        Crono.start();
                        ci.setQuerie6(sgv, num);
                        System.out.println(ci.toStringQ6(num));
                        System.out.println("Tempo querie 6:" + Crono.getTime());
                    } else
                        System.out.println("limite inválido");
                    break;
                case 7:
                    Crono.start();
                    ci.setQuerie7(sgv);
                    System.out.println(ci.toStringQ7());
                    System.out.println("Tempo querie 7:" + Crono.getTime());
                    break;
                case 8:
                    System.out.println("Introduza o limite");
                    num = scanner.nextInt();
                    scanner.nextLine();
                    if(num >= 0) {
                        Crono.start();
                        ci.setQuerie8(sgv, num);
                        System.out.println(ci.toStringQ8(num));
                        System.out.println("Tempo querie 8:" + Crono.getTime());
                    } else
                        System.out.println("limite inválido");
                    break;
                case 9:
                    System.out.println("Introduza o limite");
                    num = scanner.nextInt();
                    scanner.nextLine();
                    System.out.println("Introduza o produto");
                    line = scanner.nextLine();
                    if(num >= 0 && sgv.getCatP().contem(line)) {
                        Crono.start();
                        ci.setQuerie9(sgv, line,num);
                        System.out.println(ci.toStringQ9(num,line));
                        System.out.println("Tempo querie 9:" + Crono.getTime());
                    } else
                        System.out.println("limite inválido ou produto inválido");
                    break;
                case 10:
                    Crono.start();
                    ci.setQuerie10(sgv);
                    System.out.println(ci.toStringQ10());
                    System.out.println("Tempo querie 10:" + Crono.getTime());
                    break;
                case 11:
                    Crono.start();
                    ConsultasEstatisticas ce = new ConsultasEstatisticas(sgv);
                    System.out.println(ce.toString());
                    System.out.println("Tempo consultas estatisticas:" + Crono.getTime());
                    break;
                case 12:
                    menu();
                    break;
            }
        }
    }
}
