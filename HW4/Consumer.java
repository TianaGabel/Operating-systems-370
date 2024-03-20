//package HW4;

public class Consumer implements Runnable{

    //Consumer will consume items from the buffer
// if the buffer is empty the consumer must wait
//it will consume all items produced (1,000,000)

Double bufferValueCounter;
int counter;
Monitor monitor;

final int VALUES_TO_BE_PRODUCED;
final int BUFFER_SIZE;
final int INCREMENT;

    public Consumer(Monitor monitor){
        BUFFER_SIZE = monitor.BUFFER_SIZE;
        VALUES_TO_BE_PRODUCED = monitor.VALUES_TO_BE_PRODUCED;
        INCREMENT = monitor.INCREMENT;
        this.monitor = monitor;
        bufferValueCounter = 0.0;
        counter = 0;
    }

    public void run(){
        try{
        int out = 0;
        Double currConsumed = 0.0;
        while (counter < VALUES_TO_BE_PRODUCED){
            
            //System.out.println("start Consumer code");
            monitor.aquireFull();
            //System.out.println("Consumer critical section =" + counter);
            //remove from buffer
            currConsumed = monitor.consume(out);
            out = (out + 1) % BUFFER_SIZE;
            monitor.releaseEmpty();

            bufferValueCounter += currConsumed;
            counter++;
            if ((counter % INCREMENT) == 0){
                String statement = String.format("Consumer: Consumed %,d items,", counter) + String.format(" Cumulative value of consumed items=%.3f", bufferValueCounter);
                System.out.println(statement);
            }
        }  
        monitor.exit();
    }catch (Exception e){
        e.printStackTrace();
    }
    }

}
