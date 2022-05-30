#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;
class node *last = NULL;
class node 
{private:
//<============structure======================>
    int info;
    node *link;
public:
//<=============insertion=====================>
void insert (int item)
{
if(last==NULL)
{
    last = new node;
    last->info = item;
    last->link = last;
}
else 
{
    node *s = last->link;
    last->link = new node;
    last->link->info = item;
    last->link->link = s;
    last = last->link;
}
cout << "\nsuccessful insert!";
}
//<=================deletion====================>


//<================travel=======================>
void travel ()
{
    if (last ==NULL)
    {cout << "\nempty!";}

    else 
    {
        printf("last = %d\n", last->info);
        printf("first = %d", last->link->info);
    }


}
};
void menu ()
{
    cout << "1. insret \n";
    cout << "2. travel";
    cout << "\n3. exit\n";
}
int main()
{
    node k;
    while (1)
    {
        system("cls");
        menu();
        char c;
        c = getch();
        switch(c)
        {
            case '1':
                cout << "\nEnter a number - ";
                int item;
                cin>>item;
                k.insert(item);
                break;
                case '2':
                    k.travel();
                    break;
                    case '3':
                        exit(1);
                    default:
                            cout << "default";
        }
        getch(); //k.insert();
    }   
}