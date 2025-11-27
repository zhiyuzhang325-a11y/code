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
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), d(n + 1);
    for (int i = 1; i <= n;i++){
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    for (int i = 2; i <= n;i++){
        d[i] = a[i] - a[i - 1];
    }
    int k = 0;
    for (int i = 2; i <= n;i++){
        k = __gcd(k, d[i]);
    }
    if(!k){
        cout << "infinite" << endl;
        return;
    }
    int ans = k/__gcd(k,a[1]);
    cout << k << ' ' << ans << endl;
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