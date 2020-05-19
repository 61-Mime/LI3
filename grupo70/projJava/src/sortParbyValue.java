import java.util.Comparator;

public class sortParbyValue implements Comparator<ParStringFloat>{
    public int compare(ParStringFloat normal, ParStringFloat aux) {
        return (int)-(normal.getValue() - aux.getValue());
    }
}