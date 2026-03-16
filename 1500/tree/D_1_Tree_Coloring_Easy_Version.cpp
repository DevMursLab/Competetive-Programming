#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < n - 1; i++)
    { // tree has n-1 edges
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> level(n + 1, 0);
    queue<int> q;
    q.push(1);
    level[1] = 1;

    vector<int> cnt(n + 1, 0); // count of nodes per level
    int maxi1 = 0;
    while (!q.empty())
    {
        int x = 0;
        int node = q.front();
        q.pop();
        cnt[level[node]]++;

        for (int child : adj[node])
        {
            if (level[child] == 0)
            {
                level[child] = level[node] + 1;
                q.push(child);
                x++;
            }
        }
        maxi1 = max(x, maxi1);
    }

    int maxi = 0, fas = 1;
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] > maxi)
        {
            maxi = cnt[i];
            fas = i;
        }
    }

    // for (int i = 0; i <= n; i++)
    // {
    //     if (cnt[i] == maxi && cnt[fas - 1] == 1)
    //     {
    //         maxi++;
    //         break;
    //     }
    // }
    // cout << maxi1 << endl;
    if (maxi1 == maxi)
        maxi++;
    cout << maxi << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}