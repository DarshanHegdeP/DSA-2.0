// 15. 3Sum
// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.
// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation:
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.
// Example 2:

// Input: nums = [0,1,1]
// Output: []
// Explanation: The only possible triplet does not sum up to 0.
// Example 3:

// Input: nums = [0,0,0]
// Output: [[0,0,0]]
// Explanation: The only possible triplet sums up to 0.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> brute(vector<int> &nums)
{
    // Time Complexity: O(N^3 log N) due to sorting each triplet and inserting into set
     // Space Complexity: O(N) for the set to store unique triplets
     // This brute force approach checks all possible triplets in the array. For each triplet, it checks if their sum is zero. If it is, it sorts the triplet and inserts it into a set to ensure uniqueness. Finally, it converts the set to a vector of vectors and returns it.
     // Note: This approach is not efficient for large input sizes due to its cubic time complexity.
    set<vector<int>> ans;
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            for(int k=j+1;k<nums.size();k++){
                if(nums[i]+nums[j]+nums[k]==0){
                    vector<int> temp={nums[i],nums[j],nums[k]};
                    sort(temp.begin(),temp.end());
                    ans.insert(temp);
                }
            }
        }
        
    }


    return vector<vector<int>>(ans.begin(),ans.end());
}

vector<vector<int>> better(vector<int> &nums)
{
    // Time Complexity: O(N^2 log N) due to sorting each triplet and inserting into set
     // Space Complexity: O(N) for the set to store unique triplets
     // This approach uses a hash set to find the third element of the triplet. For each pair of elements, it calculates the required third element to sum to zero and checks if it exists in the hash set. If it does, it forms a triplet, sorts it, and inserts it into a set to ensure uniqueness. Finally, it converts the set to a vector of vectors and returns it.
     // Note: This approach is more efficient than the brute force method but still may not be optimal for large input sizes due to its quadratic time complexity.
    set<vector<int>> ans;
    
    for(int i=0;i<nums.size();i++){
        unordered_set<int> st;
        for(int j=i+1;j<nums.size();j++){
            int third=-(nums[i]+nums[j]);
            if(st.find(third)!=st.end()){
                vector<int> temp={nums[i],nums[j],third};
                sort(temp.begin(),temp.end());
                ans.insert(temp);
            }
            st.insert(nums[j]);
        }
        
    }

    return vector<vector<int>>(ans.begin(), ans.end());
}

vector<vector<int>> optimal(vector<int> &nums)
{
    // Time Complexity: O(N^2) due to the two-pointer approach
     // Space Complexity: O(1) if we don't consider the space used for the output, otherwise O(N) for the output list
     // This optimal approach first sorts the input array. Then, it uses a two-pointer technique to find pairs of numbers that sum to the negative of the current number. It also includes checks to skip duplicate elements to ensure that only unique triplets are added to the answer. This method is efficient and works well for large input sizes.
     // Note: The sorting step takes O(N log N) time, and the two-pointer approach takes O(N^2) time, making the overall time complexity O(N^2).
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        int left = i + 1;
        int right = nums.size() - 1;
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0)
            {
                ans.push_back({nums[i], nums[left], nums[right]});
                left++;
                right--;

                while (left < right && nums[left] == nums[left - 1])
                    left++;
                while (left < right && nums[right] == nums[right + 1])
                    right--;
            }
            else if (sum < 0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    return ans;
}

int main()
{

    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans1 = brute(nums);
    cout << "Brute Force Solution: " << endl;
    for (auto i : ans1)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    vector<vector<int>> ans2 = better(nums);
    cout << "Better Solution: " << endl;
    for (auto i : ans2)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    vector<vector<int>> ans = optimal(nums);
    cout << "Optimal Solution: " << endl;
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}