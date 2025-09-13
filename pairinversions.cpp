#include <iostream>
using namespace std;


int merge(int arr[], int l, int m, int r){
    int  count = 0;

    int n1 = m - l + 1;
    int n2 = r - m;
    int left[n1], right[n2];

    for(int i =0; i < n1; i++){
        left[i] = arr[l+i];
    }

    for(int i =0; i < n2; i++){
        right[i] = arr[1+m+i];

    }

    int i = 0, j = 0;
    int k = l;

    while(i < n1 and j < n2){
        if(left[i]<= right[j]){
            arr[k] = left[i];
            k++,i++;;
        }
        else
        {
            arr[k++] = right[j++];
            count += (n1 - i);
        }

    }

    while(i < n1){
        arr[k++] = left[i++];
    }
    
    while(j < n2){
        arr[k++] = right[j++];
    }


    cout << "Left: " << l << " right: " << r << endl;
    for (int i = l; i < k; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << count <<endl;
    return count;   
}

int mergeSort(int arr[], int l, int r){
    //int sum = 0;
    int m = l + (r - l)/2;
    int count = 0;
    if(l < r){
        count += mergeSort(arr, l, m) + mergeSort(arr, m + 1, r) + merge(arr, l, m, r);
    }
    
    return count;
}



int main(){

    int arr[] = {3, 5, 1, 10,9,2,6,8};
    int n  = 8;


    int count1 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++) {
            if(arr[i] > arr[j])
                count1++;
        }
    }


    int count = mergeSort(arr,0,n-1);
    
    for(int i = 0;i< n;i++)
        cout<<arr[i]<<" ";

    cout <<"Inversions: "<< count << endl;

    cout << count1 << endl;
    return 0;
}