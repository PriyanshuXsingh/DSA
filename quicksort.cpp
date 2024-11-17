#include <bits/stdc++.h>
using namespace std;

int partition(long int arr[], int low, int high) {
    long int pivot = arr[low];
   long int i = low;
    long int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }

        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(long int arr[], int low, int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high);
        quickSort(arr, low, pIndex - 1);
        quickSort(arr, pIndex + 1, high);
        
    }
}



int main()
{
    // vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3};
    // int n = arr.size();
    // cout << "Before Using quick Sort: " << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // arr = quickSort(arr,0,n-1);
    // cout << "After Using quick sort: " << "\n";
    // for (int i = 0; i < n; i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << "\n";
    // return 0;
    long int n = 10000; 
    int it = 0; 
  
    // Arrays to store time duration 
    // of sorting algorithms 
    double  time[10]; 
    // // Seed the random number generator
    //  srand(time(0));

  
    cout<<"size, quickSort_time\n"; 
  
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
        quickSort(a, 0,n-1); 
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