#include <bits/stdc++.h>
using namespace std;
#ifdef GILBCXX_DEBUG
#define DEBUG(x) std::cerr << x << std::endl
#else
#define DEBUG(x)
#endif
#define endl '\n'
#define int long long
const int INF = 5e18;
const int MOD = 998244353;
using i128 = __int128_t;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> b(n + 1), d(n + 1);
    for (int i = 1; i <= n;i++)
        cin >> b[i];
    for (int i = 1; i <= n;i++){
        d[i] = b[i] - b[i - 1];
    }
    int g = 0;
    for (int i = 2; i <= n;i++){
        g = __gcd(g, abs(d[i]));
    }
    if(g==0){
        cout << k << ' ' << k * (k + 1) / 2 << endl;
        return;
    }
    int mn = *min_element(b.begin() + 1, b.end());
    vector<int> res;
    for (int i = 1; i * i <= g;i++){
        if(g%i==0){
            res.push_back(i - mn);
            if(i!=g/i)
                res.push_back(g / i - mn);
        }
    }
    sort(res.begin(), res.end());

    auto check = [&](int x) -> bool
    {
        stack<int> st;
        vector<int> a(n + 1);
        for (int i = 1; i <= n;i++)
        {
            a[i] = b[i] + x;
        }
        int i = 1;
        while (i <= n){
            if(st.empty()){
                st.push(a[i]);
                i++;
            }
            else if(st.top()<=a[i]){
                if(a[i]%st.top()==0)
                {
                    st.push(a[i]);
                    i++;
                }
                else
                    return 0;
            }
            else{
                while(st.size()&&st.top()>a[i])
                {
                    if(st.top()%a[i]==0)
                        st.pop();
                    else
                        return 0;
                }
            }
        }
        return 1;
    };

    //cout << "x" << endl;
    int ans = 0, cnt = 0;
    for (auto &x : res)
    {
        //cout << x << ' ';
        if(x<1||x>k) continue;
        if(check(x)){
            cnt++, ans += x;
        }
    }
    cout << cnt << ' ' << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}