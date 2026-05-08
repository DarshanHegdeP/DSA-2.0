#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

// Time complexity is O(n) and space complexity is O(1) for optimal solution

int brute_second_largest(int arr[],int n){
    // FIrst sort the array and then iterate from last and find the element which is not equal to last element
    sort(arr, arr+n);
    for(int i=n-1;i>=0;i--){
        if(arr[i]!=arr[n-1]){
            cout<<"Second Largest element is: "<<arr[i]<<endl;
            break;
        }
    }
    return -1;

}

int better_second_largest(int arr[],int n){
    // First find largest element by iterating once
    // Later iterate again to find max el which is not equal to largest element found in first iteration
    int largest = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>largest){
            largest = arr[i];
        }
    }
    int second_largest = INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>second_largest && arr[i]!=largest){
            second_largest = arr[i];
        }
    }
    cout<<"Second Largest element is: "<<second_largest<<endl;
    return second_largest;
}

int optimal_second_largest(int arr[],int n){
    // Iterate once to find max el and second max 
    int largest = arr[0];
    int second_largest = INT_MIN;
    for(int i=1;i<n;i++){
        if(arr[i]>largest){
            second_largest = largest;
            largest = arr[i];
        }
        else if(arr[i]>second_largest && arr[i]!=largest){
            second_largest = arr[i];
        }
    }
    cout<<"Second Largest element is: "<<second_largest<<endl;
    return second_largest;
}

int main(){
    //Finding second largest element in a an array
    int arr[] = {1, 2, 3, 4,5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    brute_second_largest(arr, n);
    better_second_largest(arr,n);
    optimal_second_largest(arr,n);
    return 0;
}