#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    // function to check if a number is prime
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++) // to check divisibility only up to the square root of n
        // this is an optimization to reduce the number of iterations
        if (n % i == 0)
            return false;

    return true;
}

int nextPrimeP1(int x)
{
    // function to find the next prime number greater than x(d)
    int y = x + 1;
    while (!isPrime(y))
        y++;
    return y;
}
int nextPrimeP2(int x)
{
    // function to find the next prime number greater than or equal to x(p1+d)
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

        int p1 = nextPrimeP1(d);      // find the next prime number greater than d
        int p2 = nextPrimeP2(p1 + d); // find the next prime number greater than or equal to p1 + d

        res.push_back(p1 * p2); // calculate the product of p1 and p2 and push it to the result vector
    }

    for (int r : res)
    {
        cout << r << endl; // print the results
    }

    return 0;
}
