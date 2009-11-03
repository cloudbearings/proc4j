package org.proc4j;

class ProcessInfoNative {
    public int pid;
    public String name;

    public ProcessInfo getInfo() {
        return new ProcessInfo(pid, name);   
    }
}
