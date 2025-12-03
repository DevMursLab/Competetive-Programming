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
        int x = i + 1, h = -1, o = -1;

        // fix: use previous prefix sum
        if (i > 0)
        {
            if (-(x * x) + x + p[i - 1] > maxi)
            {
                maxi = max(maxi, -(x * x) + x + p[i - 1]);
                h = (x * x);
                o = x + p[i - 1];
            }
        }
        else
        {
            if (-(x * x) + x + 0 > maxi)
            {
                maxi = max(maxi, -(x * x) + x + 0);
                h = (x * x);
                o = x + 0;
            }
        }

        int p1 = (v * v) + v - p[i];
        int fj = sum - h + o;

        // fix: correct combination
        m = max(m, fj + p1);
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
