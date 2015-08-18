 package org.libsdl.app;

 public final class utils {
     private static int w;
     private static int h;

     public static int[] getScreenPixels() {
         return new int[] {w, h};
     }

     public static void setScreenPixels(int w, int h) {
         utils.w = w;
         utils.h = h;
     }
 }
