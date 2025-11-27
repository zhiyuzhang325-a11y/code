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
    int W, n;
    cin >> W;
    n = W;
    cout << n << endl;
    for (int i = 1; i <= n;i++){
        cout << i << ' ';
    }
    cout << endl;
    int w = W, last = 0;
    cout << w << ' ';
    last = w + 1;
    for (int i = 2; i <= n;i++){
        cout << last << " ";
        last = last + w + 1;
    }
    cout << endl;
}

/*
2
1 2
2 3

3
1 2 3
3 4 8

4
1 2 3 4
4 5 9 15

5
1 2 3 4 5
4 5 9 15 20

5
1 2 3 4 5
5 6 12 18 24
*/

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