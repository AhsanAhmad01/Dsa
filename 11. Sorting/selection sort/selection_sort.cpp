#include<iostream>
#include<conio.h>
using namespace std;

int min (int arr[] , int n, int k)
{
int min = arr[k];
int index = k;

for (int i = k ; i<n ; i++)
{
if(min>arr[i])
{
min = arr[i];
index = i;
}
}
return index;
}

//<=================sorting===========================>

void sort (int arr[] , int n )
{

for (int i = 0 ; i<n-1 ; i++)
{
int index = min (arr, n , i );
int temp = arr[index];
arr[index]= arr[i];
arr[i] = temp;


}

}



show (int arr[], int n )
{
    cout << "\n";
    for (int x = 0; x < n; x++)
        cout << arr[x] << "  ";
}
int main ()
{
    int arr[100000];
    int num = 100000;
    cout << "Enter any 10 number ";
    for (int x = 0; x <100000; x++)
        {arr[x] = num;
            num--;
        }

    //cout << "before sorting -";
    //show(arr, 100000);
   sort(arr, 100000);
    cout << "After sorting -";
    show(arr, 100000);
    getch();
}