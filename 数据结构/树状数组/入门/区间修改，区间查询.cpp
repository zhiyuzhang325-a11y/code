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
    void undate(int x, T p){
        for (; x <= n; x += x & -x){
            arr[x] += p;
        }
    }
    T query(int x){
        if(x == 0) return 0;
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
template<typename T>
struct range_adder{
    BIT<T> sum, correct;
    range_adder(int n) : sum(n), correct(n){}
    void add(int i, T v) { add(i, i, v); }
    void add(int l, int r, T v){
        sum.undate(l, v);
        sum.undate(r + 1, -v);
        correct.undate(l, v * l);
        correct.undate(r + 1, -v * (r + 1));
    }
    T query(int l, int r){
        return (r + 1) * sum.query(r) - l * sum.query(l - 1) - correct.query(l, r);
    }
};
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    range_adder<int> bit(n);
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        bit.add(i, a[i]);   //初始sum,correct都是值为0的差分数组，然后往里面加a[i]而不是a[i]-a[i-1]
    }
    while(q--){
        int op, l, r;
        cin >> op >> l >> r;
        if(op==1){
            int x;
            cin >> x;
            bit.add(l, r, x);
        }
        else{
            cout << bit.query(l, r) << endl;
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