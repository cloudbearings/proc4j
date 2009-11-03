package org.proc4j;

class ProcessesFunctions {
    public static native ProcessInfoNative[] list();
    public static native int kill(int pid, int sig);
    public static native int currentPid();
}
