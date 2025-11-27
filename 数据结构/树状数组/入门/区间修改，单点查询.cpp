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
struct BIT{
    int n;
    vector<T> arr;
    BIT(int N){
        n = N;
        arr.resize(n + 2);
    }
    void update(int x, T p){
        for (; x <= n; x += x & -x){
            arr[x] += p;
        }
    }
    T query(int x){
        T res = 0;
        for (; x; x -= x & -x){
            res += arr[x];
        }
        return res;
    }
    T query(int l, int r){
        return query(r) - query(l - 1);
    }
};
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    BIT<int> bit(n);
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        bit.update(i, a[i] - a[i - 1]);
    }
    while(q--){
        int op;
        cin >> op;
        if(op==1){
            int l, r, x;
            cin >> l >> r >> x;
            bit.update(l, x);
            bit.update(r + 1, -x);
        }
        else{
            int i;
            cin >> i;
            cout << bit.query(i) << endl;
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