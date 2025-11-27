#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int INF = 5e18;
const int MOD = 998244353;
using i128 = __int128_t;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    sort(a.begin() + 1, a.end());
    vector<int> ans(n + 1);
    int k = 0;
    int pos = 0;
    vector<int> add(n + 1);
    for (int i = n - 1; i > 0;i--){
        add[i] = add[i - 1] + a[i];
        if(add[i]>a[n]){
            pos = i;
            break;
        }
    }

    vector<int> x(3);
    for (int i = n; i > pos;i--){
        if(i>n-2){
            ans[++k] = 0;
            continue;
        }
        if(x[0]==0){
            if(a[i+2]>=a[i+1]+a[i]){
                continue;
            }
            x[0] = a[i + 2], x[1] = a[i + 1], x[2] = a[i];
            ans[++k] = x[0] + x[1] + x[2];
            continue;
        }
        if(k+1==4){
            bool ok = 1;
            for(auto b:x){
                ok &= (b == a[i]);
            }
            if(ok){
                x[0] += a[i];
                ans[++k] = x[0] + x[1] + x[2];
                continue;
            }
        }
        if(a[i]+x[2]>=x[0]+x[1])continue;
        x[2] += a[i];
        sort(x.begin(), x.end());
        ans[++k] = x[0] + x[1] + x[2];
    }
    x[0] = x[1] = x[2] = 0;
    for(int i=n;i>pos;i--){
        x[2] += a[i];
        sort(x.begin(), x.end());
    }
    for(int i=pos;i>0;i--){
        if(x[2]+a[i]>=x[0]+x[1]) continue;
        x[2] += a[i];
        sort(x.begin(), x.end());
        ans[++k] = x[0] + x[1] + x[2];
    }
    while (k < n){
        ans[++k] = 0;
    }
    for (int i = 1; i <= n;i++){
        cout << ans[i] << ' ';
    }
    cout << '\n';
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