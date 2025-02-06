#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int K = 200010;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> id(K, -1);
    int r = K;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        while (r > a)
        {
            r--;
            id[r] = i + 1;
        }
    }

    // for (int i = 0; i < m; i++)
    // {
    //     int b, x;
    //     cin >> b;
    //     for (x = 0; x < n; x++)
    //     {
    //         if (A[x] <= b)
    //         {
    //             cout << x + 1 << endl;
    //             break;
    //         }
    //     }
    //     if (x == n)
    //     {
    //         cout << -1 << endl;
    //     }
    // }

    for (int i = 0; i < m; i++)
    {
        int b;
        cin >> b;
        cout << id[b] << endl;
    }

    return 0;
}