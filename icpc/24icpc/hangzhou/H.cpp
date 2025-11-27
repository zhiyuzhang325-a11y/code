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
struct node
{
    int len, R;
    vector<int> ch;
};

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(k + 1);
    for (int i = 1; i <= k;i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin() + 1,a.end(),[&](auto a, auto b){
        return a.second - a.first > b.second - b.first;
    });
    vector<int> cnt(n + 1);
    vector<vector<int>> pos(n + 1);
    for (int i = 2; i <= k;i++){
        int len = a[i].second - a[i].first + 1;
        cnt[len]++;
        pos[len].push_back(i);
    }
    vector<node> tree(n + 1);
    for (int i = 1; i <= k;i++){
        auto [l, r] = a[i];
        while(l<=r){
            tree[l].R = r;
            tree[l].len = r - l + 1;
            l++;
        }
    }
    int root = a[1].first;
    auto dfs = [&](auto &&dfs, int u) -> void
    {
        if(tree[u].len==1){
            return;
        }

        int L = tree[u].len - 1;
        while(L){
            while(L>0&&cnt[L]==0){
                L--;
            }
            // for (int i = 1; i <= 3;i++){
            //     cout << "len = " << i << " cnt = " << cnt[i] << endl;
            // }
            //cout << u << ' ' << L << endl;
            if(L){
                int v = a[pos[L][0]].first;
                pos[L].erase(pos[L].begin());
                //cout << "v = " << v << endl;
                tree[u].ch.push_back(v);
                cnt[L]--;
                dfs(dfs, v);
            }
        }
        //cout << "u = " << u << endl;
        if(tree[u].R>u){
            tree[u].ch.push_back(u + 1);
            dfs(dfs, u + 1);
        }
    };
    dfs(dfs, root);

    for (int i = 1; i <= n;i++){
        if(cnt[i]){
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }
    vector<int> fa(n + 1);
    for (int i = 1; i <= n;i++){
        for(auto son:tree[i].ch){
            fa[son] = i;
        }
    }
    for (int i = 1; i <= n;i++){
        cout << fa[i] << ' ';
    }
    cout << endl;
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