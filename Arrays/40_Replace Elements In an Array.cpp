
// Code
// Testcase
// Testcase
// Test Result
// 2295. Replace Elements in an Array
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given a 0-indexed array nums that consists of n distinct positive integers. Apply m operations to this array, where in the ith operation you replace the number operations[i][0] with operations[i][1].

// It is guaranteed that in the ith operation:

// operations[i][0] exists in nums.
// operations[i][1] does not exist in nums.
// Return the array obtained after applying all the operations.

 

// Example 1:

// Input: nums = [1,2,4,6], operations = [[1,3],[4,7],[6,1]]
// Output: [3,2,7,1]
// Explanation: We perform the following operations on nums:
// - Replace the number 1 with 3. nums becomes [3,2,4,6].
// - Replace the number 4 with 7. nums becomes [3,2,7,6].
// - Replace the number 6 with 1. nums becomes [3,2,7,1].
// We return the final array [3,2,7,1].
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> arrayChange(vector<int>& nums,vector<vector<int>>& operations) {
        unordered_map<int, int> mp;
        for(int i=operations.size()-1;i>=0;i--){
            int first=operations[i][0];
            int second=operations[i][1];
            if(mp.count(second)) {
                mp[first]=mp[second];
            }
            else{
                mp[first]=second;
            }
        }

        for(int i=0;i<nums.size();i++){
            if(mp.count(nums[i]))
            nums[i]=mp[nums[i]];
           
        }
        return nums;
    }
};

int main(){
    Solution sol;
    vector<int> nums={1,2,4,6};
    vector<vector<int>> operations={{1,3},{4,7},{6,1}};
    vector<int> ans=sol.arrayChange(nums,operations);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

}