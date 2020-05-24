package View;

import Model.ConsultasEstatisticas;
import Model.ConsultasInterativas;

public interface IApresentacao {
    void welcome();
    void clearScreen();
    void menu();
    void menuConsultasInterativas();
    void menuConsultasEstatisticas();
    void menuQ10();
    void printMessage(String message);
    void pedirNomeFicheiro();
    void printErroLerInt();
    void printErroCarregar();
    void printErroLerFicheiro(int i);
    void printTime(String time,String type);
    String pedirCliente();
    String pedirProduto();
    String pedirMes();
    String pedirLimite();
    String pedirNumero();
    void printQ10(String prod, float[][] arr);
    void printConsultasEstatisticas(ConsultasEstatisticas ce, int i);
    void printConsultasIterativas(ConsultasInterativas ci, int i, String time);
}
