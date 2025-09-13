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


void selectionSort(vector<float>&v){
    
    for (int  i = 0; i < v.size() ; i++)
    {
        int minindex = i;
        for(int j = i + 1; j < v.size(); j++){
            if(v[j] < v[minindex]){
                minindex = j;
            }
        }
        swap(v[i], v[minindex]);
    }
}

int main(){
    fastc;

    vector<float> arr = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21,10, 5, 0.55, 0.43, 0.30, -0.5, 200, -0.1, -0.9, 1.5, 2.3, 3.7, -2.4, 5.6, 4.4, -3.3};

    selectionSort(arr);

    for(auto a: arr){
        cout<<a<<" ";
    }

    return 0;
}