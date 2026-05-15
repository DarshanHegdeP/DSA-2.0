// 2215. Find the Difference of Two Arrays
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:

// answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
// answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
// Note that the integers in the lists may be returned in any order.

// Example 1:

// Input: nums1 = [1,2,3], nums2 = [2,4,6]
// Output: [[1,3],[4,6]]
// Explanation:
// For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
// For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums1. Therefore, answer[1] = [4,6].
// Example 2:

// Input: nums1 = [1,2,3,3], nums2 = [1,1,2,2]
// Output: [[3],[]]
// Explanation:
// For nums1, nums1[2] and nums1[3] are not present in nums2. Since nums1[2] == nums1[3], their value is only included once and answer[0] = [3].
// Every integer in nums2 is present in nums1. Therefore, answer[1] = [].

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {

        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());

        vector<vector<int>> result(2);

        for (int x : s1)
        {
            if (!s2.count(x))
            {
                result[0].push_back(x);
            }
        }

        for (int x : s2)
        {
            if (!s1.count(x))
            {
                result[1].push_back(x);
            }
        }

        return result;
    }
};

// Optimal

vector<vector<int>> optimal(vector<int> &nums1, vector<int> &nums2)
{
    vector<vector<int>> result(2);
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] < nums2[j])
        {
            if (result[0].empty() || result[0].back() != nums1[i])
            {

                result[0].push_back(nums1[i]);
            }
            i++;
        }
        else if (nums1[i] > nums2[j])
        {
            if (result[1].empty() || result[1].back() != nums2[j])
            {

                result[1].push_back(nums2[j]);
            }
            j++;
        }
        else
        {
            int common = nums1[i];
            while (i < nums1.size() && nums1[i] == common)
                i++;
            while (j < nums2.size() && nums2[j] == common)
                j++;
        }
    }
    if (i == nums1.size())
    {
        for (j; j < nums2.size(); j++)
        {
            if (result[1].empty() || result[1].back() != nums2[j])
            {

                result[1].push_back(nums2[j]);
            }
        }
    }

    if (j == nums2.size())
    {
        for (i; i < nums1.size(); i++)
        {
            if (result[0].empty() || result[0].back() != nums1[i])
            {
                result[0].push_back(nums1[i]);
            }
        }
    }

    return result;
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 3};
    vector<int> nums2 = {1, 1, 2, 2};
    Solution sol;
    vector<vector<int>> result = sol.findDifference(nums1, nums2);
    for (auto &vec : result)
    {
        for (int x : vec)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}