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
    int n;
    cin >> n;
    vector<int> a(n);
    int ok = 0, ok1 = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 0)
            ok = 1;
        if (a[i] == 1)
            ok1 = 1;
    }
    int cnt_0 = count(ALL(a), 0);
    int cnt_1 = count(ALL(a), 1);
    if (cnt_0 == 0)
    {
        pn cheakmate
    }
    if (cnt_0 > 1 && cnt_1 < 1)
    {
        pn cheakmate
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
