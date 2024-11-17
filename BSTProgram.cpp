#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data1) {
        data = data1;
        left = right = NULL;
    }
};

Node* insert(Node* root, int data) {
    if (root == NULL) {
        return new Node(data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

Node*deletenode(Node*root,int data)
{
    if(root==NULL)return NULL;
    else if(data<root->data){
        root->left = deletenode(root->left,data);
    }
    else if(data>root->data){
        root->right = deletenode(root->right,data);
    }
    else{
        //case 1 No child
        if(root->left==NULL &&root->right==NULL){
            delete(root);
            return NULL;
        }
        //case 2 single child
        //case 2a if only left child is present
        else if(root->left!=NULL&&root->right==NULL)
        {
            Node*temp = root;
            root = root->left;
            delete temp;
            return root;
        }
        //case 2b if only right child is present
        else if(root->left==NULL&&root->right!=NULL)
        {
            Node*temp = root;
            root = root->right;
            delete temp;
            return root;
        }
        //case 3 if both child is present
        else{
            Node*curr = root->right;
            while(curr->left!=NULL)
            {
                curr = curr->left;
            }
            root->data = curr->data;
            root->right = deletenode(root->right,curr->data);
            
        }
       
    }
    return root;
}

void preorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void levelorder(Node*root){
    if(root==NULL)return ;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node*curr=q.front();
        cout<<curr->data<<" ";
        if(curr->left!=NULL) q.push(curr->left);
        if(curr->right!=NULL) q.push(curr->right);
        q.pop();
    }
}

int main() {
    Node* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Preorder Traversal: ";
    preorder(root);

    cout << endl << "Postorder Traversal: ";
    postorder(root);

    cout << endl << "Inorder Traversal: ";
    inorder(root);

    cout<<endl<<"LevelOrder Traversal:";
    levelorder(root);
    root = deletenode(root,25);
     cout<<endl<<"LevelOrder Traversal:";
    levelorder(root);
    root = deletenode(root,20);
     cout<<endl<<"LevelOrder Traversal:";
    levelorder(root);

    return 0;
}
