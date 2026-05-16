// 204. Count Primes
/
// Given an integer n, return the number of prime numbers that are strictly less than n.

// Example 1:

// Input: n = 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
// Example 2:

// Input: n = 0
// Output: 0
// Example 3:

// Input: n = 1
// Output: 0
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n,true);
       if (n <= 2) return 0;
        isPrime[2]=true;
        int count=0;
        for(int i=2;i<n;i++){

            if(isPrime[i]){
                count+=1;
                for(long j=(long)i*i;j<n;j+=i){
                    isPrime[(int)j]=false;
                }
            }
        }
        return count;
        
    }
};

int main(){
    int n=10;
    Solution sol;
    int result = sol.countPrimes(n);
    cout<<result;
}