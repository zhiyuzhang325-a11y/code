#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int INF = 5e18;
const int MOD = 998244353;
using i128 = __int128_t;

void solve()    //  cf上会TL,qoj上能过,没有前一个常数低
{
    const int N = 5e3;
    int n;
    cin >> n;
    vector<bitset<N>> s(n);
    for (int i = 0; i < n;i++){
        string str;
        cin >> str;
        for (int j = 0; j < n;j++){
            s[i][j] = (str[j] == '1');
        }
    }
    vector<int> ans;
    for (int i = 0; i < n;i++){
        bitset<N> cur = s[i];
        for (int j = 0; j < n;j++){
            if(s[i][j]){
                cur |= s[j];
            }
        }
        if(cur.count()==n-1){
            ans.push_back(i);
        }
        if(ans.size()==3) break;
    }
    if(ans.size()<3){
        cout << "NOT FOUND" << '\n';
    }
    else{
        for(auto v:ans)
                cout << v + 1 << ' ';
            cout << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    // cin >> T;
    T = 1;
    while (T--)
    {
        solve();
    }
}