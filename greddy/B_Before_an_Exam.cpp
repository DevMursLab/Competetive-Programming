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
    int n, d;
    cin >> n >> d;
    vector<int> a;
    multiset<int> b;
    int p = 0, q = 0;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a.push_back(1);
        b.insert(y - x - 1);

        p += x, q += y;
    }
    if (p > d || q < d)
    {
        pn cheakmate
    }
    // sort(ALL(a));
    int c = d - n;
    int j = 0;
    while (c)
    {
        int v = *b.begin();
        a[j++] += *b.begin();
        b.erase(b.begin());
        c -= v;
    }
    py for (auto it : a) cout << it << " ";
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

    solve();

    return 0;
}

/*===============================================
  :::::::::::::Author :Md.Mursalin:::::::::::::
  ===============================================*/
