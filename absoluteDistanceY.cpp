#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <deque>
#include <list>
#include <climits>
#include <sstream>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
#define fastc ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'


/*
Consider an unsorted array of integers Arr[] of size “N” and an integer “y”. 
Your task is to determine whether there exists any pair of indices whose absolute difference is equal to “y”. 
Design an algorithm using divide and conquer approach to solve this problem in O(〖N*log〗⁡N).	
Sample input and output:
Input: Ar1[] = {3, 7, 2, 1, 4, 10} ,   y = 1
Since we are talking about Abs Difference so |3-4| = 1 and also |2-1| = 1 so your algorithm must return true

*/


void merge(vector<int>&arr, int low, int mid, int high){
    int s1 = mid - low + 1;
    int s2 = high - mid;

    int L[s1], R[s2];

    for(int i = low; i<=mid; i++){
        L[i] = arr[i];
    }

    for(int i = mid + 1; i <= high; i++){
        R[i] = arr[i];
    }

    int k = low;
    int i = 0, j = 0;

    while(i < s1 and j < s2){
        if(L[i] <= R[j]){
            arr[k++] = L[i++];
        }
        else{
            arr[k++] = R[j++];
        }
    }
    while( i < s1){
        arr[k++] = L[i++];
    }
    
    while( j < s2){
        arr[k++] = R[j++];
    }
}


void mergeSort(vector<int>&arr, int low, int high){

    if(low < high){
        int mid = low + (high - low)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
    
}


bool binarySearch(vector<int>&arr,int num,  int target){
    int low = 0, high = arr.size() - 1;

    while(low <= high){
        int mid = low + (high - low)/2;
        if(abs(arr[mid] - num) == target && arr[mid] != num){
            return true;
        }
        else if(arr[mid] < num - target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return false;
}

int main(){
    fastc;
    vector<int> array  = {3, 7, 2, 1, 4, 10};
    int y = 1;


    //first sort the array and then do binary search for each element to find arr[i] + y or arr[i] - y in the array
    
    mergeSort(array, 0, array.size() - 1);

    for(int i = 0; i < array.size(); i++){
        if(binarySearch(array, array[i], y)){
            cout << "True" << endl;
            return 0;
        }
    }

    cout << "False" << endl;

    return 0;
}