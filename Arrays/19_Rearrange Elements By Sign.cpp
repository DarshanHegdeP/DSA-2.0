// 2149. Rearrange Array Elements by Sign
// You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.
// You should return the array of nums such that the array follows the given conditions:
// Every consecutive pair of integers have opposite signs.
// For all integers with the same sign, the order in which they were present in nums is preserved.
// The rearranged array begins with a positive integer.
// Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

// Example 1:S

// Input: nums = [3,1,-2,-5,2,-4]
// Output: [3,-2,1,-5,2,-4]
// Explanation:
// The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
// The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4].
// Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are incorrect because they do not satisfy one or more conditions.  

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    //Brute approach is use 2 arrays one for storing positive numbers and another for storing negatives;
    //Then copy it back to original array, by placing positives in even and negatives in odd positions.

    vector<int> rearrangeArray(vector<int>& nums) {
        //Optimal approach
        // Time complexity: O(n)
        // Space complexity: O(n)
        // We can create a copy of the original array and fill it with the rearranged elements. We can use two pointers, one for positive numbers and one for negative numbers, to fill the copy array in the correct order.    

        vector<int> copy(nums.size());
        int i=0;int j=1;
        for(int k=0;k<nums.size();k++){
            if(nums[k]>0) {
                copy[i]=nums[k];
                i+=2;
            }
            else{
                copy[j]=nums[k];
                j+=2;
            }
        }
        return copy;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {3, 1, -2, -5, 2, -4};
    vector<int> result = sol.rearrangeArray(nums);
    cout << "Rearranged array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}