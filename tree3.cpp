#include<iostream>
using namespace std;
struct node
{
    int data;
    node *left,*right;
};
node* create()
{
    node *newnode=0;
    int x=0;
    newnode=new node();
    cout<<"\nenter the data -1 if you dnt want \n";
    cin>>x;
    if(x==-1)
    {
        return 0;
    }
    newnode->data=x;
    cout<<"\nleft\n";
    newnode->left=create();
    cout<<"\nright\n";
    newnode->right=create();
    return newnode;
}

int family(node *head,int root,int val)
{
    if(head==0)
    {
        return 0;
    }
    if(head->data==val)
    {
        return root;
    }
    int x=family(head->left,head->data,val);
    if(x!=0)
    {
        return x;
    }
    x= family(head->right,head->data,val);
    return x;
}
int flevel(node *root,int data1,int level)
{
    if(root==0)
    {
        return 0;
    }
    if(root->data==data1)
    {
        cout<<"level = "<<level<<"data = "<<data1<<endl;
        return level;
    }
    int downlevel=flevel(root->left,data1,level+1);
    if(downlevel!=0)
    {
        return downlevel;
    }
    downlevel=flevel(root->right,data1,level+1);
    return downlevel;
}

int getlevel(node *root,int data)
{
    return flevel(root,data,1);
}
int main()
{
    node *root=0;
    root=create();
    int level1=getlevel(root,5);
        int level2=getlevel(root,6);
        if(level1!=level2)
        {
            cout<<"false";
        }
        else
        {
            int parent1=family(root,-1,5);
            int parent2=family(root,-1,6);
            cout<<"p1 = "<<parent1<<"p2  = "<<parent2<<endl;
            if(parent1==parent2)
            {
                cout<<"false";
            }
            else
            {
                cout<<"true";
            }


        }
    return 0;
}
