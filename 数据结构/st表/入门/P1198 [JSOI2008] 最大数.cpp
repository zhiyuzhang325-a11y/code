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
                st[k][r] = max(st[k - 1][r], st[k - 1][r - (1 << (k - 1))]);
            }
        }
    }
    T query(int l, int r){
        int k = __lg(r - l + 1);
        return max(st[k][r], st[k][l + (1 << k) - 1]);
    }
    void insert(int i, int x){
        st[0][i] = x;
        for (int k = 1; k <= logn;k++){
            if (i - (1 << k) + 1 < 0) break;    //st表左边有1 << k - 1个0
            st[k][i] = max(st[k - 1][i], st[k - 1][i - (1 << (k - 1))]);
        }
    }
};
void solve()
{
    int m, d;
    cin >> m >> d;
    vector<int> a(m + 1);
    sparse_table<int> mx(a);
    int res = 0, n = 0;
    while(m--){
        char op;
        cin >> op;
        if (op == 'Q'){
            int L;
            cin >> L;
            res = mx.query(n - L + 1, n);
            cout << res << endl;
        }
        else{
            int x;
            cin >> x;
            n++;
            mx.insert(n, (x + res) % d);
        }
    }
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