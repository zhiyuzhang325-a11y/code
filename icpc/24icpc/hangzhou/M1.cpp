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

struct node {
  int idx, val, par, ch[2];

  friend bool operator<(node a, node b) { return a.idx < b.idx; }

  void init(int _idx, int _val, int _par) {
    idx = _idx, val = _val, par = _par, ch[0] = ch[1] = 0;
  }
};

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> b(n + 1);
    vector<node> tree(n + 1);
    for (int i = 1; i <= n;i++){
        cin >> b[i];
        tree[i].init(i, b[i], 0);
    }
    tree[0].init(0, 0, 0);

    auto cartesian_build = [&](int n) -> int { // 建树，满足小根堆性质
        for (int i = 1; i <= n; i++)
        {
            int k = i - 1;
            while (tree[k].val > tree[i].val)
                k = tree[k].par;
            tree[i].ch[0] = tree[k].ch[1];
            tree[k].ch[1] = i;
            tree[i].par = k;
            tree[tree[i].ch[0]].par = i;
        }
        return tree[0].ch[1];
    };
    int root = cartesian_build(n);

    vector<int> L(n + 1), R(n + 1);
    auto dfs = [&](auto &&dfs, int u) -> void //区间边界，左子树和右子树的子节点
    {
        if(!u) return;
        int l = tree[u].ch[0];
        int r = tree[u].ch[1];
        dfs(dfs, l);
        dfs(dfs, r);
        L[u] = l ? L[l] : tree[u].idx;
        R[u] = r ? R[r] : tree[u].idx;
    };
    dfs(dfs, root);

    int g = 0;
    for (int i = 2; i <= n;i++){
        g = __gcd(g, abs(b[i] - b[i - 1]));
    }
    if(!g){
        cout << k << ' ' << k * (k + 1) / 2 << endl;
        return;
    }
    int mn = *min_element(b.begin() + 1, b.end());
    vector<int> res;
    for (int i = 1; i * i <= g;i++){
        if(g%i==0){
            res.push_back(i - mn);
            if(i!=g/i)                              //特判 i == g/i
                res.push_back(g / i - mn);
        }
    }

    vector<int> gc(n + 1);
    auto dfs1 = [&](auto &&dfs1, int u) -> void
    {
        int l = tree[u].ch[0];
        int r = tree[u].ch[1];
        if(L[u]==R[u]){
            gc[u] = 0;
            return;
        }
        dfs1(dfs1, l);
        dfs1(dfs1, r);
        gc[u] = __gcd(gc[l], gc[r]);
        if(l)
            gc[u] = __gcd(gc[u], abs(b[u] - b[l]));
        if(r)
            gc[u] = __gcd(gc[u], abs(b[r] - b[u]));
    };
    dfs1(dfs1, root);

    auto check = [&](int x)
    {
        for (int i = 1; i <= n; i++){
            if(gc[i]%(b[i]+x)){
                return 0;
            }
        }
        return 1;
    };
    int ans = 0, cnt = 0;
    for (auto &x : res)
    {
        if(x<1||x>k) continue;
        if(check(x)){
            ans += x;
            cnt++;
        }
    }
    cout << cnt << ' ' << ans << endl;
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