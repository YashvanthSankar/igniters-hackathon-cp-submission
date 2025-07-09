#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> res;

void final_enchanted_array(int t, vector<int> &arr, vector<int> &exp)
{
    int n = arr.size();
    int q = exp.size();

    for (int j = 0; j < q; j++)
    {
        int pow2 = 1 << exp[j];
        int inc = 1 << (exp[j] - 1);

        for (int i = 0; i < n; i++)
        {
            if (arr[i] % pow2 == 0)
            {
                arr[i] += inc;
            }
        }
    }
    res.push_back(arr);
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<int> exp(q);
        for (int i = 0; i < q; i++)
        {
            cin >> exp[i];
        }
        final_enchanted_array(t, arr, exp);
    }

    for (auto &r : res)
    {
        for (int i = 0; i < r.size(); i++)
        {
            cout << r[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
