#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> vv(n);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vector<int> a(x);

        for (int j = 0; j < x; j++)
        {
            cin >> a[j];
        }

        vv[i] = a; // FIXED
    }

    int mini = LLONG_MAX;
    map<int, set<int>> mp;

    for (int i = 0; i < n; i++)
    {
        int maxi = LLONG_MIN;
        int index = -1;

        for (int j = 0; j < vv[i].size(); j++)
        {
            if (vv[i][j] - j + 1 > maxi)
            {
                maxi = max(maxi, vv[i][j] - j + 1);
            }
        }

        mp[maxi].insert(vv[i].size());
    }
    int l = 1, h = 1e18, ans = 0;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        int ok = 1;
        int temp = mid;
        for (auto it : mp)
        {

            if (it.first > temp)
            {
                ok = 0;
                break;
            }
            for (auto y : it.second)
            {
                temp += y;
            }
        }

        if (ok)
        {
            ans = mid;
            h = mid - 1;
        }
        else
            l = mid + 1;
    }

    for (auto it : mp)
        cout << it.first << " ";
    cout << endl;
    // cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
