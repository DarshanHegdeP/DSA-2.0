// 73. Set Matrix Zeroes
// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
// You must do it in place.

// Example 1:

// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]

#include <bits/stdc++.h>
using namespace std;

// Brute approach: mark zeroed cells with a sentinel (-1), then convert them to 0.
// This avoids overwriting original zeros too early.
void brute(vector<vector<int>> &mat)
{   
    int m = mat.size();
    int n = mat[0].size();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0) {
                // Mark every non-zero entry in this row as -1
                for (int k = 0; k < n; k++) {
                    if (mat[i][k] != 0) {
                        mat[i][k] = -1;
                    }
                }
                // Mark every non-zero entry in this column as -1
                for (int k = 0; k < m; k++) {
                    if (mat[k][j] != 0) {
                        mat[k][j] = -1;
                    }
                }
            }
        }
    }

    // Convert all marked values to 0
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == -1) {
                mat[i][j] = 0;
            }
        }
    }
}

// Better approach: use two auxiliary arrays to remember which rows and columns contain zeros.
void better(vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();
    vector<int> row(m, 1);
    vector<int> col(n, 1);

    // Record zero rows and zero columns.
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0) {
                row[i] = 0;
                col[j] = 0;
            }
        }
    }

    // Set cells to 0 if their row or column was marked.
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (row[i] == 0 || col[j] == 0) {
                mat[i][j] = 0;
            }
        }
    }
}

// Optimal approach: use the matrix itself to store row/column markers and one extra variable for the first column.
void optimal(vector<vector<int>> &mat)
{
    int col = 1;            // Tracks whether the first column should be zeroed.
    int m = mat.size();
    int n = mat[0].size();

    // Use first row and first column as marker storage.
    for (int i = 0; i < m; i++) {
        if (mat[i][0] == 0) {
            col = 0;
        }
        for (int j = 1; j < n; j++) {
            if (mat[i][j] == 0) {
                mat[i][0] = 0;    // mark this row
                mat[0][j] = 0;    // mark this column
            }
        }
    }

    // Iterate from bottom-right to top-left to avoid overwriting markers too early.
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j > 0; j--) {
            if (mat[i][0] == 0 || mat[0][j] == 0) {
                mat[i][j] = 0;
            }
        }
        // Handle the first column separately.
        if (col == 0) {
            mat[i][0] = 0;
        }
    }
}

int main()
{
    vector<vector<int>> arr = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    vector<vector<int>> arr2 = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    vector<vector<int>> arr3 = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};

    brute(arr);       // run brute-force version
    better(arr2);     // run better version using extra row/col arrays
    optimal(arr3);    // run optimal in-place version

    cout << "Result::" << endl;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[0].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Result::" << endl;
    for (int i = 0; i < arr2.size(); i++) {
        for (int j = 0; j < arr2[0].size(); j++) {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Result::" << endl;
    for (int i = 0; i < arr3.size(); i++) {
        for (int j = 0; j < arr3[0].size(); j++) {
            cout << arr3[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}