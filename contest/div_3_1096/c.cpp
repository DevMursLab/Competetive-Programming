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
    vector<int> a(n), b, c, d, e, f;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        if ((a[i] % 2 == 0) && (a[i] % 3 == 0))
            b.push_back(a[i]);
        else if (a[i] % 2 == 0)
            c.push_back(a[i]);
        else if (a[i] % 3 == 0)
            d.push_back(a[i]);
        else
            e.push_back(a[i]);
    }
    for (int i = 0; i < c.size(); i++)
    {
        f.push_back(c[i]);
    }
    for (int i = 0; i < e.size(); i++)
    {
        f.push_back(e[i]);
    }
    for (int i = 0; i < d.size(); i++)
    {
        f.push_back(d[i]);
    }
    for (int i = 0; i < b.size(); i++)
    {
        f.push_back(b[i]);
    }

    for (int i = 0; i < f.size(); i++)
    {
        cout << f[i] << " ";
    }

    cout << endl;
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
