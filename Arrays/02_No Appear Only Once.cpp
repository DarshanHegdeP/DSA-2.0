#include <iostream>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

// Time complexity is O(n) and space complexity is O(1) for optimal solution

int brute_approach(int arr[],int n){
   //Time o(n2)
    //For finding no that appear only once, we can sort the array and then iterate and find the element which is not equal to previous and next element
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        if(i==0 && arr[i]!=arr[i+1]){
            cout<<"Element which appear only once is: "<<arr[i]<<endl;
            return arr[i];
        }
        if(i==n-1 && arr[i]!=arr[i-1]){
            cout<<"Element which appear only once is: "<<arr[i]<<endl;
            return arr[i];
        }
        if(arr[i]!=arr[i-1] && arr[i]!=arr[i+1]){
            cout<<"Element which appear only once is: "<<arr[i]<<endl;
            return arr[i];
        }
    }
    return -1;

}

int better_approach(int arr[],int n){
    //Time o(n) and space o(n)
    // We can use hash map to store the frequency of each element and then iterate the hash map to find the element which has frequency 1
    unordered_map<int,int> freq;
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }
    for(auto it:freq){
        if(it.second==1){
            cout<<"Element which appear only once is: "<<it.first<<endl;
            return it.first;
        }
    }
    return -1;

}

int optimal_approach(int arr[],int n){
    //Time o(n) and space o(1)
    // We can use XOR operator to find the element which appear only once. XOR of a number with itself is 0 and XOR of a number with 0 is the number itself. So if we XOR all the elements of the array, we will get the element which appear only once.
    int res = 0;
    for(int i=0;i<n;i++){
        res = res ^ arr[i];
    }
    cout<<"Element which appear only once is: "<<res<<endl;
    return res;
}

int main(){
    //Finding second largest element in a an array
    int arr[] = {1,2,3,4, 2, 3, 4,5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    brute_approach(arr, n);
    better_approach(arr,n);
    optimal_approach(arr,n);
    return 0;
}