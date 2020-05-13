import java.util.Comparator;

public class sortStringQueri8 implements Comparator<Querie8>{
    public int compare(Querie8 normal, Querie8 aux) {
        return -(normal.getDif() - aux.getDif());
    }
}