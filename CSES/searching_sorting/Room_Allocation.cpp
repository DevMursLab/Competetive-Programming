#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Person
{
    int a, b, idx;
};

int32_t main()
{
    int n;
    cin >> n;

    vector<Person> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].a >> v[i].b;
        v[i].idx = i;
    }

    sort(v.begin(), v.end(), [](auto &x, auto &y)
         { return x.a < y.a; });

    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    vector<int> ans(n);
    int rooms = 0;

    for (auto p : v)
    {
        if (!pq.empty() && pq.top().first < p.a)
        {
            auto [endt, room] = pq.top();
            pq.pop();
            ans[p.idx] = room;
            pq.push({p.b, room});
        }
        else
        {
            rooms++;
            ans[p.idx] = rooms;
            pq.push({p.b, rooms});
        }
    }

    cout << rooms << "\n";
    for (int x : ans)
        cout << x << " ";
}
