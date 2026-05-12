#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

// Given an array of size n containing only 0s, 1s and 2s; sort the array in ascending order.

void optimal(int arr[], int n){
    // We can use three pointers low, mid and high
    // low and mid will start from 0 and high will start from n-1
    // We will iterate the array until mid is less than or equal to high
    // If arr[mid] is 0 then we will swap arr[low] and arr[mid] and increment low and mid
    // If arr[mid] is 1 then we will just increment mid
    // If arr[mid] is 2 then we will swap arr[mid] and arr[high] and decrement high
    int low = 0, mid = 0, high = n-1;
    while(mid<=high){
        if(arr[mid]==0){f
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}
void better(int arr[], int n){
    // We can count the number of 0s, 1s and 2s in the array and then fill the array with 0s, 1s and 2s according to the count
    int count0 = 0, count1 = 0, count2 = 0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            count0++;
        }
        else if(arr[i]==1){
            count1++;
        }
        else{
            count2++;
        }
    }
    for(int i=0;i<count0;i++){
        arr[i] = 0;
    }
    for(int i=count0;i<count0+count1;i++){
        arr[i] = 1;
    }
    for(int i=count0+count1;i<n;i++){
        arr[i] = 2;
    }
}

int main(){
    int arr[] = {0, 1, 2, 0, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    better(arr,n);
    optimal(arr, n);
    cout<<"Sorted array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}