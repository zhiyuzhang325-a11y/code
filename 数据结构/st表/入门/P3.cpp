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
                st[k][r] = max(st[k - 1][r], st[k - 1][r - (1 << (k - 1))]);
            }
        }
    }
    T query(int l, int r){
        int k = __lg(r - l + 1);
        return max(st[k][r], st[k][l + (1 << k) - 1]);
    }
};
template<typename T>
struct sparse_table2{
    vector<vector<T>> st;
    int n, logn;
    sparse_table2(const vector<T> &a){
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
        auto &[x, y] = a[i];
        cin >> x >> y;
    }
    int S2 = 1e18;
    int S1;
    auto f = [&]() -> void
    {
        sort(a.begin() + 1, a.end());
        vector<int> b(n + 1);
        for (int i = 1; i <= n; i++)
        {
            b[i] = a[i].second;
        }
        sparse_table<int> mx(b);
        sparse_table2<int> mi(b);
        S1 = (a[n].first - a[1].first) * (mx.query(1, n) - mi.query(1, n));
        for (int i = 2; i <= n; i++)
        {
            int s1 = (a[i - 1].first - a[1].first) * (mx.query(1, i - 1) - mi.query(1, i - 1));
            int s2 = (a[n].first - a[i].first) * (mx.query(i, n) - mi.query(i, n));
            S2 = min(S2, s1 + s2);
        }
    };
    f();
    for (int i = 1; i <= n;i++){
        swap(a[i].first, a[i].second);
    }
    f();
    cout << S1 - S2 << endl;
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
