#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define int long long
#define gcd __gcd

#define ALL(x) (x).begin(), (x).end()
#define py cout << "Yes\n";
#define pm cout << "-1\n";
#define pz cout << "0\n";
#define pn cout << "No\n";
#define cheakmate return;
const int N = 1e5 + 5;
#define Mod 1000000009 + 7

void solve()
{

    // 2d input
    // vector<vector< int>> d(n, vector< int>(m));
    int n;
    cin >> n;
    vector<pair<int, int>> vp(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        vp[i] = {x, y};
    }
    sort(ALL(vp), [](auto &a, auto &b)
         { return a.second < b.second; });
    int st = 0;
    for (int i = 0; i < n; i++)
    {
        if (st + vp[i].first > vp[i].second)
        {
            pn cheakmate
        }
        st += vp[i].first;
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

    solve();

    return 0;
}

/*===============================================
  :::::::::::::Author :Md.Mursalin:::::::::::::
  ===============================================*/
