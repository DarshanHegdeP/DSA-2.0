// 151. Reverse Words in a String
// Given an input string s, reverse the order of the words.
// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
// Return a string of the words in reverse order concatenated by a single space.
// Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.
// Example 1:

// Input: s = "the sky is blue"
// Output: "blue is sky the"
// Example 2:

// Input: s = "  hello world  "
// Output: "world hello"
// Explanation: Your reversed string should not contain leading or trailing spaces.
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Better Approach
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    // Explanation: We can use a vector to store the words in the string. We can then reverse the vector and concatenate the words to form the final string. We can also use a temporary string
    //  to store the current word while iterating through the string. If we encounter a space, we can push the temporary string to the vector and clear it. Finally, we can reverse the vector and concatenate the words to form the final string.
    //  We can also use a temporary string to store the current word while iterating through the string. If we encounter a space, we can push the temporary string to the vector and clear it. Finally, we can reverse the vector and concatenate the words to form the final string.

    string better_reverseWords(string s)
    {
        vector<string> ans;
        string temp;
        for (auto c : s)
        {
            if (c == ' ')
            {
                if (!temp.empty())
                {
                    ans.push_back(temp);
                    temp.clear();
                }
            }
            else
            {
                temp.push_back(c);
            }
        }
        if (!temp.empty())
        {
            ans.push_back(temp);
            temp.clear();
        }
        for (int i = ans.size() - 1; i > 0; i--)
        {
            temp += ans[i];
            temp += ' ';
        }
        temp += ans[0];
        return temp;
    }

    void reverseS(string &s, int start, int end)
    {

        while (start < end)
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }

    // Optimal Approach
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    // Explanation: We can reverse the entire string and then reverse each word in the string. Finally, we can remove any extra spaces from the string.
    //  We can use two pointers to remove the extra spaces. One pointer will point to the current character in the string and the other pointer will point to the position where we want to copy the character. If the current character is not a space, we will copy it to the position pointed by the second pointer and increment both pointers. If the current character is a space, we will skip it and only increment the first pointer. Finally, we will resize the string to remove any extra characters at the end.

    string optimal_reverseWords(string s)
    {

        int n = s.size();

        // Reverse entire string
        reverseS(s, 0, n - 1);

        // Reverse each word
        int start = 0;

        for (int end = 0; end <= n; end++)
        {

            if (end == n || s[end] == ' ')
            {
                reverseS(s, start, end - 1);
                start = end + 1;
            }
        }

        // Remove extra spaces
        int i = 0;
        int j = 0;

        while (j < n)
        {
            // leaading spaces   skip
            while (j < n && s[j] == ' ')
                j++;
            // words   copy
            while (j < n && s[j] != ' ')
                s[i++] = s[j++];
            // trailing spaces   skip
            while (j < n && s[j] == ' ')
                j++;
            // single space   copy
            if (j < n)
                s[i++] = ' ';
        }

        s.resize(i);

        return s;
    }

    int main()
    {
        Solution s;
        string str = "  hello world  ";
        cout << s.better_reverseWords(str) << endl; // Output: "world hello"
        cout << s.optimal_reverseWords(str) << endl; // Output: "world hello"
        return 0;
    }
};
