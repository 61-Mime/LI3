import java.io.*;

public class DataFile extends IOException {

    public void guardaDados(String fileName, Load load) {
        try {
            FileOutputStream file = new FileOutputStream(fileName);
            ObjectOutputStream oos = new ObjectOutputStream(file);
            oos.writeObject(load);
            oos.flush();
            oos.close();
        }
        catch (FileNotFoundException e) {
            e.getMessage();
        }
        catch (IOException e) {
            e.getMessage();
        }
    }

    public Load carregaDados(String fileName) throws IOException, ClassNotFoundException {
        FileInputStream file = new FileInputStream(fileName);
        ObjectInputStream ois = new ObjectInputStream(file);
        Load sgv = (Load) ois.readObject();
        ois.close();
        return sgv;
    }
}
