//package HW4;

public class Consumer implements Runnable{

    //Consumer will consume items from the buffer
// if the buffer is empty the consumer must wait
//it will consume all items produced (1,000,000)

Double bufferValueCounter;
int counter;
Monitor monitor;

final int VALUES_TO_BE_PRODUCED = 10;
final int BUFFER_SIZE = 3;

    public Consumer(Monitor monitor){
        this.monitor = monitor;
        bufferValueCounter = 0.0;
        counter = 0;
        System.out.println("Created Consumer");
    }

    public void run(){
        int out = 0;
        Double currConsumed = 0.0;
        while (counter < VALUES_TO_BE_PRODUCED){
            
            System.out.println("start Consumer code");
            monitor.aquireFull();
            monitor.aquireMutex();
            System.out.println("Consumer critical section =" + counter);
            //remove from buffer
            currConsumed = monitor.consume(out);
            out = (out + 1) % BUFFER_SIZE;
            monitor.releaseMutex();
            monitor.releaseEmpty();

            bufferValueCounter += currConsumed;
            counter++;
        }   
    }

}
