import java.util.Comparator;
import java.util.Objects;

public class ParStringInt implements Comparable<ParStringInt>{
    private String code;
    private double[] value;

    public ParStringInt(String code, int value) {
        this.code = code;
        this.value = new double[1];
        this.value[0] = value;
    }

    public ParStringInt(String code, double value,double value2) {
        this.code = code;
        this.value = new double[2];
        this.value[0] = value;
        this.value[1] = value2;
    }

    public ParStringInt(ParStringInt q) {
        this.code = q.getCode();
        this.value = q.getArray();
    }

    public String getCode() {
        return code;
    }

    public void setValue(int dif) {
        this.value = value;
    }

    public double getValue() {
        return value[0];
    }

    public double getValue2() {
        return value[1];
    }

    public double[] getArray(){
        return value;
    }

    public void addUni(double value) {
        this.value[0] += value;
    }

    public void addUni(double value,double value2) {
        this.value[0] += value;
        this.value[1] += value2;
    }

    public int compareTo(ParStringInt aux) {
        return this.getCode().compareTo(aux.getCode());
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        ParStringInt parStringInt = (ParStringInt) o;
        return this.getCode().equals(parStringInt.getCode());
    }

    @Override
    public int hashCode() {
        return Objects.hash(code, value);
    }

    @Override
    public String toString() {
        return code + " value=" + value[0] + '\n';
    }

    public String toString2() {
        return code + " value=" + value[1] + '\n';
    }

    public ParStringInt clone() {
        return new ParStringInt(this);
    }
}
