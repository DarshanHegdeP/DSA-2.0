// 989. Add to Array-Form of Integer
// The array-form of an integer num is an array representing its digits in left to right order.

// For example, for num = 1321, the array form is [1,3,2,1].
// Given num, the array-form of an integer, and an integer k, return the array-form of the integer num + k.

// Example 1:

// Input: num = [1,2,0,0], k = 34
// Output: [1,2,3,4]
// Explanation: 1200 + 34 = 1234
// Example 2:

// Input: num = [2,7,4], k = 181
// Output: [4,5,5]
// Explanation: 274 + 181 = 455
// Example 3:

// Input: num = [2,1,5], k = 806
// Output: [1,0,2,1]
// Explanation: 215 + 806 = 1021
 

// Constraints:

// 1 <= num.length <= 104
// 0 <= num[i] <= 9
// num does not contain any leading zeros except for the zero itself.
// 1 <= k <= 104

# include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> brute_addToArrayForm(vector<int>& num,int k){
        // We can convert the array-form of num to an integer, add k to it, and then convert the result back to an array-form. However, this approach may not be efficient for large values of num and k, as it may lead to integer overflow.
        // The time complexity of this solution is O(n + log(k)), where n is the length of num and log(k) is the number of digits in k. The space complexity is O(n + log(k)) for the result vector.
        //But this approach is not optimal as it may lead to integer overflow for large values of num and k. We can use a better approach that does not require converting the array-form of num to an integer.
        long long int number = 0;
        for (int i = 0; i < num.size(); i++) {
            number = number * 10 + num[i];
        }
        number += k;
        vector<int> ans;
        while (number > 0) {
            ans.push_back(number % 10);
            number /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;

    }

    vector<int> better_addToArrayForm(vector<int>& num,int k){
        // We can add the digits of num and k from the end, and keep track of the carry. We can use a vector to store the result, and reverse it at the end.
        // The time complexity of this solution is O(max(n, log(k))), where n is the length of num and log(k) is the number of digits in k. The space complexity is O(max(n, log(k))) for the result vector.
        vector<int> ans;
        int i = num.size() - 1;
        int carry=0;
        while(i>=0 || k>0 || carry){
            int digit1=(i>=0)?num[i]:0;
            int digit2=k%10;
            int sum=digit1+digit2+carry;
            ans.push_back(sum%10);
            carry=sum/10;
            i--;
            k/=10;
        }
        reverse(ans.begin(),ans.end());
        
        return ans;

    }

    vector<int> optimal_addToArrayForm(vector<int>& num, int k) {
        // We can add the digits of num and k from the end and use k for carrying . We can use a vector to store the result, and reverse it at the end.
        // We can also use a while loop to iterate through the digits of num and k, and add them together. We can use the modulus operator to get the last digit of the sum, and the division operator to get the carry.
        // The time complexity of this solution is O(max(n, log(k))), where n is the length of num and log(k) is the number of digits in k. The space complexity is O(max(n, log(k))) for the result vector.
        
        vector<int> ans;
        int i = num.size() - 1;
        while (i >= 0 || k > 0) {
            if (i >= 0) {
                k = k + num[i];
                i--;
            }
            ans.push_back(k % 10);

            k /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> arr={1,2,0,0};
    int k=34;
    vector<int> optimal_result = s.optimal_addToArrayForm(arr,k);
    vector<int> brute_result = s.brute_addToArrayForm(arr,k);
    vector<int> better_result = s.better_addToArrayForm(arr,k);
    cout<<"Optimal Result: ";
    for(int i: optimal_result){
        cout<<i<<" ";
    }    cout<<endl;
    cout<<"Brute Force Result: ";   
    for(int i: brute_result){
        cout<<i<<" ";
    }    cout<<endl;
    cout<<"Better Result: ";
    for(int i: better_result){
        cout<<i<<" ";
    }    cout<<endl;    
    return 0;
}