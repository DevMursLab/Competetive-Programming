#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define gcd __gcd
typedef long long ll;
#define ALL(x) (x).begin(), (x).end()
#define py cout << "YES\n";
#define pm cout << "-1\n";
#define pz cout << "0\n";
#define pn cout << "NO\n";
#define cheakmate return;
const int N = 2e5 + 1;
#define Mod 1000000009 + 7
vector<ll> g[N];
ll vis[N];
ll indeg[N];

void solve()
{

    // 2d input
    ll n;
    cin >> n;
    for (ll i = 0; i <= n; i++)
    {
        g[i].clear();
        vis[i] = 0;
        indeg[i] = 0;
    }

    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v, x, y;
        cin >> u >> v >> x >> y;
        if (x <= y)
        {
            g[u].push_back(v);
            indeg[v]++;
        }
        else
        {
            g[v].push_back(u);
            indeg[u]++;
        }
    }

    queue<ll> q;
    for (ll i = 1; i <= n; i++)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
            vis[i] = 1;
        }
    }

    vector<ll> ans(n, 0);
    ll ct = 1;

    while (!q.empty())
    {
        ll node = q.front();
        ans[node - 1] = ct;
        ct++;
        q.pop();

        for (auto child : g[node])
        {
            if (vis[child])
                continue;
            indeg[child]--;
            if (indeg[child] == 0)
            {
                q.push(child);
                vis[child] = 1;
            }
        }
    }
    for (auto i : ans)
        cout << i << " ";
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
