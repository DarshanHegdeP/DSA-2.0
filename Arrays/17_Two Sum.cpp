// Two Sum Return the indices of the two numbers such that they add up to a specific target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// Example:
// Given nums = [2, 7, 11, 15], target = 9,
// Because nums[0] + nums[1] = 2 + 7 =  9,
// return [0, 1].

#include <bits/stdc++.h>
using namespace std;

vector<int> brute_meth(vector<int>& arr,int target){
    vector<int> ans;
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[i]+arr[j]==target){
                return {i,j};
            }
        }
    }
    return {};
}
vector<int> optimal_meth(vector<int>& arr,int target){
    unordered_map<int,int> mp;
    for(int i=0;i<arr.size();i++){
        int need=target-arr[i];
        if(mp.find(need)!=mp.end()){
            return {i,mp[need]};
        }
        mp[arr[i]]=i;
    }
    return {};
}

int main(){
    vector<int> arr={1,3,4,7,4,10,6};
    vector<int> ans=brute_meth(arr,9);
    vector<int> ans2=optimal_meth(arr,9);
    for(auto item: ans){
        cout<<item<<" ";
    }
    cout<<endl;
      for(auto item: ans2){
        cout<<item<<" ";
    }
    cout<<endl;
}