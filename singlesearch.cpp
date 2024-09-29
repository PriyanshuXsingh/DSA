#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node(int data1)
    {
        data=data1;
        next=NULL;
    }

};

 bool searchelement(Node*head,int key){
    Node*ptr=head;
    while(ptr!=NULL){
        if(ptr->data==key){
            return true;
        }
        ptr=ptr->next;
        }
        return false;
    }


int main()
{
    Node*head=new Node(4);
    Node*second=new Node(8);
    Node*third=new Node(6);
    Node*tail=new Node(10);
    head->next=second;
    second->next=third;
    third->next=tail;
    int key=6;
    searchelement(head,6);
    return 0;
}