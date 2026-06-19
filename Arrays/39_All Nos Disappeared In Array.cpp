// 448. Find All Numbers Disappeared in an Array

// Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

// Example 1:

// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [5,6]
// Example 2:

// Input: nums = [1,1]
// Output: [2]

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Approach 1: Brute Force
    // Time complexity: O(n^2), Space complexity: O(1)
    // We can iterate through the numbers from 1 to n and for each number, we can check if it is present in the input array. If it is not present, we can add it to the answer vector.
    vector<int> brute_findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> ans;
        for (int i = 1; i <= nums.size(); i++)
        {
            bool found = false;
            for (int j = 0; j < nums.size(); j++)
            {
                if (nums[j] == i)
                {
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }

    // Approach 2: Better
    //  Time complexity: O(n), Space complexity: O(n)
    // We can use a frequency array to keep track of the frequency of each number in the input array. We can iterate through the input array and for each number, we can increment its frequency
    // in the frequency array. After that, we can iterate through the frequency array and for each number with a frequency of 0, we can add it to the answer vector.
    // This approach has a time complexity of O(n) and a space complexity of O(n) for the frequency array.
    vector<int> better_findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> ans;
        vector<int> freq(nums.size(), 0);

        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i] - 1] += 1;
        }

        for (int i = 0; i < freq.size(); i++)
        {
            if (freq[i] == 0)
                ans.push_back(i + 1);
        }

        return ans;
    }

    // Approach 3: Optimal
    // Time complexity: O(n), Space complexity: O(1)
    // We can iterate through the input array and for each number, we can mark its corresponding
    // index in the input array as negative. After that, we can iterate through the input array and for each number with a positive value, we can add its index + 1 to the answer vector.
    vector<int> optimal_findDisappearedNumbers(vector<int> &nums)
    {

        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] > 0)
                nums[idx] *= -1;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                ans.push_back(i + 1);
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {4, 3, 2, 7,
                        8, 2, 3, 1};
    vector<int> ans1 = s.brute_findDisappearedNumbers(nums);
    vector<int> ans2 = s.better_findDisappearedNumbers(nums);
    vector<int> ans3 = s.optimal_findDisappearedNumbers(nums);

    cout << "Brute Force: ";
    for (int i : ans1)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "Better: ";
    for (int i : ans2)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "Optimal: ";
    for (int i : ans3)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}