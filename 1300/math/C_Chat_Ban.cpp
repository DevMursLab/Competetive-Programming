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

    for (int i = 0; i < n; i++)
    {
        int maxi = LLONG_MIN;

        for (int j = 0; j < vv[i].size(); j++)
        {
            maxi = max(maxi, vv[i][j] - j + 1);
        }

        mini = min(mini, maxi);
    }

    cout << mini << "\n";
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
