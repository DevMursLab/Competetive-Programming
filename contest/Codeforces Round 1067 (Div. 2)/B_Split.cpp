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
    vector<int> a(2 * n);
    map<int, int> mp;
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> a[i];

        mp[a[i]]++;
    }

    int ans = 0, p = 0, t = 0, s = 0, o = 0;
    for (auto it : mp)
    {
        if (it.second % 2 == 0)
            p++;
        if (it.second % 2 == 0 && (it.second / 2) % 2 == 0)
            s++;
        if (it.second == 1)
            o++;

        if (it.second & 1)
            t++;
    }

    s = t + 2 * p;
    if (!t)
    {
        int x = p % 2;
        int h = n % 2;
        if (x != h)
            s -= 2;
    }

    cout << s << endl;
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
