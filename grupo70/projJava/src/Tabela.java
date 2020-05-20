import java.util.List;
import java.util.Scanner;

public class Tabela {
    private void printPagina1(List<ParStringFloat> list, int page, int max, int maxpage) {
        int i, j;
        int size = list.size();

        System.out.println("---------------------------------------------------------------------------------------------");
        System.out.println("                                       Página " + (page+1) + maxpage+1);
        System.out.println("---------------------------------------------------------------------------------------------");

        for(i=max*page; i<(max*(page+1)) && i<size; i+=6) {
            for(j=i; (j<i+5) && (j<size-1); j++)
                System.out.print(list.get(j).toString());
            System.out.println(list.get(j).toString());
        }

        System.out.println("---------------------------------------------------------------------------------------------");
        System.out.println("      [N] Next Page | [P] Previous Page | [F] First Page | [L] Last Page | [Q] Quit        ");
        System.out.println("---------------------------------------------------------------------------------------------");
    }
/*
    private void printPagina2(List<ParStringFloat> list, int page, int max, int maxpage) {
        int i, j;
        int size = list.size();

        System.out.println("---------------------------------------------------------------------------------------------");
        System.out.println("                                       Página " + (page+1) + maxpage+1);
        System.out.println("---------------------------------------------------------------------------------------------");

        for(i=max*page; i<(max*(page+1)) && i<size; i+=6) {
            for(j=i; (j<i+5) && (j<size-1); j++)
                System.out.print(list.get(j).toString2());
            System.out.println(list.get(j).toString2());
        }

        System.out.println("---------------------------------------------------------------------------------------------");
        System.out.println("      [N] Next Page | [P] Previous Page | [F] First Page | [L] Last Page | [Q] Quit        ");
        System.out.println("---------------------------------------------------------------------------------------------");
    }

    private void printArray(List<ParStringFloat> list, int max, int type) {
        int page = 0, maxpage = (list.size()-1)/max;
        Scanner s = new Scanner(System.in);
        String line;
        boolean r=true;

        while(r) {
            if(type==1)
                printPagina1(list, page, max, maxpage);
            else
                printPagina2(list, page, max, maxpage);

            line = s.nextLine();

            if(line.equals("N") && page<maxpage)
                page++;

            else if(line.equals("P") && page>0)
                page--;

            else if(line.equals("F"))
                page = 0;

            else if(line.equals("L"))
                page = maxpage;

            else if(line.equals("Q"))
                r=false;
        }
    }*/
}
