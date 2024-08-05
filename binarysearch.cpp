#include<iostream>
using namespace std;
int binarysearch(int arr[],int low, int high,int k)
{
    int mid;
    mid=(high-low)/2;
    while(low<=high){
        if(arr[mid]==k)
        {
            return mid;
        }
        else if(arr[mid]>=k)
        {
            return low=mid-1;
        }
        else {
            return high=mid+1;
        }

    }
    return -1;
}



int main()
{
    int arr[]={2,5,7,10,15,74};
    int k,r;
    cout<<"enter the element you want to search ";
    cin>>k;
    int  low=0;
    int high=5;
    r= binarysearch(arr,low,high,k);
    if( r!=-1)
    {
        cout<<"element is present at index"<<r;
    }
    else{
        cout<<"element is not found";
    }
    return 0;
    
}