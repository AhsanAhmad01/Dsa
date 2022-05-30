#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
class node;
//<#####################queue#######################>
class ArrayQueue {
 private:
 //<==============structure==================>
     int rear, front;
     int capacity ;
     node  **array;
     public :
 //<============constructor================>
     ArrayQueue()
     {
         array = NULL;
         capacity = 0;
         rear = -1;
         front = -1;
     }
//<================create queue===============>
void create_queue(int capacity )
{
    array = new node * [capacity];
    this->capacity = capacity;
}     
//<===================is empty================>
bool is_empty()
{
    if(front==-1)
        return true;
    return false;
}
//<==================is full======================>
bool is_full()
{
    if((rear+1)%capacity ==front)
        return true;
    return false;
}
//<=================en queue=========================>
void enqueue (node *item)
{
    if(!is_full())
    {
        rear = (rear + 1) % capacity;
        array[rear] = item;
        if(front==-1)
            front = 0;
    }

    else {
        cout << "\nQueue is full!";
    }
}
//<=================de queue============================>
node*  dequeue ()
{
    
    if(!is_empty())
    {
        node  *item = array[front];
        if(rear==front)
            rear = front = -1;
      else{  front = (front + 1) % capacity;}
        return item;
    }
    else
        {cout << "\nQueue is empty! ";
    return NULL;}
}
~ArrayQueue()
{
    delete array;
}
};



//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$


class node *root = NULL;

class node {
private:
//<========================structure============================>
    int info;
    node *left;
    node *right;

    public:
//<======================travel=================================>
void  preorder(node *n )
{
    if (n!=NULL)
    {
        
        preorder(n->left);
        preorder(n->right);
        cout << n->info << "  ";
    }
}


//<==========level order traversal===================>
void level_order ()
{
    ArrayQueue q;
    node *temp;
    q.create_queue(5);
    if(root!=NULL)
    {
        int no = 1;
        q.enqueue(root);
        while(!q.is_empty())
        {
            cout << no;
            temp = q.dequeue();
            cout << temp->info;
            if(temp->left)
                {q.enqueue(temp->left);
                    no++;
                }
            if(temp->right)
            {    q.enqueue(temp->right);
                no++;
            }
        }
    }

}
//<====================for rotation=====================>

//<==================finde blanace factor==============>
int BF (node *p )
{

    int left = 0, right = 0;
    node *c = p;

    while (c!=NULL)
    {
        c = c->left;

        if (c != NULL)
            left++;
    }
    c = p;

    while (c!=NULL)
    {
        c = c->left;

        if (c != NULL)
            right++;
    }
    return (left - right);
}
//<===========find type of rotation=========================>
int find_rtype (node *p , int  data)
{
    
        if(p->left->left->info == data)  //for LL
            return 1;
     if(p->right->right->info == data)  //for RR
            return 2;
             if(p->left->right->info == data)  //for LR
            return 3;
     if(p->right->left->info == data)  //for RL
            return 4;



}
//<=================rotation================>
void rotation (node *a , int c)
{
    if (c==1)
    {
        int a3 = a->left->left->info;
        node *r = a->left->left;
        a->left->left = NULL;
        delete r;
        int temp = a->info;
        a->info = a->left->info;
        a->left->info = temp;
        a->right = new node;
        a->right->info = a3;
        a->right->left = NULL;
        a->right->info = NULL;

    }


    else if (c==2)
    {
int a3 = a->right->right->info;
        node *r = a->right->right;
        a->right->right = NULL;
        delete r;
        int temp = a->info;
        a->info = a->right->info;
        a->right->info = a3;

        a->left = new node;
        a->left->info = temp;
        a->right->left = NULL;
        a->right->info = NULL;


    }
}


//<===================insertion====================================>
void insert (int data)
{

if(root ==NULL)
{ root = new node;
root->info = data;
root->left = NULL;
root->right = NULL;
}

else 
{
    node *add = new node;
    add->info = data;
    add->left = NULL;
    add->right= NULL;
    node *p = root;
    node *A = NULL, *B = NULL, *C = NULL;
    C = p;
    while (1)
    {

if(p->info==data)
    return;
    else if(p->info<data)
    {
        if(p->right==NULL)
            {p->right = add;
                p = p->right;
            }
            else
                p = p->right;
    }

    else
    {
 if(p->left==NULL)
            {p->left = add;
                p = p->left;
            }
            else
                p = p->left;
    }
    A = B;
    B = C;
    C = p;
    if (p == add)
        break;
}
if(A!=NULL)
{

    int bf=BF(A);
    if(bf<-1&&bf>1)
    {
       int rt= find_rtype(A,data);
       switch (rt)
       {
case 1 :
    rotation(A ,1);
    break;
    case 2 :
    rotation(A ,1);
    break;
    case 3 :
    rotation(A ,1);
    break;
    case 4 :
    rotation(A ,1);
    break;
       }
    }
}


}
}

void find2(int n)
{
    node *k = find(root, n);
    cout << "k =" << k << " no = " << k->info<<" ";
}
 node * find (node *p , int data)
        {
             if(p==NULL)
                 return NULL;
                 if(data>p->info)
                 return (find(p->right, data));
                 else if (data<p->info)
                     return (find(p->left, data));
                 else
                     return p;
        }
};

void menu ()
{
    cout << "1.add\n2.show\n3.exit\n\nenter - ";
}
int main()
{
node m;
    int n;
    cout << "(special)enter a number ";
    cin >> n;
    cout << "\nPress enter for " << n << "input ";
    getch();
    for (int x = 1; x <= n;x++)
        m.insert(x);
    cout << "\nEntry complited";

    cout << "\npress enter for seching ";
    getch();
     m.find2(n);
    cout << "seching completed  ";
    getch();
}