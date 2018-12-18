package com.example.myscapp;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.content.Context;
import android.os.AsyncTask;
import android.os.Bundle;
import android.text.method.ScrollingMovementMethod;
import android.view.Gravity;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import java.io.DataInputStream;
import java.io.IOException;
import java.net.Socket;

public class SocketClient extends Activity {
    /**
     * Called when the activity is first created.
     */

    Button btnReq;
    TextView txtAx;
    TextView txtAy;
    TextView txtAz;
    TextView txtMic;
    TextView txtOut;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

        btnReq = (Button) findViewById(R.id.btnReq);
        txtAx = (TextView) findViewById(R.id.txtAx);
        txtAy = (TextView) findViewById(R.id.txtAy);
        txtAz = (TextView) findViewById(R.id.txtAz);
        txtMic = (TextView) findViewById(R.id.txtMic);
        txtOut = (TextView) findViewById(R.id.txtOut);
        txtOut.setMovementMethod(new ScrollingMovementMethod());

        txtOut.append("Ready\n");

        btnReq.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                txtOut.append("Trying to Request\n");
                MyClientTask mycl = new MyClientTask("192.168.4.1");
                mycl.execute();
            }
        });

    }

    private void Pesan(String txtpesan){
        Context context = getApplicationContext();
        int duration = Toast.LENGTH_LONG;

        Toast toast = Toast.makeText(context,txtpesan,duration);

        toast.setGravity(Gravity.CENTER,0,0);
        toast.show();
    }

    @SuppressLint("StaticFieldLeak")
    public class MyClientTask extends AsyncTask<Void, Void, Void> {
        String hostIP;
        int str;
        StringBuilder strData = new StringBuilder();

        MyClientTask(String strIP){
            hostIP = strIP;
        }

        @Override
        protected Void doInBackground(Void... arg0) {
            Socket socket = null;
            DataInputStream dataInputStream = null;

            try {
                socket = new Socket(hostIP, 80);

                dataInputStream = new DataInputStream(socket.getInputStream());

                while((str = dataInputStream.read()) != -1){
                    strData.append((char) str);
                }

            } catch (IOException e) {Pesan("e");}
            finally {
                if (socket != null) {
                    try {
                        socket.close();
                    } catch (IOException e) {Pesan("e");}
                }
                if (dataInputStream != null) {
                    try {
                        dataInputStream.close();
                    } catch (IOException e) {Pesan("e");}
                }
            }
            return null;
        }

        @Override
        protected void onPostExecute(Void result) {
            txtOut.append(strData.toString() + "\n");

            String resData = strData.toString().trim();

            if(resData.length()>0) {
                String[] arrStrData = resData.split(":");

                if(arrStrData.length > 3) {
                    txtMic.setText(arrStrData[0].trim());
                    txtAx.setText(arrStrData[1].trim());
                    txtAy.setText(arrStrData[2].trim());
                    txtAz.setText(arrStrData[3].trim());
                }
            }

            super.onPostExecute(result);
        }
    }

}
