#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;

class node *start= NULL;
class node{
private:
//<============structure===================>
    int info;
    node *prev, *next;
public :
//<==============insertion=================>
void insert (int item)
{
    if(start == NULL)
    {
        start = new node;
        start->prev = NULL;
        start->info = item;
        start->next = NULL;
    }
else 
{
    node *c;
    c = start;
    while(c->next!=NULL)
        c = c->next;
    c->next = new node;
    c->next->next = NULL;
    c->next->info = item;
    c->next->prev = c;
}
cout << "\nsucccesful insert";
}
//<===============Deletion==================>
void deletion ()
{
    if(start==NULL)
        cout << "\nempty";
   else if(start->next!=NULL)
{
    node *r= start;
    start = start->next;
    start->prev = NULL;
    delete r;
    cout << "\nsuccesful remove!";
}
else if (start->next==NULL)
{
    delete start;
    start = NULL;
    cout << "\nsuccesful remove!";
}
    else
    {
        cout << "\nEmpty";
    }
}

//<============travel=========================>
void travel ()
{
if(start == NULL)
    cout << "\nlinkedlist is empty!";
else{
node *r;
r = start;
cout << "\nFrom Right ->";
while (1)
    {cout << r->info<< " ";
if(r->next==NULL)
    break;
r = r->next;
}
    cout << "\nFrom left  ->";
    cout << r->info<<" ";
    r = r->prev;
    while(r!=NULL)
    {    cout << r->info<<" ";
    r = r->prev;}

}}
};

void menu ()
{
    cout << "1. insret \n";
    cout << "2. Deletion\n";
    cout << "3. travel";
    cout << "\n4. exit\n";
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
                    k.deletion();
                    break;
                case '3':
                    k.travel();
                    break;
                    case '4':
                        exit(1);
                        default:
                            cout << "default";
        }
        getch(); //k.insert();
    }   
}