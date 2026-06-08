# include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Method better: Using Binary Search and a linear scan to find the first and last positions of the target element in the sorted array.
    // Time Complexity: O(log n) for binary search + O(k) for linear scan, where k is the number of occurrences of the target element.
    // Space Complexity: O(1) for iterative approach.
    
    int binary(vector<int> nums, int target, int start, int end) {
        if (start > end)
            return -1;
        int mid = (start + end) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            return binary(nums, target, start, mid - 1);
        else
            return binary(nums, target, mid + 1, end);
    }

    vector<int> searchRangeBetter(vector<int>& nums, int target) {
        int index = binary(nums, target, 0, nums.size() - 1);

        int last = index;
        int first = index;
        if (index == -1)
            return {-1, -1};
        while (last + 1 < nums.size() && nums[last + 1] == target) {
            last++;
        }
        while (first - 1 >= 0 && nums[first - 1] == target) {
            first--;
        }
        return {first, last};
    }

    //Method Optimal: Using two binary searches to find the first and last positions of the target element in the sorted array.
    // Time Complexity: O(log n) for each binary search, resulting in O(log n) overall.
    // Space Complexity: O(1) for iterative approach.

    int firstOccurance(vector<int>& nums, int target, int low, int high) {
        if (low > high)
            return -1;
        int mid = (low + high) / 2;
        int first = -1;
        if (nums[mid] == target) {
            first = mid;
            int res = firstOccurance(nums, target, low, mid - 1);
            return res == -1 ? mid : res;
        } else if (nums[mid] > target) {
            return firstOccurance(nums, target, low, mid - 1);
        } else {
            return firstOccurance(nums, target, mid + 1, high);
        }
    }

    int lastOccurance(vector<int>& nums, int target, int low, int high) {
        if (low > high)
            return -1;
        int mid = (low + high) / 2;
        int last = -1;
        if (nums[mid] == target) {
            last = mid;
            int res = lastOccurance(nums, target, mid + 1, high);
            return res == -1 ? mid : res;
        } else if (nums[mid] > target) {
            return lastOccurance(nums, target, low, mid - 1);
        } else {
            return lastOccurance(nums, target, mid + 1, high);
        }
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return {firstOccurance(nums, target, 0, nums.size() - 1),
                lastOccurance(nums, target, 0, nums.size() - 1)};
    }

};

int main(){
    Solution s;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    vector<int> ans1 = s.searchRangeBetter(nums, 8);
    vector<int> ans = s.searchRange(nums, 8);
    cout<<"Better Method: First and Last Position of Element in Sorted Array: [" << ans1[0] << ", " << ans1[1] << "]" << endl;
    cout << "First and Last Position of Element in Sorted Array: [" << ans[0] << ", " << ans[1] << "]" << endl;
    return 0;
}