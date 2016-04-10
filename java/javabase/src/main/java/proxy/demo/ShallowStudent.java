package proxy.demo;

/**
 * Created by zwj on 2016/4/7.
 */
public class ShallowStudent implements Cloneable {
    private String name;

    private int age;

    ShallowStudent(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public Object clone() {
        ShallowStudent o = null;
        try {
            // Object中的clone()识别出你要复制的是哪一个对象。
            o = (ShallowStudent) super.clone();
        } catch (CloneNotSupportedException e) {
            System.out.println(e.toString());
        }
        return o;
    }

    public static void main(String[] args) {
        ShallowStudent s1 = new ShallowStudent("zhangsan", 18);
        ShallowStudent s2 = (ShallowStudent) s1.clone();
        s2.name = "lisi";
        s2.age = 20;
        //修改学生2后，不影响学生1的值。
        System.out.println("name=" + s1.name + "," + "age=" + s1.age);
        System.out.println("name=" + s2.name + "," + "age=" + s2.age);
    }
}
