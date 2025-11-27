#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int INF = 5e18;
const int MOD = 998244353;
using i128 = __int128_t;

void solve()
{
    const int N = 5e3;
    int n;
    cin >> n;
    vector<bitset<N>> row(n), col(n);
    for (int u = 0; u < n;u++){
        string s;
        cin >> s;
        for (int v = 0; v < n;v++){
            if(s[v]=='1'){
                row[u].set(v);
                col[v].set(u);
            }
        }
    }
    vector<int> ans;
    ans.reserve(n);
    for (int u = 0; u < n;u++){
        bool ok = 1;
        for (int v = 0; v < n;v++){
            if(u==v) continue;
            if(row[u].test(v)||(row[u]&col[v]).any()) 
            continue;
            ok = 0;
            break;
        }
        if(ok)
            ans.push_back(u);
        if(ans.size()==3) break;
    }
    if(ans.size()<3)
        cout << "NOT FOUND\n";
    else{
        for(auto v:ans)
            cout << v + 1 << ' ';
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    // cin >> T;
    T = 1;
    while (T--)
    {
        solve();
    }
}