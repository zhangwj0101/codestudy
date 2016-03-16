package proxy;

import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Method;

/**
 * Created by zwj on 2016/3/14.
 */
public class TransactionHandler implements InvocationHandler {

    private Object target;

    public TransactionHandler(Object target) {
        super();
        this.target = target;
    }


    @Override
    public Object invoke(Object proxy, Method method, Object[] args) throws Throwable {
        System.out.println("开启事务.....");
        try {
            return method.invoke(target, args);
        } catch (Exception e) {
            e.printStackTrace();
        }
        System.out.println("提交事务.....");
        return null;
    }
}
