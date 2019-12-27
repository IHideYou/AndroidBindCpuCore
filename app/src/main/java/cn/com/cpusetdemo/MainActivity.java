package cn.com.cpusetdemo;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class MainActivity extends AppCompatActivity {
    private static final String TAG = "MainActivity";
    static {
        System.loadLibrary("native-lib");
    }

    private boolean flag=true;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());

        Strat();
    }

    private void Strat() {
        new Thread("demo_one"){
            @Override
            public void run() {
                super.run();
                int ret=jniSetCPUCore(1, -1, -1, -1);
                if(ret<0){
                    //设置失败
                }
                while (flag){
                    testOne();
                    try {
                        sleep(2);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }

            }
        }.start();

        new Thread("demo_two"){
            @Override
            public void run() {
                super.run();
                jniSetCPUCore(2, -1, -1, -1);
                while (flag){
                    testTwo();
                    try {
                        sleep(10);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
        }.start();
    }

    private void testOne() {
        countA();
        countB();
    }

    private void testTwo() {
        countA();
        countB();
        countC();
    }

    private void countA() {
        List<String> strings=new ArrayList<>();
        for(int i=0;i<10;i++){
            strings.add(Math.random()+"");
        }
    }

    private void countB() {
        List<String> strings=new LinkedList<>();
        for(int i=0;i<10;i++){
            strings.add(Math.random()+"");
        }
    }

    private void countC() {
        List<String> strings=new ArrayList<>();
        for(int i=0;i<10;i++){
            strings.add(Math.random()+"");
        }

        List<String> stringList=new LinkedList<>();
        for(int i=0;i<10;i++){
            strings.add(Math.random()+"");
        }
    }

    public native String stringFromJNI();

    public native int jniSetCPUCore(int core1, int core2, int core3, int core4);
}
