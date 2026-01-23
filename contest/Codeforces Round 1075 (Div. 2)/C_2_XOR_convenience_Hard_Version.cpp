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
    vector<int> a(n + 1, 0);
    set<int> st1, st2;
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        st1.insert(i);
        st2.insert(i);
    }
    for (int i = 1; i <= n; i++)
    {
        if (((n - 1) ^ i) <= n)

        {
            a[n - 1] = (n - 1) ^ i;
            a[n] = i;

            st1.erase(i);
            st1.erase((n - 1) ^ i);
            st2.insert(i);
            st2.insert((n - 1) ^ i);
            mp[(n - 1) ^ i] = 1;
            mp[i] = 1;
            break;
        }
    }
    if (n > 3)
    {
        for (int i = n - 2; i >= 1; i--)
        {
            for (auto it : st2)
            {
                if (((i) ^ it) <= n && mp[((i) ^ it)] == 0)
                {
                    a[i] = ((i) ^ it);

                    mp[((i) ^ it)] = 1;
                    st1.erase(((i) ^ it));
                    break;
                }
            }
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     if (mp[i] == 0)
    //     {
    //         a[0] = i;
    //         break;
    //     }
    // }
    // cout << *st1.begin() << endl;

    a[1] = *st1.begin();
    int ok = 0;
    for (int i = 2; i <= n; i++)
    {
        if ((a[i] ^ 1) == a[1])
            ok = 1;
    }
    if (!ok)
    {
        pm cheakmate
    }

    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
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
