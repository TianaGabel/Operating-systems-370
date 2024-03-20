public class Monitor {
    //The number of currently empty
    private int empty;
    //The number of currently full
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
