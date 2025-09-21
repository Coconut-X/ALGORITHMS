#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;

#define fastc ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

pair<int,int> count(vector<int>&arr, int low, int high, int a, int b){

    int c1 = 0, c2 = 0;

    for(int i = low; i <=high; i++){
        c1+=(arr[i] == a);
        c2+=(arr[i] == b);
    }
    return {c1,c2};

}

int majority(vector<int>&arr, int low, int high){

    //agr aik element rehta ha 
    if(low==high){
        return arr[low];
    }

    int length = high - low + 1;

    int mid = low + (high - low)/2;
    int left = majority(arr, low, mid);
    int right = majority(arr, mid + 1, high);

    if(left == right) return left;

    auto [c1,c2] = count(arr, low, high, left, right);
    
    if(c1 > length/2) return left;
    if(c2 > length/2) return right;

   return -1;

}


int main(){
    fastc;

     vector<int> arr = {48, 92, 35, 48, 48, 35, 48, 17, 48};
    //vector<int> arr = {48, 92, 35, 48, 92, 35, 48, 35, 48};
    int n = arr.size();

    int ans = majority(arr, 0, n - 1);
    if(ans != -1) cout<<"Majority Element: "<<ans<<endl;
    else cout<<"No Majority Element"<<endl;
    return 0;
}