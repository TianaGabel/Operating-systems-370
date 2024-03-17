//package HW4;

import java.util.Random;

public class Producer implements Runnable {

    //Only wait and notify are allowed
    //avoid deadlocks

    //Producer will be producing data items to be added to the buffer. It will wait if the buffer is currently full.
    //Producer will produce 1,000,000 random items

    //running totalof values added
    Double bufferValueCounter;
    int counter;
    Monitor monitor;
    Double[] circularBuffer;
    final int VALUES_TO_BE_PRODUCED;
    final int BUFFER_SIZE;

    public Producer(Monitor monitor){
        BUFFER_SIZE = monitor.BUFFER_SIZE;
        VALUES_TO_BE_PRODUCED = monitor.VALUES_TO_BE_PRODUCED;
        this.monitor = monitor;
        bufferValueCounter = 0.0;
        counter = 0;
        System.out.println("Created Producer");
    }


    public void run(){
        int in = 0;
        Double currProduced = 0.0;
        Random random = new Random();
        while (counter < VALUES_TO_BE_PRODUCED){
            currProduced = random.nextDouble() * 100.0;

            monitor.aquireEmpty();
            monitor.aquireMutex();
            //System.out.println("Producer critical section =" + counter);
            //Add to buffer
            monitor.produce(in, currProduced);
            in = (in + 1) % BUFFER_SIZE;
            monitor.releaseMutex();
            monitor.releaseFull();

            bufferValueCounter += currProduced;
            counter++;
            if ((counter % 1000) == 0){
                System.out.println("Producer: Generated " + counter + " items, Cumulative value of generated items=" + bufferValueCounter);
            }
        }
        System.out.println("Done" + counter);
    }
    
}

