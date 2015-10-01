package com.elmanahil.rdown;

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
    public static native String render(String down);
}