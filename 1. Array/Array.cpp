#include<iostream>
#include<conio.h>
using namespace std;


int main()
{
//Array declaration
int a[5];    //we get 5 memory block of int type (n=5)

a[0] = 1; //where a=base address then a[0]=a+0
a[2] = 4; //where a=base address then a[0]=a+2

//a(base address)=1000 then a[2] =a+2  =1000+2*int(4)  =1008;

//one dimension array
int k[8];  //n = 8
//two dimension array
int t[4][2]; //n =8
}