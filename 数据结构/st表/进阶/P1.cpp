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
template<typename T>
struct sparse_table{
    vector<vector<T>> st;
    int n, logn;
    sparse_table(const vector<T> &a){
        n = a.size() - 1;
        logn = __lg(n);
        st.resize(logn + 1, vector<T>(n + 1));
        st[0] = a;
        for (int k = 1; k <= logn;k++){
            for (int r = 1 << k; r <= n;r++){
                st[k][r] = min(st[k - 1][r], st[k - 1][r - (1 << (k - 1))]);
            }
        }
    }
    T query(int l, int r){
        int k = __lg(r - l + 1);
        return min(st[k][r], st[k][l + (1 << k) - 1]);
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n + 1);
    for (int i = 1; i <= n;i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin() + 1, a.end(), [](auto a, auto b)
         { return a.second > b.second; });
    vector<int> sum(n + 1), A(n + 1);
    for (int i = 1; i <= n;i++){
        sum[i] = a[i].first + a[i].second;
        A[i] = a[i].first;
    }
    sparse_table<int> mi1(sum), mi2(A);
    int ans = 1e9;
    for (int i = 2; i <= n - 1;i++){
        ans = min(ans, sum[i] + mi1.query(1, i - 1) + mi2.query(i + 1, n));
    }
    cout << ans << endl;
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
