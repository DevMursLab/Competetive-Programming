#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> p[i];

        vector<int> prefMin(n + 2, (int)1e9), sufMax(n + 2, -1);
        for (int i = 1; i <= n; i++)
            prefMin[i] = min(prefMin[i - 1], p[i]);

        for (int i = n; i >= 1; i--)
            sufMax[i] = max(sufMax[i + 1], p[i]);

        bool ok = true;
        for (int i = 1; i <= n - 1; i++)
        {
            if (prefMin[i] > sufMax[i + 1])
            {
                ok = false;
                break;
            }
        }
        cout << (ok ? "Yes\n" : "No\n");
    }
    return 0;
}
