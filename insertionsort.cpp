#include<bits/stdc++.h>
#include <chrono>
using namespace std;
void insertionSort( long int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int key=arr[i];
        int j=i-1;
        while(arr[j]>key&&j>=0)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    
}
int main()
{
   long int n = 10000; 
    int it = 0; 
  
    // Arrays to store time duration 
    // of sorting algorithms 
    double  time[10]; 
    // // Seed the random number generator
    //  srand(time(0));

  
    cout<<"size, Insertion_time\n"; 
  
    // Performs 10 iterations 
    while (it < 10) { 
        long int a[n];

  
        // generating n random numbers 
        // storing them in arrays a, b, c 
        for (int i = 0; i < n; i++) { 
            long int no = rand() % n + 1; 
            a[i] = no; 
            
        } 

        // Insertion sort 
         auto start = chrono::high_resolution_clock::now(); 
        insertionSort(a, n); 
        auto end = chrono::high_resolution_clock::now();
        
        chrono::duration<double> duration = end - start;
        time[it] = duration.count();
  

    cout << n << ", "<< time[it] << ","<<endl;

        // increases the size of array by 10000 

     n+=10000;

     it++;
}
    return 0; 
}