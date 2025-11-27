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
    double n, m;
    cin >> n >> m;
    vector<pair<double, double>> node(m + 1);
    vector<int> poss, pose;
    for (int i = 1; i <= m;i++){
        auto &[x, y] = node[i];
        cin >> x >> y;
    }

    vector<tuple<double, int, int>> edg;
    for (int i = 1; i <= m;i++){
        auto [x, y] = node[i];
        edg.emplace_back(x, 0, i);
        edg.emplace_back(n - x, i, m + 1);
        for (int j = i + 1; j <= m;j++){
            auto [x2, y2] = node[j];
            edg.emplace_back(hypot(x - x2, y - y2) / 2, i, j);
        }
    }
    sort(edg.begin(), edg.end());
    disjoint_set<int> dsu(m + 1);
    for (auto [w,u,v]:edg){
        dsu.unite(u, v);
        if(dsu.is_united(0,m+1)){
            printf("%.2f\n", w);
            return;
        }
    }
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