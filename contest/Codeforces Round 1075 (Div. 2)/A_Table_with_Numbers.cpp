#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define int long long
#define gcd __gcd

#define ALL(x) (x).begin(), (x).end()
#define py cout << "YES\n";
#define pm cout << "-1\n";
#define pz cout << "0\n";
#define pn cout << "NO\n";
#define cheakmate return;
const int N = 1e5 + 5;
#define Mod 1000000009 + 7

void solve()
{

    // 2d input
    // vector<vector< int>> d(n, vector< int>(m));
    int h, l, n;
    cin >> n >> h >> l;
    vector<int> a(n);
    multiset<int> st;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        // if (a[i] <= h || a[i] <= l)
        st.insert(a[i]);
    }
    int cnt = 0;

    sort(ALL(a));
    for (int i = h; i >= 1; i--)
    {
        for (int j = l; j >= 1; j--)
        {
            if (st.count(i) && st.count(j))
            {
                if (i != j)
                {
                    cnt += min(st.count(i), st.count(j));

                    for (int k = 1; k <= min(st.count(i), st.count(j)); k++)
                    {
                        st.erase(i);
                        st.erase(j);
                    }
                }
                else
                {
                    cnt += st.count(i) / 2;
                    st.erase((i));
                    if (st.count(i) & 1)
                        st.insert(i);
                }
            }
        }
    }

    // for (int i = n - 1; i >= 1; i -= 2)
    // {
    //     if ((a[i] <= h && a[i - 1] <= l) || (a[i] <= l && a[i - 1] <= h))
    //         cnt++;
    // }
    cout << cnt << endl;
}
// sort(ALL(a),greater<int>());
// int maxi=*max_element(a.begin(),a.end());
//  int maxi = distance(a.begin(), max_element(a.begin(), a.end()));   // return max index

signed main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

/*===============================================
  :::::::::::::Author :Md.Mursalin:::::::::::::
  ===============================================*/
