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
    int n, m;
    vector<T> arr;
    vector<vector<T>> add;
    BIT(int N){
        n = N;
        arr.resize(n + 2);
    }
    BIT(int n, int m):n(n),m(m){
        add.resize(n + 2, vector<T>(m + 2));
    }
    void update(int x, T p){
        for (; x <= n; x += x & -x){
            arr[x] += p;
        }
    }
    void update(int x, int _y, T v){
        for (; x <= n;x+=x&-x){
            for (int y = _y; y <= m; y += y & -y){
                add[x][y] += v;
            }
        }
    }
    void update(int x1, int y1, int x2, int y2, T v){
        update(x1, y1, v);
        update(x1, y2 + 1, -v);
        update(x2 + 1, y1, -v);
        update(x2 + 1, y2 + 1, v);
    }
    T query(int x){
        T res = 0;
        for (; x; x -= x & -x){
            res += arr[x];
        }
        return res;
    }
    // T query(int l, int r){
    //     return query(r) - query(l - 1);
    // }
    T query(int x, int _y){
        int res = 0;
        for (; x; x -= x & -x){
            for (int y = _y; y; y -= y & -y){
                res += add[x][y];
            }
        }
        return res;
    }
    T query(int x1, int y1, int x2, int y2){
        return query(x2, y2) - query(x2, y1 - 1) - query(x1 - 1, y2) + query(x1 - 1, y1 - 1);
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    BIT<int> bit(n, m);
    int op;
    while(cin>>op){
        if(op==1){
            int x1, y1, x2, y2, k;
            cin >> x1 >> y1 >> x2 >> y2 >> k;
            bit.update(x1, y1, x2, y2, k);
        }
        else{
            int x, y;
            cin >> x >> y;
            cout << bit.query(x, y) << endl;
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