#include<bits/stdc++.h>
using namespace std;
void heapify(long int arr[], int n, int i){

    // Initialize largest as root
    long int large = i;

    // left index = 2*i + 1
    long int l = 2 * i + 1;

    // right index = 2*i + 2
    long int r = 2 * i + 2;

    // If left child is larger than root
    if (l < n && arr[l] > arr[large])
        large = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[large])
        large = r;

    // If largest is not root
    if (large != i) {
        swap(arr[i], arr[large]);

        // Recursively heapify 
        heapify(arr, n, large);
    }
}

void buildHeap(long int arr[],int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

}
void heapSort(long int arr[],int n)
{    
    buildHeap(arr,n);
     for (int i = n - 1; i > 0; i--) {

        // Move current root to end
        swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }

}
// void printArray(vector<int>& arr,int n){
//     for (int i = 0; i < arr.size(); ++i)
//         cout << arr[i] << " ";
//     cout << "\n";
// }
int main()
{

// long int n = 10000; 
//     int it = 0; 
  
//     // Arrays to store time duration 
//     // of sorting algorithms 
//     double  time[10]; 
//     // // Seed the random number generator
//     //  srand(time(0));

  
//     cout<<"size, heapSort_time\n"; 
  
//     // Performs 10 iterations 
//     while (it < 10) { 
//         long int a[n];

  
//         // generating n random numbers 
//         // storing them in arrays a, b, c 
//         for (int i = 0; i < n; i++) { 
//             long int no = rand() % n + 1; 
//             a[i] = no; 
            
//         } 

//         // Insertion sort 
//          auto start = chrono::high_resolution_clock::now(); 
//         heapSort(a, n); 
//         auto end = chrono::high_resolution_clock::now();
        
//         chrono::duration<double> duration = end - start;
//         time[it] = duration.count();
  

//     cout << n << ", "<< time[it] << ","<<endl;

//         // increases the size of array by 10000 

//      n+=10000;

//      it++;
// }
long int a[] = {10,20,15,12,40,25,18};
long int n = 7;
long int i;
cout<<"Before heap sort:";
for( i=0;i<n;i++){
cout<<a[i]<<" ";
}
heapSort(a,n);
cout<<"\nafter heap sort:";
for(i=0;i<n;i++){
cout<<a[i]<<" ";
}
    return 0; 
}

