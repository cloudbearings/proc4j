package proc4j;

import org.proc4j.Proc4j;
import org.proc4j.ProcessInfo;
import org.junit.Before;
import org.junit.Test;

import java.util.List;

public class SimpleTest {
    @Before
    public void setUp() {
        LibraryLoaderTestHelper.load();
    }
    @Test
    public void test() {
        List<ProcessInfo> processes = Proc4j.getProcessList();
        for (ProcessInfo process : processes) {
            System.out.println("Found process: " + process);
        }
    }
}
