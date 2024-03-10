//package HW4;

public class Consumer implements Runnable{

    //Consumer will consume items from the buffer
// if the buffer is empty the consumer must wait
//it will consume all items produced (1,000,000)

int bufferValueCounter;
int counter;
Monitor monitor;

    public Consumer(Monitor monitor){
        this.monitor = monitor;
        bufferValueCounter = 0;
        counter = 0;
    }

    public void run(){
        while (counter < 1000000){
            int currValue = 0;

            monitor.aquireFull();
            monitor.aquireMutex();
            //Add to buffer
            monitor.releaseMutex();
            monitor.releaseEmpty();

            bufferValueCounter += currValue;
            counter++;
        }   
    }

}
