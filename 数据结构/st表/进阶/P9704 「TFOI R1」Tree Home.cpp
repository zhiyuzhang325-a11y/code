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
struct sparse_table{
    vector<vector<T>> st;
    int n, logn;
    sparse_table(const vector<T> &a){
        n = a.size() - 1;
        logn = __lg(n);
        st.resize(logn + 1, vector<T>(n + 1));
        st[0] = a;
        for (int k = 1; k <= logn;k++){
            for (int r = 1 << k; r <= n;r++){
                st[k][r] = max(st[k - 1][r], st[k - 1][r - (1 << (k - 1))]);
            }
        }
    }
    T query(int l, int r){
        int k = __lg(r - l + 1);
        return max(st[k][r], st[k][l + (1 << k) - 1]);
    }
};
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n + 1);
    for (int i = 1; i <= n;i++){
        cin >> v[i];
    }
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 1; i < n;i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    int root = 1;
    vector<int> vis(n + 1), d(n + 1);
    vis[1] = 1;
    auto dfs = [&](auto &&dfs, int u)->void
    {
        for(auto [v, w] : g[u]){
            if(!vis[v]){
                vis[v] = 1;
                d[v] += d[u] + w;
                dfs(dfs, v);
            }
        }
    };
    dfs(dfs, root);
    for (int i = 1; i <= n;i++){
        d[i] *= d[i] * d[i];
    }
    vector<int> pp(n + 1), pm(n + 1), mp(n + 1), mm(n + 1);
    for (int i = 1; i <= n;i++){
        pp[i] = d[i] + v[i];
        mm[i] = -d[i] - v[i];
        pm[i] = d[i] - v[i];
        mp[i] = -d[i] + v[i];
    }
    sparse_table<int> st1(pp), st2(mm), st3(pm), st4(mp);
    while(q--){
        int l1, l2, r1, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int mx = max({
            st1.query(l1, r1) + st2.query(l2, r2),
            st4.query(l1, r1) + st3.query(l2, r2),
            st3.query(l1, r1) + st4.query(l2, r2),
            st2.query(l1, r1) + st1.query(l2, r2),
        });
        cout << mx << endl;
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