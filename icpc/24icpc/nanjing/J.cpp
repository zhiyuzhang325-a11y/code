#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int INF = 5e18;
const int MOD = 998244353;

struct Pl
    {
        int a, b;
    };

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> f(k + 1);
    for (int i = 1; i <= n;i++){
        int F;
        cin >> F;
        f[F] = 1;
    }
    vector<Pl> pl(m + 1);
    for (int i = 1; i <= m;i++){
        cin >> pl[i].a >> pl[i].b;
    }
    map<pair<int, int>, int> mp;
    vector<int> cnt(k + 1);
    int ans = 0;
    for (int i = 1; i <= m;i++){
        auto &[a, b] = pl[i];
        if(b>a)
            swap(a, b);
        if(f[a]&&f[b])
            ans++;
        else if(f[a]){
            cnt[b]++;
        }
        else if(f[b]){
            cnt[a]++;
        }
        else if(a==b){
            cnt[a]++;
        }
        else{
            mp[{a, b}]++;
        }
    }

    int sum1 = 0, sum2 = 0;
    int res = 0, mx = -1;
    int a, b;
    if(mp.size()){
        for (auto it = mp.begin(); it != mp.end();it++){
                mx = it->second;
                a = it->first.first;
                b = it->first.second;
                res = max(mx + cnt[a] + cnt[b], res);
                //cout << a << ' ' << b << ' ' << mx << ' ' << res << endl;
        }
        sum2 = res;
    }
    // for (int i = 1; i <= k;i++){
    //     cout << i << ' ' << cnt[i] << endl;
    // }
        sort(cnt.begin() + 1, cnt.end());
    sum1 = cnt[k] + cnt[k - 1];
    //cout << cnt[k] << ' ' << cnt[k - 1] << endl;
    //cout << ans << ' ' << sum1 << ' ' << sum2 << endl;
    cout << ans + max(sum1, sum2) << '\n';
}

signed main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}