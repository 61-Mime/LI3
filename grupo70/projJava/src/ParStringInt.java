import java.util.Comparator;
import java.util.Objects;

public class ParStringInt implements Comparable<ParStringInt>{
    private String code;
    private int value;

    public ParStringInt(String code, int value) {
        this.code = code;
        this.value = value;
    }

    public ParStringInt(ParStringInt q) {
        this.code = q.getCode();
        this.value = q.getValue();
    }

    public String getCode() {
        return code;
    }

    public void setValue(int dif) {
        this.value = value;
    }

    public int getValue() {
        return value;
    }

    public void addUni(int value) {
        this.value += value;
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
        return "ParStringInt{" +
                "code='" + code + '\'' +
                ", value=" + value +
                '}' + '\n';
    }

    public ParStringInt clone() {
        return new ParStringInt(this);
    }
}
