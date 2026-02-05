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
        vector<int> p(n + 1), pos(n + 1);

        for (int i = 1; i <= n; i++)
        {
            cin >> p[i];
            pos[p[i]] = i; // inverse permutation
        }

        vector<int> prefMin(n + 1), sufMax(n + 2);
        prefMin[0] = INT_MAX;

        for (int k = 1; k <= n; k++)
        {
            prefMin[k] = min(prefMin[k - 1], pos[k]);
        }

        sufMax[n + 1] = 0;
        for (int k = n; k >= 1; k--)
        {
            sufMax[k] = max(sufMax[k + 1], pos[k]);
        }

        bool ok = true;
        for (int k = 1; k <= n - 1; k++)
        {
            if (prefMin[k] > sufMax[k + 1])
            {
                ok = false;
                break;
            }
        }

        cout << (ok ? "Yes\n" : "No\n");
    }
    return 0;
}
