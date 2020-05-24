package Model;

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

    @Override
    public String toString() {
        if(value.length == 2)
            return String.format("%5s %1s %5.2f %1s %7.2f", code , " ", value[0] , " ", value[1]);
        else
            return String.format("%5s %1s %5.2f", code , " ", value[0] );
    }

    public ParStringFloat clone() {
        return new ParStringFloat(this);
    }
}
