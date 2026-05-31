// 128. Longest Consecutive Sequence
// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

// You must write an algorithm that runs in O(n) time.
// Example 1:

// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
// Example 2:

// Input: nums = [0,3,7,2,5,8,4,6,0,1]
// Output: 9
// Example 3:

// Input: nums = [1,0,1,2]
// Output: 3

#include <bits/stdc++.h>
using namespace std;

int brute(vector<int>& nums){
    // Time complexity: O(n^2) due to nested loops
    // Space complexity: O(1)
    int longest=0;
  
    for(int i=0;i<nums.size();i++){
     int count=1;
     while(find(nums.begin(),nums.end(),nums[i]+count)!=nums.end()){// Check if the next consecutive number exists in the array
        //kind of like a while loop to keep checking for the next consecutive number until we find a break in the sequence. We can keep track of the longest sequence length found.
        //linear search to find the next consecutive number in the array, which takes O(n) time. Since we have a loop that iterates through each element of the array, the overall time complexity is O(n^2).
         count++;
     }
        longest=max(longest,count);
    }
    return longest;
}

int better(vector<int>& nums){
    // Time complexity: O(nlogn) due to sorting
    // Space complexity: O(1) if we sort in place, otherwise O(n)
    // We can sort the array and then iterate through it to find the longest consecutive sequence.

    sort(nums.begin(),nums.end());
    int longest=0;
     int count=1;
    for(int i=1;i<nums.size();i++){
       
       if(nums[i]==nums[i-1]) continue; // Skip duplicates
       else if(nums[i]==nums[i-1]+1) count++; // If current number is consecutive to the previous one, increment count
       else count=1; // Reset count if current number is not consecutive        
        longest=max(longest,count);
    }
    return longest;
}

int optimal(vector<int>& nums){
// Time complexity: O(n)
    // Space complexity: O(n)
    // We can use a hash set to store the elements of the array. Then, for each element, we can check if it is the start of a sequence (i.e., if the previous element is not in the set). If it is the start of a sequence, we can keep checking for the next elements in the sequence until we find a break. We can keep track of the longest sequence length found.
        // Create a hash set to store the elements of the array
        unordered_set<int> s(nums.begin(),nums.end());
        int longest=0;
        for(int num:nums){
            // Check if the current number is the start of a sequence
            if(s.find(num-1)==s.end()){
                int count=1;
                // Keep checking for the next elements in the sequence
                while(s.find(num+count)!=s.end()){
                    count++;    
                }
                longest=max(longest,count);
            }
        }
        return longest;
    
}


int main(){

    vector<int> nums = {100,4,200,1,3,2};
    vector<int> nums2 = {0,3,7,2,5,8,4,6,0,1};
    vector<int> nums3 = {1,0,1,2};
    cout<<"Brute: "<<brute(nums)<<endl;
    cout<<"Better: "<<better(nums)<<endl;
    cout<<"Optimal: "<<optimal(nums)<<endl;
    cout<<"Brute: "<<brute(nums2)<<endl;
    cout<<"Better: "<<better(nums2)<<endl;      
    cout<<"Optimal: "<<optimal(nums2)<<endl;
    cout<<"Brute: "<<brute(nums3)<<endl;
    cout<<"Better: "<<better(nums3)<<endl;
    cout<<"Optimal: "<<optimal(nums3)<<endl;

    return 0;
}