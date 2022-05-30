#include<iostream>
#include<windows.h>
#include<conio.h>
#include<stdio.h>
using namespace std;
class node *start;
class node {
    private:
//<===============structure================>
int info;
node *link;
public:
    
    //<===============insertion==============>
    void insert(int item)
    {

        node *n = new node;
        n->info = item;
        n->link = NULL;

        if (start == NULL)
            start = n;
        else
        {
            node *t = start;
            while (t->link != NULL)
            {
                t = t->link;
            }
            t->link = n;
        }



}
//<==============Deletion===================>
void deletion ()
{
    node *r;
    if(start==NULL)
        cout << "\n empty!";
  else{  r = start;
    start = start->link;
    delete r;
        cout << "succesful remove!";
    }
}
//<=====================travel==========================>

void travel ()
{
   node  *p = start;
   if(p==NULL)
       cout << "\n empty";
       else{
           cout << "\nData - ";
           while (p != NULL)
           {
               cout << p->info << "\t";
               p = p->link;
        }}
        //getch();
}
//<================remove item==============>
void deletion(int item)
{
    node *p = start;
    bool b = true;
    if(p!=NULL)
{
    if(p->link==NULL&&p->info==item)
    {
        delete start;
        start = NULL;
        b = false;
    }
    else if (p->info==item)
    {
        node *r = start;
        start = start->link;
        delete r;
    }

    else  {
        while(p->link!=NULL)
        {
            if(p->link->info==item)
            {
                node *r = p->link;
                p->link = p->link->link;
                delete r;
                b = false;
                break;
            }
            p = p->link;
        }
    }
}
if(b==true)
{
    cout << "not in the list";
}
    


    
}
//<================structure=================>
void structure ()
{

    if(start == NULL)
    {
        cout << "\n\nNULL(start)";
    }
    else 
    {
node *p=start;
cout <<"\n\n"<<p<<"(start)\n    |\n    |\n  ";
while(p->link!=NULL)
{
    
    cout <<"  ----->  |"<<p->info << "," << p->link<<"|";
    p = p->link;
} 

cout <<"  ---->  |"<<p->info<< "," <<"NULL|";

    }
}

};
//<================menu==========================>
void menu()
{
    cout << "1. add \n2. remove\n3. travel \n4. removeitem\n5. structure\n6. exit\n\nchoice - ";
}
int main()
{
    node k;
    while(1)
    {
        system("cls");
        menu();
        char c;
        c = getch();
        switch (c)
        {
        case '1':
            cout << "\nenter a number - ";
            int item;
            cin >> item;
            k.insert(item);
            cout << "succesful insert!";
            break;

        case '2' :
            k.deletion();
        break;
        case '3' :
            

            k.travel();
            break;
            case '4':
                int i;
                cout << "\nEnter a number from ";
                k.travel();
                cout << "\n-";
                cin >> i;
                k.deletion(i);
                break;
                case '5':
                    k.structure();
                    break;
            case '6':
                exit(1);
            default:
                cout << "";

}
getch();
}
}
