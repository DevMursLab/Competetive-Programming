#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    if (m == 0)
    {
        cout << n << '\n';
        return;
    }

    vector<int> good(n, 0);
    for (int j = 1; j < n; ++j)
    {

        if (a[j] * 2 > a[j - 1])
            good[j] = 1;
    }

    vector<int> pref(n + 1, 0);
    for (int i = 0; i < n; ++i)
        pref[i + 1] = pref[i] + good[i];

    int ans = 0;

    for (int i = 0; i + m < n; ++i)
    {
        int left = i + 1;
        int right = i + m;
        int cnt = pref[right + 1] - pref[left];
        if (cnt == m)
            ++ans;
    }

    cout << ans << '\n';
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
