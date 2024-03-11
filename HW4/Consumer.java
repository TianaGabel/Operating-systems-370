//package HW4;

public class Consumer implements Runnable{

    //Consumer will consume items from the buffer
// if the buffer is empty the consumer must wait
//it will consume all items produced (1,000,000)

int bufferValueCounter;
int counter;
Monitor monitor;
final int VALUES_TO_BE_PRODUCED = 10;

    public Consumer(Monitor monitor){
        this.monitor = monitor;
        bufferValueCounter = 0;
        counter = 0;
        System.out.println("Created Consumer");
    }

    public void run(){
        while (counter < VALUES_TO_BE_PRODUCED){
            int currValue = 0;
            try {
            System.out.println("start Consumer code");
            monitor.aquireFull();
            monitor.aquireMutex();
            System.out.println("Consumer critical section =" + counter);
            //Add to buffer
            monitor.releaseMutex();
            monitor.releaseEmpty();
            } catch (Exception e){
                System.out.println("Threw and exception");
                e.printStackTrace();
            }

            bufferValueCounter += currValue;
            counter++;
        }   
    }

}
