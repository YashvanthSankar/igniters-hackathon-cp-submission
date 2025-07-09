#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;

    return true;
}

int nextPrimeP1(int x)
{
    int y = x + 1;
    while (!isPrime(y))
        y++;
    return y;
}
int nextPrimeP2(int x)
{
    while (!isPrime(x))
        ++x;
    return x;
}

int main()
{
    vector<int> res;
    int t;
    cin >> t;
    while (t--)
    {
        int d;
        cin >> d;

        int p1 = nextPrimeP1(d);
        int p2 = nextPrimeP2(p1 + d);

        res.push_back(p1 * p2);
    }

    for (int r : res)
    {
        cout << r << endl;
    }

    return 0;
}
