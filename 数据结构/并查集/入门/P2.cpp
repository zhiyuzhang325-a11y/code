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
    stack<pair<int, int>> stk;
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
        if(fa[u]==u) return u;
        int anc = find(fa[u]);
        weight[u] += weight[fa[u]];
        return anc;     //不能路径压缩
        //return find_by_index(index[u]);
    }
    void undo(){
        if(stk.empty()) return;
        auto [u, v] = stk.top();
        stk.pop();
        if(v==-1) return;
        fa[u] = u;
        sz[v] -= sz[u];
    }
    void remove(int u){
        index[u] = fa.size();
        fa.push_back(fa.size());
        sz.push_back(1);
        weight.push_back(0);
    }
    void unite(int u, int v){
        int from = find(u), to = find(v);
        if(from==to) {
            stk.emplace(u, -1);
            return;
        }
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
        stk.emplace(from, to);
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

// 可回滚并查集
void solve()
{
    int n, m;
    cin >> n >> m;
    disjoint_set<int> dsu(n);
    while(m--){
        int op, u, v;
        cin >> op;
        if(op==1){
            cin >> u >> v;
            dsu.unite(u, v);
        }
        else if(op==2){
            dsu.undo();
        }
        else{
            cin >> u >> v;
            if(dsu.is_united(u,v)){
                cout << "Yes" << endl;
            }
            else{
                cout << "No" << endl;
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
