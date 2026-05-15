

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

vector<int> optimal(vector<int> &a,vector<int> b){
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int i=0,j=0;
    vector<int> res;
    while(i<a.size()&& j<b.size()){
        if(a[i]<b[j]) i++;
        else if(a[i]>b[j]) j++;
        else{
            if(res.empty() || res.back()!=a[i]){
                res.push_back(a[i]);
            }i++;j++;
        }
    }
    return res;
}

vector<int> better(vector<int> a,vector<int> b){
    unordered_set<int> s1(a.begin(),a.end());
    unordered_set<int> res_set;
    
    for(auto item:b){
        if(s1.count(item)){
           res_set.insert(item);
        }
    }
   vector<int> res(res_set.begin(),res_set.end());
   return res;
}

vector<int> brute(vector<int> a,vector<int> b){
    vector<int> res;
    for(int i=0;i<a.size();i++){
        bool found=false;
        for(int k=0;k<res.size();k++){
            if(res[k]==a[i]) {found=true;break;}
        }
        if(found) continue;
        for(int j=0;j<b.size();j++){
            if(a[i]==b[j]){
                res.push_back(a[i]);
                break;
            }
        }
    }
    return res;
}
int main(){
    vector<int> a={1,2,3,6,4,5};
    vector<int> b={2,4,6,7};
    vector<int> res2=better(a,b);
    vector<int> res3=brute(a,b);
    vector<int> res=optimal(a,b);
    cout<< "Optimal : "<<endl;
    for(auto item:res){
        cout<<item<<" ";

    }
    cout<<endl;
    cout<< "Better : "<<endl;
    for(auto item:res2){
        cout<<item<<" ";

    }
     cout<<endl;
    cout<< "Brute : "<<endl;
    for(auto item:res3){
        cout<<item<<" ";

    }
     cout<<endl;
    return 0;
}