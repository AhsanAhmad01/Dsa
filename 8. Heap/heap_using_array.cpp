#include<iostream>
#include<conio.h>
using namespace std;

class heap {
private :
//<===================structure=====================>
    int size;
    int *arr;
    int last;

public:
    //<==================create=======================>
void create (int size)
{
    this->size = size;
    arr = new int[size];
    last = -1;
} 

//<========================insertion======================>
void insert (int data)
{
if(last<size-1)
{
    last++;
    arr[last] = data;
    int l = last;
    while(1)
    {
        
        int p = (l - 1) / 2;
        if(arr[p]<arr[l])
        {
            int temp = arr[p];
            arr[p] = arr[l];
            arr[l] = temp;
        }
        else 
        {
            break;
        }
        l = p;
    }
}

else 
{
    cout << "\nFull!";
}
}
//<=========================show======================>
void show ()
{
if(last>=0)
    {for (int x = 0; x <= last; x++)
    {
        cout << arr[x] << " ";
    }
    }
    else
        cout << "\nempty!";
}
//<=================deletion=========================>
int del ()
{
    int k;

    if (last >= 0)
    {
        int p = 0;
        while (1)
        {
            int c1 = (p * 2) + 1;
            int c2 = (p * 2) + 2;
            if (c2 <= last)
            {
                if (arr[c1] > arr[c2])
                {
                    arr[p] = arr[c1];
                    p = c1;
                }
                else
                {
                    arr[p] = arr[c2];
                    p = c2;
                }
            }
            else if (c1 <= last)
            {
                arr[p] = arr[c1];
                p = c1;
            }
            else
            {
                k = arr[p];
                arr[p] = -1;
                break;
            }
        }
        while (arr[last] != -1)
        {
            if (p != 0)
            {
                arr[p] = arr[p + 1];
                arr[p + 1] = -1;
                p++;
            }
        }

        last--;
        return k;
}
return -1;
}





};

int main()
{

    heap h;
    h.create(10);
    for (int x = 0; x < 10; x++)
    {

        h.insert(rand()%10);
    }
     for (int x = 0; x < 10; x++)
    {

        cout<<h.del()<< "  ";
    }

        h.show();
    getch();
}



