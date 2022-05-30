 int find (node *p , int data)
        {
             if(p==NULL)
                 return NULL;
                 if(data>p->info)
                 return (find(p->right, data));
                 else if (data<p->info)
                     return (find(p->left, data));
                 else
                         return (p->info);
        }