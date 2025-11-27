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
    T lower_bound(T target) { return lower_bound(1, target); }
    //找到最后一个 query(r) < target的位置
    // index + 1是第一个 >= target的位置
    T lower_bound(int l, T target){
        if(target < 0) return 0;
        T sum = 0;
        int index = 0;
        for (int i = 1 << __lg(n); i; i >>= 1){
            if(index + i <= n && sum + arr[index + i] < target){
                index += i;
                sum += arr[index];
            }
        }
        return index + 1;
    }
};
void solve()
{
    int n, q;
    cin >> n >> q;
    int aA, aB, aC;
    int op0, opA, opB;
    int x0, xA, xB;
    int z0, zA, zB;
    vector<int> a(n + 1);
    cin >> a[0] >> aA >> aB >> aC;
    cin >> op0 >> opA >> opB;
    cin >> x0 >> xA >> xB;
    cin >> z0 >> zA >> zB;
    int total = 0;
    BIT<int> bit(n);
    for (int i = 1; i <= n; i++)
    {
        a[i] = (a[i - 1] * aA + aB) % aC;
        bit.update(i, a[i]);
        total += a[i];
    }
    int ans = 0;
    for (int i = 1; i <= q; i++)
    {
        int op = (op0 * opA + opB) % 9 + 1;
        int x = (x0 * xA + xB) % n + 1;
        int z = ((long long)z0 * zA + zB) % (op == 1 ? aC : total);
        op0 = op;
        x0 = x;
        z0 = z;
        // 处理 op, x, z
        if(op==1){
            bit.update(x, z - a[x]);
            a[x] = z;
        }
        else if(op<=3){
            z += (op == 3);
            int y = max(bit.lower_bound(x, bit.query(x - 1) + z), x);
            // cout << y << endl;
            ans += (y > n ? -1 : y);
        }
        else if(op<=5){
            z += (op == 4);
            int y = bit.lower_bound(x, bit.query(x - 1) + z) - 1;
            // cout << y << endl;
            ans += (y < x ? -1 : y);
        }
        else if(op<=7){
            z += (op == 7);
            int y = min(bit.lower_bound(x, bit.query(x) - z + 1), x);
            // cout << y << endl;
            ans += (y < 1 ? -1 : y);
        }
        else{
            z -= (op == 9);
            int y = bit.lower_bound(x, bit.query(x) - z) + 1;   //!可能传递的参数 < 0
            // cout << y << endl;
            ans += (y > x ? -1 : y);
        }
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