#include<iostream>
#include<conio.h>
using namespace std;
bubble_sort (int arr[] , int n )
{
    for (int x = 1; x < n; x++)
    {

        for (int i = 0; i<n-1 ; i++)
        {
            if (arr[i]>arr[i+1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
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
    int arr[10];
    cout << "Enter any 10 number ";
    for (int x = 0; x < 10; x++)
        cin >> arr[x];

    cout << "before sorting -";
    show(arr, 10);
    bubble_sort(arr, 10);
    cout << "After sorting -";
    show(arr, 10);
    getch();
}