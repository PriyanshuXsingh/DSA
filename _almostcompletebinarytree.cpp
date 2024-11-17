#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node*left;
    node*right;

    //constructor
    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};
void insert(node*&root,int data)
{
    node* newNode = new node(data);
    if(root == NULL){
        root = newNode;
        return;
    }
    queue<node*>q;
    q.push(root);
    
    while(!q.empty())
    {
        node*temp = q.front();
        q.pop();
        
        if(temp ->left ==NULL)
        {
            temp->left = newNode;
            break;
        }
        else{
            q.push(temp->left);
        }
        if(temp->right ==NULL)
        {
            temp->right = newNode;
            break;
        }
        else{
            q.push(temp->right);
        }
    }
}

void levelOrder(node*root)
{
    if(root==NULL)return;
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        node*temp = q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left!=NULL){
        q.push(temp->left);
        }
        if(temp->right!=NULL){
        q.push(temp->right);
        }
    }
}
int main()
{
    node*root = NULL;
    insert(root,1);
    insert(root,2);
    insert(root,3);
    insert(root,4);
    insert(root,5);
    insert(root,6);
    insert(root,7);

    cout<<"level order Traversal:";
    levelOrder(root);
    return 0;
}
