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

struct st
{
    /* data */
    int a, b;
};

void solve()
{

    // 2d input
    // vector<vector< int>> d(n, vector< int>(m));
    int n;
    cin >> n;
    vector<st> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].a >> v[i].b;
    }
    sort(v.begin(), v.end(), [](auto &x, auto &y)
         { return x.a < y.a; });

    int ans = 0, curr = 0;
    for (int i = 0; i < n; i++)
    {
        curr += v[i].a;
        ans += (v[i].b - (curr));
    }

    cout << ans << endl;
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
