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
    long long k;
    cin >> n >> k;
    vector<long long> a(n), b(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;

    // L[i] = max subarray sum ending at i
    vector<long long> L(n);
    L[0] = a[0];
    for (int i = 1; i < n; i++)
        L[i] = max(a[i], L[i - 1] + a[i]);

    if (k % 2 == 0)
    {
        cout << *max_element(L.begin(), L.end()) << "\n";
        cheakmate
    }

    vector<long long> R(n);
    R[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
        R[i] = max(a[i], R[i + 1] + a[i]);

    long long ans = LLONG_MIN;
    for (int i = 0; i < n; i++)
    {
        long long best_through_i = L[i] + R[i] - a[i];
        ans = max(ans, best_through_i + b[i]);
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
