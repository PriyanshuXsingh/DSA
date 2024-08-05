#include<iostream>
using namespace std;
int linearsearch(int arr[],int k)
{
    for(int i=0;i<6;i++)
    {
        if(arr[i]==k)
        return i;
    }
    return -1;

    

}
int main()
{
    int arr[]={8,10,30,16,19,23};
    int k;
    cout<<"Enter the element you want to check";
    cin>>k;
    int r;
    r= linearsearch(arr,k);
    if(r!=-1){
    cout<<"the element is present at index"<<r;
    }
    else{
        cout<<"the element is not found";
    }
    return 0;
}