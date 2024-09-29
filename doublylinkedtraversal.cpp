#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node*prev;
    Node(int data1)
    {
        data=data1;
        next=NULL;
        prev=NULL;
    }
};
void forwardtrav(Node*head)
{
    Node*ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}
void backwardtrav(Node*tail)
{
    Node*ptr=tail;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->prev;
    }
}
int main()
{
    Node*head = new Node(1);
    Node*second = new Node(2);
    Node*tail = new Node(3);
    head->next=second;
    second->prev=head;
    second->next=tail;
    tail->prev=second;
    cout<<"forward Traversal:";
    forwardtrav(head);
    cout<<endl<<"backward Traversal:";
     backwardtrav(tail);
    
}