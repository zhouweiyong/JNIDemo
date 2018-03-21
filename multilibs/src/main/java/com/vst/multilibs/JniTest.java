package com.vst.multilibs;

/**
 * Created by zwy on 2018/3/21.
 * email:16681805@qq.com
 */

public class JniTest {
    static {
        System.loadLibrary("one-lib");
        System.loadLibrary("two-lib");
    }

    public static native String getStr();

    public static native String getStr2();
}
