#include <bits/stdc++.h>
using namespace std;
#ifdef GILBCXX_DEBUG
#define DEBUG(x) std::cerr << x << std::endl
#else
#define DEBUG(x)
#endif
#define endl '\n'
#define int long long
const int INF = 5e18;
const int MOD = 998244353;
using i128 = __int128_t;
template <typename T>
struct disjoint_set
{
    int N = 0;
    vector<int> fa, sz;
    vector<T> weight;
    disjoint_set(int n) : fa(n + 2), sz(n + 2, 1), weight(n + 1)
    {
        N = n;
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int u)
    {
        if (fa[u] == u)
            return u;
        int anc = find(fa[u]);
        weight[u] += weight[fa[u]];
        return fa[u] = anc;
    }
    pair<int, int> unite(int u, int v)
    {
        int from = find(u), to = find(v);
        if (from == to)
            return {u, -1};
        int exp_to = to;
        if (sz[from] > sz[to])
            swap(from, to);
        fa[from] = to;
        // if(exp_to==to){
        //     weight[from] = weight[v] - weight[u] + w;
        // }
        // else{
        //     weight[from] = weight[u] - weight[v] - w;
        // }
        sz[to] += sz[from];
        return {from, to};
    }
    bool is_united(int u, int v)
    {
        return find(u) == find(v);
    }
    T getweight(int u, int v)
    {
        return weight[u] - weight[v];
    }
    bool ok(int u)
    {
        return sz[find(u)] == N + 1;
    }
    int size(int u) { return sz[u]; }
    void add()
    {
        fa.push_back(fa.size());
        sz.push_back(1);
        weight.push_back(0);
        N++;
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> node(n + 1);
    for (int i = 1; i <= n; i++)
    {
        auto &[x, y] = node[i];
        cin >> x >> y;
    }
    using tiii = tuple<int, int, int>;
    priority_queue<tiii, vector<tiii>, greater<tiii>> dis;
    for (int i = 1; i <= n; i++)
    {
        auto [x1, y1] = node[i];
        for (int j = i + 1; j <= n; j++)
        {
            auto [x2, y2] = node[j];
            dis.emplace(abs(x1 - x2) + abs(y1 - y2), i, j);
        }
    }
    disjoint_set<int> dsu(n);
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int a, b;
            cin >> a >> b;
            node.push_back({a, b});
            n++;
            dsu.add();
            for (int i = 1; i < n; i++)
            {
                auto [x, y] = node[i];
                dis.emplace(abs(x - a) + abs(y - b), i, n);
            }
        }
        else if (op == 3)
        {
            int u, v;
            cin >> u >> v;
            if (dsu.is_united(u, v))
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
        else
        {
            if (dsu.size(dsu.find(1)) == n)
            {
                cout << -1 << endl;
                continue;
            }
            int w, u, v;
            while (dis.size())
            {
                tie(w, u, v) = dis.top();
                if (!dsu.is_united(u, v))
                    break;
                dis.pop();
            }
            int x = get<0>(dis.top());
            while (dis.size() && get<0>(dis.top()) == x)
            {
                tie(w, u, v) = dis.top();
                if (dsu.is_united(u, v))
                {
                    dis.pop();
                    continue;
                }
                dsu.unite(u, v);
            }
            cout << x << endl;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
}