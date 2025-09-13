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


void insertionSort(vector<int>&arr){
    for(int i = 1; i < arr.size(); i++){
        int key = arr[i];
        int j = i - 1;

        //move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main(){
    fastc;


    return 0;
}