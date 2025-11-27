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
        arr.resize(n + 1);
    }
    void update(int x, T p){
        for (; x <= n;x+=x&-x){
            arr[x] = max(arr[x], p);
        }
    }
    T query(int x){
        T res = 0;
        for (; x; x -= x & -x){
            res = max(res, arr[x]);
        }
        return res;
    }
    T query(int l, int r){
        return query(r) - query(l - 1);
    }
};
void solve()
{
    vector<int> a;
    a.push_back(0);
    BIT<int> bit(5e4);
    int x;
    while (cin >> x){
        a.push_back(x);
    }
    int n = a.size() - 1;
    int len = 0;
    for (int i = n; i > 0;i--){
        int x = bit.query(a[i]);
        bit.update(a[i], x + 1);
        len = max(len, x + 1);
    }
    int ans = 0;
    BIT<int> bi(5e4);
    for (int i = 1; i <= n;i++){
        int x = bi.query(a[i] - 1);
        bi.update(a[i], x + 1);
        ans = max(ans, x + 1);
    }
    cout << len << endl << ans << endl;
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