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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            cin >> mat[i][j];
        }
    }
    int res = 0;
    for (int j = 1; j <= m;j++){
        int need = 0;
        for (int i = n; i > 0;i--){
            if(mat[i][j]<0){
                need += -mat[i][j];
                mat[i][j] = 0;
            }
            else{
                if(mat[i][j]>need){
                    mat[i][j] -= need;
                    need = 0;
                }
                else{
                    need -= mat[i][j];
                    mat[i][j] = 0;
                }
            }
        }
        //cout << j << ' ' << need << endl;
        res += need;
        if(j==m) break;
        for (int i = 1; i <= n;i++){
            mat[i][j + 1] += mat[i][j];
            mat[i][j] = 0;
        }
    }
    // for (int i = 1; i <= n;i++){
    //     for (int j = 1; j <= m;j++){
    //         cout << mat[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    int ans = res;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            ans += abs(mat[i][j]);
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
}