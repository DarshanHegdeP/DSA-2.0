// 2221. Find Triangular Sum of an Array

// You are given a 0-indexed integer array nums, where nums[i] is a digit between 0 and 9 (inclusive).

// The triangular sum of nums is the value of the only element present in nums after the following process terminates:

// Let nums comprise of n elements. If n == 1, end the process. Otherwise, create a new 0-indexed integer array newNums of length n - 1.
// For each index i, where 0 <= i < n - 1, assign the value of newNums[i] as (nums[i] + nums[i+1]) % 10, where % denotes modulo operator.
// Replace the array nums with newNums.
// Repeat the entire process starting from step 1.
// Return the triangular sum of nums.
// Example 1:
// Input: nums = [1,2,3,4,5]
// Output: 8
// Explanation:
// The above diagram depicts the process from which we obtain the triangular sum of the array.
// Example 2:

// Input: nums = [5]
// Output: 5
// Explanation:
// Since there is only one element in nums, the triangular sum is the value of that element itself.

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute Force Approach
    // Time Complexity: O(n^2)
    // Space Complexity: O(n)
    // create a new array of size n-1 and keep on doing this until the size of the array becomes 1
    // return the only element present in the array
    int brute_triangularSum(vector<int> &nums)
    {

        while (nums.size() > 1)
        {
            vector<int> temp;
            for (int i = 0; i < nums.size() - 1; i++)
            {
                temp.push_back((nums[i] + nums[i + 1]) % 10);
            }
            nums = temp;
        }
        return nums[0];
    }
    // Better Approach
    // Time Complexity: O(n^2)
    // Space Complexity: O(1)
    // Instead of creating a new array, we can modify the existing array and keep on doing this until the size of the array becomes 1
    // return the only element present in the array
    int better_triangularSum(vector<int> &nums)
    {

        while (nums.size() > 1)
        {
            for (int i = 0; i < nums.size() - 1; i++)
            {
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
            nums.pop_back();
        }
        return nums[0];
    }
};

int main()
{

    Solution sol;
    vector<int> nums = {2, 5, 3, 4};
    cout << sol.better_triangularSum(nums);
    cout << sol.brute_triangularSum(nums);
}