#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#define fastc ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

pair<int,int> getMinMax(vector<int>& array, int low, int high){

    if(high-low==1){
        return { min(array[high],array[low]), max(array[high],array[low]) };
    }
    int mid = low + (high - low)/2;
    pair<int,int> left = {INT_MAX, INT_MIN};
    pair<int,int> right = {INT_MAX, INT_MIN};
    if(low < high){
        left = getMinMax(array, low, mid);
        right = getMinMax(array, mid + 1, high);
    }

    int maxi = max(left.second, right.second);
    int mini = min(left.first, right.first);
    return {mini, maxi};
}



int main(){
    fastc;

    vector<int> arr = {10, 7, 8, 9, 1, 5,10, 7, 8, 9, 1, 5,13, 7, 8, 9, 1, 5};
    int n = arr.size();
    pair<int,int> ans = getMinMax(arr, 0, n-1);
    cout<<"Min: "<<ans.first<<endl;
    cout<<"Max: "<<ans.second<<endl;

    return 0;
}