#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int INF = 5e18;
const int MOD = 998244353;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<set<int>> g(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }
    auto G = g;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    stack<int> st;
    auto add=[&](int v){
        st.push(v);
        for(auto u:g[v]){
            G[u].erase(v);
        }
    };
    int ans = 0;
    vector<pair<int, int>> res;
    for (int i = 0; i < n;i++){
        int target = p[i];
        while(1){
            if(st.empty()){
                add(target);
                break;
            }

            int x = st.top();
            if(G[x].empty()){
                st.pop();
                continue;
            }
            else if(G[x].find(target)!=G[x].end()){
                add(target);
                break;
            }
            else{
                ans++;
                res.push_back({x, target});
                g[x].insert(target);
                g[target].insert(x);
                add(target);
                break;
            }
        }
    }
    cout << ans << '\n';
    for(auto [u,v]:res)
        cout << u << ' ' << v << endl;
}

signed main()
{
    int T;
    T = 1;
    while (T--)
    {
        solve();
    }
}
/*
8 8
2 8
3 8
5 6
1 6
6 3
8 7
2 3
4 3
1 8 7 5 4 3 2 6
*/