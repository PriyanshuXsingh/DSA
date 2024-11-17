#include<bits/stdc++.h>
using namespace std;
class Queue{
    int *arr;
    int front;
    int rear;
    int size;
    public:
    Queue()
    {
        front =rear=-1;
        size =6;
        arr = new int[size];
    }
    void Enqueue(int x)
    {
        if(rear==size-1){
            cout<<"\nQueue is Full\n";
        }
        else if(front==-1&&rear==-1)
       {
        front=rear=0;
       }
       else{
        rear=rear+1;
       }
       arr[rear]=x;
    }
   int Dequeue()
   {
    if(front==-1&&rear==-1)
    {
        return -1;
    }
    int n= arr[front];
    if(front==rear)
    {
        front=rear=-1;
    }
    else{
        front=front+1;
    }
    return n;
   }
   int Front()
   {
        if(front==-1&&rear==-1) {
            cout << "Queue is empty\n";
            return -1;
        }
        else{
            return arr[front];
        }
   }
   void print_queue(){
    queue<int>temp;
    for(int i=1;i<size;i++)
    {
        cout<<q.front()<<endl;
        temp.push(q.front());
        q.pop();
    }
   }

};
int main()
{
     Queue q;
    q.Enqueue(4);
    q.Enqueue(2);
    q.Enqueue(9);
    q.Enqueue(3);
    q.Enqueue(7);
    cout<<"the front of the queue before deleting any element:"<<q.Front()<<endl;
   cout<<"first element dequeued is:" <<q.Dequeue()<<endl;
    q.Enqueue(4);
   cout<<"second element dequeued is:" <<q.Dequeue()<<endl;
    cout<<"front of the queue is:"<<q.Front();
    q.Enqueue(11);
    q.Enqueue(12);
    q.Enqueue(13);
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    
   
    return 0;
}