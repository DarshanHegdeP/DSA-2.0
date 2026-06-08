#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums,int target){
        int start=0;
        int end=nums.size()-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) {
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return -1;
    }


    int recursive(vector<int>& nums,int target,int st,int end){
        if(st>end) return -1;
        int mid=(st+end)/2;
        if(nums[mid]==target) return mid;
        else if(nums[mid]> target) return recursive(nums,target,st,mid-1);
        else return recursive(nums,target,mid+1,end);
    }
};

    int main(){
        Solution s;
       vector<int> nums = {1, 2, 3, 4, 5};
       cout<< "Iterative"<<s.search(nums,4)<<endl;
       cout<< "Recursive"<<s.recursive(nums,4,0,nums.size()-1)<<endl;
       return 0;
    }