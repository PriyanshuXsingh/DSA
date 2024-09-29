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


Node* insertatpos(Node* head, int pos, int value)
{
    if (pos < 1) {
        cout << "Invalid position!" << endl;
        return head;
    }

    
    if (pos == 1) {        
        Node* temp = new Node(value);
        temp->next = head;
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
    ptr->next = temp;

    return head;
}
void print(Node*head)
{
    Node*curr=head;
    while(curr!=NULL)
    {
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}

int main(){
    Node*head = new Node(4);
    Node*second = new Node(6);
    Node*third = new Node(10);
    Node*tail = new Node(12);
    head->next=second;
    second->next=third;
    third->next=tail;
    cout<<"Before Insertion"<<endl;
    print(head);
    
    int value=6;
    int position=3;
   head= insertatpos(head,position,value);
   cout<<endl<<"after insertion"<<endl;
   print(head);
   return 0;
}