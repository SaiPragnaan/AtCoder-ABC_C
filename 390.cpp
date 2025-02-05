#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int h, w;
    cin >> h >> w;
    int Rmin = INT_MAX, Rmax = INT_MIN, Cmin = INT_MAX, Cmax = INT_MIN;
    vector<string> s(h);
    for (int i = 0; i < h; i++)
    {
        cin >> s[i];
        for (int j = 0; j < w; j++)
        {
            if (s[i][j] == '#')
            {
                Rmin = min(Rmin, i);
                Rmax = max(Rmax, i);
                Cmin = min(Cmin, j);
                Cmax = max(Cmax, j);
            }
        }
    }
    for (int i = Rmin; i <= Rmax; i++)
    {
        for (int j = Cmin; j <= Cmax; j++)
        {
            if (s[i][j] == '.')
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}