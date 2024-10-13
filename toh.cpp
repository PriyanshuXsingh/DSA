#include<bits/stdc++.h>
using namespace std;
static int countt;
void TOH(int n, char from_stick, char aux_stick,char to_stick )
{    
    if(n==1){
        //cout<<"Move dixc "<<n<<"from stick "<<from_stick<<"to "<<to_stick<<endl;
        countt++;
       
    }
    else{
        
        TOH(n-1,from_stick,to_stick,aux_stick);
       // cout<<"Move disc "<<n<<"from stick "<<from_stick<<"to "<<to_stick<<endl;
       countt++;
        TOH(n-1,aux_stick,from_stick,to_stick);
        
        
    }
}
int main()
{
   
    int n;
    cout<<"size:";
    cin>>n;
   for(int i=1;i<=n;i++)
   { countt=0;
    TOH(i,'F','A','T');
    cout<<i<<" "<<countt<<endl;
   }
    return 0;

}