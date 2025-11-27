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
    int size(int u) { return sz[u]; }
};

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    bool flag = 0;
    disjoint_set<int> dsu(n);
    while(k--){
        int u, v;
        cin >> u >> v;
        dsu.unite(u, v);
    }

    const int N = 2e4 + 1;
    bitset<N> dp;
    dp[0] = 1;
    for (int i = 1; i <= n;i++){
        if(dsu.find(i)==i){
            dp |= dp << dsu.size(i);
        }
    }

    for (int i = 0; i < N;i++){
        if(m-i>=0&&dp.test(m-i)){
            cout << m - i << endl;
            return;
        }
        else if(m+i<N&&dp.test(m+i)){
            cout << m + i << endl;
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