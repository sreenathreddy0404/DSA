#include <bits/stdc++.h>
using namespace std;

// if the size of arr is n then no of subsets is 2^n;

void subsets(int arr[], int n, vector<vector<int>> &v)
{
    int subs = 1 << n; // 2^n

    // see i in terms of binary value
    // 0   0   0 -->0   []
    // 0   0   1 -->1   [1]
    // 0   1   0 -->2   [2]
    // 0   1   1 -->3   [1,2]
    // 1   0   0 -->4   [3]
    // 1   0   1 -->5   [1,3]
    // 1   1   0 -->6   [2,3]
    // 1   1   1 -->7   [1,2,3]

    // 0   1   2 -->indexes of array
    // if the index bit is set then add element to temp vector

    // iterate from 0 to 2^n-1
    for (int i = 0; i < subs; i++)
    {

        // temporary vector to store elements of array;
        vector<int> t;

        // iterate for 0 to lenght of array
        for (int j = 0; j < n; j++)
        {

            // this if condition check the index bit is set or not.
            if (i & (1 << j))
            {
                t.push_back(arr[j]);
            }
        }
        v.push_back(t);
    }
}

int main()
{
    int arr[] = {1, 2, 3};
    vector<vector<int>> v;
    subsets(arr, 3, v);
    for (auto k : v)
    {
        for (auto l : k)
        {
            cout << l << ' ';
        }
        cout << endl;
    }
}