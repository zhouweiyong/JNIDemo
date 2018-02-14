package com.vst.jnidemo;

import java.util.List;

/**
 * Created by zwy on 2018/2/7.
 * email:16681805@qq.com
 */

public class JniTest {

    static {
        System.loadLibrary("native-lib");
    }

    //返回字符串
    public native String sayHello();

    //传递字符串
    public native String join(String str);

    //传递整型，返回整型
    public native int total(int a, int b);


    //传递自定义对象，返回自定义对象
    public native UserBean tObj(UserBean userBean);

    //获取c中生成的对象
    public native UserBean getObj();

    public native UserBean gObj();

    //传递集合，返回集合
    public native void tList(List<UserBean> list);

    //传递一个回调函数
    public void helloFromJava() {
        System.out.println("hello from java ");
    }

    public void printString(String s) {
        System.out.println("in java code " + s);
    }

}
