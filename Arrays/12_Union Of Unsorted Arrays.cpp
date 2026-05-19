# include <bits/stdc++.h>
using namespace std;

vector<int> brute_union(vector<int>& arr1,vector<int>& arr2){
    // Time Complexity: O((m+n)log(m+n)) + O(m+n) ~ O((m+n)log(m+n))
    // Space Complexity: O(m+n) for temp vector

    int m=arr1.size();
    int n=arr2.size();
    vector<int> temp;
    for(int  i=0;i<m;i++){
        temp.push_back(arr1[i]);
    }
    for(int  i=0;i<n;i++){
        temp.push_back(arr2[i]);
    }
    
    sort(temp.begin(),temp.end());
    vector<int> res;
    for(auto item: temp){
        if(res.empty() || item!=res.back())   res.push_back(item);
    }
    return res;
}
vector<int> better_union(vector<int>& arr1,vector<int>& arr2){
    // Time Complexity: O(mlogm + nlogn) for sorting both arrays + O(m+n) for merging ~ O(mlogm + nlogn)
    // Space Complexity: O(m+n) for temp vector
    vector<int> res;
  int m=arr1.size();
    int n=arr2.size();
    set<int> s;
    for(auto item:arr1){
        s.insert(item);
    }
    for(auto item:arr2){
        s.insert(item);
    }
    for(auto item:s){
        res.push_back(item);
    }
    return res;

}
vector<int> optimal_union(vector<int>& arr1,vector<int>& arr2){
 vector<int> res;
 // Time Complexity: O(m+n) for inserting elements into the set + O(k) for iterating over the set where k is the number of unique elements in both arrays ~ O(m+n+k)
    // Space Complexity: O(k) for the set and result vector where k is the number of unique elements in both arrays                     
      int m=arr1.size();
    int n=arr2.size();
    unordered_set<int> s;
      for(auto item:arr1){
        s.insert(item);
    }
    for(auto item:arr2){
        s.insert(item);
    }
    for(auto item:s){
        res.push_back(item);
    }

    return res;
}
int main(){
    vector<int> arr1={1,2,4,2,3,41,2,};
    vector<int> arr2={3,4,5,6};
    vector<int> res1= brute_union(arr1,arr2);
    vector<int> res2= better_union(arr1,arr2);
    vector<int> res3= optimal_union(arr1,arr2);

    for(auto item: res1){
        cout<<item<<" ";
    }
    cout<<endl;
    for(auto item: res2){
        cout<<item<<" ";
    }
    cout<<endl;
    for(auto item: res3){
        cout<<item<<" ";
    }
    cout<<endl;

    return 0;
}