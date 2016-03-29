package proxy.demo;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by zwj on 2016/3/26.
 */
public class HeapOOM {
    static class OOMObject {

    }

    public static void main(String[] args) {
        List<OOMObject> list = new ArrayList<OOMObject>();
        while (true) {
            list.add(new OOMObject());
        }
    }
}
