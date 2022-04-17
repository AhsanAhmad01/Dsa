#include<iostream>
#include<conio.h>
using namespace std;
//in c++ we have a string class 
int main()
{
//<=====Declaration==============>
 string  str ="hello world";
cout<<str;
getch();
//<============getline==========>
cout << "\n enter in line ";
getline(cin,str);//for input
cout<<"\nafter getline "<<str;
getch();
//<===========push_back==========>
str.push_back('.');//input a character end of string
cout<<"\nafter push back a dot "<<str;
getch();
//<===========pop_back===========>
str.pop_back();//for remove last charcter
cout<<"\nAfter remove last charcter "<<str;    
getch();
//<============capacity============>
cout<<"\ncapacity = "<<str.capacity();
getch();
//<===========resize================>
str.resize(100);
cout<<"\nafter resize 100 capicity = "<<str.capacity();
getch();
//<==========lenght==================>
cout<<"\n str = "<<str<<"\t , length = "<<str.length();
getch();
//<===========swap================>
string ptr = "ahsan ahmad";
cout << "\nbefore swaping with ptr \nstr = " << str << "\nptr = " << ptr;
getch();
swap(str, ptr);
cout << "\nAfter swaping with ptr \nstr = " << str << "\nptr = " << ptr;
getch();
}
