#include <bits/stdc++.h>
using namespace std;

int optimal(vector<int>& nums) {

    int count = 0;
    int candidate = -1;

    for(auto item : nums){

        if(count == 0){
            candidate = item;
            count = 1;
        }
        else if(item == candidate){
            count++;
        }
        else{
            count--;
        }
    }

    int counter = 0;

    for(auto item : nums){
        if(candidate == item)
            counter++;
    }

    if(counter > nums.size()/2)
        return candidate;

    return -1;
}

int brute_meth(vector<int> arr){

    for(int i=0;i<arr.size();i++){

        int count = 0;

        for(int j=0;j<arr.size();j++){

            if(arr[i] == arr[j])
                count++;
        }

        if(count > arr.size()/2)
            return arr[i];
    }

    return -1;
}

int better_meth(vector<int> arr){

    unordered_map<int,int> mp;

    for(auto item : arr){
        mp[item]++;
    }

    for(auto item : mp){

        if(item.second > arr.size()/2)
            return item.first;
    }

    return -1;
}

int main(){

    vector<int> arr = {1,2,3,1,1,2,1,1,5};

    cout<<"Majority Element is "<<optimal(arr)<<endl;

    cout<<"Majority Element is "<<brute_meth(arr)<<endl;

    cout<<"Majority Element is "<<better_meth(arr)<<endl;

    return 0;
}