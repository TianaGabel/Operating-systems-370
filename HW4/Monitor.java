public class Monitor {
    private int mutex;
    private int empty;
    private int full;
    private Double[] circularBuffer;
    private boolean exit;
    public final int VALUES_TO_BE_PRODUCED;
    public final int BUFFER_SIZE;
    public final int INCREMENT;


    public Monitor(int bufferSize, int valuesToBeProduced,int increment){
        VALUES_TO_BE_PRODUCED = valuesToBeProduced;
        BUFFER_SIZE = bufferSize;
        INCREMENT = increment;
        mutex = 1;
        empty = bufferSize;
        full = 0;
        circularBuffer = new Double[bufferSize];
        exit = false;
    }

    public synchronized double consume(int out){
        return circularBuffer[out];
    }

    public synchronized void produce(int in, double currValue){
        circularBuffer[in] = currValue;
    }

    public synchronized void aquireMutex() throws InterruptedException{
        //System.out.println("m ok =" + mutex);
        while(mutex <= 0){
            wait();
        }
        mutex--;
    }

    public synchronized void releaseMutex(){
        mutex++;
        notify();
    }

    public synchronized void aquireEmpty() throws InterruptedException{
        while(empty <= 0){
            wait();
        }
        empty--;
    }

    public synchronized void releaseEmpty(){
        empty++;
        notify();
    }

    public synchronized void aquireFull() throws InterruptedException{
        //System.out.println("Start Aquire full");
        while(full <= 0){
            wait();
        }
        full--;
    }

    public synchronized void releaseFull(){
        //System.out.println("Released Full = " + full);
        full++;
        notify();
    }

    public synchronized void exit(){
        if (!exit){
            exit = true;
        } else {
            System.out.println("Exiting!");
        }
    }

    
}
