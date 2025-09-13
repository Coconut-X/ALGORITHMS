#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define fastc ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

int hoaresPartition(vector<int>&arr, int low, int high){

    int pivot = arr[low]; //take first element as pivot in hoares

    int i = low-1, j = high+1; //because we will increment and decrement before using due to do while loop
    
    while(true){
        //find element greater than or equal to pivot
        do{
            i++;
        }while(arr[i] < pivot);

        //find element smaller than or equal to pivot
        do{
            j--;
        }while(arr[j] > pivot);

        //if two pointers met or crossed each other, return the partition index
        //this means j is the index where all elements to the left are smaller than or equal to pivot
        if(i >= j){
            break;
        }
        swap(arr[i],arr[j]);
    }

    return j;   //return the partition index

}


void quickSort(vector<int>& arr, int low, int high){
    if(low < high){
        int partition = hoaresPartition(arr, low, high);
        quickSort(arr,low,partition);
        quickSort(arr,partition+1,high);
    }
}


int main(){
    fastc;


    vector<int> arr = {10, 7, 8, 9, 1, 5,10, 7, 8, 9, 1, 5,10, 7, 8, 9, 1, 5};
    int n = arr.size();
    quickSort(arr, 0, n - 1);
  
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }


    return 0;
}