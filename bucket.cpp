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

int bucketIndex(float value, float minValue, float maxValue, int bucketCount){

    float bucketWidth = (maxValue - minValue);
    int index = ((value - minValue)/bucketWidth)*bucketCount;
    if(index < 0) index = 0;
    if(index >= bucketCount) index = bucketCount - 1;

    return index;
}

pair<float,float> getMinMax(vector<float>&arr){
    pair<float,float> mm;

    mm.first = *max_element(arr.begin(), arr.end());
    mm.second = *min_element(arr.begin(), arr.end());

    return mm;
}

vector<float> getSorted(vector<float>&arr){
    vector<vector<float>>bucket(arr.size());

    auto [max, min] = getMinMax(arr);

    for(auto &n: arr){
        bucket[bucketIndex(n,min,max,arr.size())].push_back(n);
    }

}

int main(){
    fastc;
    return 0;
}