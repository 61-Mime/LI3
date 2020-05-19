import java.util.Comparator;
import java.util.Objects;

public class ParStringFloat implements Comparable<ParStringFloat>{
    private String code;
    private float[] value;

    public ParStringFloat(String code, float value) {
        this.code = code;
        this.value = new float[1];
        this.value[0] = value;
    }

    public ParStringFloat(String code, float value,float value2) {
        this.code = code;
        this.value = new float[2];
        this.value[0] = value;
        this.value[1] = value2;
    }

    public ParStringFloat(ParStringFloat q) {
        this.code = q.getCode();
        this.value = q.getArray();
    }

    public String getCode() {
        return code;
    }

    public void setValue2(float dif) {
        this.value[1] = dif;
    }

    public float getValue() {
        return value[0];
    }

    public float getValue2() {
        return value[1];
    }

    public float[] getArray(){
        return value;
    }

    public void addUni(float value,float value2) {
        this.value[0] += value;
        this.value[1] += value2;
    }

    public int compareTo(ParStringFloat aux) {
        return this.getCode().compareTo(aux.getCode());
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        ParStringFloat ParStringFloat = (ParStringFloat) o;
        return this.getCode().equals(ParStringFloat.getCode());
    }

    public String toString3() {
        return code + " value=" + value[0] + '\n';
    }

    public String toString2() {
        return code + " value=" + value[1] + '\n';
    }

    @Override
    public String toString() {
        return code + " value=" + value[0] + " value=" + value[1] + "\n";
    }

    public ParStringFloat clone() {
        return new ParStringFloat(this);
    }
}
