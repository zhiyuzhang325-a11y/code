#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int INF = 5e18;
const int MOD = 998244353;
using i128 = __int128_t;
void solve()
{
    int n, m;
    cin >> n >> m;
    if(__gcd(n,m)>1){
        cout<<"No"<<'\n';
        return;
    }
    cout << "Yes" << '\n';
    int mod = n * m;
    for (int i = 0; i < n;i++){
        cout << (i * m + 1) % mod << ' ';
    }
    cout << '\n';
    for (int i = 0; i < m;i++){
        cout << (i * n + 1) % mod << ' ';
    }
    cout << '\n';
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