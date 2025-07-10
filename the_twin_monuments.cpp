#include <bits/stdc++.h>
using namespace std;

vector<int> res;

vector<pair<int, int>> findCells(int x, int y, int a, int b) // to find possible cells with given moves
{
    vector<pair<int, int>> possibleCells;
    vector<pair<int, int>> moves = {
        {a, b}, {a, -b}, {-a, b}, {-a, -b}, {b, a}, {b, -a}, {-b, a}, {-b, -a}};

    for (auto move : moves)
    {
        // push the new cell into the possibleCells vector
        possibleCells.push_back({x + move.first, y + move.second});
    }
    return possibleCells;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, x1, y1, x2, y2, k = 0;
        cin >> a >> b >> x1 >> y1 >> x2 >> y2;

        auto possibleCells1 = findCells(x1, y1, a, b); // find possible cells for first monument
        auto possibleCells2 = findCells(x2, y2, a, b); // find possible cells for second monument

        set<pair<int, int>> cellsSet1(possibleCells1.begin(), possibleCells1.end());
        for (auto cell : possibleCells2)
        {
            // check for the interesection of possible cells
            // if the cell is present in the first monument's possible cells, increment k
            if (cellsSet1.count(cell))
            {
                k++;
            }
        }
        res.push_back(k);
    }
    for (int r : res)
    {
        cout << r << endl;
    }
}