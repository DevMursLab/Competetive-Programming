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
int mex(set<int> st)
{
    int i = 0;
    for (auto it : st)
    {
        if (it != i)
        {
            return i;
        }
        i++;
    }
    return i;
}
void solve()
{

    // 2d input
    // vector<vector< int>> d(n, vector< int>(m));
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    set<int> st;
    multiset<int> ms;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ms.insert(a[i]);
        st.insert(a[i]);
    }
    int x = ms.size() - st.size();
    int op = n - k + 1;
    if (op <= x)
    {
        cout << mex(st) << endl;
        cheakmate
    }
    int p = op - x;
    while (p && !st.empty())
    {
        auto it = prev(st.end());
        st.erase(it);
        p--;
    }
    cout << mex(st) << endl;
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
