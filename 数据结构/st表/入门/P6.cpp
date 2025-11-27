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
    vector<int> a(3 * n + 2), b(3 * n + 2);
    for (int i = n + 1; i <= 2 * n;i++){
        cin >> a[i];
        a[i + n] = a[i];
        a[i - n] = a[i];
    }
    for (int i = n + 1; i <= 2 * n;i++){
        cin >> b[i];
        b[i + n] = b[i];
        b[i - n] = b[i];
    }
    sparse_table<int> mx(a);
    vector<int> ans(n + 1);
    for (int i = n + 1; i <= 2 * n;i++){
        int l = 1, r = n - 1;   //二分范围
        while(l<=r){
            int mid = (l + r) / 2;
            if(max(mx.query(i-mid,i-1),mx.query(i+1,i+mid))>=b[i]) r=mid-1;
            else l=mid+1;
        }
        ans[i - n] = (l == n ? -1 : l);
    }
    for (int i = 1; i <= n;i++){
        cout << (ans[i] ? ans[i] : -1) << ' ';
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
