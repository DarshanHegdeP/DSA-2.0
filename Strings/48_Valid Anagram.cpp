// 242. Valid Anagram
// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// Input: s = "anagram", t = "nagaram"

// Output: true
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
//Brute Force Approach
//Time Complexity: O(nlogn)
//Space Complexity: O(1)
//Explanation: We can sort both strings and compare them. If they are equal, then t is an anagram of s.
   bool isAnagram(string s, string t) {
       
        if(s.size()!=t.size()) return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s==t) 
        return true;
        else return false;
    }
//Optimal Approach
//Time Complexity: O(n)
//Space Complexity: O(1)
//Explanation: We can use a frequency array of size 26 to count the occurrences of each character in both strings. If the frequency counts match for all characters, then t is an anagram of s.
    bool optimal_isAnagram(string s, string t) {
        int freq[26]={0};
        if(s.size()!=t.size()) return false;
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']+=1;
            freq[t[i]-'a']-=1;
        }
        for(auto item:freq){
            if(item!=0) return false;
        }
        return true;
    }
};