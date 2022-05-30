#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;
class node *root;
class node 
{
    private:
    //<=======================structure=================>
        int info;
        node *left, *right;
        public :
        //<================find========================>
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

 //<==================insertion==================>

void insert (int data)
{
    if(find(root,data))
    {
        cout << "exist";
    }

     else if (root==NULL)
    {
        node *a = new node;
        a->info = data;
        a->left = NULL;
        a->right= NULL;
        root = a;
    }
else
{
node *a = new node;
        a->info = data;
        a->left = NULL;
        a->right= NULL;

        node *p = root;
        while(p!=NULL)
        {
if(p->info<data)
{
  if(p->right==NULL)
  {
    p->right = a;
    p = NULL;
   }
    else
     p = p->right;
}
else 
{
    if(p->left==NULL)
    {
        p->left = a;
        p = NULL;
    }
    else
        p = p->left;
}

        }

}
    
}

//<================Maximum==================>
node * find_max(node *k)
{
    node *r;
    if (k == NULL)
        return NULL;

        else 
        {

           int data= k->info;
           r = k;

           while(k!=NULL)
           {
               if(k->info>data)
               {
                   r = k;
                   data = k->info;
               }
               k = k->right;
           }
           return r;
        }
}

//<=============deletion====================>
node* deletion (node *p , int  data)
{
        if(p==NULL)
        cout << "NO such element exist";
        else if (data<p->info)
            p->left = deletion(p->left, data);
        else if (data>p->info)
            p->right = deletion(p->right, data);
        else {
                  if(p->left &&p->right)  //both  children
                     {
                         node *temp;
                         temp = find_max(p->left);
                         p->info = temp->info;
                         p->left = deletion(p->left, p->info);
                     }

                     else                   // one or none child
                     {
                         node *temp = p;
                         if(p->left==NULL)
                             p = p->right;
                             if(p->right==NULL)
                                 p = p->left;
                             delete temp;

                     }
                     return p;
        }


}
//<====================travel==============>
void inorder(node *a)
{
    if(a!=NULL)
    {
        inorder(a->left);
        cout << a->info<<"\t";
        inorder(a->right);
    }
}
};
//<================main=======================>
int main()
{
    node k;
    for (int a = 10; a > 0; a--)
        k.insert(a);
    cout << "before delete ->  ";
    k.inorder(root);
    getch();
    k.deletion(root , 1);
    cout << "\nAfter delete ->  ";
    k.inorder(root);
}