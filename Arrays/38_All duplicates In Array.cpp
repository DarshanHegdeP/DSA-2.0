// 442. Find All Duplicates in an Arra
// Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears at most twice, return an array of all the integers that appears twice.

// You must write an algorithm that runs in O(n) time and uses only constant auxiliary space, excluding the space needed to store the output

// Example 1:

// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [2,3]
// Example 2:

// Input: nums = [1,1,2]
// Output: [1]
// Example 3:

// Input: nums = [1]
// Output: []
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Approach 1: Brute Force
    // Time complexity: O(n^2), Space complexity: O(1)
    vector<int> brute_findDuplicates(vector<int> &nums)
    {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] == nums[j])
                {
                    ans.push_back(nums[i]);
                    break;
                }
            }
        }

        return ans;
    }
    // Approach 2: Better
    //  Time complexity: O(n), Space complexity: O(n)
    // We can use a frequency array to keep track of the frequency of each number in the input array. We can iterate through the input array and for each number, we can increment its frequency in the frequency array. If the frequency of a number becomes 2, we can add it to the answer vector.
    vector<int> better_findDuplicates(vector<int> &nums)
    {
        vector<int> ans;
        vector<int> freq(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
        }
        for (int i = 1; i < freq.size(); i++)
        {
            if (freq[i] == 2)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }

    // Approach 3: Optimal
    // Time complexity: O(n), Space complexity: O(1)
    // We can use the input array itself to keep track of the frequency of each number. We can iterate through the array and for each number, we can mark the index corresponding to that number as negative. If we encounter a negative number at that index, it means that the number has already been seen before and we can add it to the answer vector.
    // For example, if we encounter the number 3, we can mark the index 2 (3 - 1) as negative. If we encounter the number 3 again, we will see that the index 2 is already negative and we can add 3 to the answer vector.
    //
    vector<int> optimal_findDuplicates(vector<int> &nums)
    {
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] < 0)
            {
                ans.push_back(abs(nums[i]));
            }
            else
            {
                nums[idx] = -nums[idx];
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> arr = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> ans1 = s.brute_findDuplicates(arr);
    vector<int> ans2 = s.better_findDuplicates(arr);
    vector<int> ans3 = s.optimal_findDuplicates(arr);
    cout << "Brute" << endl;
    for (auto item : ans1)
    {
        cout << item << " ";
    }
    cout << endl;
    cout << "Better" << endl;
    for (auto item : ans2)
    {
        cout << item << " ";
    }
    cout << endl;
    cout << "Optimal" << endl;
    for (auto item : ans3)
    {
        cout << item << " ";
    }
    cout << endl;
}