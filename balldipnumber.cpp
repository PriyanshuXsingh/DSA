#include<iostream>
using namespace std;
int numberofdips(int v)
{ int count=0;
 while(v!=0)
 { 
    v=v/2;
    count++;
 }
 return count;
}
int main()
{
    int v;
    cout<<"enter the velocity of a ball ";
    cin>>v;
    int ndip;
    ndip=numberofdips(v);
    cout<<"number of dips is "<<ndip;
    return 0;
}