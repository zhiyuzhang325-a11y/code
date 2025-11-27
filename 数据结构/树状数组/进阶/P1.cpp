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
const int MOD = 1e8 - 3;
using i128 = __int128_t;
template<typename T>
struct BIT{
    int n;
    vector<T> arr;
    BIT(int N){
        n = N;
        arr.resize(n + 1);
    }
    void update(int x, T p){
        for (; x <= n;x+=x&-x){
            arr[x] += p;
        }
    }
    T query(int x){
        T res = 0;
        for (; x; x -= x & -x){
            res += arr[x];
        }
        return res;
    }
    T query(int l, int r){
        return query(r) - query(l - 1);
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n;i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n;i++){
        cin >> b[i];
    }
    auto f = [](vector<int> &a) -> void
    {
        auto disc = a;
        disc[0] = -1e9;
        sort(disc.begin(), disc.end());
        disc.erase(unique(disc.begin(), disc.end()), disc.end());
        for (int i = 1; i < a.size();i++){
            a[i] = lower_bound(disc.begin(), disc.end(), a[i]) - disc.begin();
        }
    };
    f(a);
    f(b);
    vector<int> mp(n + 1);
    for (int i = 1; i <= n;i++){
        mp[b[i]] = i;
    }
    for (int i = 1; i <= n;i++){
        a[i] = mp[a[i]];
    }
    BIT<int> bit(n);
    int ans = 0;
    for (int i = n; i > 0;i--){
        bit.update(a[i], 1);
        ans += bit.query(a[i] - 1);
        ans %= MOD;
    }
    cout << ans % MOD << endl;
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
