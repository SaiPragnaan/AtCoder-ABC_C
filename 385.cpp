#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> H(n);
    for (int i = 0; i < n; i++)
    {
        cin >> H[i];
    }
    int max_buildings = 1;
    int flag = 0;
    unordered_map<int, unordered_map<int, int>> dp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (H[i] == H[j])
            {
                flag = 1;
                int d = i - j;
                dp[i][d] = dp[j][d] + 1;
                max_buildings = max(max_buildings, dp[i][d]);
            }
        }
    }

    if (flag == 1)
    {
        cout << max_buildings + 1 << endl;
    }
    else
    {
        cout << max_buildings << endl;
    }
    return 0;
}