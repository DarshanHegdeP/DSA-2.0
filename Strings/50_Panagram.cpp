// 1832. Check if the Sentence Is Pangram
// A pangram is a sentence where every letter of the English alphabet appears at least once.
// Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.

// Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
// Output: true
// Explanation: sentence contains at least one of every letter of the English alphabet.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
//Better Approach
//Time Complexity: O(n)
//Space Complexity: O(1)
//Explanation: We can use a frequency array of size 26 to count the occurrences of each character in the sentence. If all characters have a frequency of at least 1, then the sentence
// is a pangram.
    bool better_checkIfPangram(string sentence) {
        vector<int> freq(26,0);
        for(auto item:sentence){
            freq[item-'a']=1;
        }
        for(auto item:freq){
            if(item==0) return false;
        }
        return true;
    }

//Optimal Approach
//Time Complexity: O(n)
//Space Complexity: O(1)
//Explanation: We can use a frequency array of size 26 to count the occurrences of each character in the sentence. We can also use a counter to keep track of how many unique characters we
// have seen so far. If the counter reaches 26, then the sentence is a pangram.
      bool optimal_1_checkIfPangram(string sentence) {
        vector<int> freq(26, 0);
        int counter = 0;
        for (auto item : sentence) {

            if (freq[item - 'a'] != 1) {
                freq[item - 'a'] = 1;
                counter += 1;
            }
            if (counter == 26)
                return true;
        }
        return false;
    }

    //Optimal Approach
    //Time Complexity: O(n)
    //Space Complexity: O(1)
    //Explanation: We can use a bitmask to keep track of which characters we have seen so far. We can use a 32-bit integer to represent the 26 letters of the English alphabet. If the bitmask has all 26 bits set, then the sentence is a pangram
    bool optimal_2_checkIfPangram(string sentence) {
        int bitmask = 0;
        for (auto item : sentence) {
            bitmask |= (1 << (item - 'a'));
        }
        return bitmask == (1 << 26) - 1;
    }

    int main() {
        Solution s;
        string sentence = "thequickbrownfoxjumpsoverthelazydog";
        cout << s.better_checkIfPangram(sentence) << endl; // Output: 1 (true)
        cout << s.optimal_1_checkIfPangram(sentence) << endl; // Output: 1 (true)
        cout << s.optimal_2_checkIfPangram(sentence) << endl; // Output: 1 (true)
        return 0;
    }
};