public interface IApresentacao {
    void welcome();
    void clearScreen();
    void menu();
    void menuConsultasInterativas();
    void menuConsultasEstatisticas();
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
    void printConsultasEstatisticas(ConsultasEstatisticas ce, int i);
    void printConsultasIterativas(ConsultasInterativas ci, int i,String time);
    /*
    void printQ1(ConsultasInterativas ci, String time);
    void printQ2(ConsultasInterativas ci, String time,int num);
    void printQ3(ConsultasInterativas ci, String time);
    void printQ4(ConsultasInterativas ci, String time);
    void printQ5(ConsultasInterativas ci, String time);
    void printQ6(ConsultasInterativas ci, String time,int num);
    void printQ7(ConsultasInterativas ci, String time);
    void printQ8(ConsultasInterativas ci, String time,int num);*/
}
