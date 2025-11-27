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
    int lcm(int a, int b){
        return a / __gcd(a, b) * b;
    }
    sparse_table(const vector<T> &a){
        n = a.size() - 1;
        logn = __lg(n);
        st.resize(logn + 1, vector<T>(n + 1));
        st[0] = a;
        for (int k = 1; k <= logn;k++){
            for (int r = 1 << k; r <= n;r++){
                st[k][r] = __gcd(st[k - 1][r], st[k - 1][r - (1 << (k - 1))]);
            }
        }
    }
    T query(int l, int r){
        int k = __lg(r - l + 1);
        return __gcd(st[k][r], st[k][l + (1 << k) - 1]);
    }
    void updata(int l, int r, int z){
        int k = __lg(r - l + 1);
        st[k][r] = lcm(st[k][r], z);
        st[k][l + (1 << k) - 1] = lcm(st[k][l + (1 << k) - 1], z);
    }
    vector<T> make(){
        for (int k = logn; k >= 1;k--){
            for (int r = 1 << k; r <= n;r++){
                st[k - 1][r] = lcm(st[k - 1][r], st[k][r]);
                st[k - 1][r - (1 << (k - 1))] = lcm(st[k - 1][r - (1 << (k - 1))], st[k][r]);
            }
        }
        return st[0];
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1, 1);
    sparse_table<int> st(a);
    vector<tuple<int, int, int>> cons(m + 1);
    for (int i = 1; i <= m;i++){
        auto &[l, r, z] = cons[i];
        cin >> l >> r >> z;
        st.updata(l, r, z);
    }
    a = st.make();
    sparse_table<int> st1(a);
    for (int i = 1; i <= m;i++){
        auto [l, r, z] = cons[i];
        if(z!=st1.query(l,r)){
            cout << "Impossible" << endl;
            return;
        }
    }
    for (int i = 1; i <= n;i++){
        cout << a[i] << ' ';
    }
    cout << endl;
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