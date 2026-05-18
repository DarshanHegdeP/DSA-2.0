#include <bits/stdc++.h>
using namespace std;


void brute_meth(vector<int>& arr){
    //Copy the unique elements first and then copy back and place remaining as zero

    vector<int> temp;
    for(int i=0;i<arr.size();i++){
        if(arr[i]!=0) temp.push_back(arr[i]);
        
    }
    for(int i=0;i<arr.size();i++){
       if(i<temp.size()){
         arr[i]=temp[i];
       }
       else arr[i]=0;
    }
}

void optimal_meth(vector<int>& arr){
// Two pointer: First find the first zero element's index later make swaps so that all zeroes end up at last
    int n=arr.size();
    int j=0;
    for(j=0;j<n;j++){
        if(arr[j]==0) break;
    }
    for(int i=j+1;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
}
int main(){
    vector<int> arr={1,2,0,2,0,4,5,5,78,5};
    vector<int> arr2={1,2,0,2,0,4,5,5,78,5};
    brute_meth(arr);
    optimal_meth(arr2);
    for(auto item: arr){
        cout<<item<<" ";
    }
    cout<<endl;
    for(auto item: arr2){
        cout<<item<<" ";
    }
    cout<<endl;
    return 0;
}