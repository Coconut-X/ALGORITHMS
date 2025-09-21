
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

int maxSubArray(vector<int>& nums) {

    int left = 0, right = 0;
    int currentStart = 0;

    int current = nums[0] , res = nums[0];
    for(int i = 1; i < nums.size(); i++){
        // current = max(nums[i], current + nums[i]);
        if(nums[i]>current+nums[i]){
            current = nums[i];
            currentStart = i;
        }
        else{
            current += nums[i];
        }

        // res = max(res, current);
        if(current > res){
            res = current;
            left = currentStart;
            right = i;
        }
    }
    cout<<"("<<left<<","<<right<<")"<<endl;

    return res;
}

//////////////////////////////////////////////////////////////////////////////////
// Divide and Conquer Approach

int maxCrossingSum(vector<int>&arr, int left, int mid, int right){

    int maxLeft = INT_MIN;
    int sum = 0;
    for(int x = mid; x >= left;x--){
        sum+=arr[x];
        maxLeft = max(sum, maxLeft);
    }

    int maxRight = INT_MIN;
    sum = 0;
    for(int x = mid+1; x <= right; x++){ 
        sum+=arr[x];
        maxRight = max(maxRight, sum);
    }

    return maxLeft + maxRight;
}

int maxSumSubArrayUsingDivideAndConquer(vector<int> &arr, int left, int right){
    if(left == right) return arr[left]; //base case: only one element
    int mid = left + (right - left) / 2;
    int leftSum, rightSum, crossSum;
    if(left < right){
        leftSum = maxSumSubArrayUsingDivideAndConquer(arr, left,mid);
        rightSum = maxSumSubArrayUsingDivideAndConquer(arr, mid + 1, right);
        crossSum = maxCrossingSum(arr, left, mid, right);
    }

    return max(max(leftSum, rightSum), crossSum);
}


int main(){
    fastc;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << "Maximum Subarray Sum: " << maxSubArray(nums) << endl;

    cout<<"Using Divide and Conquer: "<< maxSumSubArrayUsingDivideAndConquer(nums, 0, nums.size() - 1) << endl;
    return 0;
}
