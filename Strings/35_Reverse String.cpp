#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left=0;
        int right=s.size()-1;
        while(left<=right){
            int temp=s[left];
            s[left]=s[right];
            s[right]=temp;
            left++;
            right--;
        }
    }
};
int main(){
    vector<char> s={'h','e','l','l','o'};
    Solution sol;
    sol.reverseString(s);
    for(char c:s){
        cout<<c<<" ";
    }
}