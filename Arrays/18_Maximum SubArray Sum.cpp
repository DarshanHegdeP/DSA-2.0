// 53. Maximum Subarray
// Given an integer array nums, find the subarray with the largest sum, and return its sum.
// Example 1:
// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.

#include <bits/stdc++.h>
using namespace std;

int brute_meth(vector<int>& arr)
{
    int maxi=INT_MIN;
    for(int i=0;i<arr.size();i++){
        for(int j=i;j<arr.size();j++){
            int sum=0;
            for(int k=i;k<=j;k++){
                sum+=arr[k];
                maxi=max(maxi,sum);
            }
        }
    }

    return maxi;
}
int better_meth(vector<int>& arr)
{
    int maxi=INT_MIN;
    for(int i=0;i<arr.size();i++){
        int sum=0;
        for(int j=i;j<arr.size();j++){
            sum=max(arr[j],sum+arr[j]);
            maxi=max(sum,maxi);
        }
    }
    return maxi;
}
int optimal_meth(vector<int>& arr)
{
    int maxi=INT_MIN;
    int currSum=0;
    for(int i=0;i<arr.size();i++){
        currSum=max(arr[i],currSum+arr[i]);
        maxi=max(maxi,currSum);
    }
    return maxi;
}
int main()
{
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum subarray sum -brute = " << brute_meth(arr) << endl;
    cout << "Maximum subarray sum -better = " << better_meth(arr) << endl;
    cout << "Maximum subarray sum -optimal = " << optimal_meth(arr) << endl;
    return 0;
}