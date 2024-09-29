#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node(int data1){
        data=data1;
        next=NULL;
    }
};
Node*deletionatend(Node*head){
    if(head==NULL||head->next==NULL) {return NULL;}
   Node*temp=head;
   while(temp->next->next!=NULL)
   {
    temp=temp->next;
   }
   free(temp->next);
   temp->next=NULL;
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
int main(){
    Node*head = new Node(1);
    Node*second = new Node(2);
    Node*tail = new Node(3);
    head->next=second;
    second->next=tail;
    cout<<"before deletion"<<endl;
    print(head);
    
    head=deletionatend(head);
    cout<<endl<<"after deletion"<<endl;
    print(head);
    return 0;
}