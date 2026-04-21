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
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> vis(n + 1, false);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int k;
    cin >> k;
    set<pair<int, int>> st;
    for (int i = 0; i < k; i++)
    {
        int x1, y1;
        cin >> x1 >> y1;
        st.insert({x1, y1});
    }
    int maxi = 0;
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        int ok = 1;
        vector<int> grp;
        grp.push_back(i);
        if (vis[i])
            continue;
        q.push(i);
        while (!q.empty())
        {
            /* code */
            int node = q.front();
            q.pop();
            for (auto it : adj[node])
            {
                if (!vis[it])
                {
                    grp.push_back(it);
                    vis[it] = true;
                }
            }
        }
        for (int i = 0; i < grp.size(); i++)
        {
            int ok1 = 1;
            for (int j = i + 1; j < grp.size(); j++)
            {
                if (st.count({grp[i], grp[j]}))
                {
                    ok1 = 0;
                    ok = 0;
                    break;
                }
            }
            if (!ok1)
                break;
        }
        if (ok)
            maxi = max(maxi, (int)grp.size());
    }
    cout << maxi << endl;
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
