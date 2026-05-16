// 12345 ->23451

#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int> &arr){
    int n=arr.size();
    int temp=arr[0];
    for(int i=0;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    arr[n-1]=temp;
}
int main(){
    vector<int> arr={1,2,3,4,5};
    cout<<"Before left rotate by one place"<<endl;
    for( auto item: arr){
        cout<<item<<" ";
    }
    cout<<endl;
    rotate(arr);
    cout<<"After left rotate by one place"<<endl;
    for( auto item: arr){
        cout<<item<<" ";
    }
    cout<<endl;
    return 0;
}