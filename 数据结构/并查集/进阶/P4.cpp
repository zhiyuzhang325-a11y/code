#include <bits/stdc++.h>
using namespace std;
#ifdef GILBCXX_DEBUG
#define DEBUG(x) std::cerr << x << std::endl
#else
#define DEBUG(x)
#endif
//#define endl '\n'
#define int long long
const int INF = 5e18;
const int MOD = 998244353;
using i128 = __int128_t;
template<typename T>
struct disjoint_set
{
    int N = 0;
    vector<int> fa, sz;
    vector<T> weight;
    disjoint_set(int n):fa(n+2),sz(n+2,1),weight(n+1){
        N = n;
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int u){
        if(fa[u]==u) return u;
        int anc = find(fa[u]);
        weight[u] += weight[fa[u]];
        return fa[u] = anc;
    }
    void unite(int u, int v){
        int from = find(u), to = find(v);
        if(from==to) return;
        int exp_to = to;
        if(sz[from]>sz[to]) swap(from,to);
        fa[from] = to;
        // if(exp_to==to){
        //     weight[from] = weight[v] - weight[u] + w;
        // }
        // else{
        //     weight[from] = weight[u] - weight[v] - w;
        // }
        sz[to] += sz[from];
    }
    bool is_united(int u,int v){
        return find(u) == find(v);
    }
    T getweight(int u, int v){
        return weight[u]-weight[v];
    }
    bool ok(int u){
        return sz[find(u)] == N + 1;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> edg(m + 1);
    for (int i = 1; i <= m;i++){
        auto &[w, u, v] = edg[i];
        cin >> u >> v >> w;
    }
    int s, t;
    cin >> s >> t;
    sort(edg.begin() + 1, edg.end());
    int fm = 1e9, fz = 1;
    for (int i = 1; i <= m;i++){
        int L = get<0>(edg[i]);
        disjoint_set<int> dsu(n);
        for (int j = i; j <= m;j++){
            auto [w, u, v] = edg[j];
            dsu.unite(u, v);
            if(dsu.is_united(s,t)){
                if(fm*L>w*fz){
                    fm = w, fz = L;
                }
            }
        }
    }
    if(fm==1e9){
        cout << "IMPOSSIBLE" << endl;
    }
    else if(fm%fz){
        int gc = __gcd(fm, fz);
        cout << fm / gc << '/' << fz / gc << endl;
    }
    else{
        cout << fm / fz << endl;
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
