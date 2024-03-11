public class Monitor {
    private int mutex;
    private int empty;
    private int full;

    //waits for empty slots
    Thread waitingForEmpty;
    //waits for an element in the buffer
    Thread waitingForFull;
    Thread WaitingOnMutex;

    //Once we add wait and notify we may need to add the synchronized keyword

    public Monitor(int bufferSize){
        mutex = 1;
        empty = bufferSize;
        full = 0;
    }

    public void aquireMutex(){
        System.out.println("m ok =" + mutex);
        while(mutex <= 0){;}
        mutex--;
    }

    public void releaseMutex(){
        mutex++;
    }

    public void aquireEmpty(){
        while(empty <= 0);
        empty--;
    }

    public void releaseEmpty(){
        empty++;
    }

    public void aquireFull(){
        System.out.println("Start Aquire full");
        while(full <= 0){;}
        System.out.println("not ok");
        full--;
    }

    public void releaseFull(){
        System.out.println("Released Full = " + full);
        full++;
    }

    
}
