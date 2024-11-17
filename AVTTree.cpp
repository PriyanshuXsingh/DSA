#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int key;
    Node*left;
    Node*right;
    int height;

    Node(int k)
    {
      key = k;
      left=right=NULL;
      height =1;
    }
};
int height(Node*N)
{
    if(N==NULL) return 0;
    return N->height;
}
int getbalance(Node*N)
{
    return height(N->left)-height(N->right);
}

Node*rightrotate(Node*y){
    Node*x=y->left;
    Node*z=x->right;
    //perform rotation
    x->right=y;
    y->left=z;
    //update height
    y->height = 1+ max(height(y->left),height(y->right));
      x->height = 1 + max(height(x->left), height(x->right));
   //return new node
   return x;
}

Node*leftrotate(Node*y)
{
    Node*x=y->right;
    Node*z=x->left;
    //perform rotation
    x->left=y;
    y->right=z;
    //update new height
    y->height = 1+ max(height(y->left),height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));
    //return new root
    return x;
}

Node*insert(Node*N,int k)
{
    //perform the normal BST insertion
    if(N==NULL) return new Node(k);
    if(k<N->key)
    {
        N->left=insert(N->left,k);
    }
    else if(k>N->key)
    {
        N->right= insert(N->right,k);

    }
    else return N;

    //update height of the ancestor node
    N->height = 1+max(height(N->left),height(N->right));

    //get the balance factor
    int balance = getbalance(N);

    //if the node becomes unbalanced then there are 4 cases
    // left left case 
    if(balance>1 && k < N->left->key) return rightrotate(N);
    //right right case
    if(balance<-1 && k>N->right->key)return leftrotate(N);
    //left right case
    if(balance>1 && k>N->left->key){
        N->left =  leftrotate(N->left);
        return rightrotate(N);
    }
    //right left case
    if(balance<-1 && k<N->right->key){
        N->right =  rightrotate(N->right);
        return leftrotate(N);
    }
  return N;
}

Node*deletenode(Node*N,int k)
{
    if(N==NULL)return N;

    if(k<N->key){
        N->left=deletenode(N->left,k);
    }
    else if(k>N->key){
       N->right = deletenode(N->right,k);
    }
    else{
        //case 1 if Leaf Node
        if(N->left==NULL&&N->right==NULL){
            delete(N);
            return NULL;
        }
        //case 2 only one chile exist
        else if(N->left!=NULL&&N->right==NULL)
        {
            Node*temp = N->left;
            delete(N);
            return temp;
        }
        else if(N->left==NULL&&N->right!=NULL)
        {
            Node*temp = N->right;
            delete(N);
            return temp;
        }
        //Case 3 both child exists
        else{
            //right side smallest element

            Node*curr = N->right;
            while(curr->left!=NULL)
            {
                curr = curr->left;
            }
            N->key = curr->key;
           N->right = deletenode(N->right,curr->key);
        }
    }
    
    //update height
    N->height = 1+max(height(N->left),height(N->right));
    //check the balance
    int balance = getbalance(N);
   //if the node becomes unbalanced 
   //left side
   if(balance>1)
   {
    //LL
    if(getbalance(N->left)>=0) return rightrotate(N);
    //LR
    else{
        N->left = leftrotate(N->left);
        return rightrotate(N);
    }
   }
   //right side
   else if(balance<-1)
   {
      //RR
      if(getbalance(N->right)<=0) return leftrotate(N);
      //RL
     else{
        N->right = rightrotate(N->right);
        return leftrotate(N);
      }
   }
   else
       return N;
}
void InOrder(Node*N)
{
    if(N==NULL)return;
    
    InOrder(N->left);
    cout<<N->key<<" ";
    InOrder(N->right);
}
int main()
{
    Node*root=NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    cout << "InOrder: ";
    InOrder(root);

    root = deletenode(root,40);
    cout << "\nInOrder: ";
    InOrder(root);
    root = deletenode(root,30);
     cout << "\nInOrder: ";
    InOrder(root);
    return 0;
}
