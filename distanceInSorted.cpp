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
PROBLEM STATEMENT:
Assume that you are given an unsorted array of integers Arr[] of size “N” and two integers “x” and “y”. 
It is guaranteed that the values of both the integers are from the original array. 
Your task is to find the distance between “x” and “y”.
The distance between two elements of the array is the number of elements that lie between them in sorted order. 
Design an efficient algorithm using the divide and conquer approach to get the distance between two elements of the array.
*/

//O(n) approach using divide and conquer
int distanceInSorted(vi &arr, int x, int y, int low, int high){
    
    if(low-high==0){
        if(arr[low]>x and arr[low]<y) return 1;
        else return 0;
    }

    int mid = low + (high - low)/2;
    int left = distanceInSorted(arr, x, y, low, mid);
    int right = distanceInSorted(arr, x, y, mid + 1, high);

    return left + right;
}


int main(){
    fastc;

    vector<int> arr = {30, 55, 40, 20, 50, 45, 10, 60, 25, 58};
    int x = 20, y = 50;
    int n = arr.size();
    cout<<"Distance: "<<distanceInSorted(arr, x, y, 0, n - 1)<<endl;
    return 0;
}