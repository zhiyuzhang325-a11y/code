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
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> hack(k + 1);
    vector<int> cnt(m + 1);
    for (int i = 1; i <= k;i++){
        auto &[x, y] = hack[i];
        cin >> x >> y;
        cnt[y] = 1;
    }
    int N = 1 << k;
    vector<vector<int>> dp(N + 1, vector<int>(n + 1));
    for (int i = 1; i <= m;i++){
        if(!cnt[i]) continue;
        for (int x = 1; x<=N;x++){
            int up=1
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
}