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
    vector<int> fa, sz, index;
    vector<T> weight;
    disjoint_set(int n):fa(n+2),sz(n+2,1),weight(n+1),index(n+1){
        N = n;
        iota(fa.begin(), fa.end(), 0);
        iota(index.begin(), index.end(), 0);
    }
    int find_by_index(int u){
        if(fa[u]==u) return u;
        return fa[u] = find_by_index(fa[u]);
    }
    int find(int u){
        // if(fa[u]==u) return u;
        // int anc = find(fa[u]);
        // weight[u] += weight[fa[u]];
        // return fa[u] = anc;
        return find_by_index(index[u]);
    }
    void remove(int u){
        index[u] = fa.size();
        fa.push_back(fa.size());
        sz.push_back(1);
        weight.push_back(0);
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

// 可删除并查集
void solve(int n, int m)
{
    disjoint_set<int> dsu(n);
    while(m--){
        char op;
        int u, v;
        cin >> op >> u;
        if(op=='M'){
            cin >> v;
            dsu.unite(u, v);
        }
        else{
            dsu.remove(u);
        }
        //cout << u << ' ' << dsu.find(u) << endl;
    }
    int cnt = 1;
    for (int i = 1; i < n;i++){
        if(!dsu.is_united(i,0)){
            dsu.unite(i, 0);
            cnt++;
        }
    }
    cout << cnt << endl;
    // set<int> se;
    // for (int i = 0; i < n;i++){
    //     se.insert(dsu.find(i));
    //     //cout << dsu.find(i) << ' ';
    // }
    // cout << se.size() << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    int n, m;
    while (1)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)break;
        cout << "Case #" << T++ << ": ";
        solve(n, m);
    }
}