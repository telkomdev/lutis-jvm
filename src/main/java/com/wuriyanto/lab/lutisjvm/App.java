package com.wuriyanto.lab.lutisjvm;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class App 
{
    public static void main( String[] args )
    {
        // set default OS_NAME
        if(System.getenv().get("OS_NAME") == null) {
            System.out.println("required OS_NAME env variable");
            System.exit(1);
        }

        FileOutputStream fos = null;
        FileInputStream fis = null;

        Lutis lutis = new Lutis();

        System.out.println( "Hello World!" );
        try {
            File file = new File("/Users/wuriyanto/Documents/java-work/lutis-jvm/testdata/pp.jpg");
            fos = new FileOutputStream("/Users/wuriyanto/Documents/java-work/lutis-jvm/testdata/out.png");
            fis = new FileInputStream(file);

            lutis.rotateImage(90, fis, fos);

        } catch (Exception e) {
            System.out.println("err...");
            e.printStackTrace();
        } finally {
            try {
                if (fos != null)
                    fos.close();

                if (fis != null)
                    fis.close();
            } catch (IOException ex) {
                ex.printStackTrace();
            }
        }
    }
}
