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
template <bool flag = true>
struct disjoint_set
{
    vector<int> fa, sz;
    disjoint_set(int n) : fa(n + 1), sz(n + 1, 1) {
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
};
void solve()
{
    int n, m;
    cin >> n >> m;
    disjoint_set<> dsu(n);
    while(m--){
        int z, x, y;
        cin >> z >> x >> y;
        if(z==1){
            dsu.unite(x, y);
        }
        else{
            if(dsu.is_united(x,y)){
                cout << "Y" << endl;
            }
            else{
                cout << "N" << endl;
            }
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
