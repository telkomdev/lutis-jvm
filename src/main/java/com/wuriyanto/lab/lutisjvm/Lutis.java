package com.wuriyanto.lab.lutisjvm;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.file.FileSystems;

public class Lutis {

    public static final String WIN_DYNAMIC_LIB = "liblutis.dll";
    public static final String WIN_STATIC_LIB = "liblutis.lib";

    public static final String LINUX_DYNAMIC_LIB = "liblutis.so";
    public static final String LINUX_STATIC_LIB = "liblutis.a";

    public static final String DARWIN_DYNAMIC_LIB = "liblutis.dylib";
    public static final String DARWIN_STATIC_LIB = "liblutis.a";

    public static final String WIN_OS = "win";
    public static final String LINUX_OS = "linux";
    public static final String DARWIN_OS = "darwin";

    public static final String ENV_OS_NAME = "OS_NAME";

    private static String loadNativeLib(String fileName) {
        return FileSystems.getDefault()
                .getPath(fileName)  // Dynamic link
                .normalize().toAbsolutePath().toString();
    }

    static {
        if (System.getenv(ENV_OS_NAME).equalsIgnoreCase(WIN_OS)) {
            // Windows based
            String path = loadNativeLib(WIN_DYNAMIC_LIB);
            try {
                System.load(path);
            } catch (UnsatisfiedLinkError e) {
                System.load(loadNativeLib(WIN_STATIC_LIB));
            }
        } else if (System.getenv(ENV_OS_NAME).equalsIgnoreCase(LINUX_OS)) {
            // Linux based
            String path = loadNativeLib(LINUX_DYNAMIC_LIB);
            try {
                System.load(path);
            } catch (UnsatisfiedLinkError e) {
                System.load(loadNativeLib(LINUX_STATIC_LIB));
            }
        } else {
            // Assumed Darwin based
            String path = loadNativeLib(DARWIN_DYNAMIC_LIB);
            try {
                System.load(path);
            } catch (UnsatisfiedLinkError e) {
                System.load(loadNativeLib(DARWIN_STATIC_LIB));
            }
        }
    }

    // native method interface
    private native int powerN(int a, int b);

    private native byte[] rotateImageN(double angle, byte[] data);

    public int power(int a, int b) {
        return powerN(a, b);
    }

    public void rotateImage(double angle, InputStream input, OutputStream out) throws IOException {
        byte[] inputData = IOUtil.readAllBytes(input);

        byte[] outputData = rotateImageN(angle, inputData);
        out.write(outputData);
    }

}
