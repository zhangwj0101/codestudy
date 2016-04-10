package proxy.demo;

import java.lang.reflect.Method;
import java.lang.reflect.ParameterizedType;
import java.lang.reflect.Type;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

/**
 * Created by zwj on 2016/4/7.
 */
public class T {

    public static void main(String[] args) throws NoSuchMethodException {
        List<String> s1 = new ArrayList<>();
        List<Integer> s2 = new ArrayList<>();
        s1.add("sdf");
        s2.add(2);
        String s = s1.get(0);
        Integer integer = s2.get(0);
        T t = new T();
        Method apply = T.class.getMethod("apply", List.class);

        Type[] genericParameterTypes = apply.getGenericParameterTypes();
        ParameterizedType genericParameterType = (ParameterizedType) genericParameterTypes[0];
        Type type = genericParameterType.getActualTypeArguments()[0];
        System.out.println(type.getTypeName());
    }

    public void apply(List<Date> lis) {

    }
}
