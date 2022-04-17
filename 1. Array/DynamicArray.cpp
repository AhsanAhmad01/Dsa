#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;

class dynamic_array {
private :
 //<=============structure==================>
int *arr;
int cap;
int count;
public:
//<============constructor===================>
 dynamic_array ()
 {
  *arr =NULL;
  cap=0;
   count =-1;
 }
//<============grow size=====================>
void grow_size ()
{


  if(cap==0)
{cap=1;
   arr = new int [cap];
    }
   else
   {

    cap=cap*2;

   int *carray= new int [cap];
   for(int i = 0 ; i<=count;i++)
  carray[i] = arr[i];
  for(int i =count+1;i<cap;i++)
   carray[i]=0;
delete arr;
  arr = carray;
//  carray=NULL;
   }
 }
 //<==========shrink size====================>
 void shrink_size ()
 {
  cap=cap/2;
  int *carray = new int [cap];
  for(int i = 0 ;i<=count;i++ )
  {
   carray[i]=arr[i];
  }
  for(int i =count+1 ; i<cap;i++)
  {
   carray[i]=0;
  }
  delete arr;
  arr=carray;

 }
 //<==========add element====================>
 void add_element(int iteam)
 {
if((count+1)==cap)
  this->grow_size();
  count++;

  arr[count]=iteam;
 }
 void  show ()
 {
  for(int i = 0 ; i<=count; i++)
   cout<<arr[i]<<", ";
 }


 //<============remove element=================>
 void remove_element ()
 {
  if(count>=0)
  {arr[count]=0;
  count =count-1;
  if((count+1)<=(cap/2))
  {
  this->shrink_size();
  }
 }
 }
 //<============removeat_element===============>
 void removeat_element(int index)
 {
  if(index>=0&&index<=count)
{
 arr[index]=0;
 count=count-1;
 for(int i = index ; i<=count ; i++)
 {
 arr[i]=arr[i+1];
 }
  if((count+1)<=(cap/2))
  {
  this->shrink_size();
  }


}
 }
 //<==============capacity=====================>
 int capacity()
 {
  return (cap);
 }
 //<==============element=======================>
 int element ()
 {
  return (count+1);
 }

 //<=============distructor=====================>


};

int main()
{
 dynamic_array a;
a.add_element(1);
a.add_element(2);
a.add_element(3);
a.add_element(3);
a.removeat_element(0);
a.removeat_element(0);
a.removeat_element(0);
cout<<"capacity = ";
cout<<a.capacity();
cout<<"\no of element = ";
cout<<a.element();
cout<<"\nelement is = ";
a.show();
getch();

}
