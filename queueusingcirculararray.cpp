#include<iostream>
using namespace std;
class queue{
    int *arr;
    int front;
    int rear;
    int size;
    public:
    queue()
    {
        front=rear=-1;
        size=6;
        arr=new int[size];
    }
    bool IsEmpty()
    {
        if(front==-1&&rear==-1) return true;
        return false;
    }
    void Enqueue(int x)
    {
        if((rear+1)%size==front){
            cout<<"\nQueue is full";
        }
        else if(IsEmpty()){
            front=rear=0;
    }
    else{
        rear=rear+1;
    }
    arr[rear]=x;
    }
    int Dequeue()
    {
        if (IsEmpty()) {
            cout << "\nQueue is empty\n";
            return -1;
        }
         int val= arr[front];
         if(front==rear)
        {
            front=rear=-1;
            
        }
        else{
            front=(front+1)%size;
           
           
        }
         return val;
        
    }
    int Front() {  // Function renamed to Front
        if (!IsEmpty())
            return arr[front];
        else {
            cout << "Queue is empty\n";
            return -1;
        }
    }
};
int main()
{
    queue q;
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