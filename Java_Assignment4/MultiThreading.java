import java.util.*;
class A
{
      private int materials;
      private boolean available = false;
      public synchronized int get()
      {
            while (available == false)
            {
                  try
                  {
                        wait();
                  }
                  catch (InterruptedException ie)
                  {
                  }
            }
            available = false;
            notify();
            return materials;
      }
      public synchronized void put(int value)
      {
            while (available == true)
            {
                  try
                  {
                        wait();
                  }
                  catch (Exception e)
                  {
                        e.printStackTrace();
                  }
            }
            materials = value;
            available = true;
            notify();
      }
}
class Consumer extends Thread
{
      private A Shop;
      private int number;
      public Consumer(A a, int number)
      {
            Shop = a;
            this.number = number;
      }
      public void run()
      {
            int value = 0;
            for (int i = 0; i < 10; i++)
            {
                  value = Shop.get();
                  System.out.println("Value Consumed : " + value);
            }
      }
}
class Producer extends Thread
{
      private A Shop;
      private int number;

      public Producer(A a, int number)
      {
            Shop = a;
            this.number = number;
      }
      public void run()
      {
            for (int j = 0; j < 10; j++)
            {
            	Random rand=new Random();
            	int i=rand.nextInt(100);
                  Shop.put(i);
                  System.out.println("Value Produced : "+ i);
                  try
                  {
                        sleep((int)(Math.random() * 100));
                  }
                  catch (Exception e)
                  {
                        e.printStackTrace();
                  }
            }
      }
}
public class MultiThreading
{
      public static void main(String[] args)
      {
            A a = new A();
            Producer p1 = new Producer(a, 1);
            Consumer c1 = new Consumer(a, 1);
            p1.start();
            c1.start();
      }
}

