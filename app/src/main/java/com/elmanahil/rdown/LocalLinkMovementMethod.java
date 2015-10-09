/*
 * Copyright (C) 2015 Heliangwei
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.elmanahil.rdown;

import android.content.ActivityNotFoundException;
import android.text.Layout;
import android.text.Spannable;
import android.text.method.LinkMovementMethod;
import android.text.style.ClickableSpan;
import android.text.style.URLSpan;
import android.view.MotionEvent;
import android.widget.TextView;

public class LocalLinkMovementMethod extends LinkMovementMethod {
    static LocalLinkMovementMethod sInstance;

    private HtmlTextView.OnLinkClickedListener clickListener;
    public void setLinkClickedListener(HtmlTextView.OnLinkClickedListener ev) {
        this.clickListener = ev;
    }

    public static LocalLinkMovementMethod getInstance() {
        if (sInstance == null)
            sInstance = new LocalLinkMovementMethod();

        return sInstance;
    }

    @Override
    public boolean onTouchEvent(TextView widget, Spannable buffer, MotionEvent event) {

        int action = event.getAction();

        if (action == MotionEvent.ACTION_UP) {
            int x = (int) event.getX();
            int y = (int) event.getY();

            x -= widget.getTotalPaddingLeft();
            y -= widget.getTotalPaddingTop();

            x += widget.getScrollX();
            y += widget.getScrollY();

            Layout layout = widget.getLayout();
            int line = layout.getLineForVertical(y);
            int off = layout.getOffsetForHorizontal(line, x);
            float maxLineRight = layout.getLineWidth(line);

            ClickableSpan[] link = buffer.getSpans(off, off, ClickableSpan.class);

            if (link.length == 0) return false;
            try {
                clickListener.onClick(((URLSpan) link[0]).getURL());
                return false;
            } catch (ActivityNotFoundException ex) {
                return true;
            }
        }
        return true;
    }
}
