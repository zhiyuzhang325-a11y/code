#include <bits/stdc++.h>
using namespace std;
#ifdef GILBCXX_DEBUG
#define DEBUG(x) std::cerr << x << std::endl
#else
#define DEBUG(x)
#endif
// #define endl '\n'
#define int long long
const int INF = 5e18;
const int MOD = 998244353;
using i128 = __int128_t;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), d(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    for (int i = 2; i <= n; i++)
    {
        d[i] = a[i] - a[i - 1];
    }
    int k = 0;
    for (int i = 2; i <= n; i++)
    {
        k = __gcd(k, d[i]);
    }
    if (!k)
    {
        cout << "infinite" << endl;
        return;
    }
    set<int> se;
    for (int i = 1; i * i <= k; i++)
    {
        if (k % i == 0)
        {
            int x1 = i, x2 = k / i;
            se.insert(x1);
            se.insert(x2);
        }
    }
    vector<int> res(se.begin(), se.end());
    auto check=[&](int x)->bool
    {
        int ju=a[1]%x;
        if(ju==0)
            return 0;
        // for (int i = 2; i <= n;i++){
        //     if(a[i]%x!=ju){
        //         return 0;
        //     }
        // }
        return 1;
    };
    k = 1;
    int xx = 0;
    for(auto x:res){
        if(x==1||check(x)){
            k = x;
            xx = a[1] - a[1] % x + x;
            break;
        }
    }
    for(auto x:res){
        if(x==1||check(x)){
            int tt = a[1] - a[1] % x + x;
            //cout << tt << ' ' << x << endl;
            if(tt>xx){
                xx = tt;
                k = x;
            }
        }
    }
    if(k==1){
        int ans = 0;
        for (int i = 1; i <= n;i++){
            ans = __gcd(ans, a[i]);
        }
        cout << ans <<' '<<k<< endl;
        return;
    }
    int x = a[1] % k;
    cout << a[1] - x + k << ' ' << k << endl;
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