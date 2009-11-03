package org.proc4j;

public class ProcessInfo {
    private int id;
    private String name;

    public ProcessInfo(int id, String name) {
        this.id = id;
        this.name = name;
    }

    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    @Override
    public String toString() {
        return String.format("{pid=%s,name=%s}", id, name);
    }
}
