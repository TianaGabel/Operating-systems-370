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
    final int INCREMENT;

    public Producer(Monitor monitor){
        BUFFER_SIZE = monitor.BUFFER_SIZE;
        VALUES_TO_BE_PRODUCED = monitor.VALUES_TO_BE_PRODUCED;
        INCREMENT = monitor.INCREMENT;
        this.monitor = monitor;
        bufferValueCounter = 0.0;
        counter = 0;
    }


    public void run(){
        try{
        int in = 0;
        Double currProduced = 0.0;
        Random random = new Random();
        while (counter < VALUES_TO_BE_PRODUCED){
            currProduced = random.nextDouble() * 100.0;

            monitor.aquireEmpty();
            //Add to buffer
            monitor.produce(in, currProduced);
            in = (in + 1) % BUFFER_SIZE;
            monitor.releaseFull();

            bufferValueCounter += currProduced;
            counter++;
            if ((counter % INCREMENT) == 0){
                String statement = String.format("Producer: Generated %,d items,", counter) + String.format(" Cumulative value of generated items=%.3f", bufferValueCounter);
                System.out.println(statement);
            }
        }
        monitor.exit();
    } catch(Exception e){
        e.printStackTrace();
    }
    }
    
}

