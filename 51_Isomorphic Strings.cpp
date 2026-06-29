// 205. Isomorphic Strings
// Given two strings s and t, determine if they are isomorphic.
// Two strings s and t are isomorphic if the characters in s can be replaced to get t.
// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
// Example 1:

// Input: s = "egg", t = "add"

// Output: true

// Explanation:

// The strings s and t can be made identical by:

// Mapping 'e' to 'a'.
// Mapping 'g' to 'd'.
// Example 2:

// Input: s = "f11", t = "b23"

// Output: false

// Explanation:

// The strings s and t can not be made identical as '1' needs to be mapped to both '2' and '3'.

// Example 3:

// Input: s = "paper", t = "title"

// Output: true

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool optimal_isomorhic(string s,string t){
        vector<char> a(256,0);
        vector<char> b(256,0);
        for(int i=0;i<s.size();i++){
            if(a[s[i]]==0 && b[t[i]]==0){
                a[s[i]]=t[i];
                b[t[i]]=s[i];
            }
            else if(a[s[i]]!=t[i]|| b[t[i]]!=s[i]) 
            return false;
        }

        return true;
    }
    bool better_isIsomorphic(string s, string t) {

        unordered_map<char, char> mp, tp;

        for (int i = 0; i < s.size(); i++) {

            if (mp.count(s[i]) && mp[s[i]] != t[i])
                return false;

            if (tp.count(t[i]) && tp[t[i]] != s[i])
                return false;

            mp[s[i]] = t[i];
            tp[t[i]] = s[i];
        }

        return true;
    }
};


int main(){
    Solution s;
    cout<<s.better_isIsomorphic("egg","add")<<endl;
    cout<<s.optimal_isomorhic("f11","b23")<<endl;
    cout<<s.optimal_isomorhic("paper","title")<<endl;
}