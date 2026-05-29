// 88. Merge Sorted Array

// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

// Merge nums1 and nums2 into a single array sorted in non-decreasing order.

// The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

// Example 1:

// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]
// Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
// The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
// Example 2:

// Input: nums1 = [1], m = 1, nums2 = [], n = 0
// Output: [1]
// Explanation: The arrays we are merging are [1] and [].
// The result of the merge is [1].

#include <bits/stdc++.h>
using namespace std;

void brute(vector<int> &a, int m, int n, vector<int> &b)
{
    //Approach 1: Merge and sort
    // Time complexity: O((m + n) log(m + n)), Space complexity: O(m + n)
    // We first copy the elements of nums2 into the extra space at the end of nums1. Then we sort the entire nums1 array, which now contains all the elements from both arrays
    for (int j = 0; j < n; j++)
    {
        a[m] = b[j];
        m++;
    }
    sort(a.begin(), a.end());
}

void better(vector<int> &a, int m, int n, vector<int> &b)
{
    //Approach 2: Merge using extra space
    // Time complexity: O(m + n), Space complexity: O(m + n)
    // We create a temporary array to hold the merged result. We use two pointers to traverse both input arrays, comparing elements and adding the smaller one to the temporary array. After one of the arrays is fully traversed, we add any remaining elements from the other array to the temporary array. Finally, we copy the merged result back into nums1.
    vector<int> temp;
    int i = 0;
    int j = 0;
    while (i<m && j<n){
        if(a[i]<=b[j]){
            temp.push_back(a[i]);
            i++;
        }
        else{
            temp.push_back(b[j]);
            j++;
        }
    }
    while(j<n){
        temp.push_back(b[j]);
        j++;
    }
    while(i<m){
         temp.push_back(a[i]);
            i++;
    }
    for(int k=0;k<m+n;k++){
        a[k]=temp[k];
    }
}

void optimal(vector<int> &a, int m, int n, vector<int> &b)
{
    //Approach 3: Merge in-place from the end
    // Time complexity: O(m + n), Space complexity: O(1)
    // We use three pointers: one for the end of the merged array (k), and two for the end of the input arrays (i for nums1 and j for nums2). We compare the elements pointed to by i and j, and place the larger one at the position pointed to
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;
    while (i >= 0 && j >= 0)
    {
        if (a[i] >= b[j])
        {
            a[k] = a[i];
            i--;
        }
        else
        {
            a[k] = b[j];
            j--;
        }
        k--;
    }
    while (j >= 0)
    {
        a[k] = b[j];
        k--;
        j--;
    }
}

int main()
{
    vector<int> a = {1, 2, 3, 0, 0, 0};
    vector<int> c = {1, 2, 3, 0, 0, 0};
    vector<int> d = {1, 2, 3, 0, 0, 0};
    vector<int> b = {2, 5, 6};
    optimal(a, 3, 3, b);
    brute(c, 3, 3, b);
    better(d, 3, 3, b);
    cout << "Optimal" << endl;
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "Brute" << endl;
    for (int i = 0; i < c.size(); i++)
    {
        cout << c[i] << " ";
    }
    cout << endl;
    cout << "Better" << endl;
    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;
    return 0;
}