#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*prev;
    Node*next;
    Node(int data1)
    {
        data=data1;
        next=NULL;
        prev=NULL;
    }
};
Node*insertatfirst(Node*head,int value)
{
  if(head==NULL){
    Node*temp=new Node(value);
    return temp;
  }
  Node*temp=new Node(value);
  temp->next=head;
  head->prev=temp;
  head=temp;
  return head;
}
void print(Node*head)
{
    Node*ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}
Node*insertatpos(Node*head,int pos,int value)
{
    {
    if (pos < 1) {
        cout << "Invalid position!" << endl;
        return head;
    }

    
    if (pos == 1) {        
        Node* temp = new Node(value);
        temp->next = head;
        temp->prev=NULL;
        return temp;
    }

    
    Node* ptr = head;
    int count = 1;
    while (count < pos - 1 && ptr != nullptr) {
        ptr = ptr->next;
        count++;
    }

    
    if (ptr== nullptr) {
        cout << "Invalid position!" << endl;
        return head;
    }

   
    Node* temp = new Node(value);
    temp->next = ptr->next;
    ptr->next->prev=temp;
    ptr->next = temp;
    temp->prev=ptr;

    return head;
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
    cout<<"before inserting:";
    print(head);
   
    cout<<endl<<"after inserting:";
    head= insertatfirst(head,12);
    print(head);

    cout<<endl<<"insertion at position:";
    int pos=3;
    int value=10;
    head=insertatpos(head,pos,value);
    print(head);
    return 0;
}