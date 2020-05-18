import org.junit.Before;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ParStringIntTest {
    ParStringInt p1;
    ParStringInt p2;

    @Before
    public void setUp(){
        p1 = new ParStringInt("Z5000", 5);
        p2 = new ParStringInt("AB542", 8, 2);
    }

    @Test
    public void testAddUnit(){
//        p1.addUni(2);
//        p2.addUni(1, 3);
        double unitObtidas1 = p1.getValue();
        double unitObtidas2 = p2.getValue2();

        assertEquals(7, unitObtidas1, "unit1 mal adicionadas");
        assertEquals(5, unitObtidas2, "unit2 mal adicionadas");
    }
}