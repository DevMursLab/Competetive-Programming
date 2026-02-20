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
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    b = a;
    sort(ALL(b), greater<int>());

    vector<int> v(n + 1);
    vector<pair<int, int>> vp2(q);
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        vp2[i] = {x, y};
        v[x] += 1;
        v[y + 1] -= 1;
    }
    // int sz=
    vector<int> ps(n);
    ps[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        ps[i] = ps[i - 1] + v[i];
    }
    vector<pair<int, int>> vp(n);
    // for (auto it : ps)
    //     cout << it << " ";

    for (int i = 0; i < n; i++)
    {
        vp[i] = {ps[i], i};
    }
    sort(ALL(vp), [](pair<int, int> &a, pair<int, int> &b)
         { return a.first > b.first; });
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        c[vp[i].second] = b[x++];
    }
    vector<int> ps2(n);
    ps2[0] = c[0];
    for (int i = 1; i < n; i++)
    {
        ps2[i] = ps2[i - 1] + c[i];
    }

    // for (auto it : c)
    //     cout << it << " ";
    long long ans = 0;
    for (int i = 0; i < q; i++)
    {
        int l = vp2[i].first;
        int r = vp2[i].second;

        if (l == 0)
            ans += ps2[r];
        else
            ans += ps2[r] - ps2[l - 1];
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
