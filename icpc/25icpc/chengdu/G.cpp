#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int INF = 5e18;
const int MOD = 998244353;
using i128 = __int128_t;
void solve()
{
    int n, m, k;
    cin >> n >> k >> m;
    vector<int> prime;
    vector<int> is_prime(n + 1);
    auto Eratosthenes = [&](int n) -> void
    {
        is_prime[0] = is_prime[1] = 0;
        for (int i = 2; i * k <= n; ++i)
            is_prime[i] = 1;
        for (int i = 2; i * k <= n; ++i)
        {
            if (is_prime[i])
            {
                prime.push_back(i);
                if ((long long)i * i > n)
                    continue;
                for (int j = i * i; j <= n; j += i)
                    is_prime[j] = 0;
            }
        }
    };
    Eratosthenes(n);

    int ans = 1;
    vector<int> res;
    for (int i = 1; i <= n;i++){
        if(i%k==0&&i!=k){
            res.push_back(i/k);
        }
    }
    ans += res.size() / 2;
    ans += m;
    if(ans>n)
        ans = n;
    cout << ans << '\n';
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