#include<iostream>
#include<conio.h>
using namespace std;

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



//<########################binary tree##########################>
class node *root;
class node 
{
    private:
    //<============structure===========================>
        int info;
        node *left, *right;

    public:
    //<===============my input=================>
    void my_input()
{
   root = new node;
        root->info = 1;
        root->left = new node;
        root->left->info = 2;
        root->right = new node;
        root->right->info = 3;
        root->left->left = new node;
        root->left->left->info = 4;
        root->left->left->left = NULL;
        root->left->left->right = NULL;
        root->left->right = new node;
        root->left->right->info = 5;
        root->left->right->left = NULL;
        root->left->right->right = NULL;
        
        root->right->left = new node;
        root->right->left->info = 6;
        root->right->left->left = NULL;
        root->right->left->right = NULL;
        root->right->right = new node;
        root->right->right->info = 7;
        root->right->right->left = NULL;
        root->right->right->right = NULL;
}

//<==========level order traversal===================>
void level_order ()
{
    ArrayQueue q;
    node *temp;
    q.create_queue(5);
    if(root!=NULL)
    {
        q.enqueue(root);
        while(!q.is_empty())
        {
            temp = q.dequeue();
            cout << temp->info;
            if(temp->left)
                q.enqueue(temp->left);
            if(temp->right)
                q.enqueue(temp->right);

        }
    }

}


};


int main()
{
    node k;
    k.my_input();
    cout << "level order traversal -> ";
    k.level_order();
getch();
}