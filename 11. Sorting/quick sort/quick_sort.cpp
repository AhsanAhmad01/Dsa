#include<iostream>
#include<conio.h>
using namespace std;

int sort(int arr[] , int beg , int end)
{
    int left = beg, right = end ;
    int loc = beg;

    while (1)
    {

while (1)
{
if (arr[loc]<=arr[right])
    right--;
if (loc==right) 
return loc;

if (arr[loc]>arr[right])
{
    int temp = arr[loc];
    arr[loc] = arr[right];
    arr[right] = temp;
    loc = right;
    break;
}


}
while (1)
{
if (arr[loc]>=arr[left])
    left++;
if (loc==left) 
return loc;

if (arr[loc]<arr[left])
{
    int temp = arr[loc];
    arr[loc] = arr[left];
    arr[left] = temp;
    loc = left;
    break;
}


}


  }
    
} 


void quicksort(int arr[] , int l,int h )
{

if (l<h)
{
    int j = sort(arr, l, h);
    quicksort(arr, l, j - 1);
    quicksort(arr, j+1,h);

}

}


int main()
{

    int a[1000];
    int j = 1000;
    for (int x = 0; x < 1000; x++)
        {a[x] = j;
    j--;}
    //quicksort(a, 0, 999);
    for (int x = 0; x < 1000; x++)
        cout << a[x] <<" ";

    getch();
}