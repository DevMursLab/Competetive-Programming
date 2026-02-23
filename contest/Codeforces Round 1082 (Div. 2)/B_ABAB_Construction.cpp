#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define int long long
#define gcd __gcd

#define ALL(x) (x).begin(), (x).end()
#define py cout << "YES\n";
#define pm cout << "-1\n";
#define pz cout << "0\n";
#define pn cout << "NO\n";
#define cheakmate return;
const int N = 1e5 + 5;
#define Mod 1000000009 + 7

void solve()
{

    // 2d input
    // vector<vector< int>> d(n, vector< int>(m));
    //   int n;
    // cin >> n;
    // vector< int> a(n);
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> a[i];
    //}

    int n;
    cin >> n;
    string s, p, q;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        if (i & 1)
            p.push_back('b');
        else
            p.push_back('a');
    }
    int k = n / 2;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '?')
        {

            int sz = p.size();
            if (i + 1 < n && s[i + 1] == 'a')
            {
                if (p[0] == 'a')
                {
                    p.pop_back();
                    continue;
                }
                if (p[sz - 1] == 'a')
                {
                    p.erase(0, 1);
                    continue;
                }
                p.pop_back();
            }

            if (i + 1 < n && s[i + 1] == 'b')
            {
                if (p[0] == 'b')
                {
                    p.pop_back();
                    continue;
                }
                if (p[sz - 1] == 'b')
                {
                    p.erase(0, 1);
                    continue;
                }
                p.pop_back();
            }
        }
        else if (s[i] == 'a')
        {
            int sz = p.size();
            if (p[0] != 'a' && p[sz - 1] != 'a')
            {
                pn cheakmate
            }
            if (p[0] == 'a')
            {
                p.erase(0, 1);
                continue;
            }
            if (p[sz - 1] == 'a')
            {
                p.pop_back();
                continue;
            }
        }
        else if (s[i] == 'b')
        {
            int sz = p.size();
            if (p[0] != 'b' && p[sz - 1] != 'b')
            {
                pn cheakmate
            }
            if (p[0] == 'b')
            {
                p.erase(0, 1);
                continue;
            }
            if (p[sz - 1] == 'b')
            {
                p.pop_back();
                continue;
            }
        }
    }
    py
}
// sort(ALL(a),greater<int>());
// int maxi=*max_element(a.begin(),a.end());
//  int maxi = distance(a.begin(), max_element(a.begin(), a.end()));   // return max index

signed main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

/*===============================================
  :::::::::::::Author :Md.Mursalin:::::::::::::
  ===============================================*/
