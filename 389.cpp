#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin >> q;
    long long now = 0;
    vector<long long> x;
    int id = 0;
    for (int i = 0; i < q; ++i)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            long long l;
            cin >> l;
            x.push_back(now);
            now += l;
        }
        else if (t == 2)
        {
            id++;
        }
        else
        {
            int k;
            cin >> k;
            k--;
            cout << x[id + k] - x[id] << "\n";
        }
    }
}
