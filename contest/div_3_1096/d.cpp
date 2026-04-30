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

    int n;
    cin >> n;
    vector<int> b((2 * n) + 1), c(n), d(n), e((2 * n) + 1);
    for (int i = 1; i <= 2 * n; i++)
    {
        cin >> b[i];
        if (!c[b[i]])
            c[b[i]] = i;
        else
            d[b[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        e[c[i]] = c[i] + d[i];
        e[d[i]] = c[i] + d[i];
    }
    int res = 0;
    map<int, int> mp;
    int cnt = 0;
    for (int i = 1; i <= 2 * n; i++)
    {
        cnt++;

        mp[b[i]] = 1;
        int l = i - 1, r = i + 1;
        while (l >= 1 && r <= 2 * n)
        {
            if ((e[l] == 2 * i) && (e[r] == 2 * i))
            {
                tmp[b[l]] = 1;
                tmp[b[r]] = 1;
                l--;
                r++;
            }
            else
                break;
        }
        int mara = 0;
        while (mara < n && tmp[mara])
            mara++;
        res = max(res, mara);
    }

    for (int i = 1; i < 2 * n; i++)
    {
        cnt++;
        // vector<int> tmp(n);
        mp[b[i]] = cnt;
        int l = i, r = i + 1;
        int ok = 0;
        while (l >= 1 && r <= 2 * n)
        {
            if (e[l] == (2 * i + 1) && e[r] == (2 * i + 1))
            {
                mp[b[l]] = cnt;
                mp[b[r]] = cnt;
                ok = 1;
                l--;
                r++;
            }
            else
                break;
        }
        if (ok)
        {
            int mara = 0;
            while (mara < n && mp[mara] == cnt)
                mara++;
            res = max(res, mara);
        }
    }

    cout << res << endl;
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
