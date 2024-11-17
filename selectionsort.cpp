#include <iostream>
using namespace std;


void selectionSort(int arr[], int size) {
    for (int i = 0; i < size-1; i++) {
        
        int minIndex = i;
        for (int j = i+1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int main() {
    
    int size;
    cout<<"size of an array:";
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }

    cout << "Original array: \n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    selectionSort(arr,size);

    cout << "\nSorted array: \n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
