#include <bits/stdc++.h>
using namespace std;
#ifdef GILBCXX_DEBUG
#define DEBUG(x) std::cerr << x << std::endl
#else
#define DEBUG(x)
#endif
// #define endl '\n'
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
    pair<int,int> unite(int u, int v)
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
};

void solve()
{
    int n, m, k;
    cin >> n >> m;
    vector<vector<int>> g(n);
    while(m--){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin >> k;
    vector<int> cnt(n);
    stack<int> stk;
    int cnt1 = n - k;
    while(k--){
        int u;
        cin >> u;
        cnt[u] = 1;
        stk.push(u);
    }
    disjoint_set<int> dsu(n);
    for (int i = 0; i < n;i++){
        if(cnt[i]) continue;
        for (auto v : g[i]) {
            if (cnt[v]) continue;
            if(dsu.unite(i, v).second!=-1)
                cnt1--;
        }
    }
    stack<int> ans;
    ans.push(cnt1);
    while(stk.size()){
        int u = stk.top();
        stk.pop();
        cnt[u] = 0;
        cnt1++;
        for (auto v:g[u]){
            if(cnt[v]) continue;
            if(dsu.unite(u, v).second!=-1) cnt1--;
        }
        ans.push(cnt1);
    }
    while(ans.size()){
        cout << ans.top() << endl;
        ans.pop();
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