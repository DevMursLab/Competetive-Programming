#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, m, k;

bool can(ll len)
{
    // len = number of bases we want to cover, containing k
    if (len > n)
        return false;
    ll max_a = min(len - 1, k - 1); // left extension
    ll max_b = min(len - 1, n - k); // right extension
    for (ll a = 0; a <= max_a; ++a)
    {
        ll b = len - 1 - a;
        if (b < 0 || b > max_b)
            continue;
        // cost to expand 'a' steps left and 'b' steps right
        ll left_cost = a * (a + 1) / 2;
        ll right_cost = b * (b + 1) / 2;
        ll need = left_cost + right_cost + min(a, b);
        if (need <= m)
            return true;
    }
    return false;
}

void solve()
{
    cin >> n >> m >> k;
    ll l = 1, r = n, ans = 1;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (can(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}