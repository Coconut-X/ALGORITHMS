#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define fastc ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

pair<int,int> hoaresPartition(vector<pair<int,int>>&arr, int low, int high){

    int pivot = arr[low].first; //take first element as pivot in hoares

    int i = low-1, j = high+1; //because we will increment and decrement before using due to do while loop

    vector<pair<int,int>> smaller,equal,greater;

    for(int k = low; k <= high; k++){
        if(arr[k].first < pivot) smaller.push_back(arr[k]);
        else if(arr[k].first == pivot) equal.push_back(arr[k]);
        else greater.push_back(arr[k]);
    }

    int index = low;
    for(auto& val : smaller) arr[index++] = val;
    int equalStart = index;
    for(auto& val : equal) arr[index++] = val;
    int equalEnd = index - 1;
    for(auto& val : greater) arr[index++] = val;

    return {equalStart, equalEnd};
}

void quickSort(vector<pair<int,int>>& arr, int low, int high){
    if(low < high){
        pair<int,int> partition = hoaresPartition(arr, low, high);
        int equalStart = partition.first;
        int equalEnd = partition.second;
        quickSort(arr,low,equalStart-1);
        quickSort(arr,equalEnd+1,high);
    }
}


int main(){
    fastc;

    vector<pair<int,int>> arr = {{10,1}, {7,2}, {8,3}, {9,4}, {1,5}, {5,6},{10,7}, {7,8}, {8,9}, {9,10}, {1,11}, {5,12},{10,13}, {7,14}, {8,15}, {9,16}, {1,17}, {5,18}};
    int n = arr.size();
    quickSort(arr, 0, n - 1);
  
    for (int i = 0; i < n; i++) {
        cout <<"("<< arr[i].first << ", " << arr[i].second << "), ";
    }

    return 0;
}