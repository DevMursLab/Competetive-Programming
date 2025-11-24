#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, k, q;
    cin >> n >> k >> q;

    int maxi2 = INT_MIN, m = INT_MIN;
    vector<int> a(n, 0);
    vector<pair<pair<int, int>, int>> vp;

    for (int i = 0; i < q; i++)
    {
        int c, l, r;
        cin >> c >> l >> r;
        l--, r--; // convert to 0-based index
        vp.push_back({{l, r}, c});

        if (c == 1)
        {
            maxi2 = max(maxi2, l);
            m = max(m, r);
        }
    }

    // Assign k to single-element ranges if applicable
    for (auto it : vp)
    {
        int x = it.first.first, y = it.first.second, d = it.second;
        if (d == 1 && x == y)
        {
            a[x] = k;
        }
    }

    if (maxi2 != INT_MIN)
        a[maxi2] = k;
    if (m != INT_MIN)
        a[m] = k;

    set<int> st;
    for (int i = 0; i < k; i++)
        st.insert(i);

    // Process type-2 operations
    for (auto it : vp)
    {
        int x = it.first.first, y = it.first.second, d = it.second;

        if (d == 2)
        {
            // Reset elements equal to k except maxi2
            for (int i = x; i <= y; i++)
            {
                if (a[i] == k && i != maxi2)
                    a[i] = 1e9;
            }

            set<int> temp, curr = st;
            for (int i = x; i <= y; i++)
                temp.insert(a[i]);
            for (auto v : temp)
                if (st.count(v))
                    curr.erase(v);

            for (int i = x; i <= y; i++)
            {
                if (!st.count(a[i]) && !curr.empty() && i > m)
                {
                    a[i] = *curr.begin();
                    curr.erase(curr.begin());
                }
                else if (!st.count(a[i]) && !curr.empty() && x == y)
                {
                    a[i] = *curr.begin();
                    curr.erase(curr.begin());
                }
            }
        }
    }

    for (auto x : a)
        cout << x << " ";
    cout << "\n";
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

/*===============================================
  :::::::::::::Author : Md.Mursalin:::::::::::::
  ===============================================*/
