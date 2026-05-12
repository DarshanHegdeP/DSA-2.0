// 26. Remove Duplicates from Sorted Array

// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.

// Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. After removing duplicates, return the number of unique elements k.

// The first k elements of nums should contain the unique numbers in sorted order. The remaining elements beyond index k - 1 can be ignored.

// Custom Judge:

// The judge will test your solution with the following code:

// int[] nums = [...]; // Input array
// int[] expectedNums = [...]; // The expected answer with correct length

// int k = removeDuplicates(nums); // Calls your implementation

// assert k == expectedNums.length;
// for (int i = 0; i < k; i++) {
//     assert nums[i] == expectedNums[i];
// }
// If all assertions pass, then your solution will be accepted.

 

// Example 1:

// Input: nums = [1,1,2]
// Output: 2, nums = [1,2,_]
// Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).
// Example 2:

// Input: nums = [0,0,1,1,1,2,2,3,3,4]
// Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
// Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).

#include <bits/stdc++.h>
using namespace std;

int brute(int arr[],int n){
    //We can use a set to store the unique elements of the array and then copy the unique elements back to the array
    set<int> s;
    for(int i=0;i<n;i++){
        s.insert(arr[i]);
    }
    int i = 0;
    for(auto it : s){
        arr[i] = it;
        i++;    
    }
    return s.size();

}
int optimal(int nums[], int n){
    // We can use two pointers to remove the duplicates from the array
    // We will have two pointers i and j, i will start from 0 and j will start from 1
    // We will iterate the array until j is less than n
    // If arr[i] is equal to arr[j] then we will just increment j
    // If arr[i] is not equal to arr[j] then we will increment i and copy arr[j] to arr[i]
    // int i = 0, j = 1;
    // while(j<n){
    //     if(arr[i]==arr[j]){
    //         j++;
    //     }
    //     else{
    //         i++;
    //         arr[i] = arr[j];
    //         j++;
    //     }
    // }
    // return i+1;

   int j=0;
       for(int i=1;i<n;i++){
        if(nums[j]!=nums[i]){
            nums[++j]=nums[i];
        }
       }
        return j+1;
}

int main(){
    int arr[]={0,0,1,1,1,2,2,3,3,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k = brute(arr,n);
    cout<<"Number of unique elements is: "<<k<<endl;
    cout<<"Array after removing duplicates is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
        int arr1[]={0,0,1,1,1,2,2,3,3,4};
    int n1=sizeof(arr1)/sizeof(arr1[0]);

    k = optimal(arr1,n1);
    cout<<"Number of unique elements is: "<<k<<endl;
    cout<<"Array after removing duplicates is: ";
    for(int i=0;i<n1;i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    return 0;
}