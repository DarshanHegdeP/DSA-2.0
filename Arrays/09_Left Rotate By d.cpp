// 12345 -> By 2 places -> 34512
#include <bits/stdc++.h>
using namespace std;

void brute_rotate(vector<int> &arr, int d)
{
    int n = arr.size();
    d = d % n;
    vector<int> temp;
    for (int i = 0; i < d; i++)
    {
        temp.push_back(arr[i]);
    }

    for (int i = d; i < n; i++)
    {
        arr[i - d] = arr[i];
    }
    int j = 0;
    for (int i = n - d; i < n; i++)
    {
        arr[i] = temp[j];
        j++;
    }
}
void optimal_rotate(vector<int> &arr, int d)
{
    int n = arr.size();
    d = d % n;
    reverse(arr.begin(), arr.begin() + d);
    reverse(arr.begin() + d, arr.end());
    reverse(arr.begin(), arr.end());
}

int main()
{
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {1, 2, 3, 4, 5};
    cout << "Before left rotate by 2 place" << endl;
    for (auto item : arr1)
    {
        cout << item << " ";
    }
    cout << endl;
    brute_rotate(arr1, 2);
    optimal_rotate(arr2, 2);
    cout << "After left rotate by 2 place---Brute" << endl;
    for (auto item : arr1)
    {
        cout << item << " ";
    }
    cout << endl;
    cout << "After left rotate by 2 place---Optimal" << endl;
    for (auto item : arr2)
    {
        cout << item << " ";
    }
    cout << endl;
    return 0;
}