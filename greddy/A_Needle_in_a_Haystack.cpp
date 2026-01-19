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

    string s, t;
    cin >> s >> t;

    unordered_multiset<int> st1, st2;
    vector<int> ct(26, 0), cs(26, 0);

    st1.reserve(t.size() * 2 + 10);
    st2.reserve(s.size() * 2 + 10);

    for (char c : t)
    {
        int x = c - 'a';
        st1.insert(x);
        ct[x]++;
    }

    for (char c : s)
    {
        int x = c - 'a';
        if (ct[x] == 0)
        {
            cout << "Impossible\n";
            cheakmate
        }
        st2.insert(x);
        cs[x]++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (cs[i] > ct[i])
        {
            cout << "Impossible\n";
            cheakmate
        }
    }

    string p = "abcdefghijklmnopqrstuvwxyz";
    string ans;
    int pt = 0;

    for (int i = 0; i < 26; i++)
    {
        if (ct[i] > 0)
        {
            while (pt < (int)s.size() && s[pt] <= p[i])
            {
                ans += s[pt++];
            }
            int need = ct[i] - cs[i];
            ans.append(need, p[i]);
        }
    }

    while (pt < (int)s.size())
        ans += s[pt++];

    cout << ans << "\n";
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
