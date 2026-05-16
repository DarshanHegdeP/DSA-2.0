// 12345 -> 51234
#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int>& arr){
    int n=arr.size();
    int temp=arr[n-1];\
    for(int i=n-2;i>=0;i--){
        arr[i+1]=arr[i];
    }
    arr[0]=temp;
}

int main(){
    vector<int> arr={1,2,3,4,5};
    cout<<"Before right rotate by one place"<<endl;
    for( auto item: arr){
        cout<<item<<" ";
    }
    cout<<endl;
    rotate(arr);
    cout<<"After right rotate by one place"<<endl;
    for( auto item: arr){
        cout<<item<<" ";
    }
    cout<<endl;
    return 0;
}