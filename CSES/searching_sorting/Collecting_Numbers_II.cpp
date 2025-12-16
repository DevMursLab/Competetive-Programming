#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1), pos(n + 1);

    // input array এবং position store
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pos[a[i]] = i;
    }

    // initial rounds হিসাব
    int rounds = 1;
    for (int i = 1; i < n; i++)
    {
        if (pos[i] > pos[i + 1])
            rounds++;
    }

    while (m--)
    {
        int x, y;
        cin >> x >> y;

        int v1 = a[x];
        int v2 = a[y];

        // যেসব pair affect হতে পারে
        set<pair<int, int>> affected;

        if (v1 - 1 >= 1)
            affected.insert({v1 - 1, v1});
        if (v1 + 1 <= n)
            affected.insert({v1, v1 + 1});
        if (v2 - 1 >= 1)
            affected.insert({v2 - 1, v2});
        if (v2 + 1 <= n)
            affected.insert({v2, v2 + 1});

        // swap এর আগে contribution বাদ
        for (auto p : affected)
        {
            if (pos[p.first] > pos[p.second])
                rounds--;
        }

        // actual swap
        swap(a[x], a[y]);
        pos[v1] = y;
        pos[v2] = x;

        // swap এর পরে contribution যোগ
        for (auto p : affected)
        {
            if (pos[p.first] > pos[p.second])
                rounds++;
        }

        cout << rounds << "\n";
    }

    return 0;
}
