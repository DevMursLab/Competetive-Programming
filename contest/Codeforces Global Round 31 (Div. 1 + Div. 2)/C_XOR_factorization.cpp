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
    //   int n;
    // cin >> n;
    // vector< int> a(n);
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> a[i];
    //}

    int n, k;
    cin >> n >> k;
    vector<int> ans(k, n);

    int ok = 1, pt = 0, m = 0;
    if ((k & 1))
    {
        for (int i = 1; i <= k; i++)
        {
            cout << n << " ";
        }

        cout << endl;

        cheakmate
    }
    // for (int i = 31; i >= 0; i--)
    // {
    //     if (!ok)
    //     {
    //         if ((n & (1LL << i)) != 0)
    //         {
    //             pt = i;
    //             break;
    //         }
    //     }
    //     if (ok)
    //     {
    //         if ((n & (1LL << i)) != 0)
    //         {
    //             ok = 0;
    //             m = i;
    //         }
    //     }
    // }
    // int o = (1LL << m) - 1;
    // vector<int> ans(k, o);

    // for (int i = 0; i < ans.size(); i++)
    // {
    //     ans[i] &= ~(1 << pt); // bit reset
    // }

    if (k == 2)
    {

        int m1 = 0, m2 = 0;
        for (int j = 30; j >= 0; j--)
        {
            if ((n & (1LL << j)) != 0)
            {
                if (m1 <= m2)
                {
                    m1 |= (1LL << j);
                }
                else
                    m2 |= (1LL << j);
            }

            else
            {
                m1 |= (1LL << j);
                m2 |= (1LL << j);
            }
        }

        if (m1 > n)
        {
            for (int i = 30; i >= 0; i--)
            {
                if (m1 > n && (m1 & (1LL << i)) && !(n & (1LL << i)))
                {
                    m1 ^= (1LL << i);
                    m2 ^= (1LL << i);
                }
            }
        }
        cout << m1 << " " << m2 << endl;

        cheakmate
    }

    int m1 = 0, m2 = 0;
    for (int j = 30; j >= 0; j--)
    {
        if ((n & (1LL << j)) != 0)
        {
            if (m1 <= m2)
            {
                m1 |= (1LL << j);
            }
            else
                m2 |= (1LL << j);
        }

        else
        {
            m1 |= (1LL << j);
            m2 |= (1LL << j);
        }
    }

    if (m1 > n)
    {
        for (int i = 30; i >= 0; i--)
        {
            if (m1 > n && (m1 & (1LL << i)) && !(n & (1LL << i)))
            {
                m1 ^= (1LL << i);
                m2 ^= (1LL << i);
            }
        }
    }
    for (int i = 0; i < k - 2; i++)
        cout << n << " ";
    cout << m1 << " " << m2 << endl;
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
