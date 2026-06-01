// 2520. Count the Digits That Divide a Number

// Given an integer num, return the number of digits in num that divide num.

// An integer val divides nums if nums % val == 0.

 

// Example 1:

// Input: num = 7
// Output: 1
// Explanation: 7 divides itself, hence the answer is 1.
// Example 2:

// Input: num = 121
// Output: 2
// Explanation: 121 is divisible by 1, but not 2. Since 1 occurs twice as a digit, we return 2.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDigits(int num) {
        int n=num;
        int count=0;
        while(num!=0){
            int rem=num%10;
            num=num/10;
            if(n%rem==0) count++;

        }
        return count;
    }
};
int main(){
    int num=121;
    Solution s;
    cout<<s.countDigits(num);
}