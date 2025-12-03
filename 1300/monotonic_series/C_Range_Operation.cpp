#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ALL(x) (x).begin(), (x).end()

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i == 0)
            p[i] = a[i];
        else
            p[i] = p[i - 1] + a[i]; // prefix sum
    }

    int sum = accumulate(ALL(a), 0ll);
    int maxi = LLONG_MIN, m = sum;

    for (int i = 0; i < n; i++)
    {
        int v = i + 1;
        int x = i + 1;

        // use previous prefix sum for maxi
        if (i > 0)
            maxi = max(maxi, p[i - 1] - (x * x) + x);
        else
            maxi = max(maxi, -(x * x) + x);

        int p1 = v * v - p[i] + v;

        // combine correctly
        m = max(m, p1 + maxi + sum);
    }

    cout << m << "\n";
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
