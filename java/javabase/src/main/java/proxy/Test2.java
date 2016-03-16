package proxy;

import java.lang.reflect.*;
import java.util.ArrayList;
import java.util.Collection;

/**
 * Created by zwj on 2016/3/14.
 */
public class Test2 {

    public static void main(String[] args) {
        Proxy.newProxyInstance(Collection.class.getClassLoader()
                , new Class[]{Collection.class}
                , new InvocationHandler() {
            public Object invoke(Object proxy, Method method, Object[] args) throws Throwable {
                return null;
            }
        });
    }
}

