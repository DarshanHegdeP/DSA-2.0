

// 349. Intersection of Two Arrays
// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

// Example 1:

// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2]
// Example 2:

// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [9,4]
// Explanation: [4,9] is also accepted.

#include <bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int> &a,vector<int> b){
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int i=0,j=0;
    vector<int> res;
    while(i<a.size()&& j<b.size()){
        if(a[i]<b[j]) i++;
        else if(a[i]>b[j]) j++;
        else{
            if(res.empty() || res.back()!=a[i]){
                res.push_back(a[i]);i++;j++;
            }
        }
    }
    return res;
}

int main(){
    vector<int> a={1,2,3,6,4,5};
    vector<int> b={2,4,6,7};
    vector<int> res=intersection(a,b);
    for(auto item:res){
        cout<<item<<" ";

    }
    return 0;
}