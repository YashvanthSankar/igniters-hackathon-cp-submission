#include <bits/stdc++.h>
using namespace std;

vector<int> res;
void max_mystic_power(int n, vector<int> &arr)
{
    int max_power = 0;

    for (int i = 0; i < n; i++)
    {
        int current_power = arr[i];
        max_power = max(max_power, current_power);
        for (int j = i + 1; j < n; j++)
        {
            current_power &= arr[j];
            if (current_power == 0)
                break;
        }
        if (current_power > max_power)
            max_power = current_power;
    }

    res.push_back(max_power);
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

        max_mystic_power(n, arr);
    }

    for (int r : res)
    {
        cout << r << endl;
    }

    return 0;
}