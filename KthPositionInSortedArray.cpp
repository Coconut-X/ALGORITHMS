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
Given two sorted arrays “A[]”, and “B[]” of size “M” and “N” respectively and integer value “K”. Your task is to find the element that would be at Kth position of the final sorted array. Design an efficient in-place algorithm using divide and conquer approach to find the element at kth position of the final sorted array.
Sample input and output:
Input: Ar1[] = {20, 30, 60, 70, 90} , Ar2[] = {10, 40, 80, 100},  K = 5
Output: 60 the final sorted array would be like {10,20,30,40,60, 70, 80, 90, 100}

*/

//we can use iterative approach with binary search
//please do this problem on leetcode to understand this one better
//https://leetcode.com/problems/median-of-two-sorted-arrays/submissions/1763061156

int findKthElement(vector<int>&arr1, vector<int>&arr2, int K){

    int n1 = arr1.size();
    int n2 = arr2.size();
    //we have to find elem
    if(K > n1 + n2){
        return -1;
    }
  
    if(n1 > n2){
        return findKthElement(arr2, arr1, K);
    }
    int low = 0, high = n1;

    while(low <= high){
        int cut1 = low + (high - low)/2;
        int cut2 = K - cut1;

        int l1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
        int l2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];

        int r1 = (cut1 == n1) ? INT_MAX : arr1[cut1];
        int r2 = (cut2 == n2) ? INT_MAX : arr2[cut2];

        if(l1 <= r2 and l2 <= r1){
            return max(l1, l2);
        }
        else if(l1 > r2){
            high = cut1 - 1;
        }
        else{
            low = cut1 + 1;
        }
    }

    return -1;
}



int main(){
    fastc;

    vector<int> arr1 = {20, 30, 60, 70, 90};
    vector<int> arr2 = {10, 40, 80, 100};

    int K = 5;
    int result = findKthElement(arr1, arr2, K);
    if(result != -1){
        cout<<"The "<<K<<"th element is: "<<result<<endl;
    }
    else{
        cout<<"Invalid K"<<endl;
    }

    return 0;
}