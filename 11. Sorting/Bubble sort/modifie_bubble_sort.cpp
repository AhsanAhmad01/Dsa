#include<iostream>
#include<conio.h>
using namespace std;



void m_bubble (int arr[] , int n)
{
    bool b = false;
    while (b != true)
{
    b = true;
    for (int x = 0; x < n - 1; x++)
    {
        if (arr[x]>arr[x+1])
        {
            b = false;
            int temp = arr[x];
            arr[x] = arr[x + 1];
            arr[x + 1] = temp;
        }
    }
}



}
void show (int arr[], int n )
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
    show (arr, 10);
    m_bubble(arr, 10);
    cout << "After sorting -";
    show(arr, 10);
    getch();
}