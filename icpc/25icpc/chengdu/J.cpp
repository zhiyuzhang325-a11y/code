#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int INF = 5e18;
const int MOD = 998244353;
using i128 = __int128_t;
void solve()
{
    int n, k, m;
    cin >> n >> k >> m;
    int cnt = n / k;
    if(n-cnt>=m)
        cout << m + (cnt + 1) / 2 << endl;
    else
        cout << m + (n - m + 1) / 2 << endl;

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