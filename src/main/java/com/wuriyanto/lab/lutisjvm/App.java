package com.wuriyanto.lab.lutisjvm;

/**
 * Hello world!
 *
 */
public class App 
{
    public static void main( String[] args )
    {
        // set default OS_NAME
        if(System.getenv().get("OS_NAME") == null) {
            System.out.println("required OS_NAME env variable");
            System.exit(1);
        }

        Lutis lutis = new Lutis();

        System.out.println( "Hello World!" );
        try {
            int p = lutis.power(2, 8);
            System.out.println(p);
        } catch (Exception e) {
            System.out.println("err...");
            e.printStackTrace();
        }
    }
}
