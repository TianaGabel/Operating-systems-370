//Bounded buffer. it is FIFO and can only hold 1000 at a time
//This will be implemented as a circular buffer

//Producer will be producing data items to be added to the buffer. It will wait if the buffer is currently full.
//Producer will produce 1,000,000 random items

//Consumer will consume items from the buffer
// if the buffer is empty the consumer must wait
//it will consume all items produced (1,000,000)

//Only wait and notify are allowed

public class Main{
    final static int BUFFER_SIZE = 1000;
    final static int VALUES_TO_BE_PRODUCED = 1000000;
    final static int INCREMENT = 100000;
    public static void main(String[] args){
        
        try {
        Monitor monitor = new Monitor(BUFFER_SIZE, VALUES_TO_BE_PRODUCED, INCREMENT);
        Producer producer = new Producer(monitor);
        Consumer consumer = new Consumer(monitor);
        Thread p = new Thread(producer);
        Thread c = new Thread(consumer);

        p.start();
        c.start();
        }catch (Exception e){
            e.printStackTrace();
        }

    }

}

