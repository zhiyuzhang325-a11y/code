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
template<typename T>
struct disjoint_set
{
    int N = 0;
    vector<int> fa, sz;
    vector<T> wight;
    disjoint_set(int n):fa(n+1),sz(n+1,1),wight(n+1){
        N = n;
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int u){
        if(fa[u]==u) return u;
        return fa[u] = find(fa[u]);
    }
    void unite(int u,int v){
        int from = find(u), to = find(v);
        if(from==to) return;
        if(sz[from]>sz[to]) swap(from,to);
        fa[from] = to;
        sz[to] += sz[from];
    }
    bool is_united(int u,int v){
        return find(u) == find(v);
    }
    bool ok(int u){
        return sz[find(u)] == N;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> edg(m + 1);
    for (int i = 1; i <= m;i++){
        auto &[u, v, w] = edg[i];
        cin >> u >> v >> w;
    }
    sort(edg.begin()+1,edg.end(),[](auto a,auto b){
        return get<2>(a) < get<2>(b);
    });
    disjoint_set<int> dsu(n);
    int ans = -1;
    for (int i = 1; i <= m;i++){
        auto [u, v, w] = edg[i];
        dsu.unite(u, v);
        if(dsu.ok(u)||dsu.ok(v)){
            ans = w;
            break;
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--)
    {
        solve();
    }
}