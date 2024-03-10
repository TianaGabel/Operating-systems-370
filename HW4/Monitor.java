public class Monitor {
    private int mutex;
    private int empty;
    private int full;

    //waits for empty slots
    Thread waitingForEmpty;
    //waits for an element in the buffer
    Thread waitingForFull;
    Thread WaitingOnMutex;

    public Monitor(int bufferSize){
        mutex = 1;
        empty = bufferSize;
        full = 0;
    }

    public synchronized void aquireMutex(){
        while(mutex <= 0);
        mutex--;
    }

    public synchronized void releaseMutex(){
        mutex++;
    }

    public synchronized void aquireEmpty(){
        while(empty <= 0);
        empty--;
    }

    public synchronized void releaseEmpty(){
        empty++;
    }

    public synchronized void aquireFull(){
        while(full <= 0);
        full--;
    }

    public synchronized void releaseFull(){
        full++;
    }

    
}
