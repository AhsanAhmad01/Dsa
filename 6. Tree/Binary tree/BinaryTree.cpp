#include<iostream>
#include<conio.h>
using namespace std;
class  node *root;
class node 
{
private:
//<====================structure===============>
    int info;
    node *left, *right;
    public:
    //<==========my input in tree=====================>
    void  youinput()
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

//<=============preorder travelsion==============>
void preorder (node *a)
{
    if(a!=NULL)
        {cout << a->info;
            preorder(a->left);
            preorder(a->right);
        }

}
//<===================inorder travelsion================>
void inorder (node *a)
{

    if(a!=NULL)
    {
    inorder(a->left);
        cout << a->info;
        inorder(a->right);
    }
}

//<===================postorder travelsion================>
void postorder (node *a)
{

    if(a!=NULL)
    {
        postorder(a->left);
        postorder(a->right);
        cout << a->info;

    }
}
};

//<===============================main==========================>
int main()
{
    node k;
    k.youinput();
    cout << "preorder traversal -> ";
    k.preorder(root);
    cout << "\ninorder traversal -> ";
    k.inorder(root);
    cout << "\nposteorder traversal -> ";
    k.postorder(root);
    getch();
}