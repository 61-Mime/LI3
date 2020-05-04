public class Info {

    public String code;

    public Info(String code) {
        this.code = code;
    }

    public String getCode() {
        return code;
    }

    public int getSize() {
        return this.getSize();
    }

    public int getSizeN() {
        return this.getSizeN();
    }

    public int getSizeP() {
        return this.getSizeP();
    }

    public void addCli(String cliCode, char type) {
    }

    public void addProd(String prodCode, int mes, int uni, double price) {
    }

    public int compareTo(Info i) {
        return this.getCode().compareTo(i.getCode());
    }
}
