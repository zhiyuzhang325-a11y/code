#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int INF = 5e18;
const int MOD = 998244353;

void solve()
{
    int n, m, k, w;
    cin >> n >> m >> k >> w;
    vector<int> a(n + 1), b(m + 2);
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    for (int i = 1; i <= m;i++)
        cin >> b[i];
    b[m + 1] = w + 1;
    sort(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end());

    // for (int i = 1; i <= n;i++)
    //     cout << b[i] << ' ';
    // cout << endl;
    vector<int> pos(n + 1);
    int L = 0, R = b[1];//黑
    int p = 0;
    int s = 0, e = 0;
    for (int i = 1; i <= m+1;i++){
        s = e + 1;
        for (; p <= n;p++){
            if(a[p]>R)
                break;
            if(a[p]<=pos[e])
                continue;
            else{
                pos[++e] = a[p] + k - 1;
            }
        }
        s = min(e, s);
        if(pos[e]>=R){
            int x = pos[e] - R + 1;
            pos[e] -= x;
            for (int j = e - 1; j >= s;j--){
                x = pos[j] - (pos[j + 1] - k + 1);
                if(x<0)
                    break;
                else
                    pos[j] -= x + 1;
            }
            if(pos[s]-k+1<=L){
                //cout << L << ' ' << R << ' ' << pos[s] << endl;
                cout << -1<<endl;
                return;
            }
        }
        L = R;
        if(i<=m)R = b[i + 1];
    }
    cout << e << '\n';
    for (int i = 1; i <= e;i++){
        cout << pos[i] - k + 1 << ' ';
    }
    cout << '\n';
}

signed main()
{
    int T;
    cin >> T;
    while (T--)
    {
        //cout << "T = " << T << endl;
        solve();
    }
}