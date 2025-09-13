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

void selectionSort(vector<float>&v){

    for (int  i = 0; i < v.size(); i++)
    {
        int index = i;
        float minelement = v[i];
        for(int j = i + 1; j < v.size(); j++){
            if(v[j] < minelement){
                index = j;
                minelement = v[j];
            }
        }
        swap(v[i], v[index]);
    }
}

vector<float> getSorted(vector<float>&arr){
    vector<vector<float>>bucket(arr.size());
    auto [max, min] = getMinMax(arr);

    cout<<"Max: "<<max<<" Min: "<<min<<endl;
    for(auto &n: arr){
        bucket[bucketIndex(n,min,max,arr.size())].push_back(n);
    }

    for(auto &b: bucket){
        selectionSort(b);
    }

    vector<float> sorted;
    for(auto &a: bucket){
        for(auto &b: a){
            sorted.push_back(b);
        }
    }
    return sorted;
}

int main(){
    fastc;

    //big test case having both big small numbers and negative numbers and integers and floats
    vector<float> arr = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21,10, 5, 0.55, 0.43, 0.30, -0.5, 200, -0.1, -0.9, 1.5, 2.3, 3.7, -2.4, 5.6, 4.4, -3.3};
    vector<float> sorted = getSorted(arr);  
    cout<<"Sorted Array: "<<endl;
    for(auto &n: sorted){
        cout<<n<<" ";
    }
    cout<<endl;

    return 0;
}