#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, k;
    cin >> n >> k;

    set<int> st;
    for (int i = 1; i <= n; i++)
        st.insert(i);

    auto it = st.begin();
    while (!st.empty())
    {
        if (st.size() >= k)
        {
            for (int i = 0; i < k; i++)
            {
                it++;
                if (it == st.end())
                    it = st.begin();
            }
        }
        cout << *it << " ";
        auto del = it++;
        if (it == st.end())
            it = st.begin();
        st.erase(del);
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
