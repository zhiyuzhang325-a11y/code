#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int INF = 5e18;
const int MOD = 998244353;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    int cnt2 = 0;
    vector<vector<int>> cnt(2, vector<int>(2));
    for (int i = 0; i < n;i++){
        if(s[i]=='2')
            cnt2++;
        else
            cnt[i % 2][s[i] - '0']++;
    }
    int cnt0 = abs(cnt[0][0] - cnt[1][0]);
    int cnt1 = abs(cnt[0][1] - cnt[1][1]);
    int x = min(cnt0, cnt2);
    cnt0 -= x;
    cnt2 -= x;
    x = min(cnt1, cnt2);
    cnt1 -= x;
    cnt2 -= x;
    cnt2 %= 2;
    cout << cnt0 + cnt1 + cnt2 << '\n';
}

signed main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}