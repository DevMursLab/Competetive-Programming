#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i, n) for (int i = 0; i < (n); i++)

void solve()
{
    ll n;
    cin >> n;
    n <<= 1;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (n == 2)
    {
        cout << a[1] - a[0] << "\n";
        return;
    }

    vector<ll> ans1, ans2;

    // ans1
    {
        ll sum = 0;
        f(i, n)
        {
            if (i & 1)
                sum += a[i];
            else
                sum -= a[i];
        }
        ans1.push_back(sum);
    }

    // ans2
    {
        ll sum = a[n - 1] - a[0];
        for (int i = 1; i < n - 1; i++)
        {
            if (i & 1)
                sum -= a[i];
            else
                sum += a[i];
        }
        ans2.push_back(sum);
    }

    for (int i = 1; i < n - 1 - i; i += 2)
    {
        ans1.push_back(ans1.back() - 2 * a[i] + 2 * a[n - 1 - i]);
    }

    for (int i = 2; i < n - 1 - i - 1; i += 2)
    {
        ans2.push_back(ans2.back() - 2 * a[i] + 2 * a[n - 1 - i]);
    }

    for (int i = 0; i < (int)ans2.size(); i++)
    {
        cout << ans1[i] << " " << ans2[i] << " ";
    }

    if ((n >> 1) & 1)
        cout << ans1.back();
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}
