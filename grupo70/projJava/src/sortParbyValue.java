import java.util.Comparator;

public class sortParbyValue implements Comparator<ParStringFloat>{
    public int compare(ParStringFloat normal, ParStringFloat aux) {
        int i = (int) (aux.getValue() - normal.getValue());
        if (i == 0)
            return normal.getCode().compareTo(aux.getCode());
        return i;
    }
}