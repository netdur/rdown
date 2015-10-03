package com.elmanahil.rdown;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.StringReader;

public class Rdown {
    static {
        System.loadLibrary("rdown");
    }
    public static String process(String down) {
        try {
            return render(down);
        } catch (Exception e) {
            return "error: " + e.getMessage();
        }
    }
    public static boolean hasTable(String md) {
        BufferedReader bufReader = new BufferedReader(new StringReader(md));
        String line = null;
        boolean pipeToken = false;
        try {
            while ((line = bufReader.readLine()) != null) {
                if (pipeToken == false) {
                    pipeToken = line.contains("|");
                    continue;
                } else {
                    boolean illegal = false;
                    for (char c: line.toCharArray()) {
                        if ((c != ':') && (c != '-') && (c != '|') && (c != ' ')) {
                            illegal = true;
                        }
                    }
                    if (illegal == false) {
                        return true;
                    }
                }
                pipeToken = line.contains("|");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return false;
    }
    public static native String render(String down);
}