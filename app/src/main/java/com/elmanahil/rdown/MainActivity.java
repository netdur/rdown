package com.elmanahil.rdown;

import android.app.Activity;
import android.os.Bundle;
import android.text.Html;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.TextView;

public class MainActivity extends Activity {

    public TextView tvr;
    public TextView tv;
    public HtmlTextView htv;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        tvr = (TextView) findViewById(R.id.fullscreen_content_raw);
        tv = (TextView) findViewById(R.id.fullscreen_content);
        htv = (HtmlTextView) findViewById(R.id.html_text);

        final EditText et = (EditText) findViewById(R.id.fullscreen_content_edit);
        Button btn = (Button) findViewById(R.id.fullscreen_content_btn);
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                setText(et.getText().toString());
            }
        });

        final Spinner dropdown = (Spinner) findViewById(R.id.spinner1);
        final String[] items = getItems();
        ArrayAdapter<String> adapter = new ArrayAdapter<String>(this, android.R.layout.simple_spinner_dropdown_item, items);
        dropdown.setAdapter(adapter);
        dropdown.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                setText(dropdown.getSelectedItem().toString());
            }

            @Override
            public void onNothingSelected(AdapterView<?> parent) {

            }
        });
    }

    public void setText(String md) {
        String html = Rdown.process(md);
        tv.setText(Html.fromHtml(html));
        tvr.setText(html);
        htv.setHtmlFromString(html);
    }

    public String[] getItems() {
        return new String[]{
                "http://www.reddit.com",
                "foo@example.com",
                "[foo](http://en.wikipedia.org/wiki/Link_(film\\))",
                "(http://tsfr.org)",
                "[A link with a /r/subreddit in it](/lol)",
                "[A link with a http://www.url.com in it](/lol)",
                "[Empty Link]()",
                "http://en.wikipedia.org/wiki/café_racer",
                "#####################################################hi",
                "[foo](http://bar\\nbar)",
                "/r/test",
                "Words words /r/test words",
                "/r/",
                "escaped \\/r/test",
                "ampersands http://www.google.com?test&blah",
                "[_regular_ link with nesting](/test)",
                " www.a.co?with&test",
                "Normal^superscript",
                "Escape\\^superscript",
                "~~normal strikethrough~~",
                "\\~~escaped strikethrough~~",
                "anywhere\\x03, you",
                "[Test](//test)",
                "[Test](//#test)",
                "[Test](#test)",
                "[Test](git://github.com)",
                "[Speculation](//?)",
                "/r/sr_with_underscores",
                "[Test](///#test)",
                "/r/multireddit+test+yay",
                "/r/multireddit+test+yay",
                "words_with_underscores",
                "words*with*asterisks",
                "~test",
                "/u/test",
                "/u/test/m/test test",
                "/U/nope",
                "/r/test/m/test test",
                "/r/test/w/test test",
                "/r/test/comments/test test",
                "/u/test/commentscommentscommentscommentscommentscommentscomments/test test",
                "a /u/reddit"
        };
    }
}