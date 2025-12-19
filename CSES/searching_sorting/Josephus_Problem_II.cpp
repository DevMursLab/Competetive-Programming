#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    pbds;

void solve()
{
    int n, k;
    cin >> n >> k;

    pbds t;
    for (int i = 1; i <= n; i++)
        t.insert(i);

    int idx = 0;
    while (!t.empty())
    {
        idx = (idx + k) % t.size();
        auto it = t.find_by_order(idx);
        cout << *it << " ";
        t.erase(it);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}