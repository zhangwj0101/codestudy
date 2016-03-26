package proxy.demo;

/**
 * Created by zwj on 2016/3/26.
 */
public class HelloWorld {
    String str = "";

    public String getStr() {
        return str;
    }

    public void setStr(String str) {
        this.str = str;
    }

    public static void main(String[] args) {
        HelloWorld hl = new HelloWorld();
        hl.getStr();
        hl.setStr("AA");
    }
}
