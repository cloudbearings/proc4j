package proc4j;

import java.io.File;
import java.io.IOException;

public class LibraryLoaderTestHelper {
    public static void load() {
        String PROP_NAME = "proc4j.native.path";
        String librariesPath = System.getProperty(PROP_NAME);
        if (librariesPath == null) {
            throw new IllegalStateException(PROP_NAME + " system property is undefined");
        }
        try {
            load(librariesPath + File.separator + "proc4j_" + platform() + "_x86_64");
        } catch (Throwable e) {
            load(librariesPath + File.separator + "proc4j_" + platform() + "_i386");
        }
    }

    private static void load(String filePath) {
        try {
            System.load(new File(filePath).getCanonicalPath());
        } catch (IOException e) {
            System.load(new File(filePath).getAbsolutePath());
        }
    }

    private static String platform() {
        return "darwin";
    }

    public static void main(String[] args) {
        load();
    }
}
