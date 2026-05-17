# include <bits/stdc++.h>
using namespace std;

int optimal(vector<int>& arr){
    int n=arr.size();
    int maxCount=0;
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            count++;
            maxCount=max(count,maxCount);
        }
        else{
            count=0;
        }
    }
    return maxCount;
}

int main(){
    vector<int> arr={1,1,2,3,1,1,1,1};
    int count= optimal(arr);
    cout<<count<<endl;

    return 0;
}