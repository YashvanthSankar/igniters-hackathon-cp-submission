#include <bits/stdc++.h>
using namespace std;

vector<int> res;
void max_mystic_power(int n, vector<int> &arr)
{
    int max_power = 0;

    for (int i = 0; i < n; i++)
    {
        int current_power = arr[i];                // start with the current element
        max_power = max(max_power, current_power); // update max_power if current_power is greater
        for (int j = i + 1; j < n; j++)
        {
            current_power &= arr[j]; // perform bitwise AND with the next element
            if (current_power == 0)  // if current_power becomes 0, we can stop further calculations
                break;
        }
        if (current_power > max_power) // check if the current_power is greater than max_power
            max_power = current_power; // update max_power
    }

    res.push_back(max_power); // store the result for this test case
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        max_mystic_power(n, arr); // call the function to calculate the maximum mystic power
    }

    for (int r : res)
    {
        cout << r << endl; // print the results
    }

    return 0;
}