// Find the missing number in an sorted array of size n-1 containing numbers from 1 to n
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int optimal(vector<int> &arr){
            int n=arr.size()+1;
            int sum=n*(n+1)/2;
            for(int i=0;i<arr.size();i++){
                sum-=arr[i];
            }
            return sum; 
        }

       int optimal2(vector<int> &arr) {
    int n = arr.size()+1;
    int res = 0;

    for(int i = 0; i < n-1; i++) {
        res ^= (i+1) ^ arr[i];
    }
    res^=n;

    return res;
}

        int bruteForce(vector<int> &arr){
            int n=arr.size();int i;
            for( i=0;i<n;i++){
                if(arr[i]!=i+1){
                    return i+1;
                }

            }
            return i;

        }

};
int main(){
    vector<int> arr = {1,2,3,4,6};
    vector<int> arr2 = {1,2,3,4,6};
    vector<int> arr3 = {1,2,3,4,6};
    Solution sol;
    cout<<"Missing number is: "<<sol.optimal(arr)<<endl;
    cout<<"Missing number is: "<<sol.optimal2(arr2)<<endl;
    cout<<"Missing number is: "<<sol.bruteForce(arr3)<<endl;
}