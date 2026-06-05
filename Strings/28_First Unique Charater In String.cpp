// 387. First Unique Character in a String
// Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
// Example 1:
// Input: s = "leetcode"
// Output: 0
// Explanation:
// The character 'l' at index 0 is the first character that does not occur at any other index.
// Example 2:
// Input: s = "loveleetcode"
// Output: 2

#include <bits/stdc++.h>
using namespace std;

int brute(string s){
    // Time Complexity: O(N^2) where N is the length of the string. This is because for each character, we check if it is unique by comparing it with every other character in the string.
    // Space Complexity: O(1) as we are not using any additional data structures that grow with the input size.
    // This brute force approach checks each character in the string and compares it with every other character to determine if it is unique. If a unique character is found, its index is returned. If no unique character exists, -1 is returned.
    for(int i=0;i<s.size();i++){
        bool repeat=false;
        for(int j=0;j<s.size();j++){
            if(s.at(i)==s.at(j)&&i!=j){
                repeat=true;
                break;
            }
         
        }
           if(!repeat) return i;
    }
    return -1;
}

int better(string s){
    // Time Complexity: O(N) where N is the length of the string. This is because we traverse the string twice: once to count the frequency of each character and once to find the first unique character.
    // Space Complexity: O(1) as we are using a fixed-size array (or hash map) to store the frequency of characters, which does not grow with the input size.
    // This approach uses a hash map (or an array for character counts) to count the frequency of each character in the string. After counting, it traverses the string again to find the first character that has a frequency of 1, which is the first unique character. If no unique character exists, -1 is returned.
    unordered_map<char,int> mp;
    for(auto item:s){
        mp[item-'a']++;
    }
    for(int i=0;i<s.size();i++){
        if(mp[(s[i]-'a')]==1) return i;
    }
    return -1;
}
int optimal(string s){
    // Time Complexity: O(N) where N is the length of the string. This is because we traverse the string twice: once to count the frequency of each character and once to find the first unique character.
    // Space Complexity: O(1) as we are using a fixed-size array to store the frequency of characters, which does not grow with the input size.
    // This approach uses a fixed-size array to count the frequency of each character in the string. After counting, it traverses the string again to find the first character that has a frequency of 1, which is the first unique character. If no unique character exists, -1 is returned.

    vector<int> freq(26,0);
    for(auto item:s){
        freq[item-'a']++;
    }
    for(int i=0;i<s.size();i++){
        if(freq[s[i]-'a']==1) return i;
    }
    return -1;
}

int main(){
    string s = "leetcode";
    int ans = brute(s);
    int ans1=better(s);
    int ans2=optimal(s);
    cout << "The index of the first unique character is: " << ans << endl;
    cout << "The index of the first unique character is: " << ans1 << endl;
    cout << "The index of the first unique character is: " << ans2 << endl;
    
    return 0;

}