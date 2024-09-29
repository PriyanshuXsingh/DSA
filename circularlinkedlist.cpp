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




// Function to insert a node at a specific position in a circular linked list
Node *insertAtPosition(Node *tail, int data, int pos){
    if (tail == nullptr){
        // If the list is empty
        if (pos != 1){
            cout << "Invalid position!" << endl;
            return tail;
        }
        // Create a new node and make it point to itself
        Node *newNode = new Node(data);
        tail = newNode;
        tail->next = tail;
        return tail;
    }

    // Create a new node with the given data
    Node *newNode = new Node(data);

    // curr will point to head initially
    Node *curr = tail->next;

    if (pos == 1){
        // Insert at the beginning
        newNode->next = curr;
        tail->next = newNode;
        return tail;
    }

    // Traverse the list to find the insertion point
    for (int i = 1; i < pos - 1; ++i) {
        curr = curr->next;
      
        // If position is out of bounds
        if (curr == tail->next){
            cout << "Invalid position!" << endl;
            return tail;
        }
    }
    // Insert the new node at the desired position
    newNode->next = curr->next;
    curr->next = newNode;

    // Update last if the new node is inserted at the end
    if (curr == tail) tail = newNode;

    return tail;
}

void printList(Node *tail){
    if (tail == NULL) return;

    Node *head = tail->next;
    while (true){
        cout << head->data << " ";
        head = head->next;
        if (head == tail->next) break;
    }
    cout << endl;
}
int main()
{
     Node*head = new Node(4);
    Node*second = new Node(6);
    Node*third = new Node(10);
    Node*tail = new Node(12);
    head->next=second;
    second->next=third;
    third->next=tail;
    tail->next=head;
    cout << "Original list: ";
    printList(tail);
// Insert elements at specific positions
    int data = 5, pos = 2;
    tail = insertAtPosition(tail, data, pos);
    cout << "List after insertions: ";
    printList(tail);

}