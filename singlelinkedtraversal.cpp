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
void travers(Node* head){
    Node*ptr=head;
    while(ptr!=NULL){
    
        cout<<"value "<<ptr->data<<endl;
        ptr=ptr->next;
    }
}
int main(){
    Node*head=new Node(4);
    Node*second=new Node(8);
    Node*third=new Node(6);
    Node*tail=new Node(10);
    head->next=second;
    second->next=third;
    third->next=tail;
    travers(head);
}
