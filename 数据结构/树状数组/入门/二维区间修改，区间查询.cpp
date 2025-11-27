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
struct BIT {
    int n, m;
    vector<T> arr;
    vector<vector<T>> add;
    BIT(int N) {
        n = N;
        arr.resize(n + 2);
    }
    BIT(int n, int m): n(n), m(m) {
        add.resize(n + 2, vector<T>(m + 2));
    }
    void update(int x, T p) {
        for (; x <= n; x += x & -x) {
            arr[x] += p;
        }
    }
    void update(int x, int _y, T v) {
        for (; x <= n; x += x & -x) {
            for (int y = _y; y <= m; y += y & -y) {
                add[x][y] += v;
            }
        }
    }
    void update(int x1, int y1, int x2, int y2, T v) {
        update(x1, y1, v);
        update(x1, y2 + 1, -v);
        update(x2 + 1, y1, -v);
        update(x2 + 1, y2 + 1, v);
    }
    T query(int x) {
        T res = 0;

        for (; x; x -= x & -x) {
            res += arr[x];
        }

        return res;
    }
    // T query(int l, int r){
    //     return query(r) - query(l - 1);
    // }
    T query(int x, int _y) {
        int res = 0;

        for (; x; x -= x & -x) {
            for (int y = _y; y; y -= y & -y) {
                res += add[x][y];
            }
        }

        return res;
    }
    T query(int x1, int y1, int x2, int y2) {
        return query(x2, y2) - query(x2, y1 - 1) - query(x1 - 1, y2) + query(x1 - 1, y1 - 1);
    }
};
template<typename T>
struct range_adder_2d {
    BIT<T> a, b, c, d;
    range_adder_2d(int n, int m) : a(n, m), b(n, m), c(n, m), d(n, m) {}
    void add(int x, int y, T v) {
        add(x, y, x, y, v);
    }
    void add(int x1, int y1, int x2, int y2, T v) {
        auto range_add = [&](int x, int y, T v) -> void {
            a.update(x, y, v);
            b.update(x, y, v * x);
            c.update(x, y, v * y);
            d.update(x, y, v *x * y);
        };
        range_add(x1, y1, v);
        range_add(x2 + 1, y1, -v);
        range_add(x1, y2 + 1, -v);
        range_add(x2 + 1, y2 + 1, v);
    }
    T query(int x1, int y1, int x2, int y2) {
        auto range_query = [&](int x, int y) -> T {
            return a.query(x, y) * (x + 1) * (y + 1)
            - b.query(x, y) * (y + 1)
            - c.query(x, y) * (x + 1)
            + d.query(x, y);
        };
        return range_query(x2, y2)
               - range_query(x1 - 1, y2)
               - range_query(x2, y1 - 1)
               + range_query(x1 - 1, y1 - 1);
    }
};
void solve() {
    int n, m;
    cin >> n >> m;
    range_adder_2d<int> bit(n, m);
    int op;

    while (cin >> op) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (op == 1) {
            int x;
            cin >> x;
            bit.add(a, b, c, d, x);
        } else {
            cout << bit.query(a, b, c, d) << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;

    //cin >> T;
    while (T--) {
        solve();
    }
}