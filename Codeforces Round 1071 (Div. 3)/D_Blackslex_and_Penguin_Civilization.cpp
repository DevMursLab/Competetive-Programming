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
int to(int x)
{
    int c = 0;
    while (x & 1)
    {
        c++;
        x >>= 1;
    }
    return c;
}
void solve()
{

    // 2d input
    // vector<vector< int>> d(n, vector< int>(m));
    int n;
    cin >> n;
    vector<int> a;
    map<int, int> mp;
    int v = (1LL << n);
    for (int i = 0; i < v; i++)
    {

        a.push_back(i);
    }
    // for (int i = 0; i <= v; i++)
    // {
    //     if (!mp.count(i) && (i & 1))
    //     {
    //         a.push_back(i);
    //         mp[i] = 1;
    //     }
    // }
    // for (int i = 0; i <= v; i++)
    // {
    //     if (!mp.count(i))
    //     {
    //         a.push_back(i);
    //     }
    // }
    sort(ALL(a), [&](int x, int y)
         {
             if (to(x) != to(y))
                 return to(x) > to(y);
             return x < y; });
    for (auto it : a)
        cout << it << " ";

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
