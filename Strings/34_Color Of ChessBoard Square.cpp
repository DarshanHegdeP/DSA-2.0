// 1812. Determine Color of a Chessboard Square
// You are given coordinates, a string that represents the coordinates of a square of the chessboard. Below is a chessboard for your reference.

// Return true if the square is white, and false if the square is black.

// The coordinate will always represent a valid chessboard square. The coordinate will always have the letter first, and the number second.
// Example 1:
// Input: coordinates = "a1"
// Output: false
// Explanation: From the chessboard above, the square with coordinates "a1" is black, so return false.

#include<bits/stdc++.h>
using namespace std;

//Solution explained: The color of the square can be determined by the sum of the ASCII values of the letter and number in the coordinates. If the sum is even, the square is black; if it's odd, the square is white.
// For example, for "a1":
// - The ASCII value of 'a' is 97.
// - The ASCII value of '1' is 49.
// - The sum is 97 + 49 = 146, which is even, so "a1" is a black square, and the function returns false.
// characters 'a' to 'h' have ASCII values from 97 to 104, and digits '1' to '8' have ASCII values from 49 to 56. By adding these values together and checking if the sum is even or odd, we can determine the color of the square on the chessboard.
// char+int will give us the sum of the ASCII values of the character and the digit, which we can then check for even or odd to determine the color of the square.


class Solution {
public:
    bool squareIsWhite(string coordinates) {
     
        return (coordinates[0]+coordinates[1])%2!=0;
            }
};
int main(){
    Solution s;
    string coordinates = "a1";
    cout<<s.squareIsWhite(coordinates);
}