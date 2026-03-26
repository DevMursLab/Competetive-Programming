#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin >> n;

    int j;
    cin >> j;

    vector<vector<int>> adj(n + 1);
    vector<bool> vis(n + 1, false);

    for (int i = 0; i < j; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int m;
    cin >> m;

    set<pair<int, int>> st;
    for (int i = 0; i < m; i++)
    {
        int x1, y1;
        cin >> x1 >> y1;

        if (x1 > y1)
            swap(x1, y1);
        st.insert({x1, y1});
    }

    int maxi = 0;

    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;

        queue<int> q;
        q.push(i);
        vis[i] = true;

        vector<int> group;
        group.push_back(i);

        while (!q.empty())
        {
            int cld = q.front();
            q.pop();

            for (auto it : adj[cld])
            {
                if (!vis[it])
                {
                    vis[it] = true;
                    q.push(it);
                    group.push_back(it);
                }
            }
        }

        int ok = 1;

        for (int x = 0; x < group.size(); x++)
        {
            for (int y = x + 1; y < group.size(); y++)
            {
                int a = group[x], b = group[y];
                if (a > b)
                    swap(a, b);

                if (st.count({a, b}))
                {
                    ok = 0;
                    break;
                }
            }
            if (!ok)
                break;
        }

        if (ok)
            maxi = max(maxi, (int)group.size());
    }

    cout << maxi << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}