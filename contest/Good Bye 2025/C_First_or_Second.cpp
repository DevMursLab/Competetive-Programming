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

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int ans = 0;
    int c;
    // for (int i = 0; i < a.size() - 1; i++)
    // {
    //     if (ans >= 0)
    //     {

    //         if (a[i] >= 0 && a[i + 1] >= 0)
    //         {
    //             if (abs(a[i]) >= abs(a[i + 1]))
    //             {
    //                 ans += abs(a[i]);
    //                 // swap(v[1], v.back());
    //                 a.pop_back();
    //             }

    //             else
    //             {
    //                 ans += abs(a[i + 1]);
    //                 swap(a[i + 1], a.back());
    //                 a.pop_back();
    //             }
    //         }
    //         else if (a[i] < 0 && a[i + 1] < 0)
    //         {
    //             if (abs(a[i]) >= abs(a[i + 1]))
    //             {
    //                 ans += abs(a[i]);
    //                 // swap(v[1], v.back());
    //                 a.pop_back();
    //             }

    //             else
    //             {
    //                 ans += abs(a[i + 1]);
    //                 swap(a[i + 1], a.back());
    //                 a.pop_back();
    //             }
    //         }

    //         else if (a[i] < 0)
    //         {
    //             ans += abs(a[i]);
    //             // swap(v[1], v.back());
    //             a.pop_back();
    //         }

    //         else
    //         {
    //             ans += abs(a[i + 1]);
    //             swap(a[i + 1], a.back());
    //             a.pop_back();
    //         }
    //     }
    //     c++;
    //     if (c == n - 2)
    //         break;
    // }
    ans = 0;
    c = 0;
    c -= a.back();
    int d = a.back();
    for (int i = n - 2; i >= 0; i--)
    {
        int setting1 = a[i];
        int setting2 = max(0LL, setting1 + d);
        int setting3 = c + setting2;
        c -= setting1;
        d = max(d, setting3 - c);
        if (i == 0)
            ans = setting3;
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
