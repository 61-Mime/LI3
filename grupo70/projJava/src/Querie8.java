public class Querie8 implements Comparable<Querie8>{
    private String code;
    private int dif;

    public Querie8(String code, int dif) {
        this.code = code;
        this.dif = dif;
    }

    public String getCode() {
        return code;
    }

    public int getDif() {
        return dif;
    }

    public int compareTo(Querie8 aux) {
        return -(this.getDif() - aux.getDif());
    }

    @Override
    public String toString() {
        return "Querie8{" +
                "code='" + code + '\'' +
                ", dif=" + dif +
                '}' + '\n';
    }
}
