// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     int max_length = 0;
//     int n;
//     string s;
//     cin >> n >> s;
//     int ones = 0, twos = 0;
//     bool slash = false;
//     for (int i = 0; i < s.length(); i++)
//     {
//         if (s[i] == '1')
//         {
//             if (!slash)
//             {
//                 ones++;
//             }
//             else
//             {
//                 ones = 1;
//                 twos = 0;
//                 slash = false;
//             }
//         }
//         else if (s[i] == '/')
//         {
//             if (ones > 0 && !slash)
//             {
//                 slash = true;
//                 twos = 0;
//             }
//             else
//             {
//                 ones = twos = 0; 
//             }
//             max_length = max(max_length, 1);
//         }
//         else if (slash && s[i] == '2')
//         {
//             twos++;
//             max_length = max(max_length, 2 * min(ones, twos) + 1);
//         }
//     }
//     cout << max_length << endl;
//     return 0;
// }



/*
 T.C of the following code is O(n) --> bcz if s[i]=='1' it will be counted in ones slashes left ,but not in right,
 so all the 1/2 will be counted only once in while loop ,and once in for loop so O(n+n)=O(n)
*/



#include <iostream>
#include <string>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;

  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (S[i] != '/') continue;
    int d = 0;
    while (true) {
      int j = i - (d + 1);
      int k = i + (d + 1);
      if (!(0 <= j and j < N)) break;
      if (!(0 <= k and k < N)) break;
      if (S[j] != '1') break;
      if (S[k] != '2') break;
      d++;
    }
    ans = max(ans, 1 + d * 2);
  }
  cout << ans << "\n";
}
