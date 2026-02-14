#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using i128 = __int128_t;

void print128(i128 x)
{
    if (x == 0)
    {
        cout << 0;
        return;
    }
    if (x < 0)
    {
        cout << '-';
        x = -x;
    }
    string s;
    while (x)
    {
        s.push_back('0' + (int)(x % 10));
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

// minimal possible deals = sum of digits of n in base-3
ll minDeals(ll n)
{
    ll s = 0;
    while (n)
    {
        s += n % 3;
        n /= 3;
    }
    return s;
}

void solve()
{
    ll n, k;
    cin >> n >> k;

    if (k < minDeals(n))
    { // even after full carry, can't go that low
        cout << -1 << "\n";
        return;
    }

    // start: buy n single watermelons
    i128 cost = (i128)3 * n;
    ll deals = n;

    // cnt[i] = how many bundles of size 3^i we currently have
    vector<i128> cnt(61, 0);
    cnt[0] = n;

    // p3[i] = 3^i
    vector<i128> p3(61, 1);
    for (int i = 1; i <= 60; i++)
        p3[i] = p3[i - 1] * 3;

    // reduce deals to <= k using cheapest carries first
    for (int i = 0; i < 60 && deals > k; i++)
    {
        while (cnt[i] >= 3 && deals > k)
        {
            // do one carry: 3 of level i -> 1 of level i+1
            cnt[i] -= 3;
            cnt[i + 1] += 1;

            deals -= 2;    // 3 deals become 1 deal
            cost += p3[i]; // extra cost added
        }
    }

    print128(cost);
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
    return 0;
}
