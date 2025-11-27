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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    BIT<int> bit(n);
    for (int i = 1; i <= n;i++){
        cin >> a[i];
    }
    int cnt = 0;
    for (int i = n; i > 0;i--){

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