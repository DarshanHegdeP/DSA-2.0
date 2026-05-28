
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int brute_subarraySum(vector<int> &arr, int k)
    {

        int count = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = i; j < arr.size(); j++)
            {
                int sum = 0;
                for (int k = i; k <= j; k++)
                {
                    sum += arr[k];
                }
                if (sum == k)
                    count++;
            }
        }
        return count;
    }
    int better_subarraySum(vector<int> &arr, int k)
    {

        int count = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            int sum = 0;
            for (int j = i; j < arr.size(); j++)
            {
                sum += arr[j];
                if (sum == k)
                    count++;
            }
        }
        return count;
    }

    // Prefix sum + Hashing approach: Use a hash map to count occurrences of prefix sums.
    // Time complexity: O(n), Space complexity: O(n)
    // The idea is to keep track of the cumulative sum of elements as we iterate through the array.
    // For each prefix sum, we check if there is a previous prefix sum that equals the current prefix sum minus k.
    // If such a prefix sum exists, it means the subarray between that previous index and the current index sums to k.
    // We also check if the current prefix sum itself equals k, which would indicate a valid subarray starting from index 0.
    // This approach efficiently counts all subarrays that sum to k in a single pass through the array.
    int optimal_subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        int count = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum == k)
                count++;
            int rem = sum - k;
            if (mp.find(rem) != mp.end())
            {
                count += mp[rem];
            }
            mp[sum] += 1;
        }
        return count;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {1, 1, 1};
    int k = 2;
    cout << s.optimal_subarraySum(arr, k) << endl;
    cout << s.brute_subarraySum(arr, k) << endl;
    cout << s.better_subarraySum(arr, k) << endl;
    return 0;
}