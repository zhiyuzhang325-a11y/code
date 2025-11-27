#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int INF = 5e18;
const int MOD = 998244353;
using i128 = __int128_t;
struct V
{
    vector<int> ch;
    int f = 0;
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> c(n + 1);
    vector<V> tr(n + 1);
    for (int i = 1; i <= n;i++)
        cin >> c[i];
    for (int i = 1; i < n;i++){
        int u, v;
        cin >> u >> v;
        if(u>v)
            swap(u, v);
        tr[u].ch.push_back(v);
        tr[v].f = u;
    }

    vector<int> f(n + 1);
    auto dfs=[&](auto&&dfs,int u){
        if(f[u]){
            return f[u];
        }

        if(tr[u].ch.size()==0){
            f[u] = c[u];
            return c[u];
        }
        int mn1 = 1e15, mn2 = 1e15;
        for(auto v:tr[u].ch){
            int x = dfs(dfs, v);
            if(x<mn1){
                mn1 = x;
                mn2 = mn1;
            }
        }
        f[u] = min(c[u], mn1 + mn2);
        return f[u];
    };
    int root = 0;
    for (int i = 1; i <= n;i++){
        if(tr[i].f==0) {
            root = i;
            break;
        }
    }
    dfs(dfs, root);

    vector<int> pre(n + 1);
    auto dfs2=[&](auto&&dfs2, int u, int fa)->void
    {
        int mn = 1e15;
        for(auto v:tr[fa].ch){
            if(v==u) continue;
            mn = min(mn, f[v]);
        }
        if(fa==0){
            pre[u] = 0;
        }
        else{
            pre[u] = pre[fa] + mn;
        }
        for(auto v:tr[u].ch){
            dfs2(dfs2, v, u);
        }
    };
    dfs2(dfs2, root, 0ll);
    // for (int i = 1; i <= n;i++){
    //     cout << pre[i] << ' ';
    // }
    // cout << endl;

    int timer = 0;
    vector<int> in(n + 1), out(n + 1);
    auto dfs1=[&](auto&&dfs1,int u)->void
    {
        in[u]=++timer;
        for(auto v:tr[u].ch){
            dfs1(dfs1, v);
        }
        out[u] = timer;
    };
    dfs1(dfs1,root);
    auto check = [&](int u, int v)->bool { // u->v 往下
        return (in[u] <= in[v]) && (out[u] >= out[v]);
    };

    while (m--)
    {
        int u, target;
        cin >> u >> target;
        if(!check(target,u)){
            cout << -1 << '\n';
            continue;
        }
        cout << pre[u] - pre[target] << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}