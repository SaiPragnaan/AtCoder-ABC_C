#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n_pow(int a, int p)
{
    ll res = 1;
    ll x = a;
    while (p > 0)
    {
        if (p & 1)
        {
            res *= x;
        }
        x = x * x;
        p >>= 1;
    }

    return res;
}

ll count(ll x)
{
    ll cnt = 0;
    vector<int> digits;
    while (x > 0)
    {
        digits.push_back(x % 10);
        x /= 10;
    }
    int n = digits.size();
    reverse(digits.begin(), digits.end());
    // case 1 -- n digits but start with less than digit[0]
    for (int i = 1; i < digits[0]; i++)
    {
        cnt += n_pow(i, n - 1);
    }
    // case 2 -- less than n digits
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            cnt += n_pow(j, i - 1);
        }
    }
    // case 3 -- n digits but first k match and k+1 th differ
    for (int i = 1; i <= n; i++)
    {
        if (i == n)
        {
            cnt++;
            break;
        }
        cnt += n_pow(digits[0], n - i - 1) * min(digits[0], digits[i]);
        if (digits[i] >= digits[0])
        {
            break;
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll l, r;
    cin >> l >> r;
    cout << count(r) - count(l - 1) << endl;
    // cout << n_pow(2, 3);
    return 0;
}