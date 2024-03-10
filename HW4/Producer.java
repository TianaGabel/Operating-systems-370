//package HW4;

public class Producer {

    //Only wait and notify are allowed
    //avoid deadlocks

    //Producer will be producing data items to be added to the buffer. It will wait if the buffer is currently full.
    //Producer will produce 1,000,000 random items

    //running totalof values added
    int bufferValueCounter;
    int counter;
    Monitor monitor;

    public Producer(Monitor monitor){
        this.monitor = monitor;
        bufferValueCounter = 0;
        counter = 0;
    }


    public void run(){
        while (counter < 1000000){
            int currValue = 0;

            monitor.aquireEmpty();
            monitor.aquireMutex();
            //Add to buffer
            monitor.releaseMutex();
            monitor.releaseFull();

            bufferValueCounter += currValue;
            counter++;
        }
    }
    
}

