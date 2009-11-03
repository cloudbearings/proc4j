package org.proc4j;

import java.util.List;
import java.util.ArrayList;

public class Proc4j {
    public static void loadNatives() {
        
    }

    public static List<ProcessInfo> getProcessList() {
        ProcessInfoNative[] processes = ProcessesFunctions.list();
        List<ProcessInfo> res = new ArrayList<ProcessInfo>(processes.length);
        for (ProcessInfoNative nativeInfo : processes) {
            res.add(nativeInfo.getInfo());
        }
        return res;
    }
}
