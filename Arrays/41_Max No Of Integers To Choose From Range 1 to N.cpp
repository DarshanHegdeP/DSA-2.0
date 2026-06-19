// 2554. Maximum Number of Integers to Choose From a Range I
// You are given an integer array banned and two integers n and maxSum. You are choosing some number of integers following the below rules:

// The chosen integers have to be in the range [1, n].
// Each integer can be chosen at most once.
// The chosen integers should not be in the array banned.
// The sum of the chosen integers should not exceed maxSum.
// Return the maximum number of integers you can choose following the mentioned rules.

 

// Example 1:

// Input: banned = [1,6,5], n = 5, maxSum = 6
// Output: 2
// Explanation: You can choose the integers 2 and 4.
// 2 and 4 are from the range [1, 5], both did not appear in banned, and their sum is 6, which did not exceed maxSum.
// Example 2:

// Input: banned = [1,2,3,4,5,6,7], n = 8, maxSum = 1
// Output: 0
// Explanation: You cannot choose any integer while following the mentioned conditions.

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
int brute(vector<int>& banned, int n, int maxSum) {
    int sum = 0;
    int count = 0;

    for(int i = 1; i <= n; i++) {
        bool bannedNum = false;

        for(int j = 0; j < banned.size(); j++) {
            if(banned[j] == i) {
                bannedNum = true;
                break;
            }
        }

        if(!bannedNum) {
            if(sum + i > maxSum) break;
            sum += i;
            count++;
        }
    }

    return count;
}
    int optimal_maxCount(vector<int>& banned, int n, int maxSum) {
        vector<int> booler(n,1);
        for(int i=0;i<banned.size();i++){
           if(banned[i]<=n) booler[banned[i]-1]=0;
        }
        int sum=0;
        int counter=0;
        for(int i=1;i<=n;i++){
            if(booler[i-1]){
                sum+=i;
                if(sum<=maxSum) counter++;
                
            }
            if(sum>maxSum) break;
        }
        return counter;
    }

    int maxCount(vector<int>& banned, int n, int maxSum) {
     int counter=0;
     unordered_set<int> st;
     for(auto item:banned) st.insert(item);
     int sum=0;
     for(int i=1;i<=n;i++){
        if(!st.count(i)){
            sum+=i;
            if(sum<=maxSum) counter++;
        }
        if(sum>maxSum) return counter;
     }
        return counter;
    }
};

int main(){
    Solution sol;
    vector<int> arr={1,6,5};
    int optimal=sol.optimal_maxCount(arr,5,6);
    cout<<optimal<<endl;
    cout<<sol.brute(arr,5,6)<<endl;
    cout<<sol.maxCount(arr,5,6)<<endl;
}