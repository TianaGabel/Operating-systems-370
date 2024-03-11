//package HW4;

public class Producer implements Runnable {

    //Only wait and notify are allowed
    //avoid deadlocks

    //Producer will be producing data items to be added to the buffer. It will wait if the buffer is currently full.
    //Producer will produce 1,000,000 random items

    //running totalof values added
    int bufferValueCounter;
    int counter;
    Monitor monitor;
    final int VALUES_TO_BE_PRODUCED = 10;

    public Producer(Monitor monitor){
        this.monitor = monitor;
        bufferValueCounter = 0;
        counter = 0;
        System.out.println("Created Producer");
    }


    public void run(){
        while (counter < VALUES_TO_BE_PRODUCED){
            int currValue = 0;

            monitor.aquireEmpty();
            monitor.aquireMutex();
            System.out.println("Producer critical section =" + counter);
            //Add to buffer
            monitor.releaseMutex();
            monitor.releaseFull();

            bufferValueCounter += currValue;
            counter++;
        }
    }
    
}

