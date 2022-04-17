#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;

class ArrayQueue {
 private:
 //<==============structure==================>
     int rear, front;
     int capacity ;
     int *array;
     public :
 //<============constructor================>
     ArrayQueue()
     {
         array = NULL;
         capacity = 0;
         rear = -1;
         front = -1;
     }
//<================create queue===============>
void create_queue(int capacity )
{
    array = new int[capacity];
    this->capacity = capacity;
}     
//<===================is empty================>
bool is_empty()
{
    if(front==-1)
        return true;
    return false;
}
//<==================is full======================>
bool is_full()
{
    if((rear+1)%capacity ==front)
        return true;
    return false;
}
//<=================en queue=========================>
void enqueue (int item)
{
    if(!is_full())
    {
        rear = (rear + 1) % capacity;
        array[rear] = item;
        if(front==-1)
            front = 0;
    }

    else {
        cout << "\nQueue is full!";
    }
}
//<=================de queue============================>
int dequeue ()
{
    
    if(!is_empty())
    {
        int item = array[front];
        if(rear==front)
            rear = front = -1;
      else{  front = (front + 1) % capacity;}
        return item;
    }
    else
        {cout << "\nQueue is empty! ";
    return -1;}
}
~ArrayQueue()
{
    delete array;
}
};

//<====================main=====================>
int main()
{
    ArrayQueue s;

    s.create_queue(5);
    for (int i = 1; i <= 5; i++)
        s.enqueue(i);
    
    cout << s.dequeue();
    cout << s.dequeue();
     s.enqueue(6);
      s.enqueue(7);
       s.enqueue(8);
       getch();
       for (int i = 0; i<6 ; i++)
           cout<<s.dequeue();
       getch();
}