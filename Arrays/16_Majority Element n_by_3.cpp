// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
// Input: nums = [3,2,3]
// Output: [3]
// Example 2:

// Input: nums = [1]
// Output: [1]
// Example 3:

// Input: nums = [1,2]
// Output: [1,2]

#include <bits/stdc++.h>
using namespace std;

vector<int> optimal(vector<int> &arr){
    vector<int> ans;
    int count1=0;
    int count2=0;
    int candidate1=INT_MIN;
    int candidate2=INT_MIN;

    for(auto item: arr){
        if(item==candidate1) count1++;
        else if(item==candidate2) count2++;
        else if(count1 ==0) {
            candidate1=item;
            count1++;
        }
        else if(count2==0){
            candidate2=item;
            count2++;
        }
        else{
            count1--;
            count2--;
        }
    }
        int counter1=0,counter2=0;
        for(auto item:arr){
            if(item==candidate1) counter1++;
            else if(item==candidate2) counter2++;
            
            
        }
        if(counter1>arr.size()/3)  ans.push_back(candidate1);
        if(counter2>arr.size()/3) ans.push_back(candidate2);

        return ans;
    
}


int main(){
    vector<int> arr={1,2,4,5,2,3,5,5};
    vector<int> ans=optimal(arr);
    for(auto item: ans){
        cout<<item<<" ";
    }
    return 0;
}