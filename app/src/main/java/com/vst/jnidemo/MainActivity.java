package com.vst.jnidemo;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    private TextView tv_result;
    private Button btn1;
    private JniTest jniTest;
    private Button btn2;
    private Button btn3;
    private Button btn4;
    private Button btn5;
    private Button btn6;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        initView();

    }

    private void initView() {
        tv_result = (TextView) findViewById(R.id.tv_result);
        btn1 = (Button) findViewById(R.id.btn1);

        btn1.setOnClickListener(this);

        jniTest = new JniTest();
        btn2 = (Button) findViewById(R.id.btn2);
        btn2.setOnClickListener(this);
        btn3 = (Button) findViewById(R.id.btn3);
        btn3.setOnClickListener(this);
        btn4 = (Button) findViewById(R.id.btn4);
        btn4.setOnClickListener(this);
        btn5 = (Button) findViewById(R.id.btn5);
        btn5.setOnClickListener(this);
        btn6 = (Button) findViewById(R.id.btn6);
        btn6.setOnClickListener(this);
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.btn1:
                tv_result.setText(jniTest.sayHello());
                break;
            case R.id.btn2:
                tv_result.setText(jniTest.join("this is java!!"));
                break;
            case R.id.btn3:
                tv_result.setText("result>>>" + jniTest.total(20, 38));
                break;
            case R.id.btn4:
                UserBean userBean = jniTest.tObj(new UserBean(1001L, "tom", 36, true));
                Log.i("zwy", "name=" + userBean.getName() + " age=" + userBean.getAge());
                break;
            case R.id.btn5:
                UserBean ub1 = jniTest.getObj();
                Log.i("zwy", "id=" + ub1.getId() + " name=" + ub1.getName() + " age=" + ub1.getAge() + " isMan=" + ub1.isMan());
                break;
            case R.id.btn6:
                ArrayList<UserBean> list = new ArrayList<>();
                for (int i = 0; i < 5; i++) {
                    UserBean bean = new UserBean(i, "tom" + i, 30 + i * 2, i % 2 == 0 ? true : false);
                    list.add(bean);
                }
                jniTest.tList(list);
                break;
        }
    }
}
