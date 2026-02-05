#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ALL(x) (x).begin(), (x).end()

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    multiset<int> swords;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        swords.insert(a[i]);
    }

    vector<pair<int, int>> monsters(m); // (b,c)
    for (int i = 0; i < m; i++)
        cin >> monsters[i].first;
    for (int i = 0; i < m; i++)
        cin >> monsters[i].second;

    sort(ALL(monsters)); // sort by b

    multiset<int> availableC; // available rewards
    int ptr = 0;
    int ans = 0;

    while (!swords.empty())
    {
        int x = *swords.begin();
        swords.erase(swords.begin());

        // add all monsters killable by this sword
        while (ptr < m && monsters[ptr].first <= x)
        {
            availableC.insert(monsters[ptr].second);
            ptr++;
        }

        if (availableC.empty())
            continue;

        // take biggest reward
        auto it = prev(availableC.end());
        int bestC = *it;
        availableC.erase(it);

        ans++;

        if (bestC > 0)
        {
            swords.insert(max(x, bestC));
        }
    }

    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}
