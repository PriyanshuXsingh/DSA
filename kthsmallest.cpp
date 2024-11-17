#include<bits/stdc++.h>
using namespace std;
int partition( int arr[], int low, int high) {
     int pivot = arr[low];
     int i = low;
    int m = high;

    while (i < m) {
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }

        while (arr[m] > pivot && m >= low + 1) {
            m--;
        }
        if (i < m) swap(arr[i], arr[m]);
    }
    swap(arr[low], arr[m]);
    return m;
}
int select(int arr[],int low,int high,int k)
{
    if(low==high)return arr[low];
    else{
    int j=partition(arr,low,high);
    if(j==k){
       return arr[k];
    }
    else if(k>j){
           return select(arr,j+1,high,k);
        }
        else
           return select(arr,low,j-1,k);
        
    }
}


int main()
{
    int n;
    cout<<"give a size of an array:";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int k;
    cout<<"give K:";
    cin>>k;
    if(k>0&&k<=n){
    int r=select(arr,0,n-1,k-1);
    cout<<k<<"_smallest integer is:"<<r;
    }
    else{
        cout<<k<<"is out of bound";
    }
    return 0;

}