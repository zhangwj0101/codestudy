package proxy;

import java.lang.reflect.Constructor;
import java.lang.reflect.Method;
import java.lang.reflect.Proxy;
import java.util.Collection;

/**
 * Created by zwj on 2016/3/14.
 */
public class Test {

    public static void main(String[] args) {
        Class<?> proxyClass = Proxy.getProxyClass(Collection.class.getClassLoader(), Collection.class);
        System.out.println(proxyClass.getCanonicalName());
        StringBuilder sb = new StringBuilder();
        for (Constructor<?> constructor : proxyClass.getConstructors()) {

            sb.append(constructor.getName());
            sb.append('(');
            for (Class<?> con : constructor.getParameterTypes()) {
                sb.append(con.getName());
                sb.append(',');
            }
            sb.deleteCharAt(sb.length() - 1);
            sb.append(")\n");
        }
        System.out.println(sb.toString());
        sb.delete(0, sb.length() - 1);
        for (Method method : proxyClass.getDeclaredMethods()) {
            sb.append(method.getName());
            sb.append('(');
            if (method.getParameterTypes().length >= 1) {
                for (Class<?> m : method.getParameterTypes()) {
                    sb.append(m.getName());
                    sb.append(',');
                }
                sb.deleteCharAt(sb.length() - 1);
            }
            sb.append(")\n");
        }
        System.out.println(sb.toString());


    }
}
