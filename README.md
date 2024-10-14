-->Tower of Honoi<--
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
-->Graph
![Screenshot 2024-10-13 194516](https://github.com/user-attachments/assets/ec5f30a3-893b-46ed-9c12-1fd27721fd9b)








//insertionsort
import matplotlib.pyplot as plt

# Data from the user
sizes = [10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000]
times = [0.035001, 0.142872, 0.329429, 0.573246, 0.872879, 1.25313, 1.87922, 2.34296, 2.85134, 3.46669]

# Plotting the graph
plt.figure(figsize=(10,6))
plt.plot(sizes, times, marker='o', color='b', label='Insertion Sort Time')
plt.title('Insertion Sort Time Complexity')
plt.xlabel('Array Size')
plt.ylabel('Time (seconds)')
plt.grid(True)
plt.legend()
plt.tight_layout()

# Display the plot
plt.show()

![Screenshot 2024-10-14 104050](https://github.com/user-attachments/assets/9cb8f36f-b108-4c58-b3d6-f3f8b5e2c03a)




