import java.util.Comparator;
import java.util.Objects;

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

    public void addUni(int dif) {
        this.dif += dif;
    }

    public int compareTo(Querie8 aux) {
        return this.getCode().compareTo(aux.getCode());
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Querie8 querie8 = (Querie8) o;
        return this.getCode().equals(querie8.getCode());
    }

    @Override
    public int hashCode() {
        return Objects.hash(code, dif);
    }

    @Override
    public String toString() {
        return "Querie8{" +
                "code='" + code + '\'' +
                ", dif=" + dif +
                '}' + '\n';
    }
}
