package com.elmanahil.rdown;

import android.app.Activity;
import android.os.Bundle;
import android.text.Html;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends Activity {

    public TextView tv;
    public HtmlTextView htv;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        tv = (TextView) findViewById(R.id.fullscreen_content);
        htv = (HtmlTextView) findViewById(R.id.html_text);
        htv.setLinkClickedListener(new HtmlTextView.OnLinkClickedListener() {
            @Override
            public void onClick(String url) {
                Log.i("clicked", url);
            }
        });

        final EditText et = (EditText) findViewById(R.id.fullscreen_content_edit);
        Button btn = (Button) findViewById(R.id.fullscreen_content_btn);
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String md = et.getText().toString();
                String html = Rdown.process(md);
                tv.setText(Html.fromHtml(html));
                htv.setHtmlFromString(html);
                Log.i("has table", Rdown.hasTable(md) + "");
            }
        });
    }
}