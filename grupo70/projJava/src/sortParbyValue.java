import java.util.Comparator;

public class sortParbyValue implements Comparator<ParStringInt>{
    public int compare(ParStringInt normal, ParStringInt aux) {
        return (int)-(normal.getValue() - aux.getValue());
    }
}