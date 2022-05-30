#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;

class ArrayStack {
private:
//<=============structure=================>
int top ;
int *array;
unsigned capacity;
public :
//<==========constructer================>
ArrayStack()
 {
     top = -1;
     capacity = 0;
     array = NULL;
}
//<=============distructor==================>
~ArrayStack()
{
    
    delete array;
    array = NULL;
    
}
void CreateStack(int);
void push(int );
int pop(void );
int peek(void );
bool isEmpty(void);
bool isFull(void);
};
//<=============create stack===========>
void ArrayStack::CreateStack(int capacity)
{
    this->capacity = capacity;
    array = new int[capacity];
}
//<==============is empty===============>
bool ArrayStack::isEmpty ()
{
    if(top==-1)
        return true;
    return false;
}
//<===============is full===============>
bool ArrayStack:: isFull()
{
    if(capacity-1==top)
        return true;
    return false;
}
//<=============push====================>
void ArrayStack::push(int item)
{
    if(!isFull())
    {top++;
    array[top] = item;}
    else
        cout << "\noverflow!\n";
}
//<==============pop=======================>
int ArrayStack::pop()
{

    if(!isEmpty())
    {
        int item = array[top];
        top--;
        return item;
    }
    else
        cout << "\nempty!";
    return -1;
}
//<================main================>
int main()
{
    ArrayStack df;
    df.CreateStack(10);
    for(int i = 1 ; i<=10 ; i++)
        df.push(i);
        df.push(90);
    for (int i = 0; i<10 ; i ++)
        cout<<df.pop() << endl;
        cout<<df.pop() << endl;
getch();
}
