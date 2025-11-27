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
                st[k][r] = max(st[k - 1][r], st[k - 1][r - (1 << (k - 1))]);
            }
        }
    }
    T query(int l, int r){
        int k = __lg(r - l + 1);
        return max(st[k][r], st[k][l + (1 << k) - 1]);
    }
};
void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n + 1), b(m + 1);
    for (int i = 1; i <= n;i++){
        cin >> a[i];
    }
    for (int i = 1; i <= m;i++){
        cin >> b[i];
    }
    auto a1 = a, a2 = a;
    for (int i = 1; i <= n;i++){
        if(a1[i]<0) a1[i]=1e9;
        if(a2[i]>=0) a2[i]=-1e9;
    }
    sparse_table<int> mi_a1(a1), mi_b(b), mi_a(a);
    sparse_table2<int> mx_a(a), mx_b(b), mx_a2(a2);
    while(q--){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int mii_b = mi_b.query(l2, r2);
        int mxx_b = mx_b.query(l2, r2);
        int mii_a1 = mi_a1.query(l1, r1);
        int mxx_a2 = mx_a2.query(l1, r1);
        int mxx_a = mx_a.query(l1, r1);
        int mii_a = mi_a.query(l1, r1);
        if(mii_b>=0){
            if(mxx_a>0){
                cout << mxx_a * mii_b << endl;
            }
            else{
                cout << mxx_a * mxx_b << endl;
            }
        }
        else if(mxx_b<=0){
            if(mii_a<0){
                cout << mii_a * mxx_b << endl;
            }
            else{
                cout << mii_a * mii_b << endl;
            }
        }
        else{
            if(mxx_a<=0){
                cout << mxx_a * mxx_b << endl;
            }
            else if(mii_a>=0){
                cout << mii_a * mii_b << endl;
            }
            else
                cout << max(mii_a1 * mii_b, mxx_a2 * mxx_b) << endl;
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