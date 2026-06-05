
// 27. Sum Multiples
// Given a positive integer n, find the sum of all integers in the range [1, n] inclusive that are divisible by 3, 5, or 7.
// Return an integer denoting the sum of all numbers in the given range satisfying the constraint.
// Example 1:
// Input: n = 7
// Output: 21
// Explanation: Numbers in the range [1, 7] that are divisible by 3, 5, or 7 are 3, 5, 6, 7. The sum of these numbers is 21.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfMultiples(int n) {
        int sum=0;
        for(int i=1;i<=n;i++){
            if(i%3==0||i%5==0||i%7==0){
                sum+=i;
            }
        }
        return sum;    
    }
};
int main()
{
    int n = 7;
    Solution sol;
    int ans = sol.sumOfMultiples(n);
    cout << "Sum of multiples of 3, 5, or 7 up to " << n << " is: " << ans << endl;
    return 0;
}