import java.util.List;
import java.util.Map;

public interface IConsultasInterarivas {
    public List<String> getQ1();
    public int[] getQ2();
    public Map<Integer,float[]> getQ3();
    public Map<Integer,float[]> getQ4();
    public List<ParStringFloat> getQ5();
    public List<ParStringFloat> getQ6();
    public Map<Integer,List<String>> getQ7();
    public List<ParStringFloat> getQ8();
    public List<ParStringFloat> getQ9();
    public Map<String,float[][]> getQ10();
}
