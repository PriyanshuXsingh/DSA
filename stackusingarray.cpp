#include<bits/stdc++.h>
using namespace std;
class mystack{
    public:
    int *arr;
    int top;
    int size;

    void push(int x)
    {
        if(top>size-1){
            cout<<"stack overflow";
        }
        arr[top++]=x;
        cout<<x<<" is pushed"<<endl;

    }

};
int main()
{
    mystack s;
    s.size = 10;
    s.top = -1;
    s.push(10);
    s.push(20);
    s.push(30);
    return 0;

}