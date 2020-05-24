package Model;

import Model.CliInfo;
import Model.ProdInfo;

import java.io.Serializable;
import java.util.Comparator;

public class sortCliByTotalFact implements Serializable, Comparator<ProdInfo> {

    public int compare(ProdInfo c1, ProdInfo c2) {
        return (int) (((CliInfo) c2).getGastoTotal() - ((CliInfo) c1).getGastoTotal());
    }
}


