package proxy;

import java.lang.reflect.*;
import java.util.ArrayList;
import java.util.Collection;

/**
 * Created by zwj on 2016/3/14.
 */
public class Test1 {

    public static void main(String[] args) throws NoSuchMethodException, IllegalAccessException, InvocationTargetException, InstantiationException {
        Class<?> proxyClass = Proxy.getProxyClass(Collection.class.getClassLoader(), Collection.class);

        Constructor<?> constructor = proxyClass.getConstructor(InvocationHandler.class);
        Collection o = (Collection) constructor.newInstance(new MyInvocationHandler(new ArrayList<String>()));
        o.add("231");
        System.out.println(o.toString());

    }
}

class MyInvocationHandler implements InvocationHandler {

    private Collection obj;

    public MyInvocationHandler(Collection obj) {
        this.obj = obj;
    }


    public Object invoke(Object proxy, Method method, Object[] args) throws Throwable {
        return method.invoke(obj, args);
    }
}
