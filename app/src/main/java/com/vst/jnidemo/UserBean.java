package com.vst.jnidemo;

/**
 * Created by zwy on 2018/2/8.
 * email:16681805@qq.com
 */

public class UserBean {
    private long id;
    private String name;
    private int age;
    private boolean isMan;

    public UserBean() {
    }

    public UserBean(long id, String name, int age, boolean isMan) {
        this.id = id;
        this.name = name;
        this.age = age;
        this.isMan = isMan;
    }

    public long getId() {
        return id;
    }

    public void setId(long id) {
        this.id = id;
    }

    public boolean isMan() {
        return isMan;
    }

    public void setMan(boolean man) {
        isMan = man;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }
}
