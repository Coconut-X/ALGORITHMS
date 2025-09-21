#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
#define fastc ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

/*
PROBLEM STATEMENT:
Consider an array of distinct integers Arr[] of size “N” was sorted in ascending order. 
The array has been rotated clockwise “K” number of times.
 Given such an array, your task is to find the value of “K”.
 Design an algorithm using divide and conquer technique to get the value of “K” in O(log⁡N). 
*/


//JUST USE BINARY SEARCH TO FIND THE INDEX OF MINIMUM ELEMENT
//we use iterative binary search
//not that the array is not strictly sorted, so we cannot use normal binary search
//but we can use the property that one half of the array is always sorted
//we can check if the mid element is less than the high element

int findKRotation(vi &arr, int low, int high){

    int n = arr.size();
    while(low <= high){
        int mid = low + (high - low)/2;
        int next = (mid + 1)%n;
        int prev = (mid + n - 1)%n; //

        //check if mid is the minimum element
        //78, 85, 92, 25, 34, 48, 56, 62
        //notice how 25 is less than both its neighbours
        if(arr[mid] <= arr[next] and arr[mid] <= arr[prev]){
            return mid; //index of minimum element
        }
        //if mid is not minimum, check which half to search
        else if(arr[mid] <= arr[high]){ //right half is sorted, search in left half
            high = mid - 1;
        }
        else if(arr[mid] >= arr[low]){ //left half is sorted, search in right half
            low = mid + 1;
        }
    }
    return 0; 

}


int main(){
    fastc;

    vector<int> arr = {78, 85, 92, 25, 34, 48, 56, 62};
    //vector<int> arr = {1,2,3,4,5};
    int n = arr.size();
    int k = findKRotation(arr, 0, n - 1);
    cout<<"K: "<<k<<endl;
    return 0;
}