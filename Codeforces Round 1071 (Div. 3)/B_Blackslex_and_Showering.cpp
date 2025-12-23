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
    vector<int> a(n), b;
    int m = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int p = 0;
    for (int i = 0; i < n - 1; i++)
    {
        // if (abs(a[i + 1] - a[i]) + abs(a[i + 1] - a[i]) > m)
        // {
        //     if (abs(a[i + 1] - a[i]) > abs(a[i + 1] - a[i]))
        //         p = i + 1;
        //     else
        //         p = i - 1;
        //     m = abs(a[i + 1] - a[i]) + abs(a[i + 1] - a[i]);
        // }

        m += abs(a[i] - a[i + 1]);
    }
    int res = m;
    res = min(res, m - abs(a[0] - a[1]));
    res = min(res, m - abs(a[n - 2] - a[n - 1]));
    for (auto it : b)
        cout << it << " ";
    for (int i = 1; i < n - 1; i++)
    {

        res = min(res, m - abs(a[i - 1] - a[i]) - abs(a[i] - a[i + 1]) + abs(a[i - 1] - a[i + 1]));
    }
    // cout << endl;
    cout << res << endl;
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
